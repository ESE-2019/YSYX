// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Varb__pch.h"
#include "Varb.h"
#include "Varb___024root.h"
#include "Varb_axi_if.h"
#include "Varb_xxu_if.h"

// FUNCTIONS
Varb__Syms::~Varb__Syms()
{
}

Varb__Syms::Varb__Syms(VerilatedContext* contextp, const char* namep, Varb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top__DOT__CORE__DOT__axi_ifu{this, Verilated::catName(namep, "top.CORE.axi_ifu")}
    , TOP__top__DOT__CORE__DOT__axi_lsu{this, Verilated::catName(namep, "top.CORE.axi_lsu")}
    , TOP__top__DOT__CORE__DOT__exu2lsu{this, Verilated::catName(namep, "top.CORE.exu2lsu")}
    , TOP__top__DOT__CORE__DOT__idu2exu{this, Verilated::catName(namep, "top.CORE.idu2exu")}
    , TOP__top__DOT__CORE__DOT__ifu2idu{this, Verilated::catName(namep, "top.CORE.ifu2idu")}
    , TOP__top__DOT__CORE__DOT__lsu2wbu{this, Verilated::catName(namep, "top.CORE.lsu2wbu")}
    , TOP__top__DOT__CORE__DOT__wbu2ifu{this, Verilated::catName(namep, "top.CORE.wbu2ifu")}
    , TOP__top__DOT__axi_sram{this, Verilated::catName(namep, "top.axi_sram")}
{
        // Check resources
        Verilated::stackCheck(144);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top__DOT__CORE__DOT__axi_ifu = &TOP__top__DOT__CORE__DOT__axi_ifu;
    TOP.__PVT__top__DOT__CORE__DOT__axi_lsu = &TOP__top__DOT__CORE__DOT__axi_lsu;
    TOP.__PVT__top__DOT__CORE__DOT__exu2lsu = &TOP__top__DOT__CORE__DOT__exu2lsu;
    TOP.__PVT__top__DOT__CORE__DOT__idu2exu = &TOP__top__DOT__CORE__DOT__idu2exu;
    TOP.__PVT__top__DOT__CORE__DOT__ifu2idu = &TOP__top__DOT__CORE__DOT__ifu2idu;
    TOP.__PVT__top__DOT__CORE__DOT__lsu2wbu = &TOP__top__DOT__CORE__DOT__lsu2wbu;
    TOP.__PVT__top__DOT__CORE__DOT__wbu2ifu = &TOP__top__DOT__CORE__DOT__wbu2ifu;
    TOP.__PVT__top__DOT__axi_sram = &TOP__top__DOT__axi_sram;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top__DOT__CORE__DOT__axi_ifu.__Vconfigure(true);
    TOP__top__DOT__CORE__DOT__axi_lsu.__Vconfigure(false);
    TOP__top__DOT__CORE__DOT__exu2lsu.__Vconfigure(true);
    TOP__top__DOT__CORE__DOT__idu2exu.__Vconfigure(false);
    TOP__top__DOT__CORE__DOT__ifu2idu.__Vconfigure(false);
    TOP__top__DOT__CORE__DOT__lsu2wbu.__Vconfigure(false);
    TOP__top__DOT__CORE__DOT__wbu2ifu.__Vconfigure(false);
    TOP__top__DOT__axi_sram.__Vconfigure(false);
    // Setup scopes
    __Vscope_top__CORE__EXU.configure(this, name(), "top.CORE.EXU", "EXU", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__CORE__IDU.configure(this, name(), "top.CORE.IDU", "IDU", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__CORE__IFU.configure(this, name(), "top.CORE.IFU", "IFU", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__CORE__LSU.configure(this, name(), "top.CORE.LSU", "LSU", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__sram.configure(this, name(), "top.sram", "sram", -9, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
