TOPNAME = ysyxSoCFull
INC_PATH ?=
SIM_IMG ?=
SIM_FLAGS ?=
SIM_MODE ?= -DSOC_MODE=1

VERILATOR_CFLAGS += -MMD --build -cc --exe \
	-O3 --x-assign fast --x-initial fast --noassert --trace-fst --trace-threads 2\
	--timescale-override 1ns/1ns --no-timing
	
#VERILATOR_CFLAGS += --prof-cfuncs
#VERILATOR_CFLAGS += --autoflush
#VERILATOR_CFLAGS += --debug

VERILATOR_CFLAGS += -DSIM_MODE=1  $(SIM_MODE)

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

SOC_PATH = /home/ubuntu/ysyx-workbench/ysyxSoC
default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
include $(NVBOARD_HOME)/scripts/nvboard.mk
NXDC_FILES = constr/top.nxdc
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS += /home/ubuntu/ysyx-workbench/npc/vsrc/utils/inst.sverilog
VSRCS += $(shell find $(abspath ./vsrc) -name "*.svh")
VSRCS += $(shell find $(abspath ./vsrc) -name "*.v" -or -name "*.sv")
VSRCS += $(shell find $(SOC_PATH)/perip -name "*.v")

FMT_VSRCS += $(shell find $(abspath ./vsrc) -name "*.sv")
FMT_VSRCS += ./vsrc/utils/inst.sverilog
SYN_VSRCS += $(shell find $(abspath ./vsrc) -name "*.sv")

CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

VERILATOR_CFLAGS += -I$(SOC_PATH)/perip/uart16550/rtl -I$(SOC_PATH)/perip/spi/rtl -I$(SOC_PATH)/perip/gpio

VERILATOR_CFLAGS += -CFLAGS -flto -CFLAGS -fno-exceptions
VERILATOR_CFLAGS += -LDFLAGS -lreadline -LDFLAGS -ldl -LDFLAGS -lSDL2 \
	-LDFLAGS /home/ubuntu/ysyx-workbench/npc/csrc/libdisasm.so \
	-LDFLAGS /home/ubuntu/ysyx-workbench/npc/csrc/riscv32-nemu-interpreter-so \
	-LDFLAGS -lLLVM-18 -LDFLAGS -flto
ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

#include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@$^ -IMG=$(SIM_IMG) $(SIM_FLAGS)

wave:
	gtkwave ./build/wave.fst &

run: $(BIN)
	@$^
	
lint: $(SYN_VSRCS)
	verible-verilog-syntax ./vsrc/core/*.svh $(SYN_VSRCS)
	verible-verilog-lint ./vsrc/core/*.svh $(SYN_VSRCS)
	verilator --lint-only -Wall --timescale "1ns/1ns" --top-module top ./vsrc/core/*.svh $(SYN_VSRCS)
	
syn: $(SYN_VSRCS)
	verilator --lint-only --timescale "1ns/1ns" --top-module top ./vsrc/core/*.svh $(SYN_VSRCS)
	verilator -E --timescale "1ns/1ns" --top-module top ./vsrc/core/*.svh $(SYN_VSRCS) > $(BUILD_DIR)/top.v
	sed -i '/^`line/d' $(BUILD_DIR)/top.v
	verible-verilog-format --inplace $(BUILD_DIR)/top.v

format: $(FMT_VSRCS)
	verible-verilog-format --inplace $(FMT_VSRCS)
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all run clean lint

include ../Makefile
