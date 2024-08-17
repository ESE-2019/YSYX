// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+37,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+37,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+42,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("regmap", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1,0,"immI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"immU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"immS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"immJ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"immB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"rs1_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"rs2_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"rs1_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"rs2_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"immIs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+49,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+50,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+43,0,"shamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"csr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__immI),32);
    bufp->fullIData(oldp+2,(vlSelfRef.top__DOT__immS),32);
    bufp->fullIData(oldp+3,(vlSelfRef.top__DOT__immB),32);
    bufp->fullCData(oldp+4,(vlSelfRef.top__DOT__csr_reg),5);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__regmap[0]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__regmap[1]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.top__DOT__regmap[2]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.top__DOT__regmap[3]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__regmap[4]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__regmap[5]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__regmap[6]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__regmap[7]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.top__DOT__regmap[8]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.top__DOT__regmap[9]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.top__DOT__regmap[10]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__regmap[11]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__regmap[12]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__regmap[13]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.top__DOT__regmap[14]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.top__DOT__regmap[15]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__regmap[16]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__regmap[17]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__regmap[18]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__regmap[19]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__regmap[20]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__regmap[21]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__regmap[22]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__regmap[23]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__regmap[24]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__regmap[25]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__regmap[26]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__regmap[27]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__regmap[28]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__regmap[29]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.top__DOT__regmap[30]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__regmap[31]),32);
    bufp->fullBit(oldp+37,(vlSelfRef.clk));
    bufp->fullBit(oldp+38,(vlSelfRef.rst));
    bufp->fullIData(oldp+39,(vlSelfRef.inst),32);
    bufp->fullIData(oldp+40,(vlSelfRef.pc),32);
    bufp->fullCData(oldp+41,((0x1fU & (vlSelfRef.inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelfRef.inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+43,((0x1fU & (vlSelfRef.inst 
                                       >> 0x14U))),5);
    bufp->fullIData(oldp+44,((0xfffff000U & vlSelfRef.inst)),32);
    bufp->fullIData(oldp+45,((((- (IData)((vlSelfRef.inst 
                                           >> 0x1fU))) 
                               << 0x14U) | ((0xff000U 
                                             & vlSelfRef.inst) 
                                            | ((0x800U 
                                                & (vlSelfRef.inst 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlSelfRef.inst 
                                                     >> 0x14U)))))),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__rs1_s),32);
    bufp->fullIData(oldp+47,(vlSelfRef.top__DOT__rs2_val),32);
    bufp->fullCData(oldp+48,((0x7fU & vlSelfRef.inst)),7);
    bufp->fullCData(oldp+49,((7U & (vlSelfRef.inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+50,((vlSelfRef.inst >> 0x19U)),7);
}
