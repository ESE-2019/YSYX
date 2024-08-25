// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_axi_if.h"

void Vtop_axi_if___ctor_var_reset(Vtop_axi_if* vlSelf);

Vtop_axi_if::Vtop_axi_if(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_axi_if___ctor_var_reset(this);
}

void Vtop_axi_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_axi_if::~Vtop_axi_if() {
}
