// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Varb.h for the primary calling header

#ifndef VERILATED_VARB_AXI_IF_H_
#define VERILATED_VARB_AXI_IF_H_  // guard

#include "verilated.h"


class Varb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Varb_axi_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(aclk,0,0);
    VL_IN8(aresetn,0,0);
    CData/*0:0*/ awready;
    CData/*0:0*/ awvalid;
    CData/*3:0*/ __PVT__awid;
    CData/*7:0*/ __PVT__awlen;
    CData/*2:0*/ __PVT__awsize;
    CData/*1:0*/ __PVT__awburst;
    CData/*0:0*/ wready;
    CData/*0:0*/ wvalid;
    CData/*3:0*/ wstrb;
    CData/*0:0*/ __PVT__wlast;
    CData/*0:0*/ bready;
    CData/*0:0*/ bvalid;
    CData/*1:0*/ bresp;
    CData/*3:0*/ __PVT__bid;
    CData/*0:0*/ arready;
    CData/*0:0*/ arvalid;
    CData/*3:0*/ __PVT__arid;
    CData/*7:0*/ __PVT__arlen;
    CData/*2:0*/ __PVT__arsize;
    CData/*1:0*/ __PVT__arburst;
    CData/*0:0*/ rready;
    CData/*0:0*/ rvalid;
    CData/*1:0*/ rresp;
    CData/*0:0*/ __PVT__rlast;
    CData/*3:0*/ __PVT__rid;
    IData/*31:0*/ awaddr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ araddr;
    IData/*31:0*/ rdata;

    // INTERNAL VARIABLES
    Varb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Varb_axi_if(Varb__Syms* symsp, const char* v__name);
    ~Varb_axi_if();
    VL_UNCOPYABLE(Varb_axi_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Varb_axi_if* obj);

#endif  // guard
