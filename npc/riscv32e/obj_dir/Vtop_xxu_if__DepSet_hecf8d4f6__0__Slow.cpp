// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_xxu_if.h"

VL_ATTR_COLD void Vtop_xxu_if___ctor_var_reset(Vtop_xxu_if* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_xxu_if___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->valid = 0;
    vlSelf->ready = 0;
    vlSelf->pc = 0;
    vlSelf->inst = 0;
    vlSelf->imm = 0;
    vlSelf->dnpc = 0;
    vlSelf->sdata = 0;
    vlSelf->alu_src1 = 0;
    vlSelf->alu_src2 = 0;
    vlSelf->alu_ctrl = 0;
    vlSelf->alu_set = 0;
    vlSelf->alu_res = 0;
    vlSelf->rd_addr = 0;
    vlSelf->funct3 = 0;
    vlSelf->load = 0;
    vlSelf->store = 0;
    vlSelf->wb = 0;
    vlSelf->jump = 0;
    vlSelf->branch = 0;
}
