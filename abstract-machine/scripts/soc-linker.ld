ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } > mrom AT> mrom : text
  etext = .;
  _etext = .;

  .rodata : {
    *(.rodata*)
  } > mrom AT> mrom

  .data : {
    _rom_data = .;
    *(.data)
  } > sram AT> mrom : data
  edata = .;
  _data = _rom_data;

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sram

  . = ORIGIN(sram) + LENGTH(sram);
  _stack_top = .;
  . = _stack_top - 0x800;
  _stack_pointer = _stack_top;

  _heap_start = edata;
  _heap_end = _stack_pointer - 0x800;
  
  end = .;
  _end = .;
}
