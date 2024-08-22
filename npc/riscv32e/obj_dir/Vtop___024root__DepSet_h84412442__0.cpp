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

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
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
    // Init
    CData/*0:0*/ top__DOT____VdfgRegularize_h245778ca_0_3;
    top__DOT____VdfgRegularize_h245778ca_0_3 = 0;
    // Body
    if ((1U & (~ VL_ONEHOT_I((((0x342U == (vlSelfRef.inst 
                                           >> 0x14U)) 
                               << 3U) | (((0x341U == 
                                           (vlSelfRef.inst 
                                            >> 0x14U)) 
                                          << 2U) | 
                                         (((0x305U 
                                            == (vlSelfRef.inst 
                                                >> 0x14U)) 
                                           << 1U) | 
                                          (0x300U == 
                                           (vlSelfRef.inst 
                                            >> 0x14U))))))))) {
        if ((0U != (((0x342U == (vlSelfRef.inst >> 0x14U)) 
                     << 3U) | (((0x341U == (vlSelfRef.inst 
                                            >> 0x14U)) 
                                << 2U) | (((0x305U 
                                            == (vlSelfRef.inst 
                                                >> 0x14U)) 
                                           << 1U) | 
                                          (0x300U == 
                                           (vlSelfRef.inst 
                                            >> 0x14U))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: top.v:67: Assertion failed in %Ntop: unique case, but multiple matches found for '12'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),12,
                             (vlSelfRef.inst >> 0x14U));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("top.v", 67, "");
            }
        }
    }
    vlSelfRef.top__DOT__csr_reg = ((0x300U == (vlSelfRef.inst 
                                               >> 0x14U))
                                    ? 0x10U : ((0x305U 
                                                == 
                                                (vlSelfRef.inst 
                                                 >> 0x14U))
                                                ? 0x11U
                                                : (
                                                   (0x341U 
                                                    == 
                                                    (vlSelfRef.inst 
                                                     >> 0x14U))
                                                    ? 0x12U
                                                    : 
                                                   ((0x342U 
                                                     == 
                                                     (vlSelfRef.inst 
                                                      >> 0x14U))
                                                     ? 0x13U
                                                     : 0U))));
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0x14U))];
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2 
        = (vlSelfRef.top__DOT__regmap[(0x1fU & (vlSelfRef.inst 
                                                >> 0xfU))] 
           >> 0x1fU);
    vlSelfRef.top__DOT__rs1_s = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0xfU))];
    vlSelfRef.top__DOT__imm = (((- (IData)((vlSelfRef.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.inst 
                                            >> 0x14U));
    if ((0x40U & vlSelfRef.inst)) {
        if ((0x20U & vlSelfRef.inst)) {
            if ((1U & (~ (vlSelfRef.inst >> 4U)))) {
                if ((8U & vlSelfRef.inst)) {
                    if ((4U & vlSelfRef.inst)) {
                        if ((2U & vlSelfRef.inst)) {
                            if ((1U & vlSelfRef.inst)) {
                                vlSelfRef.top__DOT__imm 
                                    = (((- (IData)(
                                                   (vlSelfRef.inst 
                                                    >> 0x1fU))) 
                                        << 0x14U) | 
                                       ((0xff000U & vlSelfRef.inst) 
                                        | ((0x800U 
                                            & (vlSelfRef.inst 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelfRef.inst 
                                                 >> 0x14U)))));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.inst)) {
                    if ((2U & vlSelfRef.inst)) {
                        if ((1U & vlSelfRef.inst)) {
                            vlSelfRef.top__DOT__imm 
                                = (((- (IData)((vlSelfRef.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelfRef.inst 
                                                >> 0x14U));
                        }
                    }
                } else if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0x800U 
                                                       & (vlSelfRef.inst 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlSelfRef.inst 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlSelfRef.inst 
                                                               >> 7U)))));
                    }
                }
            }
        }
    } else if ((0x20U & vlSelfRef.inst)) {
        if ((0x10U & vlSelfRef.inst)) {
            if ((1U & (~ (vlSelfRef.inst >> 3U)))) {
                if ((4U & vlSelfRef.inst)) {
                    if ((2U & vlSelfRef.inst)) {
                        if ((1U & vlSelfRef.inst)) {
                            vlSelfRef.top__DOT__imm 
                                = (0xfffff000U & vlSelfRef.inst);
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.inst >> 3U)))) {
            if ((1U & (~ (vlSelfRef.inst >> 2U)))) {
                if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.top__DOT__imm = (
                                                   ((- (IData)(
                                                               (vlSelfRef.inst 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.inst 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelfRef.inst 
                                                            >> 7U))));
                    }
                }
            }
        }
    } else if ((0x10U & vlSelfRef.inst)) {
        if ((1U & (~ (vlSelfRef.inst >> 3U)))) {
            if ((4U & vlSelfRef.inst)) {
                if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.top__DOT__imm = (0xfffff000U 
                                                   & vlSelfRef.inst);
                    }
                }
            } else if ((2U & vlSelfRef.inst)) {
                if ((1U & vlSelfRef.inst)) {
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.inst 
                                                  >> 0x14U));
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.inst >> 3U)))) {
        if ((1U & (~ (vlSelfRef.inst >> 2U)))) {
            if ((2U & vlSelfRef.inst)) {
                if ((1U & vlSelfRef.inst)) {
                    vlSelfRef.top__DOT__imm = (((- (IData)(
                                                           (vlSelfRef.inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.inst 
                                                  >> 0x14U));
                }
            }
        }
    }
    top__DOT____VdfgRegularize_h245778ca_0_3 = (IData)(
                                                       (0x40005000U 
                                                        == 
                                                        (0xfe007000U 
                                                         & vlSelfRef.inst)));
    vlSelfRef.top__DOT__alu_2 = ((0x13U == (0x7fU & vlSelfRef.inst))
                                  ? vlSelfRef.top__DOT__imm
                                  : vlSelfRef.top__DOT__regmap
                                 [(0x1fU & (vlSelfRef.inst 
                                            >> 0x14U))]);
    vlSelfRef.top__DOT__alu_c = (7U & (vlSelfRef.inst 
                                       >> 0xcU));
    if ((IData)((0x40000033U == (0xfe00707fU & vlSelfRef.inst)))) {
        vlSelfRef.top__DOT__alu_c = 8U;
    }
    if (((IData)(top__DOT____VdfgRegularize_h245778ca_0_3) 
         & (0x33U == (0x7fU & vlSelfRef.inst)))) {
        vlSelfRef.top__DOT__alu_c = 0xdU;
    }
    if (((IData)(top__DOT____VdfgRegularize_h245778ca_0_3) 
         & (0x13U == (0x7fU & vlSelfRef.inst)))) {
        vlSelfRef.top__DOT__alu_c = 0xdU;
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
        = (vlSelfRef.top__DOT__rs1_s << (0x1fU & vlSelfRef.top__DOT__alu_2));
    if ((1U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__rs1_s << (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((5U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((0xdU == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (VL_SHIFTL_III(32,32,32, (- (IData)((vlSelfRef.top__DOT__rs1_s 
                                                   >> 0x1fU))), 
                             ((IData)(0x1fU) - (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2))) 
               | (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2)));
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
        = (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__alu_2);
    if ((7U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__alu_2);
    } else if ((6U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s | vlSelfRef.top__DOT__alu_2);
    } else if ((4U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s ^ vlSelfRef.top__DOT__alu_2);
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
        = (0x3ffffffffULL & ((1ULL | ((QData)((IData)(
                                                      vlSelfRef.top__DOT__regmap
                                                      [
                                                      (0x1fU 
                                                       & (vlSelfRef.inst 
                                                          >> 0xfU))])) 
                                      << 1U)) + vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB));
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
        = (1U & (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                         >> 0x21U)));
    if ((2U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
            = (1U & ((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                              >> 0x20U)) ^ (((~ (IData)(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2)) 
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
                                               & (IData)(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2)))));
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
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
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
    IData/*31:0*/ __Vfunc_top__DOT__Mr__0__Vfuncout;
    __Vfunc_top__DOT__Mr__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_top__DOT__Mr__0__Mr_addr;
    __Vfunc_top__DOT__Mr__0__Mr_addr = 0;
    CData/*2:0*/ __Vfunc_top__DOT__Mr__0__funct_3;
    __Vfunc_top__DOT__Mr__0__funct_3 = 0;
    CData/*4:0*/ __Vfunc_top__DOT__Mr__0__Mr_shamt;
    __Vfunc_top__DOT__Mr__0__Mr_shamt = 0;
    IData/*31:0*/ __Vfunc_top__DOT__Mr__0__tmp;
    __Vfunc_top__DOT__Mr__0__tmp = 0;
    IData/*31:0*/ __Vfunc_top__DOT__Mr__0__temp;
    __Vfunc_top__DOT__Mr__0__temp = 0;
    IData/*31:0*/ __Vfunc_top__DOT__pmem_read__1__Vfuncout;
    __Vfunc_top__DOT__pmem_read__1__Vfuncout = 0;
    IData/*31:0*/ __Vdly__pc;
    __Vdly__pc = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v32;
    __VdlyVal__top__DOT__regmap__v32 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v32;
    __VdlyDim0__top__DOT__regmap__v32 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v33;
    __VdlyVal__top__DOT__regmap__v33 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v33;
    __VdlyDim0__top__DOT__regmap__v33 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v34;
    __VdlyVal__top__DOT__regmap__v34 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v34;
    __VdlyDim0__top__DOT__regmap__v34 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v35;
    __VdlyVal__top__DOT__regmap__v35 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v35;
    __VdlyDim0__top__DOT__regmap__v35 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v36;
    __VdlyVal__top__DOT__regmap__v36 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v36;
    __VdlyDim0__top__DOT__regmap__v36 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v37;
    __VdlyVal__top__DOT__regmap__v37 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v37;
    __VdlyDim0__top__DOT__regmap__v37 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v38;
    __VdlyVal__top__DOT__regmap__v38 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v38;
    __VdlyDim0__top__DOT__regmap__v38 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v39;
    __VdlyVal__top__DOT__regmap__v39 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v39;
    __VdlyDim0__top__DOT__regmap__v39 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v40;
    __VdlyVal__top__DOT__regmap__v40 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v40;
    __VdlyDim0__top__DOT__regmap__v40 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v41;
    __VdlyVal__top__DOT__regmap__v41 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v41;
    __VdlyDim0__top__DOT__regmap__v41 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v42;
    __VdlyVal__top__DOT__regmap__v42 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v43;
    __VdlyVal__top__DOT__regmap__v43 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v0;
    __VdlySet__top__DOT__regmap__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v32;
    __VdlySet__top__DOT__regmap__v32 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v33;
    __VdlySet__top__DOT__regmap__v33 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v34;
    __VdlySet__top__DOT__regmap__v34 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v35;
    __VdlySet__top__DOT__regmap__v35 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v36;
    __VdlySet__top__DOT__regmap__v36 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v37;
    __VdlySet__top__DOT__regmap__v37 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v38;
    __VdlySet__top__DOT__regmap__v38 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v39;
    __VdlySet__top__DOT__regmap__v39 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v40;
    __VdlySet__top__DOT__regmap__v40 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v41;
    __VdlySet__top__DOT__regmap__v41 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v42;
    __VdlySet__top__DOT__regmap__v42 = 0;
    // Body
    __Vdly__pc = vlSelfRef.pc;
    __VdlySet__top__DOT__regmap__v0 = 0U;
    __VdlySet__top__DOT__regmap__v32 = 0U;
    __VdlySet__top__DOT__regmap__v33 = 0U;
    __VdlySet__top__DOT__regmap__v34 = 0U;
    __VdlySet__top__DOT__regmap__v35 = 0U;
    __VdlySet__top__DOT__regmap__v36 = 0U;
    __VdlySet__top__DOT__regmap__v37 = 0U;
    __VdlySet__top__DOT__regmap__v38 = 0U;
    __VdlySet__top__DOT__regmap__v39 = 0U;
    __VdlySet__top__DOT__regmap__v40 = 0U;
    __VdlySet__top__DOT__regmap__v41 = 0U;
    __VdlySet__top__DOT__regmap__v42 = 0U;
    if (vlSelfRef.rst) {
        __Vdly__pc = 0x80000000U;
        __VdlySet__top__DOT__regmap__v0 = 1U;
    } else if (VL_ONEHOT0_I((((0x30200073U == vlSelfRef.inst) 
                              << 0x13U) | (((0x73U 
                                             == vlSelfRef.inst) 
                                            << 0x12U) 
                                           | (((IData)(
                                                       (0x2073U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.inst))) 
                                               << 0x11U) 
                                              | (((IData)(
                                                          (0x1073U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelfRef.inst))) 
                                                  << 0x10U) 
                                                 | (((0x100073U 
                                                      == vlSelfRef.inst) 
                                                     << 0xfU) 
                                                    | ((((0x13U 
                                                          == 
                                                          (0x7fU 
                                                           & vlSelfRef.inst)) 
                                                         | (0x33U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelfRef.inst))) 
                                                        << 0xeU) 
                                                       | (((IData)(
                                                                   (0x2023U 
                                                                    == 
                                                                    (0x707fU 
                                                                     & vlSelfRef.inst))) 
                                                           << 0xdU) 
                                                          | (((IData)(
                                                                      (0x1023U 
                                                                       == 
                                                                       (0x707fU 
                                                                        & vlSelfRef.inst))) 
                                                              << 0xcU) 
                                                             | (((IData)(
                                                                         (0x23U 
                                                                          == 
                                                                          (0x707fU 
                                                                           & vlSelfRef.inst))) 
                                                                 << 0xbU) 
                                                                | (((3U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlSelfRef.inst)) 
                                                                    << 0xaU) 
                                                                   | (((IData)(
                                                                               (0x7063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                       << 9U) 
                                                                      | (((IData)(
                                                                                (0x6063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                          << 8U) 
                                                                         | (((IData)(
                                                                                (0x5063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                             << 7U) 
                                                                            | (((IData)(
                                                                                (0x4063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 6U) 
                                                                               | (((IData)(
                                                                                (0x1063U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 5U) 
                                                                                | (((IData)(
                                                                                (0x63U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 4U) 
                                                                                | (((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 3U) 
                                                                                | (((0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelfRef.inst)) 
                                                                                << 2U) 
                                                                                | (((0x17U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelfRef.inst)) 
                                                                                << 1U) 
                                                                                | (0x37U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlSelfRef.inst))))))))))))))))))))))) {
        if ((0x37U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v32 = vlSelfRef.top__DOT__imm;
                __VdlyDim0__top__DOT__regmap__v32 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v32 = 1U;
            }
        } else if ((0x17U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v33 = 
                    (vlSelfRef.pc + vlSelfRef.top__DOT__imm);
                __VdlyDim0__top__DOT__regmap__v33 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v33 = 1U;
            }
        } else if ((0x6fU == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = (vlSelfRef.pc + vlSelfRef.top__DOT__imm);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v34 = 
                    ((IData)(4U) + vlSelfRef.pc);
                __VdlyDim0__top__DOT__regmap__v34 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v34 = 1U;
            }
        } else if ((IData)((0x67U == (0x707fU & vlSelfRef.inst)))) {
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v35 = 
                    ((IData)(4U) + vlSelfRef.pc);
                __VdlyDim0__top__DOT__regmap__v35 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v35 = 1U;
            }
            __Vdly__pc = (0xfffffffeU & (vlSelfRef.top__DOT__rs1_s 
                                         + vlSelfRef.top__DOT__imm));
        } else if ((IData)((0x63U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           == vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x1063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           != vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x4063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = (VL_LTS_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x5063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = (VL_GTES_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x6063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           < vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x7063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           >= vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__imm)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((3U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __Vfunc_top__DOT__Mr__0__funct_3 = 
                    (7U & (vlSelfRef.inst >> 0xcU));
                __Vfunc_top__DOT__Mr__0__Mr_addr = 
                    (vlSelfRef.top__DOT__rs1_s + vlSelfRef.top__DOT__imm);
                __Vfunc_top__DOT__Mr__0__Mr_shamt = 
                    ((2U & __Vfunc_top__DOT__Mr__0__Mr_addr)
                      ? ((1U & __Vfunc_top__DOT__Mr__0__Mr_addr)
                          ? 0x18U : 0x10U) : ((1U & __Vfunc_top__DOT__Mr__0__Mr_addr)
                                               ? 8U
                                               : 0U));
                Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(__Vfunc_top__DOT__Mr__0__Mr_addr, __Vfunc_top__DOT__pmem_read__1__Vfuncout);
                __Vfunc_top__DOT__Mr__0__temp = __Vfunc_top__DOT__pmem_read__1__Vfuncout;
                __Vfunc_top__DOT__Mr__0__tmp = (__Vfunc_top__DOT__Mr__0__temp 
                                                >> (IData)(__Vfunc_top__DOT__Mr__0__Mr_shamt));
                if ((4U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3))) {
                    if (VL_UNLIKELY((2U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3)))) {
                        __Vfunc_top__DOT__Mr__0__Vfuncout = 0U;
                        VL_WRITEF_NX("unknown type\n",0);
                        Verilated::runFlushCallbacks();
                        VL_FINISH_MT("top.v", 60, "");
                    } else {
                        __Vfunc_top__DOT__Mr__0__Vfuncout 
                            = ((1U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3))
                                ? (0xffffU & __Vfunc_top__DOT__Mr__0__tmp)
                                : (0xffU & __Vfunc_top__DOT__Mr__0__tmp));
                    }
                } else if ((2U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3))) {
                    if (VL_UNLIKELY((1U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3)))) {
                        __Vfunc_top__DOT__Mr__0__Vfuncout = 0U;
                        VL_WRITEF_NX("unknown type\n",0);
                        Verilated::runFlushCallbacks();
                        VL_FINISH_MT("top.v", 60, "");
                    } else {
                        __Vfunc_top__DOT__Mr__0__Vfuncout 
                            = __Vfunc_top__DOT__Mr__0__tmp;
                    }
                } else {
                    __Vfunc_top__DOT__Mr__0__Vfuncout 
                        = ((1U & (IData)(__Vfunc_top__DOT__Mr__0__funct_3))
                            ? (((- (IData)((1U & (__Vfunc_top__DOT__Mr__0__tmp 
                                                  >> 0xfU)))) 
                                << 0x10U) | (0xffffU 
                                             & __Vfunc_top__DOT__Mr__0__tmp))
                            : (((- (IData)((1U & (__Vfunc_top__DOT__Mr__0__tmp 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & __Vfunc_top__DOT__Mr__0__tmp)));
                }
                __VdlyVal__top__DOT__regmap__v36 = __Vfunc_top__DOT__Mr__0__Vfuncout;
                __VdlyDim0__top__DOT__regmap__v36 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v36 = 1U;
            }
        } else if ((IData)((0x23U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(
                                                                  (vlSelfRef.top__DOT__rs1_s 
                                                                   + vlSelfRef.top__DOT__imm), vlSelfRef.top__DOT__rs2_val, 1U);
        } else if ((IData)((0x1023U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(
                                                                  (vlSelfRef.top__DOT__rs1_s 
                                                                   + vlSelfRef.top__DOT__imm), vlSelfRef.top__DOT__rs2_val, 2U);
        } else if ((IData)((0x2023U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(
                                                                  (vlSelfRef.top__DOT__rs1_s 
                                                                   + vlSelfRef.top__DOT__imm), vlSelfRef.top__DOT__rs2_val, 4U);
        } else if (((0x13U == (0x7fU & vlSelfRef.inst)) 
                    | (0x33U == (0x7fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v37 = vlSelfRef.top__DOT__alu_3;
                __VdlyDim0__top__DOT__regmap__v37 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v37 = 1U;
            }
        } else if ((0x100073U == vlSelfRef.inst)) {
            Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP();
        } else if ((IData)((0x1073U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v38 = 
                    vlSelfRef.top__DOT__regmap[vlSelfRef.top__DOT__csr_reg];
                __VdlyDim0__top__DOT__regmap__v38 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v38 = 1U;
            }
            __VdlyVal__top__DOT__regmap__v39 = vlSelfRef.top__DOT__rs1_s;
            __VdlyDim0__top__DOT__regmap__v39 = vlSelfRef.top__DOT__csr_reg;
            __VdlySet__top__DOT__regmap__v39 = 1U;
        } else if ((IData)((0x2073U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v40 = 
                    vlSelfRef.top__DOT__regmap[vlSelfRef.top__DOT__csr_reg];
                __VdlyDim0__top__DOT__regmap__v40 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v40 = 1U;
            }
            __VdlyVal__top__DOT__regmap__v41 = (vlSelfRef.top__DOT__regmap
                                                [vlSelfRef.top__DOT__csr_reg] 
                                                | vlSelfRef.top__DOT__rs1_s);
            __VdlyDim0__top__DOT__regmap__v41 = vlSelfRef.top__DOT__csr_reg;
            __VdlySet__top__DOT__regmap__v41 = 1U;
        } else if ((0x73U == vlSelfRef.inst)) {
            __Vdly__pc = vlSelfRef.top__DOT__regmap
                [0x11U];
            __VdlyVal__top__DOT__regmap__v42 = vlSelfRef.pc;
            __VdlySet__top__DOT__regmap__v42 = 1U;
            __VdlyVal__top__DOT__regmap__v43 = vlSelfRef.top__DOT__regmap
                [0xfU];
        } else if (VL_LIKELY((0x30200073U == vlSelfRef.inst))) {
            __Vdly__pc = vlSelfRef.top__DOT__regmap
                [0x12U];
            VL_WRITEF_NX("thispc 0x%08x retpc 0x%08x\n",0,
                         32,vlSelfRef.pc,32,vlSelfRef.top__DOT__regmap
                         [0x12U]);
            Verilated::runFlushCallbacks();
        } else {
            VL_WRITEF_NX("invalid instruction 0x%08x: 0x%08x\n",0,
                         32,vlSelfRef.pc,32,vlSelfRef.inst);
            Verilated::runFlushCallbacks();
            VL_FINISH_MT("top.v", 202, "");
        }
    } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
        VL_WRITEF_NX("[%0t] %%Error: top.v:106: Assertion failed in %Ntop: 'unique if' statement violated\n",0,
                     64,VL_TIME_UNITED_Q(1),-9,vlSymsp->name());
        Verilated::runFlushCallbacks();
        VL_STOP_MT("top.v", 106, "");
    }
    vlSelfRef.pc = __Vdly__pc;
    if (__VdlySet__top__DOT__regmap__v0) {
        vlSelfRef.top__DOT__regmap[0U] = 0U;
        vlSelfRef.top__DOT__regmap[1U] = 0U;
        vlSelfRef.top__DOT__regmap[2U] = 0U;
        vlSelfRef.top__DOT__regmap[3U] = 0U;
        vlSelfRef.top__DOT__regmap[4U] = 0U;
        vlSelfRef.top__DOT__regmap[5U] = 0U;
        vlSelfRef.top__DOT__regmap[6U] = 0U;
        vlSelfRef.top__DOT__regmap[7U] = 0U;
        vlSelfRef.top__DOT__regmap[8U] = 0U;
        vlSelfRef.top__DOT__regmap[9U] = 0U;
        vlSelfRef.top__DOT__regmap[0xaU] = 0U;
        vlSelfRef.top__DOT__regmap[0xbU] = 0U;
        vlSelfRef.top__DOT__regmap[0xcU] = 0U;
        vlSelfRef.top__DOT__regmap[0xdU] = 0U;
        vlSelfRef.top__DOT__regmap[0xeU] = 0U;
        vlSelfRef.top__DOT__regmap[0xfU] = 0U;
        vlSelfRef.top__DOT__regmap[0x10U] = 0U;
        vlSelfRef.top__DOT__regmap[0x11U] = 0U;
        vlSelfRef.top__DOT__regmap[0x12U] = 0U;
        vlSelfRef.top__DOT__regmap[0x13U] = 0U;
        vlSelfRef.top__DOT__regmap[0x14U] = 0U;
        vlSelfRef.top__DOT__regmap[0x15U] = 0U;
        vlSelfRef.top__DOT__regmap[0x16U] = 0U;
        vlSelfRef.top__DOT__regmap[0x17U] = 0U;
        vlSelfRef.top__DOT__regmap[0x18U] = 0U;
        vlSelfRef.top__DOT__regmap[0x19U] = 0U;
        vlSelfRef.top__DOT__regmap[0x1aU] = 0U;
        vlSelfRef.top__DOT__regmap[0x1bU] = 0U;
        vlSelfRef.top__DOT__regmap[0x1cU] = 0U;
        vlSelfRef.top__DOT__regmap[0x1dU] = 0U;
        vlSelfRef.top__DOT__regmap[0x1eU] = 0U;
        vlSelfRef.top__DOT__regmap[0x1fU] = 0U;
    }
    if (__VdlySet__top__DOT__regmap__v32) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v32] 
            = __VdlyVal__top__DOT__regmap__v32;
    }
    if (__VdlySet__top__DOT__regmap__v33) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v33] 
            = __VdlyVal__top__DOT__regmap__v33;
    }
    if (__VdlySet__top__DOT__regmap__v34) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v34] 
            = __VdlyVal__top__DOT__regmap__v34;
    }
    if (__VdlySet__top__DOT__regmap__v35) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v35] 
            = __VdlyVal__top__DOT__regmap__v35;
    }
    if (__VdlySet__top__DOT__regmap__v36) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v36] 
            = __VdlyVal__top__DOT__regmap__v36;
    }
    if (__VdlySet__top__DOT__regmap__v37) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v37] 
            = __VdlyVal__top__DOT__regmap__v37;
    }
    if (__VdlySet__top__DOT__regmap__v38) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v38] 
            = __VdlyVal__top__DOT__regmap__v38;
    }
    if (__VdlySet__top__DOT__regmap__v39) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v39] 
            = __VdlyVal__top__DOT__regmap__v39;
    }
    if (__VdlySet__top__DOT__regmap__v40) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v40] 
            = __VdlyVal__top__DOT__regmap__v40;
    }
    if (__VdlySet__top__DOT__regmap__v41) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v41] 
            = __VdlyVal__top__DOT__regmap__v41;
    }
    if (__VdlySet__top__DOT__regmap__v42) {
        vlSelfRef.top__DOT__regmap[0x12U] = __VdlyVal__top__DOT__regmap__v42;
        vlSelfRef.top__DOT__regmap[0x13U] = __VdlyVal__top__DOT__regmap__v43;
    }
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0x14U))];
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2 
        = (vlSelfRef.top__DOT__regmap[(0x1fU & (vlSelfRef.inst 
                                                >> 0xfU))] 
           >> 0x1fU);
    vlSelfRef.top__DOT__rs1_s = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0xfU))];
    vlSelfRef.top__DOT__alu_2 = ((0x13U == (0x7fU & vlSelfRef.inst))
                                  ? vlSelfRef.top__DOT__imm
                                  : vlSelfRef.top__DOT__regmap
                                 [(0x1fU & (vlSelfRef.inst 
                                            >> 0x14U))]);
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
        = (vlSelfRef.top__DOT__rs1_s << (0x1fU & vlSelfRef.top__DOT__alu_2));
    if ((1U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__rs1_s << (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((5U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                             & vlSelfRef.top__DOT__alu_2));
    } else if ((0xdU == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res 
            = (VL_SHIFTL_III(32,32,32, (- (IData)((vlSelfRef.top__DOT__rs1_s 
                                                   >> 0x1fU))), 
                             ((IData)(0x1fU) - (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2))) 
               | (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                                & vlSelfRef.top__DOT__alu_2)));
    }
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
        = (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__alu_2);
    if ((7U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__alu_2);
    } else if ((6U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s | vlSelfRef.top__DOT__alu_2);
    } else if ((4U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res 
            = (vlSelfRef.top__DOT__rs1_s ^ vlSelfRef.top__DOT__alu_2);
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
        = (0x3ffffffffULL & ((1ULL | ((QData)((IData)(
                                                      vlSelfRef.top__DOT__regmap
                                                      [
                                                      (0x1fU 
                                                       & (vlSelfRef.inst 
                                                          >> 0xfU))])) 
                                      << 1U)) + vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB));
    vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
        = (1U & (IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                         >> 0x21U)));
    if ((2U == (IData)(vlSelfRef.top__DOT__alu_c))) {
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res 
            = (1U & ((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                              >> 0x20U)) ^ (((~ (IData)(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2)) 
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
                                               & (IData)(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT____VdfgRegularize_h8cb9263b_0_2)))));
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
}
