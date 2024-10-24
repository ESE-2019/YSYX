ENTRY(_start)

PHDRS {  
  entry PT_LOAD;
  bootloader PT_LOAD; 
  text PT_LOAD;   
  data PT_LOAD;
  bss  PT_LOAD;
}

MEMORY {
  flash (rx)  : ORIGIN = 0x30000000, LENGTH = 16M
  sdram (rwx) : ORIGIN = 0xa0000000, LENGTH = 32M
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
    . = ALIGN(0x4);
    KEEP(*(.rodata*))
    . = ALIGN(0x4);
    KEEP(*(.srodata*))
    . = ALIGN(0x4);
    _text_vma_end = .;
  } > sdram AT > flash : text
  _text_lma_start = LOADADDR(.text);
    etext = .;
  _etext = .;

  .data : { 
    _data_vma_start = .;

    /* section information for initial. 
     __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);
    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;
    . = ALIGN(8);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    . = ALIGN(8);
     section information for initial. */
    
    KEEP(*(.data*))
    . = ALIGN(0x4);
    KEEP(*(.sdata*))
    . = ALIGN(0x4);
    _data_vma_end = .;
  } > sdram AT > flash : data
  _data_lma_start = LOADADDR(.data);
   edata = .;
  _data = .;
  

  .bss : {
	  _bss_start = .;

    /* section information for initial. 
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    /* section information for initial. */
    
    *(.bss*)
    . = ALIGN(0x4);
    *(.sbss*)
    . = ALIGN(0x4);
    *(.scommon*)
  } > sdram : bss

 
  end = .;
  _end = .;

  _heap_start = ALIGN(0x4);
  . = ORIGIN(sdram) + LENGTH(sdram) - 0x100;
  _heap_end = ALIGN(0x4);


  . = _bootloader_vma_end + 0x4;
  _stack_top = ALIGN(0x4);
  . = ORIGIN(sram) + LENGTH(sram) - 0x100;
  . = ALIGN(0x4);
  _stack_pointer = .;
  
  

}