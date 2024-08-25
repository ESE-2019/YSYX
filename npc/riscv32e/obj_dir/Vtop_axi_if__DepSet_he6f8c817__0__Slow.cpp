// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_axi_if.h"

VL_ATTR_COLD void Vtop_axi_if___ctor_var_reset(Vtop_axi_if* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_if___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->aclk = 0;
    vlSelf->aresetn = 0;
    vlSelf->awready = 0;
    vlSelf->awvalid = 0;
    vlSelf->awaddr = 0;
    vlSelf->wready = 0;
    vlSelf->wvalid = 0;
    vlSelf->wdata = 0;
    vlSelf->wstrb = 0;
    vlSelf->bready = 0;
    vlSelf->bvalid = 0;
    vlSelf->bresp = 0;
    vlSelf->arready = 0;
    vlSelf->arvalid = 0;
    vlSelf->araddr = 0;
    vlSelf->rready = 0;
    vlSelf->rvalid = 0;
    vlSelf->rresp = 0;
    vlSelf->rdata = 0;
    vlSelf->__Vdly__rdata = 0;
}
