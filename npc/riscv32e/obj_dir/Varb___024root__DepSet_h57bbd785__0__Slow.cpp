// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb__Syms.h"
#include "Varb___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__stl(Varb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Varb___024root___eval_triggers__stl(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Varb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*1:0*/, 16> Varb__ConstPool__TABLE_h588dbbb1_0;
extern const VlUnpacked<CData/*1:0*/, 16> Varb__ConstPool__TABLE_h0e900e07_0;

VL_ATTR_COLD void Varb___024root___stl_sequent__TOP__0(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:29: Assertion failed in %Ntop.CORE.IFU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_ifu.sv", 29, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:29: Assertion failed in %Ntop.CORE.IFU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_ifu.sv", 29, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:30: Assertion failed in %Ntop.CORE.IDU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_idu.sv", 30, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:30: Assertion failed in %Ntop.CORE.IDU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_idu.sv", 30, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:25: Assertion failed in %Ntop.CORE.EXU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_exu.sv", 25, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:25: Assertion failed in %Ntop.CORE.EXU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_exu.sv", 25, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:26: Assertion failed in %Ntop.CORE.LSU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_lsu.sv", 26, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:26: Assertion failed in %Ntop.CORE.LSU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_lsu.sv", 26, "");
        }
    }
    if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i = 0x20U;
                }
            }
        }
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bvalid 
        = ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    vlSelfRef.top__DOT__CORE__DOT__rs1_val = vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile
        [(0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                   >> 0xfU))];
    if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc;
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr;
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = 0U;
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid)
                ? 1U : 0U);
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))) {
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready)
                ? 0U : 2U);
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid)
                ? 1U : 0U);
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready)
                ? 0U : 2U);
    }
    vlSelfRef.__Vtableidx1 = ((0xeU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                       >> 0xbU)) | 
                              (0x63U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)));
    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_set 
        = Varb__ConstPool__TABLE_h588dbbb1_0[vlSelfRef.__Vtableidx1];
    vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__rshamt 
        = ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
            ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                ? 0x18U : 0x10U) : ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                                     ? 8U : 0U));
    vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__alu_res 
        = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load)
            ? (vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__ldata 
               >> (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__rshamt))
            : vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res);
    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm = 
        (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                      >> 0x1fU))) << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                              >> 0x14U));
    vlSelfRef.__Vtableidx2 = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid) 
                               << 3U) | (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready) 
                                          << 2U) | (IData)(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr)));
    vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__next = 
        Varb__ConstPool__TABLE_h0e900e07_0[vlSelfRef.__Vtableidx2];
    vlSelfRef.top__DOT__CORE__DOT__rs2_val = vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile
        [(0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                   >> 0x14U))];
    if ((0x40U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
        if ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 4U)))) {
                if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                    = (((- (IData)(
                                                   (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0x1fU))) 
                                        << 0x14U) | 
                                       ((0xff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst) 
                                        | ((0x800U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                 >> 0x14U)))));
                            }
                        }
                    }
                } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x14U));
                        }
                    }
                } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                            = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0x800U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                     >> 7U)))));
                    }
                }
            }
            if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                        ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                ? 4U : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                            : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                        : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm);
            } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                        ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? 4U : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                        : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm);
            } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                        = ((0U == (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                         >> 0xdU)))
                            ? (8U | (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                           >> 0xdU)))
                            : (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                     >> 0xdU)));
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__rs2_val;
                } else {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
                }
            } else {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
        }
    } else if ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
        if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (0xfffff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst);
                        }
                    }
                }
            }
            if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                        = ((8U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                  >> 0x1bU)) | (7U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                   >> 0xcU)));
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__rs2_val;
                } else {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
                }
            } else {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                              >> 2U)))) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0xfe0U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                      >> 7U))));
                        }
                    }
                }
            }
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
        }
    } else {
        if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                = ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                    ? 0U : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                             ? 0U : ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                      ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                          ? ((1U == 
                                              (3U & 
                                               (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0xcU)))
                                              ? ((8U 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                     >> 0x1bU)) 
                                                 | (7U 
                                                    & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                       >> 0xcU)))
                                              : (7U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0xcU)))
                                          : 0U) : 0U)));
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (0xfffff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst);
                        }
                    }
                } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                            = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x14U));
                    }
                }
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                              >> 2U)))) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x14U));
                        }
                    }
                }
            }
        }
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
            = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid 
        = ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid 
        = ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid 
        = ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
        = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
           & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    if ((7U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    } else if ((6U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               | vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    } else if ((4U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               ^ vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
        = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1;
    if ((1U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i = 0x20U;
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffffff8U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((4U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                         >> 0x1bU)) | ((2U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                              >> 0x1dU)) 
                                       | (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                          >> 0x1fU))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffffffc7U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                            >> 0x15U)) | ((0x10U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0x17U)) 
                                          | (8U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   >> 0x19U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffffe3fU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x100U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                             >> 0xfU)) | ((0x80U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0x11U)) 
                                          | (0x40U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                >> 0x13U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffff1ffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x800U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                             >> 9U)) | ((0x400U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   >> 0xbU)) 
                                        | (0x200U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0xdU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffff8fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x4000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                              >> 3U)) | ((0x2000U & 
                                          (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               >> 7U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffc7fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                               << 3U)) | ((0x10000U 
                                           & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                              << 1U)) 
                                          | (0x8000U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                >> 1U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffe3ffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x100000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                << 9U)) | ((0x80000U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 << 5U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xff1fffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x800000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                << 0xfU)) | ((0x400000U 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 << 0xdU)) 
                                             | (0x200000U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   << 0xbU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xf8ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x4000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                 << 0x15U)) | ((0x2000000U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   << 0x13U)) 
                                               | (0x1000000U 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                     << 0x11U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xc7ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                  << 0x1bU)) | ((0x10000000U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                    << 0x19U)) 
                                                | (0x8000000U 
                                                   & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                      << 0x17U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0x3fffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                   << 0x1fU) | (0x40000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               << 0x1dU))));
    } else if (((5U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)) 
                || (0xdU == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1;
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
        = ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
           << 1U);
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid)
                ? 1U : 0U);
    } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid)
                ? 2U : 1U);
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready)
                ? 0U : 2U);
    }
    if ((8U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                        = (0x1ffffffffULL & (~ ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                                                << 1U)));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                         >> 2U)))) {
        if ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
            vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                = (0x1ffffffffULL & (~ ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                                        << 1U)));
        } else if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
            vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                = ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                   << 1U);
        }
    }
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
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid)
                ? (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load) 
                    | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store))
                    ? 1U : 2U) : 0U);
    } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid) 
                | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid))
                ? 2U : 1U);
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready)
                ? 0U : 2U);
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
        = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
           >> (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    if (((1U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)) 
         || (5U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
            = (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
               >> (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    } else if ((0xdU == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
            = VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src, 
                             (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
        = (0x3ffffffffULL & ((1ULL | ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1)) 
                                      << 1U)) + vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
        = (1U & (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                         >> 0x21U)));
    if ((2U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
            = (1U & ((IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                              >> 0x20U)) ^ (((~ (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 >> 0x1fU)) 
                                             & ((vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 
                                                 >> 0x1fU) 
                                                & (IData)(
                                                          (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                                           >> 0x20U)))) 
                                            | ((~ (
                                                   (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 
                                                    >> 0x1fU) 
                                                   | (IData)(
                                                             (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                                              >> 0x20U)))) 
                                               & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                  >> 0x1fU)))));
    } else if ((3U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
            = (1U & (~ (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                >> 0x21U))));
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
        = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                   >> 1U));
    if ((8U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        if ((4U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
                        = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res;
                }
            }
        } else if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                             >> 1U)))) {
            if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
                vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
                    = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                               >> 1U));
            }
        }
    } else if ((4U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))
                ? vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res
                : ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))
                    ? vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res
                    : vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res));
    } else if ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res;
    } else if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffffff8U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((4U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                         >> 0x1bU)) | ((2U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                              >> 0x1dU)) 
                                       | (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                          >> 0x1fU))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffffffc7U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                            >> 0x15U)) | ((0x10U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0x17U)) 
                                          | (8U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   >> 0x19U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffffe3fU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x100U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                             >> 0xfU)) | ((0x80U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0x11U)) 
                                          | (0x40U 
                                             & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                >> 0x13U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffff1ffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x800U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                             >> 9U)) | ((0x400U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   >> 0xbU)) 
                                        | (0x200U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0xdU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffff8fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x4000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                              >> 3U)) | ((0x2000U & 
                                          (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               >> 7U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffc7fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                               << 3U)) | ((0x10000U 
                                           & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                              << 1U)) 
                                          | (0x8000U 
                                             & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                >> 1U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffe3ffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x100000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                << 9U)) | ((0x80000U 
                                            & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                 << 5U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xff1fffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x800000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                << 0xfU)) | ((0x400000U 
                                              & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                 << 0xdU)) 
                                             | (0x200000U 
                                                & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   << 0xbU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xf8ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x4000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                 << 0x15U)) | ((0x2000000U 
                                                & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   << 0x13U)) 
                                               | (0x1000000U 
                                                  & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                     << 0x11U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xc7ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                  << 0x1bU)) | ((0x10000000U 
                                                 & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                    << 0x19U)) 
                                                | (0x8000000U 
                                                   & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                      << 0x17U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0x3fffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                   << 0x1fU) | (0x40000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               << 0x1dU))));
    } else {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                       >> 1U));
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res 
        = ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
            ? ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
                ? (1U & (~ vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))
                : (0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))
            : ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
                ? (1U & (~ (IData)((0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))))
                : vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__branch 
        = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch) 
           & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res);
}
