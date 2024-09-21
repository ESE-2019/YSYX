// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_xxu_if.h"

std::string VL_TO_STRING(const Vtop_xxu_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_xxu_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
