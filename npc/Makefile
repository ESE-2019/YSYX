TOPNAME = ysyxSoCFull
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR_CFLAGS += -MMD --build -cc --exe \
	-O3 --x-assign fast --x-initial fast --noassert --trace-fst \
	--timescale "1ns/1ns" --no-timing --autoflush

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

SOC_PATH = /home/ubuntu/Desktop/PA0/ysyx-workbench/ysyxSoC
default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
#SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
#$(SRC_AUTO_BIND): $(NXDC_FILES)
#	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v" -or -name "*.sv" -or -name "*.svh")
VSRCS += $(shell find $(SOC_PATH)/perip -name "*.v")

CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
#CSRCS += $(SRC_AUTO_BIND)

VERILATOR_CFLAGS += -I$(SOC_PATH)/perip/uart16550/rtl -I$(SOC_PATH)/perip/spi/rtl
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

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

run: $(BIN)
	@$^
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

include ../Makefile
