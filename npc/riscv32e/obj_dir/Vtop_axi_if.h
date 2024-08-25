// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXI_IF_H_
#define VERILATED_VTOP_AXI_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axi_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(aclk,0,0);
    VL_IN8(aresetn,0,0);
    CData/*0:0*/ awready;
    CData/*0:0*/ awvalid;
    CData/*0:0*/ wready;
    CData/*0:0*/ wvalid;
    CData/*3:0*/ wstrb;
    CData/*0:0*/ bready;
    CData/*0:0*/ bvalid;
    CData/*1:0*/ bresp;
    CData/*0:0*/ arready;
    CData/*0:0*/ arvalid;
    CData/*0:0*/ rready;
    CData/*0:0*/ rvalid;
    CData/*1:0*/ rresp;
    IData/*31:0*/ awaddr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ araddr;
    IData/*31:0*/ rdata;
    IData/*31:0*/ __Vdly__rdata;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_axi_if(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_axi_if();
    VL_UNCOPYABLE(Vtop_axi_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_axi_if* obj);

#endif  // guard
