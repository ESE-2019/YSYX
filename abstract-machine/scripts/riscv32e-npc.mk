include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/npc.mk
COMMON_CFLAGS += -falign-jumps=4 -falign-loops=4 -falign-functions=4 -falign-labels=4
COMMON_CFLAGS += -mabi=ilp32 -march=rv32im_zicsr_zifencei_zba_zbb_zbs   # overwrite  _zca_zcb _zicond
LDFLAGS       += -melf32lriscv                    # overwrite

#AM_SRCS += riscv/npc/libgcc/div.S \
#           riscv/npc/libgcc/muldi3.S \
#           riscv/npc/libgcc/multi3.c \
#           riscv/npc/libgcc/ashldi3.c \
#           riscv/npc/libgcc/unused.c
