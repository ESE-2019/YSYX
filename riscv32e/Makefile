#CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE -L /home/ubuntu/ysyx-workbench/riscv32e -ldisasm -Wl,-rpath,/home/ubuntu/ysyx-workbench/riscv32e
#LIBS += $(shell llvm-config --ldflags --libs all)
#VERILATOR_FLAGS += $(addprefix -CFLAGS ,${CXXFLAGS})
#VERILATOR_FLAGS += $(addprefix -LDFLAGS ,${LIBS})
#-CFLAGS "-O2  -Og -ggdb3 -I/usr/lib/llvm-14/include -std=c++14 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fPIE"

LLVM_LIB = $(shell llvm-config --libs)
LLVM_FLAGS = $(filter-out -D__STDC_FORMAT_MACROS, $(shell llvm-config --cxxflags))

LLVM_FLAGS += -Ofast  -fexceptions  
#-lasan(内存检查)
 
GCC_LIB = -lreadline \
		  -ldl \
		  -lSDL2 

GCC_LIB += /home/ubuntu/ysyx-workbench/riscv32e/libdisasm.so
GCC_LIB += /home/ubuntu/ysyx-workbench/riscv32e/riscv32-nemu-interpreter-so
GCC_LIB += ${LLVM_LIB} -flto 


GCC_LDFLAGS := $(addprefix -LDFLAGS ,${GCC_LIB})
GCC_CFLAGS += $(addprefix -CFLAGS ,${LLVM_FLAGS})
GCC_FLAGS := ${GCC_CFLAGS} ${GCC_LDFLAGS}


# Generate C++ in executable form            --timing #  no-
VERILATOR_FLAGS += -cc --exe --build --autoflush --timescale "1ns/1ns" --no-timing ${GCC_FLAGS}
#-LDFLAGS "-lreadline -L /home/ubuntu/ysyx-workbench/riscv32e -ldisasm -Wl,-rpath,/home/ubuntu/ysyx-workbench/riscv32e" 
# Generate makefile dependencies (not shown as complicates the Makefile)
VERILATOR_FLAGS += -MMD --x-initial fast 
# Optimize
VERILATOR_FLAGS += -x-assign fast -O3
# Warn abount lint issues; may not want this on less solid designs
#VERILATOR_FLAGS += -Wall
# Make waveforms
VERILATOR_FLAGS += --trace-fst
# Check SystemVerilog assertions
VERILATOR_FLAGS += --assert
# Generate coverage analysis
#VERILATOR_FLAGS += --coverage
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt

# Input files for Verilator   
VERILATOR_INPUT = top.v sim_main.cpp sram.v  *.sv 

######################################################################
default: run

run:
	verilator $(VERILATOR_FLAGS) $(VERILATOR_INPUT)
	@echo "-- RUN ---------------------"
	obj_dir/Vtop

out:
	verilator --lint-only --top-module top  /home/ubuntu/ysyx-workbench/riscv32e/package/ysyx_24080006.sv   ./*.sv
	verilator -E --top-module top  /home/ubuntu/ysyx-workbench/riscv32e/package/ysyx_24080006.sv   ./*.sv  > ./package/test.v
	sed -i '/^`line/d' ./package/test.v

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd coverage.dat core *.fst
