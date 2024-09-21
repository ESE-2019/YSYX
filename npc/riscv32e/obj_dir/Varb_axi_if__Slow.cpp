// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb__Syms.h"
#include "Varb_axi_if.h"

void Varb_axi_if___ctor_var_reset(Varb_axi_if* vlSelf);

Varb_axi_if::Varb_axi_if(Varb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Varb_axi_if___ctor_var_reset(this);
}

void Varb_axi_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Varb_axi_if::~Varb_axi_if() {
}
