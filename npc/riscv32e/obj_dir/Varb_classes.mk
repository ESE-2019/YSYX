# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Varb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Varb \
	Varb___024root__DepSet_h57bbd785__0 \
	Varb___024root__DepSet_h2560f16f__0 \
	Varb_axi_if__DepSet_he15d33dc__0 \
	Varb_xxu_if__DepSet_hea3b28a5__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Varb__ConstPool_0 \
	Varb___024root__Slow \
	Varb___024root__DepSet_h57bbd785__0__Slow \
	Varb___024root__DepSet_h2560f16f__0__Slow \
	Varb_axi_if__Slow \
	Varb_axi_if__DepSet_he15d33dc__0__Slow \
	Varb_xxu_if__Slow \
	Varb_xxu_if__DepSet_hea3b28a5__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Varb__Dpi \
	Varb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Varb__Syms \
	Varb__Trace__0__Slow \
	Varb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_fst_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
