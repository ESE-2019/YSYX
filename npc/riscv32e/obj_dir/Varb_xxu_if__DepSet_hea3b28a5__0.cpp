// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb_xxu_if.h"

std::string VL_TO_STRING(const Varb_xxu_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Varb_xxu_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
