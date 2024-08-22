// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__imm),32);
        bufp->chgCData(oldp+1,(vlSelfRef.top__DOT__csr_reg),5);
        bufp->chgCData(oldp+2,(vlSelfRef.top__DOT__alu_c),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__rs1_s),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__rs2_val),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__alu_2),32);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__alu_3),32);
        bufp->chgQData(oldp+7,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t),34);
        bufp->chgQData(oldp+9,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB),33);
        bufp->chgQData(oldp+11,(((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                                 << 1U)),33);
        bufp->chgIData(oldp+13,((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                         >> 1U))),32);
        bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res));
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res),32);
        bufp->chgCData(oldp+16,((0x1fU & vlSelfRef.top__DOT__alu_2)),5);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__regmap[0]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__regmap[1]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__regmap[2]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__regmap[3]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__regmap[4]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__regmap[5]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__regmap[6]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__regmap[7]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__regmap[8]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__regmap[9]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__regmap[10]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__regmap[11]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__regmap[12]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__regmap[13]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__regmap[14]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__regmap[15]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__regmap[16]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__regmap[17]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__regmap[18]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__regmap[19]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__regmap[20]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__regmap[21]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__regmap[22]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__regmap[23]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__regmap[24]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__regmap[25]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__regmap[26]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__regmap[27]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__regmap[28]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__regmap[29]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__regmap[30]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__regmap[31]),32);
    }
    bufp->chgBit(oldp+50,(vlSelfRef.clk));
    bufp->chgBit(oldp+51,(vlSelfRef.rst));
    bufp->chgIData(oldp+52,(vlSelfRef.inst),32);
    bufp->chgIData(oldp+53,(vlSelfRef.pc),32);
    bufp->chgCData(oldp+54,((0x1fU & (vlSelfRef.inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+55,((0x1fU & (vlSelfRef.inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+56,((0x1fU & (vlSelfRef.inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+57,((0x7fU & vlSelfRef.inst)),7);
    bufp->chgCData(oldp+58,((7U & (vlSelfRef.inst >> 0xcU))),3);
    bufp->chgCData(oldp+59,((vlSelfRef.inst >> 0x19U)),7);
    bufp->chgQData(oldp+60,((1ULL | ((QData)((IData)(
                                                     vlSelfRef.top__DOT__regmap
                                                     [
                                                     (0x1fU 
                                                      & (vlSelfRef.inst 
                                                         >> 0xfU))])) 
                                     << 1U))),33);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
