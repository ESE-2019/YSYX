// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__immI = (((- (IData)((vlSelfRef.inst 
                                             >> 0x1fU))) 
                                 << 0xcU) | (vlSelfRef.inst 
                                             >> 0x14U));
    vlSelfRef.top__DOT__immB = (((- (IData)((vlSelfRef.inst 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0x800U 
                                              & (vlSelfRef.inst 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSelfRef.inst 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelfRef.inst 
                                                      >> 7U)))));
    vlSelfRef.top__DOT__immS = (((- (IData)((vlSelfRef.inst 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0xfe0U 
                                              & (vlSelfRef.inst 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelfRef.inst 
                                                   >> 7U))));
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0x14U))];
    vlSelfRef.top__DOT__rs1_s = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0xfU))];
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP();

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
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v42;
    __VdlyDim0__top__DOT__regmap__v42 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v43;
    __VdlyVal__top__DOT__regmap__v43 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v43;
    __VdlyDim0__top__DOT__regmap__v43 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v44;
    __VdlyVal__top__DOT__regmap__v44 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v44;
    __VdlyDim0__top__DOT__regmap__v44 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v45;
    __VdlyVal__top__DOT__regmap__v45 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v45;
    __VdlyDim0__top__DOT__regmap__v45 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v46;
    __VdlyVal__top__DOT__regmap__v46 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v46;
    __VdlyDim0__top__DOT__regmap__v46 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v47;
    __VdlyVal__top__DOT__regmap__v47 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v47;
    __VdlyDim0__top__DOT__regmap__v47 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v48;
    __VdlyVal__top__DOT__regmap__v48 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v48;
    __VdlyDim0__top__DOT__regmap__v48 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v49;
    __VdlyVal__top__DOT__regmap__v49 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v49;
    __VdlyDim0__top__DOT__regmap__v49 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v50;
    __VdlyVal__top__DOT__regmap__v50 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v50;
    __VdlyDim0__top__DOT__regmap__v50 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v51;
    __VdlyVal__top__DOT__regmap__v51 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v51;
    __VdlyDim0__top__DOT__regmap__v51 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v52;
    __VdlyVal__top__DOT__regmap__v52 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v52;
    __VdlyDim0__top__DOT__regmap__v52 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v53;
    __VdlyVal__top__DOT__regmap__v53 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v53;
    __VdlyDim0__top__DOT__regmap__v53 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v54;
    __VdlyVal__top__DOT__regmap__v54 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v54;
    __VdlyDim0__top__DOT__regmap__v54 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regmap__v55;
    __VdlyVal__top__DOT__regmap__v55 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regmap__v55;
    __VdlyDim0__top__DOT__regmap__v55 = 0;
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
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v43;
    __VdlySet__top__DOT__regmap__v43 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v44;
    __VdlySet__top__DOT__regmap__v44 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v45;
    __VdlySet__top__DOT__regmap__v45 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v46;
    __VdlySet__top__DOT__regmap__v46 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v47;
    __VdlySet__top__DOT__regmap__v47 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v48;
    __VdlySet__top__DOT__regmap__v48 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v49;
    __VdlySet__top__DOT__regmap__v49 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v50;
    __VdlySet__top__DOT__regmap__v50 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v51;
    __VdlySet__top__DOT__regmap__v51 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v52;
    __VdlySet__top__DOT__regmap__v52 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v53;
    __VdlySet__top__DOT__regmap__v53 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v54;
    __VdlySet__top__DOT__regmap__v54 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regmap__v55;
    __VdlySet__top__DOT__regmap__v55 = 0;
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
    __VdlySet__top__DOT__regmap__v43 = 0U;
    __VdlySet__top__DOT__regmap__v44 = 0U;
    __VdlySet__top__DOT__regmap__v45 = 0U;
    __VdlySet__top__DOT__regmap__v46 = 0U;
    __VdlySet__top__DOT__regmap__v47 = 0U;
    __VdlySet__top__DOT__regmap__v48 = 0U;
    __VdlySet__top__DOT__regmap__v49 = 0U;
    __VdlySet__top__DOT__regmap__v50 = 0U;
    __VdlySet__top__DOT__regmap__v51 = 0U;
    __VdlySet__top__DOT__regmap__v52 = 0U;
    __VdlySet__top__DOT__regmap__v53 = 0U;
    __VdlySet__top__DOT__regmap__v54 = 0U;
    __VdlySet__top__DOT__regmap__v55 = 0U;
    if (vlSelfRef.rst) {
        __Vdly__pc = 0x80000000U;
        __VdlySet__top__DOT__regmap__v0 = 1U;
    } else if (VL_ONEHOT0_Q((((QData)((IData)((0x100073U 
                                               == vlSelfRef.inst))) 
                              << 0x21U) | (((QData)((IData)(
                                                            (0x7033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelfRef.inst)))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             (((IData)(
                                                                       (0x6033U 
                                                                        == 
                                                                        (0xfe00707fU 
                                                                         & vlSelfRef.inst))) 
                                                               << 0x1fU) 
                                                              | (((IData)(
                                                                          (0x40005033U 
                                                                           == 
                                                                           (0xfe00707fU 
                                                                            & vlSelfRef.inst))) 
                                                                  << 0x1eU) 
                                                                 | (((IData)(
                                                                             (0x5033U 
                                                                              == 
                                                                              (0xfe00707fU 
                                                                               & vlSelfRef.inst))) 
                                                                     << 0x1dU) 
                                                                    | (((IData)(
                                                                                (0x4033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                        << 0x1cU) 
                                                                       | (((IData)(
                                                                                (0x3033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                           << 0x1bU) 
                                                                          | (((IData)(
                                                                                (0x2033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                              << 0x1aU) 
                                                                             | (((IData)(
                                                                                (0x1033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x19U) 
                                                                                | (((IData)(
                                                                                (0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x18U) 
                                                                                | (((IData)(
                                                                                (0x33U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x17U) 
                                                                                | (((IData)(
                                                                                (0x40005013U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x16U) 
                                                                                | (((IData)(
                                                                                (0x5013U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x15U) 
                                                                                | (((IData)(
                                                                                (0x1013U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x14U) 
                                                                                | (((IData)(
                                                                                (0x7013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x13U) 
                                                                                | (((IData)(
                                                                                (0x6013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x12U) 
                                                                                | (((IData)(
                                                                                (0x4013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x11U) 
                                                                                | (((IData)(
                                                                                (0x3013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0x10U) 
                                                                                | (((IData)(
                                                                                (0x2013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelfRef.inst))) 
                                                                                << 0xfU) 
                                                                                | (((IData)(
                                                                                (0x13U 
                                                                                == 
                                                                                (0x707fU 
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
                                                                                & vlSelfRef.inst))))))))))))))))))))))))))))))))))))))) {
        if ((0x37U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v32 = 
                    (0xfffff000U & vlSelfRef.inst);
                __VdlyDim0__top__DOT__regmap__v32 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v32 = 1U;
            }
        } else if ((0x17U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v33 = 
                    (vlSelfRef.pc + (0xfffff000U & vlSelfRef.inst));
                __VdlyDim0__top__DOT__regmap__v33 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v33 = 1U;
            }
        } else if ((0x6fU == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = (vlSelfRef.pc + (((- (IData)(
                                                      (vlSelfRef.inst 
                                                       >> 0x1fU))) 
                                           << 0x14U) 
                                          | ((0xff000U 
                                              & vlSelfRef.inst) 
                                             | ((0x800U 
                                                 & (vlSelfRef.inst 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlSelfRef.inst 
                                                      >> 0x14U))))));
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
                                         + vlSelfRef.top__DOT__immI));
        } else if ((IData)((0x63U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           == vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x1063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           != vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x4063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = (VL_LTS_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x5063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = (VL_GTES_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x6063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           < vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((IData)((0x7063U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((vlSelfRef.top__DOT__rs1_s 
                           >= vlSelfRef.top__DOT__rs2_val)
                           ? (vlSelfRef.pc + vlSelfRef.top__DOT__immB)
                           : ((IData)(4U) + vlSelfRef.pc));
        } else if ((3U == (0x7fU & vlSelfRef.inst))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __Vfunc_top__DOT__Mr__0__funct_3 = 
                    (7U & (vlSelfRef.inst >> 0xcU));
                __Vfunc_top__DOT__Mr__0__Mr_addr = 
                    (vlSelfRef.top__DOT__rs1_s + vlSelfRef.top__DOT__immI);
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
                        VL_FINISH_MT("top.v", 54, "");
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
                        VL_FINISH_MT("top.v", 54, "");
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
                                                                   + vlSelfRef.top__DOT__immS), vlSelfRef.top__DOT__rs2_val, 1U);
        } else if ((IData)((0x1023U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(
                                                                  (vlSelfRef.top__DOT__rs1_s 
                                                                   + vlSelfRef.top__DOT__immS), vlSelfRef.top__DOT__rs2_val, 2U);
        } else if ((IData)((0x2023U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(
                                                                  (vlSelfRef.top__DOT__rs1_s 
                                                                   + vlSelfRef.top__DOT__immS), vlSelfRef.top__DOT__rs2_val, 4U);
        } else if ((IData)((0x13U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v37 = 
                    (vlSelfRef.top__DOT__rs1_s + vlSelfRef.top__DOT__immI);
                __VdlyDim0__top__DOT__regmap__v37 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v37 = 1U;
            }
        } else if ((IData)((0x2013U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v38 = 
                    (VL_LTS_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__immI)
                      ? 1U : 0U);
                __VdlyDim0__top__DOT__regmap__v38 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v38 = 1U;
            }
        } else if ((IData)((0x3013U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v39 = 
                    ((vlSelfRef.top__DOT__rs1_s < vlSelfRef.top__DOT__immI)
                      ? 1U : 0U);
                __VdlyDim0__top__DOT__regmap__v39 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v39 = 1U;
            }
        } else if ((IData)((0x4013U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v40 = 
                    (vlSelfRef.top__DOT__rs1_s ^ vlSelfRef.top__DOT__immI);
                __VdlyDim0__top__DOT__regmap__v40 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v40 = 1U;
            }
        } else if ((IData)((0x6013U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v41 = 
                    (vlSelfRef.top__DOT__rs1_s | vlSelfRef.top__DOT__immI);
                __VdlyDim0__top__DOT__regmap__v41 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v41 = 1U;
            }
        } else if ((IData)((0x7013U == (0x707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v42 = 
                    (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__immI);
                __VdlyDim0__top__DOT__regmap__v42 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v42 = 1U;
            }
        } else if ((IData)((0x1013U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v43 = 
                    (vlSelfRef.top__DOT__rs1_s << (0x1fU 
                                                   & (vlSelfRef.inst 
                                                      >> 0x14U)));
                __VdlyDim0__top__DOT__regmap__v43 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v43 = 1U;
            }
        } else if ((IData)((0x5013U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v44 = 
                    (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                                   & (vlSelfRef.inst 
                                                      >> 0x14U)));
                __VdlyDim0__top__DOT__regmap__v44 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v44 = 1U;
            }
        } else if ((IData)((0x40005013U == (0xfe00707fU 
                                            & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v45 = 
                    VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__rs1_s, 
                                   (0x1fU & (vlSelfRef.inst 
                                             >> 0x14U)));
                __VdlyDim0__top__DOT__regmap__v45 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v45 = 1U;
            }
        } else if ((IData)((0x33U == (0xfe00707fU & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v46 = 
                    (vlSelfRef.top__DOT__rs1_s + vlSelfRef.top__DOT__rs2_val);
                __VdlyDim0__top__DOT__regmap__v46 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v46 = 1U;
            }
        } else if ((IData)((0x40000033U == (0xfe00707fU 
                                            & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v47 = 
                    (vlSelfRef.top__DOT__rs1_s - vlSelfRef.top__DOT__rs2_val);
                __VdlyDim0__top__DOT__regmap__v47 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v47 = 1U;
            }
        } else if ((IData)((0x1033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v48 = 
                    (vlSelfRef.top__DOT__rs1_s << (0x1fU 
                                                   & vlSelfRef.top__DOT__rs2_val));
                __VdlyDim0__top__DOT__regmap__v48 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v48 = 1U;
            }
        } else if ((IData)((0x2033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v49 = 
                    (VL_LTS_III(32, vlSelfRef.top__DOT__rs1_s, vlSelfRef.top__DOT__rs2_val)
                      ? 1U : 0U);
                __VdlyDim0__top__DOT__regmap__v49 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v49 = 1U;
            }
        } else if ((IData)((0x3033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v50 = 
                    ((vlSelfRef.top__DOT__rs1_s < vlSelfRef.top__DOT__rs2_val)
                      ? 1U : 0U);
                __VdlyDim0__top__DOT__regmap__v50 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v50 = 1U;
            }
        } else if ((IData)((0x4033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v51 = 
                    (vlSelfRef.top__DOT__rs1_s ^ vlSelfRef.top__DOT__rs2_val);
                __VdlyDim0__top__DOT__regmap__v51 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v51 = 1U;
            }
        } else if ((IData)((0x5033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v52 = 
                    (vlSelfRef.top__DOT__rs1_s >> (0x1fU 
                                                   & vlSelfRef.top__DOT__rs2_val));
                __VdlyDim0__top__DOT__regmap__v52 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v52 = 1U;
            }
        } else if ((IData)((0x40005033U == (0xfe00707fU 
                                            & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v53 = 
                    VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__rs1_s, 
                                   (0x1fU & vlSelfRef.top__DOT__rs2_val));
                __VdlyDim0__top__DOT__regmap__v53 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v53 = 1U;
            }
        } else if ((IData)((0x6033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v54 = 
                    (vlSelfRef.top__DOT__rs1_s | vlSelfRef.top__DOT__rs2_val);
                __VdlyDim0__top__DOT__regmap__v54 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v54 = 1U;
            }
        } else if ((IData)((0x7033U == (0xfe00707fU 
                                        & vlSelfRef.inst)))) {
            __Vdly__pc = ((IData)(4U) + vlSelfRef.pc);
            if ((0U != (0x1fU & (vlSelfRef.inst >> 7U)))) {
                __VdlyVal__top__DOT__regmap__v55 = 
                    (vlSelfRef.top__DOT__rs1_s & vlSelfRef.top__DOT__rs2_val);
                __VdlyDim0__top__DOT__regmap__v55 = 
                    (0x1fU & (vlSelfRef.inst >> 7U));
                __VdlySet__top__DOT__regmap__v55 = 1U;
            }
        } else if (VL_LIKELY((0x100073U == vlSelfRef.inst))) {
            Vtop___024root____Vdpiimwrap_top__DOT__ebreak_TOP();
        } else {
            VL_WRITEF_NX("invalid instruction 0x%08x: 0x%08x\n",0,
                         32,vlSelfRef.pc,32,vlSelfRef.inst);
            VL_FINISH_MT("top.v", 240, "");
        }
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
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v42] 
            = __VdlyVal__top__DOT__regmap__v42;
    }
    if (__VdlySet__top__DOT__regmap__v43) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v43] 
            = __VdlyVal__top__DOT__regmap__v43;
    }
    if (__VdlySet__top__DOT__regmap__v44) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v44] 
            = __VdlyVal__top__DOT__regmap__v44;
    }
    if (__VdlySet__top__DOT__regmap__v45) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v45] 
            = __VdlyVal__top__DOT__regmap__v45;
    }
    if (__VdlySet__top__DOT__regmap__v46) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v46] 
            = __VdlyVal__top__DOT__regmap__v46;
    }
    if (__VdlySet__top__DOT__regmap__v47) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v47] 
            = __VdlyVal__top__DOT__regmap__v47;
    }
    if (__VdlySet__top__DOT__regmap__v48) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v48] 
            = __VdlyVal__top__DOT__regmap__v48;
    }
    if (__VdlySet__top__DOT__regmap__v49) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v49] 
            = __VdlyVal__top__DOT__regmap__v49;
    }
    if (__VdlySet__top__DOT__regmap__v50) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v50] 
            = __VdlyVal__top__DOT__regmap__v50;
    }
    if (__VdlySet__top__DOT__regmap__v51) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v51] 
            = __VdlyVal__top__DOT__regmap__v51;
    }
    if (__VdlySet__top__DOT__regmap__v52) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v52] 
            = __VdlyVal__top__DOT__regmap__v52;
    }
    if (__VdlySet__top__DOT__regmap__v53) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v53] 
            = __VdlyVal__top__DOT__regmap__v53;
    }
    if (__VdlySet__top__DOT__regmap__v54) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v54] 
            = __VdlyVal__top__DOT__regmap__v54;
    }
    if (__VdlySet__top__DOT__regmap__v55) {
        vlSelfRef.top__DOT__regmap[__VdlyDim0__top__DOT__regmap__v55] 
            = __VdlyVal__top__DOT__regmap__v55;
    }
    vlSelfRef.top__DOT__rs2_val = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0x14U))];
    vlSelfRef.top__DOT__rs1_s = vlSelfRef.top__DOT__regmap
        [(0x1fU & (vlSelfRef.inst >> 0xfU))];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
