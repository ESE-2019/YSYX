// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb_axi_if.h"

std::string VL_TO_STRING(const Varb_axi_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Varb_axi_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
