CROSS_COMPILE := riscv32-unknown-linux-gnu-
COMMON_CFLAGS := -O2 -fno-pic -mcmodel=medany -mstrict-align -march=rv32im_zicsr_zifencei -mabi=ilp32 \
    -fdata-sections -ffunction-sections -falign-functions=4 -falign-jumps=4 -falign-labels=4 -falign-loops=4
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS)
ARCH_H        := arch/riscv.h
LDSCRIPTS     += $(AM_HOME)/scripts/linker.ld
LDFLAGS       += -melf32lriscv --gc-sections -e _start --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
#SIM_FLAGS     := -fast -difftest

AM_SRCS := riscv/ooo/start.S \
           riscv/ooo/trm.c \
           riscv/ooo/ioe.c \
           riscv/ooo/timer.c \
           riscv/ooo/input.c \
           riscv/ooo/cte.c \
           riscv/ooo/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = The insert-arg rule in Makefile will insert mainargs here.
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=\""$(MAINARGS_PLACEHOLDER)"\"

insert-arg: image
	@python3 $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) "$(MAINARGS_PLACEHOLDER)" "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	make -C $(OoO_HOME) sim SIM_IMG=$(IMAGE).bin SIM_MODE="-DNPC_MODE=1" SIM_FLAGS=-fast

.PHONY: insert-arg
