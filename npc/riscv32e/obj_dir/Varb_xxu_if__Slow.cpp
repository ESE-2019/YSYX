// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb__Syms.h"
#include "Varb_xxu_if.h"

void Varb_xxu_if___ctor_var_reset(Varb_xxu_if* vlSelf);

Varb_xxu_if::Varb_xxu_if(Varb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Varb_xxu_if___ctor_var_reset(this);
}

void Varb_xxu_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Varb_xxu_if::~Varb_xxu_if() {
}
