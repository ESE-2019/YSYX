// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__axi_ifu__aresetn__0 
        = vlSymsp->TOP__top__DOT__axi_ifu.aresetn;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSymsp->TOP__top__DOT__axi_ifu.aresetn = (1U & 
                                               (~ (IData)(vlSelfRef.rst)));
    vlSelfRef.top__DOT__ldata = (vlSymsp->TOP__top__DOT__axi_sram.rdata 
                                 >> (IData)(vlSelfRef.top__DOT__rshamt));
    vlSymsp->TOP__top__DOT__axi_ifu.awready = ((1U 
                                                == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                               & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready));
    vlSymsp->TOP__top__DOT__axi_ifu.wready = ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready));
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
    if ((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awvalid = vlSymsp->TOP__top__DOT__axi_ifu.awvalid;
        vlSymsp->TOP__top__DOT__axi_sram.wvalid = vlSymsp->TOP__top__DOT__axi_ifu.wvalid;
        vlSymsp->TOP__top__DOT__axi_sram.bready = vlSymsp->TOP__top__DOT__axi_ifu.bready;
        vlSymsp->TOP__top__DOT__axi_ifu.rvalid = vlSymsp->TOP__top__DOT__axi_sram.rvalid;
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
        vlSymsp->TOP__top__DOT__axi_ifu.rvalid = 0U;
    }
    vlSymsp->TOP__top__DOT__axi_lsu.bvalid = ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    vlSymsp->TOP__top__DOT__axi_lsu.rvalid = ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
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
        vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__unnamedblk1__DOT__i = 0x20U;
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
