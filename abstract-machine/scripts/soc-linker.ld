ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = ORIGIN(flash);
  .text : {
    *(entry)
    *(.text*)
  } > flash AT > flash : text
  etext = .;
  _etext = .;

  .bootloader : {
    *(.bootloader*)
  } > flash AT > flash 

  .rodata : {
    *(.rodata*)
  } > flash AT > flash 

  .data : {
    _data_vma_start = .;
    *(.data*)
    *(.sdata*)
    _data_vma_end = .;
  } > sram AT > flash : data
  edata = .;
  _data = _data_vma_start;
  _data_lma_start = LOADADDR(.data);

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram

  _stack_top = ALIGN(0x4);
  . = _stack_top + 0x400;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x4);
  _heap_end = ORIGIN(sram)+LENGTH(sram);
}
