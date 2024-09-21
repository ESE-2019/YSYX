// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb__Syms.h"
#include "Varb___024root.h"

void Varb___024root___ctor_var_reset(Varb___024root* vlSelf);

Varb___024root::Varb___024root(Varb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Varb___024root___ctor_var_reset(this);
}

void Varb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Varb___024root::~Varb___024root() {
}
