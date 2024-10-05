AM_SRCS := riscv/test/start.S \
           riscv/test/trm.c \
           riscv/test/ioe.c \
           riscv/test/timer.c \
           riscv/test/input.c \
           riscv/test/cte.c \
           riscv/test/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/test-linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/test/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin
	
run: image
	/home/ubuntu/ysyx-workbench/npc/build/ysyxSoCFull -IMG=$(IMAGE).bin
