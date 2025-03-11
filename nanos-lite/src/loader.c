#include <proc.h>
#include <elf.h>
#include <fs.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB *pcb, const char *filename)
{
  int fd = fs_open(filename, 0, 0);
  assert(fd >= 0);
  Elf_Ehdr ehdr;
  fs_read(fd, &ehdr, sizeof(Elf_Ehdr));
  assert(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0);
  assert(ehdr.e_machine == EM_RISCV);

  size_t phdr_size = ehdr.e_phnum * ehdr.e_phentsize;
  Elf_Phdr *phdr = malloc(phdr_size);
  assert(phdr != NULL);
  fs_lseek(fd, ehdr.e_ehsize, SEEK_SET);
  fs_read(fd, phdr, phdr_size);
  for (int i = 0; i < ehdr.e_phnum; i++)
  {
    if (phdr[i].p_type == PT_LOAD)
    {
      fs_lseek(fd, phdr[i].p_offset, SEEK_SET);
      fs_read(fd, (void *)phdr[i].p_vaddr, phdr[i].p_memsz);
      memset((void *)(phdr[i].p_vaddr + phdr[i].p_filesz), 0, phdr[i].p_memsz - phdr[i].p_filesz);
    }
  }

  return ehdr.e_entry;
}

void naive_uload(PCB *pcb, const char *filename)
{
  Log("Jump to %s", filename);
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void (*)())entry)();
}

void context_kload(PCB *pcb, void (*entry)(void *), void *arg)
{
  pcb->cp = kcontext((Area){pcb->stack, pcb + 1}, entry, arg);
}

void context_uload(PCB *pcb, const char *filename, char *const argv[], char *const envp[])
{
  uintptr_t entry = loader(pcb, filename);
  pcb->cp = ucontext(NULL, (Area){pcb->stack, pcb + 1}, (void *)entry);
  Log("context_uload %s %p", filename, entry);
  Log("%p argv = %p, envp = %p", argv[0], argv, envp);
  uintptr_t ustack = (uintptr_t)(new_page(8) + 8 * PGSIZE);

  int argc = 0, envp_count = 0;
  int len = 0;
  assert(argv != NULL);
  Log("alive");
  while (argv[argc] != NULL)
  {
    Log("argv[%d] = [%s]", argc, argv[argc]);
    len += strlen(argv[argc]) + 1;
    argc++;
  }
  Log("alive");
  while (envp[envp_count] != NULL)
  {
    Log("envp[%d] = [%s]", envp_count, envp[envp_count]);
    len += strlen(envp[envp_count]) + 1;
    envp_count++;
  }
  Log("alive");
  uintptr_t string_area = (ustack - len) & ~(sizeof(uintptr_t) - 1);
  ustack = string_area - sizeof(uintptr_t);
  *(uintptr_t *)ustack = 0;
  for (int i = envp_count - 1; i >= 0; i--)
  {
    ustack -= sizeof(uintptr_t);
    *(uintptr_t *)ustack = string_area;
    strcpy((char *)string_area, envp[i]);
    string_area += strlen(envp[i]) + 1;
  }
  Log("alive");
  ustack -= sizeof(uintptr_t);
  *(uintptr_t *)ustack = 0;
  for (int i = argc - 1; i >= 0; i--)
  {
    ustack -= sizeof(uintptr_t);
    *(uintptr_t *)ustack = string_area;
    strcpy((char *)string_area, argv[i]);
    string_area += strlen(argv[i]) + 1;
  }
  ustack -= sizeof(uintptr_t);
  *(int *)ustack = argc;
  pcb->cp->GPRx = ustack;
  Log("argc = %d sp = %p", *(int *)ustack, ustack);
}
