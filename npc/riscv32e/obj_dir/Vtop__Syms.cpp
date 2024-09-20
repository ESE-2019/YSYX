// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_axi_if.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top__DOT__axi_ifu{this, Verilated::catName(namep, "top.axi_ifu")}
    , TOP__top__DOT__axi_lsu{this, Verilated::catName(namep, "top.axi_lsu")}
    , TOP__top__DOT__axi_sram{this, Verilated::catName(namep, "top.axi_sram")}
{
        // Check resources
        Verilated::stackCheck(259);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top__DOT__axi_ifu = &TOP__top__DOT__axi_ifu;
    TOP.__PVT__top__DOT__axi_lsu = &TOP__top__DOT__axi_lsu;
    TOP.__PVT__top__DOT__axi_sram = &TOP__top__DOT__axi_sram;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top__DOT__axi_ifu.__Vconfigure(true);
    TOP__top__DOT__axi_lsu.__Vconfigure(false);
    TOP__top__DOT__axi_sram.__Vconfigure(false);
    // Setup scopes
    __Vscope_top.configure(this, name(), "top", "top", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__sram.configure(this, name(), "top.sram", "sram", -9, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
