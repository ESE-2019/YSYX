// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb___024root.h"

VL_ATTR_COLD void Varb___024root___eval_static(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Varb___024root___eval_initial(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Varb___024root___eval_final(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__stl(Varb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Varb___024root___eval_phase__stl(Varb___024root* vlSelf);

VL_ATTR_COLD void Varb___024root___eval_settle(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Varb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Varb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__stl(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Varb___024root___stl_sequent__TOP__0(Varb___024root* vlSelf);
VL_ATTR_COLD void Varb___024root____Vm_traceActivitySetAll(Varb___024root* vlSelf);

VL_ATTR_COLD void Varb___024root___eval_stl(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Varb___024root___stl_sequent__TOP__0(vlSelf);
        Varb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Varb___024root___eval_triggers__stl(Varb___024root* vlSelf);

VL_ATTR_COLD bool Varb___024root___eval_phase__stl(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Varb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Varb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__act(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__nba(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Varb___024root____Vm_traceActivitySetAll(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root____Vm_traceActivitySetAll\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Varb___024root___ctor_var_reset(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->top__DOT__sram__DOT__mtime = 0;
    vlSelf->top__DOT__sram__DOT__dout = 0;
    vlSelf->top__DOT__CORE__DOT__we = 0;
    vlSelf->top__DOT__CORE__DOT__rd = 0;
    vlSelf->top__DOT__CORE__DOT__wdata = 0;
    vlSelf->top__DOT__CORE__DOT__rs1_val = 0;
    vlSelf->top__DOT__CORE__DOT__rs2_val = 0;
    vlSelf->top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__CORE__DOT__REG__DOT__regfile[__Vi0] = 0;
    }
    vlSelf->top__DOT__CORE__DOT__IFU__DOT__pc = 0;
    vlSelf->top__DOT__CORE__DOT__IFU__DOT__curr = 0;
    vlSelf->top__DOT__CORE__DOT__IFU__DOT__next = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__curr = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__next = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__imm = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__alu_src2 = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0;
    vlSelf->top__DOT__CORE__DOT__IDU__DOT__alu_set = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__curr = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__next = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__alu_out = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__alu_res = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__branch = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->top__DOT__CORE__DOT__LSU__DOT__curr = 0;
    vlSelf->top__DOT__CORE__DOT__LSU__DOT__next = 0;
    vlSelf->top__DOT__CORE__DOT__LSU__DOT__alu_res = 0;
    vlSelf->top__DOT__CORE__DOT__LSU__DOT__ldata = 0;
    vlSelf->top__DOT__CORE__DOT__LSU__DOT__rshamt = 0;
    vlSelf->top__DOT__CORE__DOT__WBU__DOT__curr = 0;
    vlSelf->top__DOT__CORE__DOT__WBU__DOT__next = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
