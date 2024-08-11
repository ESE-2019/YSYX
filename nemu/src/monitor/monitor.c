/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN),
                          ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE,
        Log("If trace is enabled, a log file will be generated "
            "to record the trace. This may lead to a large log file. "
            "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n",
         ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/mman.h>
#include <string.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

#ifdef CONFIG_FTRACE
#define NR_FT 256
char FT_name [NR_FT][256] = {};
uint32_t FT_addr [NR_FT] = {};
void get_elf_function(const char *filename) {
    int index = 0;
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        Log(ANSI_FMT("Open elf failed %s", ANSI_FG_YELLOW ANSI_BG_RED), filename);
        return;
    }
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("lseek");
        close(fd);
        return;
    }
    void *map = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return;
    }
    Elf32_Ehdr *ehdr = (Elf32_Ehdr *)map;
    if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file\n");
        munmap(map, file_size);
        close(fd);
        return;
    }
    Elf32_Shdr *shdr = (Elf32_Shdr *)(map + ehdr->e_shoff);
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB || shdr[i].sh_type == SHT_DYNSYM) {
            Elf32_Sym *sym = (Elf32_Sym *)(map + shdr[i].sh_offset);
            char *strtab = (char *)(map + shdr[shdr[i].sh_link].sh_offset);
            for (int j = 0; j < shdr[i].sh_size / shdr[i].sh_entsize; j++) {
                if (ELF32_ST_TYPE(sym[j].st_info) == STT_FUNC) {
                    Log("Function: %s, Address: "FMT_WORD, strtab + sym[j].st_name, sym[j].st_value);
                    strncpy(FT_name[index], strtab + sym[j].st_name, 256);
                    FT_addr[index] = sym[j].st_value;
                    index++;
                }
            }
        }
    }
    munmap(map, file_size);
    close(fd);
    strncpy(FT_name[index], "UNKNOWN", 256);
    FT_addr[index] = 0;
}
char* bin2elf(const char* input) {
    const char* bin_suffix = ".bin";
    const char* elf_suffix = ".elf";
    size_t bin_len = strlen(bin_suffix);
    size_t input_len = strlen(input);
    if (input_len < bin_len || strcmp(input + input_len - bin_len, bin_suffix) != 0) {
        return NULL;
    }
    size_t new_len = input_len - bin_len + strlen(elf_suffix) + 1;
    char* result = (char*)malloc(new_len);
    if (result == NULL) {
        return NULL;
    }
    strncpy(result, input, input_len - bin_len);
    strcpy(result + input_len - bin_len, elf_suffix);
    return result;
}
#endif

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }
  
  #ifdef CONFIG_FTRACE
  char * img_elf = bin2elf(img_file);
  get_elf_function(img_elf);
  free(img_elf);
  #endif
  
  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  Assert(ret == 1, "ret = %d", ret);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"batch", no_argument, NULL, 'b'},
      {"log", required_argument, NULL, 'l'},
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      sdb_set_batch_mode();
      break;
    case 'p':
      sscanf(optarg, "%d", &difftest_port);
      break;
    case 'l':
      log_file = optarg;
      break;
    case 'd':
      diff_so_file = optarg;
      break;
    case 1:
      img_file = optarg;
      return 0;
    default:
      printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
      printf("\t-b,--batch              run with batch mode\n");
      printf("\t-l,--log=FILE           output log to FILE\n");
      printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
      printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
      printf("\n");
      exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE,
        init_disasm(
            MUXDEF(CONFIG_ISA_x86, "i686",
                   MUXDEF(CONFIG_ISA_mips32, "mipsel",
                          MUXDEF(CONFIG_ISA_riscv,
                                 MUXDEF(CONFIG_RV64, "riscv64", "riscv32"),
                                 "bad"))) "-pc-linux-gnu"));
#endif

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
