CROSS_COMPILE := riscv32-unknown-linux-gnu-
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align -O
CFLAGS        += $(COMMON_CFLAGS) -static 
ASFLAGS       += $(COMMON_CFLAGS)
LDFLAGS       += -melf64lriscv
# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
