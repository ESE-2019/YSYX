ENTRY(_start)

PHDRS {  
  entry PT_LOAD;
  text PT_LOAD;
  bootloader PT_LOAD;  
  data PT_LOAD;
  bss  PT_LOAD;
}

MEMORY {
  flash (rx)  : ORIGIN = 0x30000000, LENGTH = 4M
  psram (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
  sram  (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = ORIGIN(flash);
  .entry : {  
    KEEP(*(entry))
    . = ALIGN(0x4);
  } > flash : entry

  .bootloader : {
    _bootloader_vma_start = .;
    KEEP(*(.bootloader))
    . = ALIGN(0x4);
    _bootloader_vma_end = .;
  } > sram AT > flash : bootloader
  _bootloader_lma_start = LOADADDR(.bootloader);

  .text : {
    _text_vma_start = .;
    KEEP(*(.text*))
    KEEP(*(.rodata*))
    KEEP(*(.srodata*))
    . = ALIGN(0x4);
    _text_vma_end = .;
  } > psram AT > flash : text
  _text_lma_start = LOADADDR(.text);
    etext = .;
  _etext = .;

  .data : { 
    _data_vma_start = .;
    KEEP(*(.data*))
    . = ALIGN(0x4);
    KEEP(*(.sdata*))
    . = ALIGN(0x4);
    _data_vma_end = .;
  } > psram AT > flash : data
  _data_lma_start = LOADADDR(.data);
   edata = .;
  _data = .;
  

  .bss : {
	_bss_start = .;
    *(.bss*)
    . = ALIGN(0x4);
    *(.sbss*)
    . = ALIGN(0x4);
    *(.scommon)
  } > psram : bss

 
  end = .;
  _end = .;

  _heap_start = ALIGN(0x4);
  . = ORIGIN(psram) + LENGTH(psram) - 0x10;
  _heap_end = ALIGN(0x4);


  . = _bootloader_vma_end + 0x4;
  _stack_top = ALIGN(0x4);
  . = ORIGIN(sram) + LENGTH(sram) - 0x10;
  . = ALIGN(0x4);
  _stack_pointer = .;
  
  

}