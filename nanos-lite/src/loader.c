#include <proc.h>
#include <elf.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB *pcb, const char *filename)
{
  Elf_Ehdr ehdr;
  ramdisk_read(&ehdr, 0, sizeof(Elf_Ehdr));
  assert(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0);
  assert(ehdr.e_machine == EM_RISCV);

  size_t phdr_size = ehdr.e_phnum * ehdr.e_phentsize;
  Elf_Phdr *phdr = malloc(phdr_size);
  assert(phdr != NULL);
  ramdisk_read(phdr, ehdr.e_ehsize, phdr_size);
  for (int i = 0; i < ehdr.e_phnum; i++)
  {
    if (phdr[i].p_type == PT_LOAD)
    {
      ramdisk_read((void *)phdr[i].p_vaddr, phdr[i].p_offset, phdr[i].p_memsz);
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
