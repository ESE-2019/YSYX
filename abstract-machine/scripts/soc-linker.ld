ENTRY(_start)

MEMORY {
  FLASH (rx)  : ORIGIN = 0x30000000, LENGTH = 16M - 1
  SDRAM (rwx) : ORIGIN = 0xa0000000, LENGTH = 32M - 1
  SRAM  (rwx) : ORIGIN = 0x0f000000, LENGTH =  8K - 1
}

SECTIONS {
  . = ORIGIN(FLASH);
  .entry : {  
    *(entry)
    . = ALIGN(4);
  } > FLASH


  /* bootloader */
  .balign :
  {
    . = ALIGN(4);
    PROVIDE(_bootloader_vma_start = .);
  } > SRAM AT > FLASH

  .blalign :
  {
    . = ALIGN(4);
    PROVIDE(_bootloader_lma_start = .);
  } > FLASH AT > FLASH
  
  .bootloader : {
    *(.bootloader)
    . = ALIGN(4);
    PROVIDE(_bootloader_vma_end = .);
  } > SRAM AT > FLASH


  /* text */
  .talign :
  {
    . = ALIGN(4);
    PROVIDE(_text_vma_start = .);
  } > SDRAM AT > FLASH

  .tlalign :
  {
    . = ALIGN(4);
    PROVIDE(_text_lma_start = .);
  } > FLASH AT > FLASH

  .text : {
    *(.text)
    *(.text*)
    . = ALIGN(4);    
    PROVIDE(_text_vma_end = .);
  } > SDRAM AT > FLASH

  
  /* data */
  .dalign :
  {
    . = ALIGN(4);
    PROVIDE(_data_vma_start = .);
  } > SDRAM AT > FLASH

  .dlalign :
  {
    . = ALIGN(4);
    PROVIDE(_data_lma_start = .);
  } > FLASH AT > FLASH

  .data : {
    *(.data)
    *(.data*)
    *(.sdata)
    *(.sdata*)
    *(.rodata)
    *(.rodata*)
    *(.srodata)
    *(.srodata*)


    . = ALIGN(4);
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(4);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(4);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(4);
    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;
    . = ALIGN(4);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;

    . = ALIGN(4);
    PROVIDE(_data_vma_end = .);
  } > SDRAM AT > FLASH
  

  
  /* bss */
  .bss : {
    *(.bss)
    *(.bss*)
    *(.sbss)
    *(.sbss*)
    *(.scommon)
    *(.scommon*)
    *(COMMON*)



    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    
  } > SDRAM

    _stack_top = ALIGN(4);
    . = . + 0x8000;
    _stack_pointer = ALIGN(4);
    
    _heap_start = ALIGN(4);
    . = ORIGIN(SDRAM) + LENGTH(SDRAM) - 3;
    _heap_end = ALIGN(4);
  

}