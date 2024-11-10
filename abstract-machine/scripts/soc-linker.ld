ENTRY(_start)
PHDRS {
    entry PT_LOAD;
    bootloader PT_LOAD;
    klib PT_LOAD;
    text PT_LOAD;
    data PT_LOAD;
    bss PT_LOAD;
    }
MEMORY {
  FLASH (rx)  : ORIGIN = 0x30000000, LENGTH = 16M - 1
  SDRAM (rwx) : ORIGIN = 0xa0000000, LENGTH = 64M - 1
  SRAM  (rwx) : ORIGIN = 0x0f000000, LENGTH =  8K - 1
}

SECTIONS {
  . = ORIGIN(FLASH);
  .entry : {  
    *(.entry)
    . = ALIGN(4);
  } > FLASH : entry


  /* bootloader */
  .blalign :
  {
    . = ALIGN(4);
    PROVIDE(_bootloader_lma_start = .);
  } > FLASH AT > FLASH
  
  .bootloader : {
    . = ALIGN(4);
    PROVIDE(_bootloader_vma_start = .);
    *(.bootloader)
    . = ALIGN(4);
    PROVIDE(_bootloader_vma_end = .);
  } > SRAM AT > FLASH : bootloader

  /* bootloader */
  .klalign :
  {
    . = ALIGN(4);
    PROVIDE(_klib_lma_start = .);
  } > FLASH AT > FLASH
  
  .klib : {
    . = ALIGN(4);
    PROVIDE(_klib_vma_start = .);
    *(.klib)
    . = ALIGN(4);
    PROVIDE(_klib_vma_end = .);
  } > SRAM AT > FLASH : klib

  /* text */
  .tlalign :
  {
    . = ALIGN(4);
    PROVIDE(_text_lma_start = .);
  } > FLASH AT > FLASH

  .text : {
    . = ALIGN(4);
    PROVIDE(_text_vma_start = .);
    *(.text)
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    *(.eh_frame)
    . = ALIGN(4);
    PROVIDE(_text_vma_end = .);
  } > SDRAM AT > FLASH : text

  
  /* data */
  .dlalign :
  {
    . = ALIGN(4);
    PROVIDE(_data_lma_start = .);
  } > FLASH AT > FLASH

  .data : {
    . = ALIGN(4);
    PROVIDE(_data_vma_start = .);
    *(.data)
    . = ALIGN(4);
    *(.data*)
    . = ALIGN(4);
    *(.sdata)
    . = ALIGN(4);
    *(.sdata*)
    . = ALIGN(4);
    *(.rodata)
    . = ALIGN(4);
    *(.rodata*)
    . = ALIGN(4);
    *(.srodata)
    . = ALIGN(4);
    *(.srodata*)

    *(.tohost) /* for riscv-test */
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
  } > SDRAM AT > FLASH : data
  

  
  /* bss */
  .bss : {
    *(.bss)
    . = ALIGN(4);
    *(.bss*)
    . = ALIGN(4);
    *(.sbss)
    . = ALIGN(4);
    *(.sbss*)
    . = ALIGN(4);
    *(.scommon)
    . = ALIGN(4);
    *(.scommon*)
    . = ALIGN(4);
    *(COMMON*)
    . = ALIGN(4);
    
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
    
  } > SDRAM : bss

    _stack_top = ALIGN(4);
    . = . + 0x10000;
    _stack_pointer = ALIGN(4);
    
    _heap_start = ALIGN(4);
    . = ORIGIN(SDRAM) + LENGTH(SDRAM) - 3;
    _heap_end = ALIGN(4);
  

}