// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" void ebreak();

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP\n"); );
    // Body
    ebreak();
}

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, int wmask);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    int wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__DOT__axi_ifu.aresetn = (1U & 
                                               (~ (IData)(vlSelfRef.rst)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, (((~ (IData)(vlSymsp->TOP__top__DOT__axi_ifu.aresetn)) 
                                        & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__axi_ifu__aresetn__0)) 
                                       | ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__axi_ifu__aresetn__0 
        = vlSymsp->TOP__top__DOT__axi_ifu.aresetn;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__sram__DOT__pmem_read__2__Vfuncout;
    __Vfunc_top__DOT__sram__DOT__pmem_read__2__Vfuncout = 0;
    CData/*1:0*/ __Vdly__top__DOT__arb__DOT__arbiter_state;
    __Vdly__top__DOT__arb__DOT__arbiter_state = 0;
    // Body
    vlSymsp->TOP__top__DOT__axi_sram.__Vdly__rdata 
        = vlSymsp->TOP__top__DOT__axi_sram.rdata;
    __Vdly__top__DOT__arb__DOT__arbiter_state = vlSelfRef.top__DOT__arb__DOT__arbiter_state;
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        vlSelfRef.top__DOT__sram__DOT__mtime = (1ULL 
                                                + vlSelfRef.top__DOT__sram__DOT__mtime);
        if ((0U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
            if (((IData)(vlSymsp->TOP__top__DOT__axi_ifu.awvalid) 
                 | (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 1U;
            } else if (((IData)(vlSymsp->TOP__top__DOT__axi_lsu.awvalid) 
                        | (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 2U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
            if ((((IData)(vlSymsp->TOP__top__DOT__axi_ifu.bvalid) 
                  & (IData)(vlSymsp->TOP__top__DOT__axi_ifu.bready)) 
                 | ((IData)(vlSymsp->TOP__top__DOT__axi_ifu.rready) 
                    & (IData)(vlSymsp->TOP__top__DOT__axi_ifu.rvalid)))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
            if ((((IData)(vlSymsp->TOP__top__DOT__axi_lsu.bvalid) 
                  & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.bready)) 
                 | ((IData)(vlSymsp->TOP__top__DOT__axi_lsu.rready) 
                    & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.rvalid)))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 0U;
            }
        } else {
            __Vdly__top__DOT__arb__DOT__arbiter_state = 0U;
        }
    } else {
        vlSelfRef.top__DOT__sram__DOT__mtime = 0ULL;
        __Vdly__top__DOT__arb__DOT__arbiter_state = 0U;
    }
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        if (((((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid)
                : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                   & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid))) 
              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready)) 
             & (~ (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid)))) {
            vlSymsp->TOP__top__DOT__axi_sram.arready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.__Vdly__rdata 
                = ((0xa0000000U <= vlSymsp->TOP__top__DOT__axi_sram.araddr)
                    ? vlSelfRef.top__DOT__sram__DOT__dout
                    : ([&]() {
                        Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP(vlSymsp->TOP__top__DOT__axi_sram.araddr, __Vfunc_top__DOT__sram__DOT__pmem_read__2__Vfuncout);
                    }(), __Vfunc_top__DOT__sram__DOT__pmem_read__2__Vfuncout));
            vlSymsp->TOP__top__DOT__axi_sram.rvalid = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.rresp = 0U;
        } else if (((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                     ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.rready)
                     : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                        & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.rready)))) {
            vlSymsp->TOP__top__DOT__axi_sram.arready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.rvalid = 0U;
        }
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.arready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.rvalid = 0U;
    }
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        if (((((((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                  ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.awvalid)
                  : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                     & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.awvalid))) 
                & ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                    ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wvalid)
                    : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                       & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wvalid)))) 
               & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready)) 
              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready)) 
             & (~ (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid)))) {
            if (VL_UNLIKELY((0xa00003f8U == vlSymsp->TOP__top__DOT__axi_sram.awaddr))) {
                VL_WRITEF_NX("%c",0,8,(0xffU & vlSymsp->TOP__top__DOT__axi_sram.wdata));
                Verilated::runFlushCallbacks();
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP(vlSymsp->TOP__top__DOT__axi_sram.awaddr, vlSymsp->TOP__top__DOT__axi_sram.wdata, 
                                                                                ((1U 
                                                                                == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                                 ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wstrb)
                                                                                 : 
                                                                                ((2U 
                                                                                == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                                 ? (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wstrb)
                                                                                 : 0U)));
            }
            vlSymsp->TOP__top__DOT__axi_sram.awready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.wready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.bvalid = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.bresp = 0U;
        } else if (((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                     ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.bready)
                     : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                        & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.bready)))) {
            vlSymsp->TOP__top__DOT__axi_sram.awready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.wready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.bvalid = 0U;
        }
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.wready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.bvalid = 0U;
    }
    vlSelfRef.top__DOT__arb__DOT__arbiter_state = __Vdly__top__DOT__arb__DOT__arbiter_state;
    vlSymsp->TOP__top__DOT__axi_ifu.bvalid = ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__top__DOT__dv;
    __Vdly__top__DOT__dv = 0;
    CData/*0:0*/ __Vdly__top__DOT__dr;
    __Vdly__top__DOT__dr = 0;
    CData/*0:0*/ __Vdly__top__DOT__lv;
    __Vdly__top__DOT__lv = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v0;
    __VdlyVal__top__DOT__regmap__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v0;
    __VdlyDim0__top__DOT__regmap__v0 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v1;
    __VdlyVal__top__DOT__regmap__v1 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v1;
    __VdlyDim0__top__DOT__regmap__v1 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v2;
    __VdlyVal__top__DOT__regmap__v2 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v2;
    __VdlyDim0__top__DOT__regmap__v2 = 0;
    IData/*31:0*/ __Vdly__top__DOT__pc;
    __Vdly__top__DOT__pc = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v3;
    __VdlyVal__top__DOT__regmap__v3 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v3;
    __VdlyDim0__top__DOT__regmap__v3 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v4;
    __VdlyVal__top__DOT__regmap__v4 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v4;
    __VdlyDim0__top__DOT__regmap__v4 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v5;
    __VdlyVal__top__DOT__regmap__v5 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v5;
    __VdlyDim0__top__DOT__regmap__v5 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v6;
    __VdlyVal__top__DOT__regmap__v6 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v6;
    __VdlyDim0__top__DOT__regmap__v6 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v7;
    __VdlyVal__top__DOT__regmap__v7 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v7;
    __VdlyDim0__top__DOT__regmap__v7 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v8;
    __VdlyVal__top__DOT__regmap__v8 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v8;
    __VdlyDim0__top__DOT__regmap__v8 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v9;
    __VdlyVal__top__DOT__regmap__v9 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v9;
    __VdlyDim0__top__DOT__regmap__v9 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v10;
    __VdlyVal__top__DOT__regmap__v10 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v10;
    __VdlyDim0__top__DOT__regmap__v10 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v11;
    __VdlyVal__top__DOT__regmap__v11 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v11;
    __VdlyDim0__top__DOT__regmap__v11 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v12;
    __VdlyVal__top__DOT__regmap__v12 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v13;
    __VdlyVal__top__DOT__regmap__v13 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v0;
    __VdlySet__top__DOT__regmap__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v1;
    __VdlySet__top__DOT__regmap__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v2;
    __VdlySet__top__DOT__regmap__v2 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v3;
    __VdlySet__top__DOT__regmap__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v4;
    __VdlySet__top__DOT__regmap__v4 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v5;
    __VdlySet__top__DOT__regmap__v5 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v6;
    __VdlySet__top__DOT__regmap__v6 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v7;
    __VdlySet__top__DOT__regmap__v7 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v8;
    __VdlySet__top__DOT__regmap__v8 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v9;
    __VdlySet__top__DOT__regmap__v9 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v10;
    __VdlySet__top__DOT__regmap__v10 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v11;
    __VdlySet__top__DOT__regmap__v11 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v12;
    __VdlySet__top__DOT__regmap__v12 = 0;
    // Body
    __Vdly__top__DOT__lv = vlSelfRef.top__DOT__lv;
    __VdlySet__top__DOT__regmap__v0 = 0U;
    __VdlySet__top__DOT__regmap__v1 = 0U;
    __VdlySet__top__DOT__regmap__v2 = 0U;
    __Vdly__top__DOT__dr = vlSelfRef.top__DOT__dr;
    __Vdly__top__DOT__dv = vlSelfRef.top__DOT__dv;
    __Vdly__top__DOT__pc = vlSelfRef.top__DOT__pc;
    __VdlySet__top__DOT__regmap__v3 = 0U;
    __VdlySet__top__DOT__regmap__v4 = 0U;
    __VdlySet__top__DOT__regmap__v5 = 0U;
    __VdlySet__top__DOT__regmap__v6 = 0U;
    __VdlySet__top__DOT__regmap__v7 = 0U;
    __VdlySet__top__DOT__regmap__v8 = 0U;
    __VdlySet__top__DOT__regmap__v9 = 0U;
    __VdlySet__top__DOT__regmap__v10 = 0U;
    __VdlySet__top__DOT__regmap__v11 = 0U;
    __VdlySet__top__DOT__regmap__v12 = 0U;
    if (vlSelfRef.rst) {
        __Vdly__top__DOT__dv = 0U;
        __Vdly__top__DOT__dr = 1U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__dc)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__dc)))))))) {
            if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__dc)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__dc)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: top.v:221: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__dc));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("top.v", 221, "");
                }
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__dc))) {
            if (vlSelfRef.top__DOT__iv) {
                __Vdly__top__DOT__dv = 1U;
                __Vdly__top__DOT__dr = 0U;
            } else {
                __Vdly__top__DOT__dv = 0U;
                __Vdly__top__DOT__dr = 1U;
            }
        } else if (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                    || (2U == (IData)(vlSelfRef.top__DOT__dc)))) {
            if (vlSelfRef.top__DOT__lr) {
                __Vdly__top__DOT__dv = 0U;
                __Vdly__top__DOT__dr = 1U;
            } else {
                __Vdly__top__DOT__dv = 1U;
                __Vdly__top__DOT__dr = 0U;
            }
        } else {
            __Vdly__top__DOT__dv = 0U;
            __Vdly__top__DOT__dr = 1U;
        }
    }
    if (vlSelfRef.rst) {
        __Vdly__top__DOT__pc = 0x80000000U;
    } else if ((1U == (IData)(vlSelfRef.top__DOT__dc))) {
        if (VL_ONEHOT0_I((((0x30200073U == vlSelfRef.top__DOT__inst) 
                           << 0xcU) | (((0x73U == vlSelfRef.top__DOT__inst) 
                                        << 0xbU) | 
                                       (((IData)((0x2073U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelfRef.top__DOT__inst))) 
                                         << 0xaU) | 
                                        (((IData)((0x1073U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelfRef.top__DOT__inst))) 
                                          << 9U) | 
                                         (((0x100073U 
                                            == vlSelfRef.top__DOT__inst) 
                                           << 8U) | 
                                          ((((0x13U 
                                              == (0x7fU 
                                                  & vlSelfRef.top__DOT__inst)) 
                                             | (0x33U 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.top__DOT__inst))) 
                                            << 7U) 
                                           | (((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlSelfRef.top__DOT__inst)) 
                                               << 6U) 
                                              | (((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.top__DOT__inst)) 
                                                  << 5U) 
                                                 | (((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.top__DOT__inst)) 
                                                     << 4U) 
                                                    | (((0x67U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.top__DOT__inst)) 
                                                        << 3U) 
                                                       | (((0x6fU 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelfRef.top__DOT__inst)) 
                                                           << 2U) 
                                                          | (((0x17U 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelfRef.top__DOT__inst)) 
                                                              << 1U) 
                                                             | (0x37U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlSelfRef.top__DOT__inst)))))))))))))))) {
            if ((0x37U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v3 
                        = vlSelfRef.top__DOT__imm;
                    __VdlyDim0__top__DOT__regmap__v3 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v3 = 1U;
                }
            } else if ((0x17U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v4 
                        = (vlSelfRef.top__DOT__pc + vlSelfRef.top__DOT__imm);
                    __VdlyDim0__top__DOT__regmap__v4 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v4 = 1U;
                }
            } else if ((0x6fU == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = (vlSelfRef.top__DOT__pc 
                                        + vlSelfRef.top__DOT__imm);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v5 
                        = vlSelfRef.top__DOT__alu_3;
                    __VdlyDim0__top__DOT__regmap__v5 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v5 = 1U;
                }
            } else if ((0x67U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = (0xfffffffeU 
                                        & (vlSelfRef.top__DOT__rs1_val 
                                           + vlSelfRef.top__DOT__imm));
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v6 
                        = vlSelfRef.top__DOT__alu_3;
                    __VdlyDim0__top__DOT__regmap__v6 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v6 = 1U;
                }
            } else if ((0x63U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = ((1U & vlSelfRef.top__DOT__alu_out)
                                         ? (vlSelfRef.top__DOT__pc 
                                            + vlSelfRef.top__DOT__imm)
                                         : ((IData)(4U) 
                                            + vlSelfRef.top__DOT__pc));
            } else if ((3U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                vlSelfRef.top__DOT__rshamt = ((2U & vlSelfRef.top__DOT__mem_addr)
                                               ? ((1U 
                                                   & vlSelfRef.top__DOT__mem_addr)
                                                   ? 0x18U
                                                   : 0x10U)
                                               : ((1U 
                                                   & vlSelfRef.top__DOT__mem_addr)
                                                   ? 8U
                                                   : 0U));
            } else if ((0x23U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
            } else if (((0x13U == (0x7fU & vlSelfRef.top__DOT__inst)) 
                        | (0x33U == (0x7fU & vlSelfRef.top__DOT__inst)))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v7 
                        = vlSelfRef.top__DOT__alu_out;
                    __VdlyDim0__top__DOT__regmap__v7 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v7 = 1U;
                }
            } else if ((0x100073U == vlSelfRef.top__DOT__inst)) {
                Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP();
            } else if ((IData)((0x1073U == (0x707fU 
                                            & vlSelfRef.top__DOT__inst)))) {
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v8 
                        = vlSelfRef.top__DOT__regmap
                        [vlSelfRef.top__DOT__csr_reg];
                    __VdlyDim0__top__DOT__regmap__v8 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v8 = 1U;
                }
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                __VdlyVal__top__DOT__regmap__v9 = vlSelfRef.top__DOT__rs1_val;
                __VdlyDim0__top__DOT__regmap__v9 = vlSelfRef.top__DOT__csr_reg;
                __VdlySet__top__DOT__regmap__v9 = 1U;
            } else if ((IData)((0x2073U == (0x707fU 
                                            & vlSelfRef.top__DOT__inst)))) {
                __Vdly__top__DOT__pc = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    __VdlyVal__top__DOT__regmap__v10 
                        = vlSelfRef.top__DOT__regmap
                        [vlSelfRef.top__DOT__csr_reg];
                    __VdlyDim0__top__DOT__regmap__v10 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    __VdlySet__top__DOT__regmap__v10 = 1U;
                }
                __VdlyVal__top__DOT__regmap__v11 = 
                    (vlSelfRef.top__DOT__regmap[vlSelfRef.top__DOT__csr_reg] 
                     | vlSelfRef.top__DOT__rs1_val);
                __VdlyDim0__top__DOT__regmap__v11 = vlSelfRef.top__DOT__csr_reg;
                __VdlySet__top__DOT__regmap__v11 = 1U;
            } else if ((0x73U == vlSelfRef.top__DOT__inst)) {
                __Vdly__top__DOT__pc = vlSelfRef.top__DOT__regmap
                    [0x11U];
                __VdlyVal__top__DOT__regmap__v12 = vlSelfRef.top__DOT__pc;
                __VdlySet__top__DOT__regmap__v12 = 1U;
                __VdlyVal__top__DOT__regmap__v13 = 
                    vlSelfRef.top__DOT__regmap[0xfU];
            } else if (VL_LIKELY((0x30200073U == vlSelfRef.top__DOT__inst))) {
                __Vdly__top__DOT__pc = vlSelfRef.top__DOT__regmap
                    [0x12U];
            } else {
                VL_WRITEF_NX("invalid instruction 0x%08x: 0x%08x\n",0,
                             32,vlSelfRef.top__DOT__pc,
                             32,vlSelfRef.top__DOT__inst);
                Verilated::runFlushCallbacks();
                VL_FINISH_MT("top.v", 474, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: top.v:409: Assertion failed in %Ntop: 'unique if' statement violated\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name());
            Verilated::runFlushCallbacks();
            VL_STOP_MT("top.v", 409, "");
        }
    }
    vlSelfRef.top__DOT__pc = __Vdly__top__DOT__pc;
    if (vlSelfRef.rst) {
        __Vdly__top__DOT__lv = 1U;
        vlSelfRef.top__DOT__lr = 1U;
        vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
        vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
        vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
        vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
        vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
    } else {
        if ((0U == (IData)(vlSelfRef.top__DOT__lc))) {
            if (vlSelfRef.top__DOT__dv) {
                if ((3U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                    __Vdly__top__DOT__lv = 0U;
                    vlSelfRef.top__DOT__lr = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.araddr 
                        = vlSelfRef.top__DOT__mem_addr;
                } else if ((0x23U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                    __Vdly__top__DOT__lv = 0U;
                    vlSelfRef.top__DOT__lr = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awaddr 
                        = vlSelfRef.top__DOT__mem_addr;
                    vlSymsp->TOP__top__DOT__axi_lsu.wdata 
                        = vlSelfRef.top__DOT__rs2_val;
                    vlSymsp->TOP__top__DOT__axi_lsu.wstrb 
                        = ((0U == (7U & (vlSelfRef.top__DOT__inst 
                                         >> 0xcU)))
                            ? 1U : ((1U == (7U & (vlSelfRef.top__DOT__inst 
                                                  >> 0xcU)))
                                     ? 3U : ((2U == 
                                              (7U & 
                                               (vlSelfRef.top__DOT__inst 
                                                >> 0xcU)))
                                              ? 0xfU
                                              : 0U)));
                } else {
                    __Vdly__top__DOT__lv = 1U;
                    vlSelfRef.top__DOT__lr = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
                }
            } else {
                __Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__lc))) {
            if (vlSymsp->TOP__top__DOT__axi_lsu.rvalid) {
                __Vdly__top__DOT__lv = 1U;
                vlSelfRef.top__DOT__lr = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    if ((0x4000U & vlSelfRef.top__DOT__inst)) {
                        if (VL_UNLIKELY((0x2000U & vlSelfRef.top__DOT__inst))) {
                            VL_WRITEF_NX("unknown type\n",0);
                            Verilated::runFlushCallbacks();
                            VL_FINISH_MT("top.v", 348, "");
                        } else {
                            __VdlyVal__top__DOT__regmap__v0 
                                = ((0x1000U & vlSelfRef.top__DOT__inst)
                                    ? (0xffffU & vlSelfRef.top__DOT__ldata)
                                    : (0xffU & vlSelfRef.top__DOT__ldata));
                            __VdlyDim0__top__DOT__regmap__v0 
                                = (0x1fU & (vlSelfRef.top__DOT__inst 
                                            >> 7U));
                            __VdlySet__top__DOT__regmap__v0 = 1U;
                        }
                    } else if ((0x2000U & vlSelfRef.top__DOT__inst)) {
                        if (VL_UNLIKELY((0x1000U & vlSelfRef.top__DOT__inst))) {
                            VL_WRITEF_NX("unknown type\n",0);
                            Verilated::runFlushCallbacks();
                            VL_FINISH_MT("top.v", 348, "");
                        } else {
                            __VdlyVal__top__DOT__regmap__v1 
                                = vlSelfRef.top__DOT__ldata;
                            __VdlyDim0__top__DOT__regmap__v1 
                                = (0x1fU & (vlSelfRef.top__DOT__inst 
                                            >> 7U));
                            __VdlySet__top__DOT__regmap__v1 = 1U;
                        }
                    } else {
                        __VdlyVal__top__DOT__regmap__v2 
                            = ((0x1000U & vlSelfRef.top__DOT__inst)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.top__DOT__ldata 
                                                   >> 0xfU)))) 
                                    << 0x10U) | (0xffffU 
                                                 & vlSelfRef.top__DOT__ldata))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.top__DOT__ldata 
                                                   >> 7U)))) 
                                    << 8U) | (0xffU 
                                              & vlSelfRef.top__DOT__ldata)));
                        __VdlyDim0__top__DOT__regmap__v2 
                            = (0x1fU & (vlSelfRef.top__DOT__inst 
                                        >> 7U));
                        __VdlySet__top__DOT__regmap__v2 = 1U;
                    }
                }
            } else if (vlSymsp->TOP__top__DOT__axi_lsu.bvalid) {
                __Vdly__top__DOT__lv = 1U;
                vlSelfRef.top__DOT__lr = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
            } else {
                __Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__lc))) {
            if (vlSelfRef.top__DOT__ir) {
                __Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
            } else {
                __Vdly__top__DOT__lv = 1U;
                vlSelfRef.top__DOT__lr = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
            }
        } else {
            __Vdly__top__DOT__lv = 1U;
            vlSelfRef.top__DOT__lr = 1U;
            vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
            vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
            vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
            vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
            vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
        }
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__lc)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__lc)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__lc)))))))) {
            if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__lc)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__lc)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__lc)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: top.v:289: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__lc));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("top.v", 289, "");
                }
            }
        }
    }
    vlSelfRef.top__DOT__dv = __Vdly__top__DOT__dv;
    if (__VdlySet__top__DOT__regmap__v0) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v0] 
            = __VdlyVal__top__DOT__regmap__v0;
    }
    if (__VdlySet__top__DOT__regmap__v1) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v1] 
            = __VdlyVal__top__DOT__regmap__v1;
    }
    if (__VdlySet__top__DOT__regmap__v2) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v2] 
            = __VdlyVal__top__DOT__regmap__v2;
    }
    if (__VdlySet__top__DOT__regmap__v3) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v3] 
            = __VdlyVal__top__DOT__regmap__v3;
    }
    if (__VdlySet__top__DOT__regmap__v4) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v4] 
            = __VdlyVal__top__DOT__regmap__v4;
    }
    if (__VdlySet__top__DOT__regmap__v5) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v5] 
            = __VdlyVal__top__DOT__regmap__v5;
    }
    if (__VdlySet__top__DOT__regmap__v6) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v6] 
            = __VdlyVal__top__DOT__regmap__v6;
    }
    if (__VdlySet__top__DOT__regmap__v7) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v7] 
            = __VdlyVal__top__DOT__regmap__v7;
    }
    if (__VdlySet__top__DOT__regmap__v8) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v8] 
            = __VdlyVal__top__DOT__regmap__v8;
    }
    if (__VdlySet__top__DOT__regmap__v9) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v9] 
            = __VdlyVal__top__DOT__regmap__v9;
    }
    if (__VdlySet__top__DOT__regmap__v10) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v10] 
            = __VdlyVal__top__DOT__regmap__v10;
    }
    if (__VdlySet__top__DOT__regmap__v11) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v11] 
            = __VdlyVal__top__DOT__regmap__v11;
    }
    if (__VdlySet__top__DOT__regmap__v12) {
        vlSelfRef.top__DOT__regmap[0x12U] = __VdlyVal__top__DOT__regmap__v12;
        vlSelfRef.top__DOT__regmap[0x13U] = __VdlyVal__top__DOT__regmap__v13;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__dc = 0U;
        vlSelfRef.top__DOT__lc = 0U;
    } else {
        vlSelfRef.top__DOT__dc = vlSelfRef.top__DOT__dn;
        vlSelfRef.top__DOT__lc = vlSelfRef.top__DOT__ln;
    }
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__ic)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__ic)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__ic)))))))) {
            if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__ic)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__ic)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__ic)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: top.v:151: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__ic));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("top.v", 151, "");
                }
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__ic))) {
            if (vlSelfRef.top__DOT__lv) {
                vlSelfRef.top__DOT__iv = 0U;
                vlSelfRef.top__DOT__ir = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 1U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
            } else {
                vlSelfRef.top__DOT__iv = 0U;
                vlSelfRef.top__DOT__ir = 1U;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__ic))) {
            if (vlSymsp->TOP__top__DOT__axi_ifu.rvalid) {
                vlSelfRef.top__DOT__iv = 1U;
                vlSelfRef.top__DOT__ir = 0U;
                vlSelfRef.top__DOT__inst = vlSymsp->TOP__top__DOT__axi_sram.rdata;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 0U;
            } else {
                vlSelfRef.top__DOT__iv = 0U;
                vlSelfRef.top__DOT__ir = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 1U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__ic))) {
            if (vlSelfRef.top__DOT__dr) {
                vlSelfRef.top__DOT__iv = 0U;
                vlSelfRef.top__DOT__ir = 1U;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
            } else {
                vlSelfRef.top__DOT__iv = 1U;
                vlSelfRef.top__DOT__ir = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_ifu.rready = 0U;
            }
        } else {
            vlSelfRef.top__DOT__iv = 0U;
            vlSelfRef.top__DOT__ir = 1U;
            vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
            vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
        }
    } else {
        vlSelfRef.top__DOT__iv = 0U;
        vlSelfRef.top__DOT__ir = 1U;
        vlSymsp->TOP__top__DOT__axi_ifu.arvalid = 0U;
        vlSymsp->TOP__top__DOT__axi_ifu.rready = 1U;
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__dc)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__dc)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__dc)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__dc)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: top.v:207: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__dc));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("top.v", 207, "");
            }
        }
    }
    vlSelfRef.top__DOT__lv = __Vdly__top__DOT__lv;
    vlSelfRef.top__DOT__dr = __Vdly__top__DOT__dr;
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__lc)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__lc)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__lc)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__lc)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__lc)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__lc)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: top.v:262: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__lc));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("top.v", 262, "");
            }
        }
    }
    vlSelfRef.top__DOT__ic = ((IData)(vlSelfRef.rst)
                               ? 0U : (IData)(vlSelfRef.top__DOT__in));
    vlSelfRef.top__DOT__dn = ((0U == (IData)(vlSelfRef.top__DOT__dc))
                               ? ((IData)(vlSelfRef.top__DOT__iv)
                                   ? 1U : 0U) : (((1U 
                                                   == (IData)(vlSelfRef.top__DOT__dc)) 
                                                  || (2U 
                                                      == (IData)(vlSelfRef.top__DOT__dc)))
                                                  ? 
                                                 ((IData)(vlSelfRef.top__DOT__lr)
                                                   ? 0U
                                                   : 2U)
                                                  : 0U));
    if ((1U & (~ VL_ONEHOT_I((((0x342U == (vlSelfRef.top__DOT__inst 
                                           >> 0x14U)) 
                               << 3U) | (((0x341U == 
                                           (vlSelfRef.top__DOT__inst 
                                            >> 0x14U)) 
                                          << 2U) | 
                                         (((0x305U 
                                            == (vlSelfRef.top__DOT__inst 
                                                >> 0x14U)) 
                                           << 1U) | 
                                          (0x300U == 
                                           (vlSelfRef.top__DOT__inst 
                                            >> 0x14U))))))))) {
        if ((0U != (((0x342U == (vlSelfRef.top__DOT__inst 
                                 >> 0x14U)) << 3U) 
                    | (((0x341U == (vlSelfRef.top__DOT__inst 
                                    >> 0x14U)) << 2U) 
                       | (((0x305U == (vlSelfRef.top__DOT__inst 
                                       >> 0x14U)) << 1U) 
                          | (0x300U == (vlSelfRef.top__DOT__inst 
                                        >> 0x14U))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: top.v:31: Assertion failed in %Ntop: unique case, but multiple matches found for '12'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),12,
                             (vlSelfRef.top__DOT__inst 
                              >> 0x14U));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("top.v", 31, "");
            }
        }
    }
    vlSelfRef.top__DOT__csr_reg = ((0x300U == (vlSelfRef.top__DOT__inst 
                                               >> 0x14U))
                                    ? 0x10U : ((0x305U 
                                                == 
                                                (vlSelfRef.top__DOT__inst 
                                                 >> 0x14U))
                                                ? 0x11U
                                                : (
                                                   (0x341U 
                                                    == 
                                                    (vlSelfRef.top__DOT__inst 
                                                     >> 0x14U))
                                                    ? 0x12U
                                                    : 
                                                   ((0x342U 
                                                     == 
                                                     (vlSelfRef.top__DOT__inst 
                                                      >> 0x14U))
                                                     ? 0x13U
                                                     : 0U))));
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.top__DOT__inst >> 0x14U))];
    vlSelfRef.top__DOT__imm = (((- (IData)((vlSelfRef.top__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.top__DOT__inst 
                                            >> 0x14U));
    vlSelfRef.top__DOT__rs1_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.top__DOT__inst >> 0xfU))];
    vlSelfRef.top__DOT__alu_c = ((8U & (vlSelfRef.top__DOT__inst 
                                        >> 0x1bU)) 
                                 | (7U & (vlSelfRef.top__DOT__inst 
                                          >> 0xcU)));
    if ((0x40U & vlSelfRef.top__DOT__inst)) {
        if ((0x20U & vlSelfRef.top__DOT__inst)) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__inst)) {
                    if ((4U & vlSelfRef.top__DOT__inst)) {
                        if ((2U & vlSelfRef.top__DOT__inst)) {
                            if ((1U & vlSelfRef.top__DOT__inst)) {
                                vlSelfRef.top__DOT__imm 
                                    = (((- (IData)(
                                                   (vlSelfRef.top__DOT__inst 
                                                    >> 0x1fU))) 
                                        << 0x14U) | 
                                       ((0xff000U & vlSelfRef.top__DOT__inst) 
                                        | ((0x800U 
                                            & (vlSelfRef.top__DOT__inst 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelfRef.top__DOT__inst 
                                                 >> 0x14U)))));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__inst)) {
                    if ((2U & vlSelfRef.top__DOT__inst)) {
                        if ((1U & vlSelfRef.top__DOT__inst)) {
                            vlSelfRef.top__DOT__imm 
                                = (((- (IData)((vlSelfRef.top__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.top__DOT__inst 
                                                >> 0x14U));
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__inst)) {
                    if ((1U & vlSelfRef.top__DOT__inst)) {
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0x800U 
                                                       & (vlSelfRef.top__DOT__inst 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlSelfRef.top__DOT__inst 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlSelfRef.top__DOT__inst 
                                                               >> 7U)))));
                    }
                }
            }
        }
    } else if ((0x20U & vlSelfRef.top__DOT__inst)) {
        if ((0x10U & vlSelfRef.top__DOT__inst)) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__inst)) {
                    if ((2U & vlSelfRef.top__DOT__inst)) {
                        if ((1U & vlSelfRef.top__DOT__inst)) {
                            vlSelfRef.top__DOT__imm 
                                = (0xfffff000U & vlSelfRef.top__DOT__inst);
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.top__DOT__inst 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__inst)) {
                    if ((1U & vlSelfRef.top__DOT__inst)) {
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.top__DOT__inst 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelfRef.top__DOT__inst 
                                                            >> 7U))));
                    }
                }
            }
        }
    } else if ((0x10U & vlSelfRef.top__DOT__inst)) {
        if ((1U & (~ (vlSelfRef.top__DOT__inst >> 3U)))) {
            if ((4U & vlSelfRef.top__DOT__inst)) {
                if ((2U & vlSelfRef.top__DOT__inst)) {
                    if ((1U & vlSelfRef.top__DOT__inst)) {
                        vlSelfRef.top__DOT__imm = (0xfffff000U 
                                                   & vlSelfRef.top__DOT__inst);
                    }
                }
            } else if ((2U & vlSelfRef.top__DOT__inst)) {
                if ((1U & vlSelfRef.top__DOT__inst)) {
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__inst 
                                                  >> 0x14U));
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.top__DOT__inst >> 3U)))) {
        if ((1U & (~ (vlSelfRef.top__DOT__inst >> 2U)))) {
            if ((2U & vlSelfRef.top__DOT__inst)) {
                if ((1U & vlSelfRef.top__DOT__inst)) {
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.top__DOT__inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__inst 
                                                  >> 0x14U));
                }
            }
        }
    }
    vlSelfRef.top__DOT__mem_addr = (vlSelfRef.top__DOT__regmap
                                    [(0x1fU & (vlSelfRef.top__DOT__inst 
                                               >> 0xfU))] 
                                    + vlSelfRef.top__DOT__imm);
    vlSelfRef.top__DOT__alu_2 = vlSelfRef.top__DOT__imm;
    if ((0x40U & vlSelfRef.top__DOT__inst)) {
        if ((0x20U & vlSelfRef.top__DOT__inst)) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__inst)) {
                    if ((4U & vlSelfRef.top__DOT__inst)) {
                        if ((2U & vlSelfRef.top__DOT__inst)) {
                            if ((1U & vlSelfRef.top__DOT__inst)) {
                                vlSelfRef.top__DOT__alu_c = 0U;
                                vlSelfRef.top__DOT__alu_2 = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__inst)) {
                    if ((2U & vlSelfRef.top__DOT__inst)) {
                        if ((1U & vlSelfRef.top__DOT__inst)) {
                            vlSelfRef.top__DOT__alu_c 
                                = (7U & (vlSelfRef.top__DOT__inst 
                                         >> 0xcU));
                            vlSelfRef.top__DOT__alu_2 = 4U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__inst)) {
                    if ((1U & vlSelfRef.top__DOT__inst)) {
                        vlSelfRef.top__DOT__alu_c = 
                            ((0U == (3U & (vlSelfRef.top__DOT__inst 
                                           >> 0xdU)))
                              ? (8U | (3U & (vlSelfRef.top__DOT__inst 
                                             >> 0xdU)))
                              : (3U & (vlSelfRef.top__DOT__inst 
                                       >> 0xdU)));
                        vlSelfRef.top__DOT__alu_2 = vlSelfRef.top__DOT__rs2_val;
                    }
                }
            }
        }
    } else if ((0x20U & vlSelfRef.top__DOT__inst)) {
        if ((0x10U & vlSelfRef.top__DOT__inst)) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__inst 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__inst)) {
                        if ((1U & vlSelfRef.top__DOT__inst)) {
                            vlSelfRef.top__DOT__alu_c 
                                = ((8U & (vlSelfRef.top__DOT__inst 
                                          >> 0x1bU)) 
                                   | (7U & (vlSelfRef.top__DOT__inst 
                                            >> 0xcU)));
                            vlSelfRef.top__DOT__alu_2 
                                = vlSelfRef.top__DOT__rs2_val;
                        }
                    }
                }
            }
        }
    } else if ((0x10U & vlSelfRef.top__DOT__inst)) {
        if ((1U & (~ (vlSelfRef.top__DOT__inst >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__inst 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__inst)) {
                    if ((1U & vlSelfRef.top__DOT__inst)) {
                        vlSelfRef.top__DOT__alu_c = 
                            ((1U == (3U & (vlSelfRef.top__DOT__inst 
                                           >> 0xcU)))
                              ? ((8U & (vlSelfRef.top__DOT__inst 
                                        >> 0x1bU)) 
                                 | (7U & (vlSelfRef.top__DOT__inst 
                                          >> 0xcU)))
                              : (7U & (vlSelfRef.top__DOT__inst 
                                       >> 0xcU)));
                        vlSelfRef.top__DOT__alu_2 = vlSelfRef.top__DOT__imm;
                    }
                }
            }
        }
    }
    vlSelfRef.top__DOT__alu_1 = vlSelfRef.top__DOT__rs1_val;
    if (((0x6fU == (0x7fU & vlSelfRef.top__DOT__inst)) 
         | (0x67U == (0x7fU & vlSelfRef.top__DOT__inst)))) {
        vlSelfRef.top__DOT__alu_1 = vlSelfRef.top__DOT__pc;
    }
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__alu_c))) {
                    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__unnamedblk2__DOT__i = 0x20U;
                }
            }
        }
    }
    if ((1U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__unnamedblk1__DOT__i = 0x20U;
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__ic)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__ic)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__ic)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.top__DOT__ic)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__ic)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__ic)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: top.v:135: Assertion failed in %Ntop: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__ic));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("top.v", 135, "");
            }
        }
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB 
        = ((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
           << 1U);
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
        = (vlSelfRef.top__DOT__alu_1 & vlSelfRef.top__DOT__alu_2);
    if ((7U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__alu_1 & vlSelfRef.top__DOT__alu_2);
    } else if ((6U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__alu_1 | vlSelfRef.top__DOT__alu_2);
    } else if ((4U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__alu_1 ^ vlSelfRef.top__DOT__alu_2);
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
        = vlSelfRef.top__DOT__alu_1;
    if ((1U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xfffffff8U & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((4U & (vlSelfRef.top__DOT__alu_1 
                         >> 0x1bU)) | ((2U & (vlSelfRef.top__DOT__alu_1 
                                              >> 0x1dU)) 
                                       | (vlSelfRef.top__DOT__alu_1 
                                          >> 0x1fU))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xffffffc7U & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x20U & (vlSelfRef.top__DOT__alu_1 
                            >> 0x15U)) | ((0x10U & 
                                           (vlSelfRef.top__DOT__alu_1 
                                            >> 0x17U)) 
                                          | (8U & (vlSelfRef.top__DOT__alu_1 
                                                   >> 0x19U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xfffffe3fU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x100U & (vlSelfRef.top__DOT__alu_1 
                             >> 0xfU)) | ((0x80U & 
                                           (vlSelfRef.top__DOT__alu_1 
                                            >> 0x11U)) 
                                          | (0x40U 
                                             & (vlSelfRef.top__DOT__alu_1 
                                                >> 0x13U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xfffff1ffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x800U & (vlSelfRef.top__DOT__alu_1 
                             >> 9U)) | ((0x400U & (vlSelfRef.top__DOT__alu_1 
                                                   >> 0xbU)) 
                                        | (0x200U & 
                                           (vlSelfRef.top__DOT__alu_1 
                                            >> 0xdU)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xffff8fffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x4000U & (vlSelfRef.top__DOT__alu_1 
                              >> 3U)) | ((0x2000U & 
                                          (vlSelfRef.top__DOT__alu_1 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSelfRef.top__DOT__alu_1 
                                               >> 7U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xfffc7fffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x20000U & (vlSelfRef.top__DOT__alu_1 
                               << 3U)) | ((0x10000U 
                                           & (vlSelfRef.top__DOT__alu_1 
                                              << 1U)) 
                                          | (0x8000U 
                                             & (vlSelfRef.top__DOT__alu_1 
                                                >> 1U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xffe3ffffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x100000U & (vlSelfRef.top__DOT__alu_1 
                                << 9U)) | ((0x80000U 
                                            & (vlSelfRef.top__DOT__alu_1 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSelfRef.top__DOT__alu_1 
                                                 << 5U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xff1fffffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x800000U & (vlSelfRef.top__DOT__alu_1 
                                << 0xfU)) | ((0x400000U 
                                              & (vlSelfRef.top__DOT__alu_1 
                                                 << 0xdU)) 
                                             | (0x200000U 
                                                & (vlSelfRef.top__DOT__alu_1 
                                                   << 0xbU)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xf8ffffffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x4000000U & (vlSelfRef.top__DOT__alu_1 
                                 << 0x15U)) | ((0x2000000U 
                                                & (vlSelfRef.top__DOT__alu_1 
                                                   << 0x13U)) 
                                               | (0x1000000U 
                                                  & (vlSelfRef.top__DOT__alu_1 
                                                     << 0x11U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0xc7ffffffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((0x20000000U & (vlSelfRef.top__DOT__alu_1 
                                  << 0x1bU)) | ((0x10000000U 
                                                 & (vlSelfRef.top__DOT__alu_1 
                                                    << 0x19U)) 
                                                | (0x8000000U 
                                                   & (vlSelfRef.top__DOT__alu_1 
                                                      << 0x17U)))));
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = ((0x3fffffffU & vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src) 
               | ((vlSelfRef.top__DOT__alu_1 << 0x1fU) 
                  | (0x40000000U & (vlSelfRef.top__DOT__alu_1 
                                    << 0x1dU))));
    } else if (((5U == (IData)(vlSelfRef.top__DOT__alu_c)) 
                || (0xdU == (IData)(vlSelfRef.top__DOT__alu_c)))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
            = vlSelfRef.top__DOT__alu_1;
    }
    if ((8U & (IData)(vlSelfRef.top__DOT__alu_c))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.top__DOT__alu_c)))) {
                    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB 
                        = (0x1ffffffffULL & (~ ((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                                                << 1U)));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                         >> 2U)))) {
        if ((2U & (IData)(vlSelfRef.top__DOT__alu_c))) {
            vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB 
                = (0x1ffffffffULL & (~ ((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                                        << 1U)));
        } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__alu_c)))) {
            vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB 
                = ((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                   << 1U);
        }
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
        = (0x3ffffffffULL & ((1ULL | ((QData)((IData)(vlSelfRef.top__DOT__alu_1)) 
                                      << 1U)) + vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB));
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
        = (vlSelfRef.top__DOT__alu_1 >> (0x1fU & vlSelfRef.top__DOT__alu_2));
    if (((1U == (IData)(vlSelfRef.top__DOT__alu_c)) 
         || (5U == (IData)(vlSelfRef.top__DOT__alu_c)))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src 
               >> (0x1fU & vlSelfRef.top__DOT__alu_2));
    } else if ((0xdU == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src, 
                             (0x1fU & vlSelfRef.top__DOT__alu_2));
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
        = (1U & (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                         >> 0x21U)));
    if ((2U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
            = (1U & ((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                              >> 0x20U)) ^ (((~ (vlSelfRef.top__DOT__alu_1 
                                                 >> 0x1fU)) 
                                             & ((vlSelfRef.top__DOT__alu_2 
                                                 >> 0x1fU) 
                                                & (IData)(
                                                          (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                                           >> 0x20U)))) 
                                            | ((~ (
                                                   (vlSelfRef.top__DOT__alu_2 
                                                    >> 0x1fU) 
                                                   | (IData)(
                                                             (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                                              >> 0x20U)))) 
                                               & (vlSelfRef.top__DOT__alu_1 
                                                  >> 0x1fU)))));
    } else if ((3U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
            = (1U & (~ (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                >> 0x21U))));
    }
    vlSelfRef.top__DOT__alu_3 = (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                         >> 1U));
    if ((8U & (IData)(vlSelfRef.top__DOT__alu_c))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__alu_c))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__alu_c))) {
                    vlSelfRef.top__DOT__alu_3 = vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res;
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__alu_c) 
                             >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__alu_c)))) {
                vlSelfRef.top__DOT__alu_3 = (IData)(
                                                    (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                                     >> 1U));
            }
        }
    } else if ((4U & (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__alu_3 = ((2U & (IData)(vlSelfRef.top__DOT__alu_c))
                                      ? vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res
                                      : ((1U & (IData)(vlSelfRef.top__DOT__alu_c))
                                          ? vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res
                                          : vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res));
    } else if ((2U & (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__alu_3 = vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res;
    } else if ((1U & (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__alu_3 = ((0xfffffff8U & vlSelfRef.top__DOT__alu_3) 
                                     | ((4U & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               >> 0x1bU)) 
                                        | ((2U & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                  >> 0x1dU)) 
                                           | (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                              >> 0x1fU))));
        vlSelfRef.top__DOT__alu_3 = ((0xffffffc7U & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x20U & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                  >> 0x15U)) 
                                        | ((0x10U & 
                                            (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                             >> 0x17U)) 
                                           | (8U & 
                                              (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               >> 0x19U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xfffffe3fU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x100U & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                   >> 0xfU)) 
                                        | ((0x80U & 
                                            (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                             >> 0x11U)) 
                                           | (0x40U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 >> 0x13U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xfffff1ffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x800U & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                   >> 9U)) 
                                        | ((0x400U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               >> 0xbU)) 
                                           | (0x200U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 >> 0xdU)))));
        vlSelfRef.top__DOT__alu_3 = ((0xffff8fffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x4000U & 
                                         (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                          >> 3U)) | 
                                        ((0x2000U & 
                                          (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               >> 7U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xfffc7fffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x20000U & 
                                         (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                          << 3U)) | 
                                        ((0x10000U 
                                          & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                             << 1U)) 
                                         | (0x8000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               >> 1U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xffe3ffffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x100000U 
                                         & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                            << 9U)) 
                                        | ((0x80000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 << 5U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xff1fffffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x800000U 
                                         & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                            << 0xfU)) 
                                        | ((0x400000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               << 0xdU)) 
                                           | (0x200000U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 << 0xbU)))));
        vlSelfRef.top__DOT__alu_3 = ((0xf8ffffffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x4000000U 
                                         & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                            << 0x15U)) 
                                        | ((0x2000000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               << 0x13U)) 
                                           | (0x1000000U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 << 0x11U)))));
        vlSelfRef.top__DOT__alu_3 = ((0xc7ffffffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((0x20000000U 
                                         & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                            << 0x1bU)) 
                                        | ((0x10000000U 
                                            & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                               << 0x19U)) 
                                           | (0x8000000U 
                                              & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                                 << 0x17U)))));
        vlSelfRef.top__DOT__alu_3 = ((0x3fffffffU & vlSelfRef.top__DOT__alu_3) 
                                     | ((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                         << 0x1fU) 
                                        | (0x40000000U 
                                           & (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
                                              << 0x1dU))));
    } else {
        vlSelfRef.top__DOT__alu_3 = (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                             >> 1U));
    }
    vlSelfRef.top__DOT__alu_out = vlSelfRef.top__DOT__alu_3;
    if ((0x63U == (0x7fU & vlSelfRef.top__DOT__inst))) {
        vlSelfRef.top__DOT__alu_out = ((0x4000U & vlSelfRef.top__DOT__inst)
                                        ? ((0x1000U 
                                            & vlSelfRef.top__DOT__inst)
                                            ? (1U & 
                                               (~ vlSelfRef.top__DOT__alu_3))
                                            : vlSelfRef.top__DOT__alu_3)
                                        : ((0x2000U 
                                            & vlSelfRef.top__DOT__inst)
                                            ? vlSelfRef.top__DOT__alu_3
                                            : ((0x1000U 
                                                & vlSelfRef.top__DOT__inst)
                                                ? (0U 
                                                   != vlSelfRef.top__DOT__alu_3)
                                                : (1U 
                                                   & (~ (IData)(
                                                                (0U 
                                                                 != vlSelfRef.top__DOT__alu_3)))))));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__DOT__axi_lsu.rvalid = ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    vlSymsp->TOP__top__DOT__axi_lsu.bvalid = ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    vlSymsp->TOP__top__DOT__axi_sram.rdata = vlSymsp->TOP__top__DOT__axi_sram.__Vdly__rdata;
    vlSymsp->TOP__top__DOT__axi_ifu.rvalid = ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__axi_ifu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__axi_ifu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSelfRef.top__DOT__pc;
    } else if ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__axi_lsu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__axi_lsu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSymsp->TOP__top__DOT__axi_lsu.araddr;
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = 0U;
    }
    vlSelfRef.top__DOT__ln = ((0U == (IData)(vlSelfRef.top__DOT__lc))
                               ? ((IData)(vlSelfRef.top__DOT__dv)
                                   ? (((3U == (0x7fU 
                                               & vlSelfRef.top__DOT__inst)) 
                                       | (0x23U == 
                                          (0x7fU & vlSelfRef.top__DOT__inst)))
                                       ? 1U : 2U) : 0U)
                               : ((1U == (IData)(vlSelfRef.top__DOT__lc))
                                   ? (((IData)(vlSymsp->TOP__top__DOT__axi_lsu.rvalid) 
                                       | (IData)(vlSymsp->TOP__top__DOT__axi_lsu.bvalid))
                                       ? 2U : 1U) : 
                                  ((2U == (IData)(vlSelfRef.top__DOT__lc))
                                    ? ((IData)(vlSelfRef.top__DOT__ir)
                                        ? 0U : 2U) : 0U)));
    vlSelfRef.top__DOT__ldata = (vlSymsp->TOP__top__DOT__axi_sram.rdata 
                                 >> (IData)(vlSelfRef.top__DOT__rshamt));
    vlSelfRef.top__DOT__in = ((0U == (IData)(vlSelfRef.top__DOT__ic))
                               ? ((IData)(vlSelfRef.top__DOT__lv)
                                   ? 1U : 0U) : ((1U 
                                                  == (IData)(vlSelfRef.top__DOT__ic))
                                                  ? 
                                                 ((IData)(vlSymsp->TOP__top__DOT__axi_ifu.rvalid)
                                                   ? 2U
                                                   : 1U)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelfRef.top__DOT__ic))
                                                   ? 
                                                  ((IData)(vlSelfRef.top__DOT__dr)
                                                    ? 0U
                                                    : 2U)
                                                   : 0U)));
    if ((1U & (~ VL_ONEHOT_I((((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr) 
                               << 1U) | (0xa0000048U 
                                         == vlSymsp->TOP__top__DOT__axi_sram.araddr)))))) {
        if ((0U != (((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr) 
                     << 1U) | (0xa0000048U == vlSymsp->TOP__top__DOT__axi_sram.araddr)))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: sram.sv:19: Assertion failed in %Ntop.sram: unique case, but multiple matches found for '32'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),32,
                             vlSymsp->TOP__top__DOT__axi_sram.araddr);
                Verilated::runFlushCallbacks();
                VL_STOP_MT("sram.sv", 19, "");
            }
        }
    }
    vlSelfRef.top__DOT__sram__DOT__dout = 0U;
    if ((0xa0000048U == vlSymsp->TOP__top__DOT__axi_sram.araddr)) {
        vlSelfRef.top__DOT__sram__DOT__dout = (IData)(vlSelfRef.top__DOT__sram__DOT__mtime);
    } else if ((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr)) {
        vlSelfRef.top__DOT__sram__DOT__dout = (IData)(
                                                      (vlSelfRef.top__DOT__sram__DOT__mtime 
                                                       >> 0x20U));
    }
}
