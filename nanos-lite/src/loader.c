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
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void (*)())entry)();
}
