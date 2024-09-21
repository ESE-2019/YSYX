// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Varb___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXEC", "WAIT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10"};
        tracep->declDTypeEnum(1, "ysyx_24080006_exu.__typeimpenum1", 3, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXEC", "WAIT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10"};
        tracep->declDTypeEnum(2, "ysyx_24080006_idu.__typeimpenum2", 3, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXEC", "WAIT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10"};
        tracep->declDTypeEnum(3, "ysyx_24080006_ifu.__typeimpenum3", 3, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXEC", "WAIT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10"};
        tracep->declDTypeEnum(4, "ysyx_24080006_lsu.__typeimpenum4", 3, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "EXEC", "WAIT", "RST"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(5, "ysyx_24080006_wbu.__typeimpenum5", 4, 2, __VenumItemNames, __VenumItemValues);
    }
}

void Varb___024root__trace_decl_types(VerilatedFst* tracep) {
    Varb___024root__traceDeclTypesSub0(tracep);
}
