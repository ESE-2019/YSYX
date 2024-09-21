// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axi_if;
class Vtop_xxu_if;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_axi_if* __PVT__top__DOT__axi_sram;
    Vtop_xxu_if* __PVT__top__DOT__CORE__DOT__ifu2idu;
    Vtop_xxu_if* __PVT__top__DOT__CORE__DOT__idu2exu;
    Vtop_xxu_if* __PVT__top__DOT__CORE__DOT__exu2lsu;
    Vtop_xxu_if* __PVT__top__DOT__CORE__DOT__lsu2wbu;
    Vtop_xxu_if* __PVT__top__DOT__CORE__DOT__wbu2ifu;
    Vtop_axi_if* __PVT__top__DOT__CORE__DOT__axi_ifu;
    Vtop_axi_if* __PVT__top__DOT__CORE__DOT__axi_lsu;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ top__DOT__CORE__DOT__we;
    CData/*4:0*/ top__DOT__CORE__DOT__rd;
    CData/*1:0*/ top__DOT__CORE__DOT__ARB__DOT__arbiter_state;
    CData/*1:0*/ top__DOT__CORE__DOT__IFU__DOT__curr;
    CData/*1:0*/ top__DOT__CORE__DOT__IFU__DOT__next;
    CData/*1:0*/ top__DOT__CORE__DOT__IDU__DOT__curr;
    CData/*1:0*/ top__DOT__CORE__DOT__IDU__DOT__next;
    CData/*3:0*/ top__DOT__CORE__DOT__IDU__DOT__alu_ctrl;
    CData/*1:0*/ top__DOT__CORE__DOT__IDU__DOT__alu_set;
    CData/*1:0*/ top__DOT__CORE__DOT__EXU__DOT__curr;
    CData/*1:0*/ top__DOT__CORE__DOT__EXU__DOT__next;
    CData/*0:0*/ top__DOT__CORE__DOT__EXU__DOT__branch;
    CData/*0:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res;
    CData/*1:0*/ top__DOT__CORE__DOT__LSU__DOT__curr;
    CData/*1:0*/ top__DOT__CORE__DOT__LSU__DOT__next;
    CData/*1:0*/ top__DOT__CORE__DOT__WBU__DOT__curr;
    CData/*1:0*/ top__DOT__CORE__DOT__WBU__DOT__next;
    CData/*3:0*/ __Vtableidx1;
    CData/*3:0*/ __Vtableidx2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__sram__DOT__dout;
    IData/*31:0*/ top__DOT__CORE__DOT__wdata;
    IData/*31:0*/ top__DOT__CORE__DOT__rs1_val;
    IData/*31:0*/ top__DOT__CORE__DOT__rs2_val;
    IData/*31:0*/ top__DOT__CORE__DOT__IFU__DOT__pc;
    IData/*31:0*/ top__DOT__CORE__DOT__IDU__DOT__imm;
    IData/*31:0*/ top__DOT__CORE__DOT__IDU__DOT__alu_src2;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__alu_out;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__alu_res;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ top__DOT__CORE__DOT__LSU__DOT__alu_res;
    IData/*31:0*/ top__DOT__CORE__DOT__LSU__DOT__ldata;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ top__DOT__sram__DOT__mtime;
    QData/*33:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t;
    QData/*32:0*/ top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__CORE__DOT__REG__DOT__regfile;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
