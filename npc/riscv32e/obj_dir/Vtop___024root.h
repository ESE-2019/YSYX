// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axi_if;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_axi_if* __PVT__top__DOT__axi_ifu;
    Vtop_axi_if* __PVT__top__DOT__axi_lsu;
    Vtop_axi_if* __PVT__top__DOT__axi_sram;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*4:0*/ top__DOT__csr_reg;
    CData/*3:0*/ top__DOT__alu_c;
    CData/*0:0*/ top__DOT__iv;
    CData/*0:0*/ top__DOT__ir;
    CData/*0:0*/ top__DOT__dv;
    CData/*0:0*/ top__DOT__dr;
    CData/*0:0*/ top__DOT__lv;
    CData/*0:0*/ top__DOT__lr;
    CData/*1:0*/ top__DOT__ic;
    CData/*1:0*/ top__DOT__in;
    CData/*1:0*/ top__DOT__dc;
    CData/*1:0*/ top__DOT__dn;
    CData/*1:0*/ top__DOT__lc;
    CData/*1:0*/ top__DOT__ln;
    CData/*3:0*/ top__DOT__wstrb;
    CData/*4:0*/ top__DOT__rshamt;
    CData/*0:0*/ top__DOT__ysyx_24080006_alu__DOT__comp_res;
    CData/*1:0*/ top__DOT__arb__DOT__arbiter_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__axi_ifu__aresetn__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__inst;
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__rs1_val;
    IData/*31:0*/ top__DOT__rs2_val;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__mem_addr;
    IData/*31:0*/ top__DOT__alu_1;
    IData/*31:0*/ top__DOT__alu_2;
    IData/*31:0*/ top__DOT__alu_3;
    IData/*31:0*/ top__DOT__alu_out;
    IData/*31:0*/ top__DOT__ldata;
    IData/*31:0*/ top__DOT__ysyx_24080006_alu__DOT__shift_res;
    IData/*31:0*/ top__DOT__ysyx_24080006_alu__DOT__shift_src;
    IData/*31:0*/ top__DOT__ysyx_24080006_alu__DOT__bit_res;
    IData/*31:0*/ top__DOT__ysyx_24080006_alu__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__ysyx_24080006_alu__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ top__DOT__sram__DOT__dout;
    IData/*31:0*/ __VactIterCount;
    QData/*33:0*/ top__DOT__ysyx_24080006_alu__DOT__add_res_t;
    QData/*32:0*/ top__DOT__ysyx_24080006_alu__DOT__srcB;
    QData/*63:0*/ top__DOT__sram__DOT__mtime;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regmap;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

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
