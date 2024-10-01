GCC_FLAGS := -CFLAGS -I/usr/lib/llvm-14/include \
	-CFLAGS -std=c++14 -CFLAGS -fno-exceptions -CFLAGS -D_GNU_SOURCE -CFLAGS -D__STDC_CONSTANT_MACROS -CFLAGS -D__STDC_LIMIT_MACROS \
	-CFLAGS -Ofast -CFLAGS -fexceptions \
	-LDFLAGS -lreadline -LDFLAGS -ldl -LDFLAGS -lSDL2 \
	-LDFLAGS /home/ubuntu/ysyx-workbench/riscv32e/libdisasm.so \
	-LDFLAGS /home/ubuntu/ysyx-workbench/riscv32e/riscv32-nemu-interpreter-so \
	-LDFLAGS -lLLVM-14 -LDFLAGS -flto

VERILATOR_FLAGS += -cc --exe --build --autoflush --timescale "1ns/1ns" --no-timing ${GCC_FLAGS} -DSIM_MODE=1
VERILATOR_FLAGS += -MMD --x-initial fast -x-assign fast -O3

# Make waveforms
VERILATOR_FLAGS += --trace-fst
# Warn abount lint issues; may not want this on less solid designs
#VERILATOR_FLAGS += -Wall
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug --gdbbt

# Input files for Verilator   
VERILATOR_INPUT = top.v sim_main.cpp sram.v  *.sv 

######################################################################
default: run

run:
	verilator $(VERILATOR_FLAGS) $(VERILATOR_INPUT)
	@echo "-- RUN --"
	obj_dir/Vtop

out:
	verilator --lint-only --top-module top  ./package/top.v   ./*.sv
	verilator -E --top-module top  ./package/top.v   ./*.sv  > ./package/verilator_out.v
	sed -i '/^`line/d' ./package/verilator_out.v
	./package/sv2v --top=top ./package/verilator_out.v > ./package/sv2v_out.v
	

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd coverage.dat core *.fst
