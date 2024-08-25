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
    // Body
    vlSelfRef.__Vdly__top__DOT__lv = vlSelfRef.top__DOT__lv;
    vlSelfRef.__VdlySet__top__DOT__regmap__v0 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v1 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v2 = 0U;
    vlSelfRef.__Vdly__top__DOT__dr = vlSelfRef.top__DOT__dr;
    vlSelfRef.__Vdly__top__DOT__dv = vlSelfRef.top__DOT__dv;
    vlSelfRef.__Vdly__top__DOT__pc = vlSelfRef.top__DOT__pc;
    vlSelfRef.__VdlySet__top__DOT__regmap__v3 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v4 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v5 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v6 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v7 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v8 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v9 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v10 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v11 = 0U;
    vlSelfRef.__VdlySet__top__DOT__regmap__v12 = 0U;
    if (vlSelfRef.rst) {
        vlSelfRef.__Vdly__top__DOT__dv = 0U;
        vlSelfRef.__Vdly__top__DOT__dr = 1U;
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
                vlSelfRef.__Vdly__top__DOT__dv = 1U;
                vlSelfRef.__Vdly__top__DOT__dr = 0U;
            } else {
                vlSelfRef.__Vdly__top__DOT__dv = 0U;
                vlSelfRef.__Vdly__top__DOT__dr = 1U;
            }
        } else if (((1U == (IData)(vlSelfRef.top__DOT__dc)) 
                    || (2U == (IData)(vlSelfRef.top__DOT__dc)))) {
            if (vlSelfRef.top__DOT__lr) {
                vlSelfRef.__Vdly__top__DOT__dv = 0U;
                vlSelfRef.__Vdly__top__DOT__dr = 1U;
            } else {
                vlSelfRef.__Vdly__top__DOT__dv = 1U;
                vlSelfRef.__Vdly__top__DOT__dr = 0U;
            }
        } else {
            vlSelfRef.__Vdly__top__DOT__dv = 0U;
            vlSelfRef.__Vdly__top__DOT__dr = 1U;
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.__Vdly__top__DOT__pc = 0x80000000U;
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
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v3 
                        = vlSelfRef.top__DOT__imm;
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v3 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v3 = 1U;
                }
            } else if ((0x17U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v4 
                        = (vlSelfRef.top__DOT__pc + vlSelfRef.top__DOT__imm);
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v4 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v4 = 1U;
                }
            } else if ((0x6fU == (0x7fU & vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = (vlSelfRef.top__DOT__pc 
                                                  + vlSelfRef.top__DOT__imm);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v5 
                        = vlSelfRef.top__DOT__alu_3;
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v5 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v5 = 1U;
                }
            } else if ((0x67U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = (0xfffffffeU 
                                                  & (vlSelfRef.top__DOT__rs1_val 
                                                     + vlSelfRef.top__DOT__imm));
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v6 
                        = vlSelfRef.top__DOT__alu_3;
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v6 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v6 = 1U;
                }
            } else if ((0x63U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = ((1U 
                                                   & vlSelfRef.top__DOT__alu_out)
                                                   ? 
                                                  (vlSelfRef.top__DOT__pc 
                                                   + vlSelfRef.top__DOT__imm)
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pc));
            } else if ((3U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
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
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
            } else if (((0x13U == (0x7fU & vlSelfRef.top__DOT__inst)) 
                        | (0x33U == (0x7fU & vlSelfRef.top__DOT__inst)))) {
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v7 
                        = vlSelfRef.top__DOT__alu_out;
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v7 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v7 = 1U;
                }
            } else if ((0x100073U == vlSelfRef.top__DOT__inst)) {
                Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP();
            } else if ((IData)((0x1073U == (0x707fU 
                                            & vlSelfRef.top__DOT__inst)))) {
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v8 
                        = vlSelfRef.top__DOT__regmap
                        [vlSelfRef.top__DOT__csr_reg];
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v8 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v8 = 1U;
                }
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
                vlSelfRef.__VdlyVal__top__DOT__regmap__v9 
                    = vlSelfRef.top__DOT__rs1_val;
                vlSelfRef.__VdlyDim0__top__DOT__regmap__v9 
                    = vlSelfRef.top__DOT__csr_reg;
                vlSelfRef.__VdlySet__top__DOT__regmap__v9 = 1U;
            } else if ((IData)((0x2073U == (0x707fU 
                                            & vlSelfRef.top__DOT__inst)))) {
                vlSelfRef.__Vdly__top__DOT__pc = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__pc);
                if ((0U != (0x1fU & (vlSelfRef.top__DOT__inst 
                                     >> 7U)))) {
                    vlSelfRef.__VdlyVal__top__DOT__regmap__v10 
                        = vlSelfRef.top__DOT__regmap
                        [vlSelfRef.top__DOT__csr_reg];
                    vlSelfRef.__VdlyDim0__top__DOT__regmap__v10 
                        = (0x1fU & (vlSelfRef.top__DOT__inst 
                                    >> 7U));
                    vlSelfRef.__VdlySet__top__DOT__regmap__v10 = 1U;
                }
                vlSelfRef.__VdlyVal__top__DOT__regmap__v11 
                    = (vlSelfRef.top__DOT__regmap[vlSelfRef.top__DOT__csr_reg] 
                       | vlSelfRef.top__DOT__rs1_val);
                vlSelfRef.__VdlyDim0__top__DOT__regmap__v11 
                    = vlSelfRef.top__DOT__csr_reg;
                vlSelfRef.__VdlySet__top__DOT__regmap__v11 = 1U;
            } else if ((0x73U == vlSelfRef.top__DOT__inst)) {
                vlSelfRef.__Vdly__top__DOT__pc = vlSelfRef.top__DOT__regmap
                    [0x11U];
                vlSelfRef.__VdlyVal__top__DOT__regmap__v12 
                    = vlSelfRef.top__DOT__pc;
                vlSelfRef.__VdlySet__top__DOT__regmap__v12 = 1U;
                vlSelfRef.__VdlyVal__top__DOT__regmap__v13 
                    = vlSelfRef.top__DOT__regmap[0xfU];
            } else if (VL_LIKELY((0x30200073U == vlSelfRef.top__DOT__inst))) {
                vlSelfRef.__Vdly__top__DOT__pc = vlSelfRef.top__DOT__regmap
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
    vlSelfRef.top__DOT__dc = ((IData)(vlSelfRef.rst)
                               ? 0U : (IData)(vlSelfRef.top__DOT__dn));
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
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout;
    __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout = 0;
    CData/*1:0*/ __Vdly__top__DOT__arb__DOT__arbiter_state;
    __Vdly__top__DOT__arb__DOT__arbiter_state = 0;
    CData/*0:0*/ __Vdly__top__DOT__sram__DOT__en;
    __Vdly__top__DOT__sram__DOT__en = 0;
    // Body
    __Vdly__top__DOT__sram__DOT__en = vlSelfRef.top__DOT__sram__DOT__en;
    vlSymsp->TOP__top__DOT__axi_sram.__Vdly__rdata 
        = vlSymsp->TOP__top__DOT__axi_sram.rdata;
    __Vdly__top__DOT__arb__DOT__arbiter_state = vlSelfRef.top__DOT__arb__DOT__arbiter_state;
    __Vdly__top__DOT__sram__DOT__en = (1U & (~ (IData)(vlSelfRef.top__DOT__sram__DOT__en)));
    if (((((IData)(vlSymsp->TOP__top__DOT__axi_sram.awvalid) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wvalid)) 
          & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bready)) 
         & (IData)(vlSelfRef.top__DOT__sram__DOT__en))) {
        Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP(
                                                                         ((1U 
                                                                           == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                           ? vlSymsp->TOP__top__DOT__axi_ifu.awaddr
                                                                           : 
                                                                          ((2U 
                                                                            == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                            ? vlSymsp->TOP__top__DOT__axi_lsu.awaddr
                                                                            : 0U)), 
                                                                         ((1U 
                                                                           == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                           ? vlSymsp->TOP__top__DOT__axi_ifu.wdata
                                                                           : 
                                                                          ((2U 
                                                                            == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                            ? vlSymsp->TOP__top__DOT__axi_lsu.wdata
                                                                            : 0U)), 
                                                                         ((1U 
                                                                           == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                           ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wstrb)
                                                                           : 
                                                                          ((2U 
                                                                            == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                            ? (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wstrb)
                                                                            : 0U)));
    }
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        if ((0U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
            if (((IData)(vlSymsp->TOP__top__DOT__axi_ifu.awvalid) 
                 | (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 1U;
            } else if (((IData)(vlSymsp->TOP__top__DOT__axi_lsu.awvalid) 
                        | (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid))) {
                __Vdly__top__DOT__arb__DOT__arbiter_state = 2U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
            if ((((((IData)(vlSymsp->TOP__top__DOT__axi_ifu.awvalid) 
                    & (IData)(vlSymsp->TOP__top__DOT__axi_ifu.awready)) 
                   & (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wvalid)) 
                  & (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wready)) 
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
        __Vdly__top__DOT__arb__DOT__arbiter_state = 0U;
    }
    if (vlSymsp->TOP__top__DOT__axi_ifu.aresetn) {
        if ((((IData)(vlSymsp->TOP__top__DOT__axi_sram.awvalid) 
              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wvalid)) 
             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bready))) {
            vlSymsp->TOP__top__DOT__axi_sram.awready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.wready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.bvalid = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.bresp = 0U;
        } else {
            vlSymsp->TOP__top__DOT__axi_sram.awready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.wready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.bvalid = 0U;
        }
        if ((((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
               ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid)
               : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                  & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid))) 
             & ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                 ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.rready)
                 : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                    & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.rready))))) {
            Vtop___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP(
                                                                            ((1U 
                                                                              == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                              ? vlSelfRef.top__DOT__pc
                                                                              : 
                                                                             ((2U 
                                                                               == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                                                               ? vlSymsp->TOP__top__DOT__axi_lsu.araddr
                                                                               : 0U)), __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout);
            vlSymsp->TOP__top__DOT__axi_sram.arready = 0U;
            vlSymsp->TOP__top__DOT__axi_sram.__Vdly__rdata 
                = __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout;
            vlSymsp->TOP__top__DOT__axi_sram.rvalid = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.rresp = 0U;
        } else {
            vlSymsp->TOP__top__DOT__axi_sram.arready = 1U;
            vlSymsp->TOP__top__DOT__axi_sram.rvalid = 0U;
        }
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.wready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.bvalid = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.arready = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.rvalid = 0U;
    }
    vlSelfRef.top__DOT__sram__DOT__en = __Vdly__top__DOT__sram__DOT__en;
    vlSelfRef.top__DOT__arb__DOT__arbiter_state = __Vdly__top__DOT__arb__DOT__arbiter_state;
    vlSymsp->TOP__top__DOT__axi_ifu.awready = ((1U 
                                                == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                               & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready));
    vlSymsp->TOP__top__DOT__axi_ifu.wready = ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    // Body
    vlSelfRef.top__DOT__pc = vlSelfRef.__Vdly__top__DOT__pc;
    if (vlSelfRef.rst) {
        vlSelfRef.__Vdly__top__DOT__lv = 1U;
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
                    vlSelfRef.__Vdly__top__DOT__lv = 0U;
                    vlSelfRef.top__DOT__lr = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.araddr 
                        = vlSelfRef.top__DOT__mem_addr;
                } else if ((0x23U == (0x7fU & vlSelfRef.top__DOT__inst))) {
                    vlSelfRef.__Vdly__top__DOT__lv = 0U;
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
                    vlSelfRef.__Vdly__top__DOT__lv = 1U;
                    vlSelfRef.top__DOT__lr = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
                }
            } else {
                vlSelfRef.__Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__lc))) {
            if (vlSymsp->TOP__top__DOT__axi_lsu.rvalid) {
                vlSelfRef.__Vdly__top__DOT__lv = 1U;
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
                            vlSelfRef.__VdlySet__top__DOT__regmap__v0 = 1U;
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
                            vlSelfRef.__VdlySet__top__DOT__regmap__v1 = 1U;
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
                        vlSelfRef.__VdlySet__top__DOT__regmap__v2 = 1U;
                    }
                }
            } else if (vlSymsp->TOP__top__DOT__axi_lsu.bvalid) {
                vlSelfRef.__Vdly__top__DOT__lv = 1U;
                vlSelfRef.top__DOT__lr = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
            } else {
                vlSelfRef.__Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__lc))) {
            if (vlSelfRef.top__DOT__ir) {
                vlSelfRef.__Vdly__top__DOT__lv = 0U;
                vlSelfRef.top__DOT__lr = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 1U;
            } else {
                vlSelfRef.__Vdly__top__DOT__lv = 1U;
                vlSelfRef.top__DOT__lr = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__axi_lsu.bready = 0U;
            }
        } else {
            vlSelfRef.__Vdly__top__DOT__lv = 1U;
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
    vlSelfRef.top__DOT__dv = vlSelfRef.__Vdly__top__DOT__dv;
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v0) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v0] 
            = __VdlyVal__top__DOT__regmap__v0;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v1) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v1] 
            = __VdlyVal__top__DOT__regmap__v1;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v2) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v2] 
            = __VdlyVal__top__DOT__regmap__v2;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v3) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v3] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v3;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v4) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v4] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v4;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v5) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v5] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v5;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v6) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v6] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v6;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v7) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v7] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v7;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v8) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v8] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v8;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v9) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v9] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v9;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v10) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v10] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v10;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v11) {
        vlSelfRef.top__DOT__regmap[vlSelfRef.__VdlyDim0__top__DOT__regmap__v11] 
            = vlSelfRef.__VdlyVal__top__DOT__regmap__v11;
    }
    if (vlSelfRef.__VdlySet__top__DOT__regmap__v12) {
        vlSelfRef.top__DOT__regmap[0x12U] = vlSelfRef.__VdlyVal__top__DOT__regmap__v12;
        vlSelfRef.top__DOT__regmap[0x13U] = vlSelfRef.__VdlyVal__top__DOT__regmap__v13;
    }
    vlSelfRef.top__DOT__lc = ((IData)(vlSelfRef.rst)
                               ? 0U : (IData)(vlSelfRef.top__DOT__ln));
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
    vlSelfRef.top__DOT__lv = vlSelfRef.__Vdly__top__DOT__lv;
    vlSelfRef.top__DOT__dr = vlSelfRef.__Vdly__top__DOT__dr;
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
    vlSelfRef.top__DOT__rs1_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.top__DOT__inst >> 0xfU))];
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.top__DOT__inst >> 0x14U))];
    vlSelfRef.top__DOT__imm = (((- (IData)((vlSelfRef.top__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.top__DOT__inst 
                                            >> 0x14U));
    vlSelfRef.top__DOT__alu_c = ((8U & (vlSelfRef.top__DOT__inst 
                                        >> 0x1bU)) 
                                 | (7U & (vlSelfRef.top__DOT__inst 
                                          >> 0xcU)));
    vlSelfRef.top__DOT__alu_1 = vlSelfRef.top__DOT__rs1_val;
    if (((0x6fU == (0x7fU & vlSelfRef.top__DOT__inst)) 
         | (0x67U == (0x7fU & vlSelfRef.top__DOT__inst)))) {
        vlSelfRef.top__DOT__alu_1 = vlSelfRef.top__DOT__pc;
    }
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
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
        = (vlSelfRef.top__DOT__alu_1 << (0x1fU & vlSelfRef.top__DOT__alu_2));
    if ((1U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__alu_1 << (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((5U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__alu_1 >> (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((0xdU == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (VL_SHIFTL_III(32,32,32, (- (IData)((vlSelfRef.top__DOT__alu_1 
                                                   >> 0x1fU))), 
                             ((IData)(0x1fU) - (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2))) 
               | (vlSelfRef.top__DOT__alu_1 >> (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2)));
    }
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
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB 
        = ((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
           << 1U);
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
    } else {
        vlSelfRef.top__DOT__alu_3 = ((4U & (IData)(vlSelfRef.top__DOT__alu_c))
                                      ? ((2U & (IData)(vlSelfRef.top__DOT__alu_c))
                                          ? vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res
                                          : ((1U & (IData)(vlSelfRef.top__DOT__alu_c))
                                              ? vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res
                                              : vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res))
                                      : ((2U & (IData)(vlSelfRef.top__DOT__alu_c))
                                          ? (IData)(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res)
                                          : ((1U & (IData)(vlSelfRef.top__DOT__alu_c))
                                              ? vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res
                                              : (IData)(
                                                        (vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                                         >> 1U)))));
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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
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
        vlSymsp->TOP__top__DOT__axi_sram.awvalid = vlSymsp->TOP__top__DOT__axi_ifu.awvalid;
        vlSymsp->TOP__top__DOT__axi_sram.wvalid = vlSymsp->TOP__top__DOT__axi_ifu.wvalid;
        vlSymsp->TOP__top__DOT__axi_sram.bready = vlSymsp->TOP__top__DOT__axi_ifu.bready;
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awvalid = 
            ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
             & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.awvalid));
        vlSymsp->TOP__top__DOT__axi_sram.wvalid = (
                                                   (2U 
                                                    == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                                   & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wvalid));
        vlSymsp->TOP__top__DOT__axi_sram.bready = (
                                                   (2U 
                                                    == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                                   & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.bready));
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
}
