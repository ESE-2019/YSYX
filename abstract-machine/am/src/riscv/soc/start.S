.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  la a0, _bootloader_vma_start
  la a1, _bootloader_vma_end
  la a2, _bootloader_lma_start

1:
  bge a0, a1, 2f
  lw a3, 0(a2)
  sw a3, 0(a0)
  addi a0, a0, 4
  addi a2, a2, 4
  j 1b

2:
  call _bootloader