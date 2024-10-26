CROSS_COMPILE := riscv32-unknown-linux-gnu-
COMMON_CFLAGS := -fno-pic -mcmodel=medany -mstrict-align -march=rv32e_zicsr -mabi=ilp32e
CFLAGS        += $(COMMON_CFLAGS) -static -fdata-sections -ffunction-sections
ASFLAGS       += $(COMMON_CFLAGS) -O2 -Os
ARCH_H        := arch/riscv.h
LDSCRIPTS     += $(AM_HOME)/scripts/soc-linker.ld
LDFLAGS       += -melf32lriscv --no-gc-sections -e _start
#LDFLAGS   += --print-map
SIM_FLAGS     := -fast

AM_SRCS += riscv/soc/libgcc/div.S \
           riscv/soc/libgcc/muldi3.S \
           riscv/soc/libgcc/multi3.c \
           riscv/soc/libgcc/ashldi3.c \
           riscv/soc/libgcc/unused.c \
           riscv/soc/start.S \
           riscv/soc/trm.c \
           riscv/soc/ioe.c \
           riscv/soc/timer.c \
           riscv/soc/input.c \
           riscv/soc/cte.c \
           riscv/soc/trap.S \
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
	make -C $(NPC_HOME) sim SIM_IMG=$(IMAGE).bin SIM_FLAGS=$(SIM_FLAGS)

.PHONY: insert-arg