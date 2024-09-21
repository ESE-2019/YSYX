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
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__CORE__DOT__we));
        bufp->chgCData(oldp+1,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+2,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+3,(vlSelfRef.top__DOT__CORE__DOT__rd),5);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__CORE__DOT__wdata),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__CORE__DOT__rs1_val),32);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__CORE__DOT__rs2_val),32);
        bufp->chgCData(oldp+7,(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state),2);
        bufp->chgCData(oldp+8,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr),2);
        bufp->chgCData(oldp+9,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next),2);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res),32);
        bufp->chgBit(oldp+12,((0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out)));
        bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__branch));
        bufp->chgIData(oldp+14,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1),32);
        bufp->chgIData(oldp+15,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2),32);
        bufp->chgCData(oldp+16,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl),4);
        bufp->chgQData(oldp+17,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t),34);
        bufp->chgQData(oldp+19,((1ULL | ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1)) 
                                         << 1U))),33);
        bufp->chgQData(oldp+21,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB),33);
        bufp->chgQData(oldp+23,(((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                                 << 1U)),33);
        bufp->chgIData(oldp+25,((IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                         >> 1U))),32);
        bufp->chgBit(oldp+26,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res));
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res),32);
        bufp->chgCData(oldp+28,((0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)),5);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i),32);
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr),2);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next),2);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm),32);
        bufp->chgCData(oldp+36,((0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)),7);
        bufp->chgCData(oldp+37,((7U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+38,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                          >> 7U))),5);
        bufp->chgIData(oldp+39,(((0x40U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                  ? ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                      ? ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                          ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                                          : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                              ? ((2U 
                                                  & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                   ? vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc
                                                   : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                                  : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                              : vlSelfRef.top__DOT__CORE__DOT__rs1_val))
                                      : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                  : ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                      ? ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                          ? ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                              ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                                              : ((4U 
                                                  & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                  ? 
                                                 ((2U 
                                                   & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                   ? 
                                                  ((1U 
                                                    & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                    ? 0U
                                                    : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                                   : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                                  : vlSelfRef.top__DOT__CORE__DOT__rs1_val))
                                          : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                      : ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                          ? ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                              ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                                              : ((4U 
                                                  & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                  ? 
                                                 ((2U 
                                                   & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                   ? 
                                                  ((1U 
                                                    & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                                    ? vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc
                                                    : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                                   : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                                  : vlSelfRef.top__DOT__CORE__DOT__rs1_val))
                                          : vlSelfRef.top__DOT__CORE__DOT__rs1_val)))),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2),32);
        bufp->chgCData(oldp+41,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl),4);
        bufp->chgCData(oldp+42,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_set),2);
        bufp->chgIData(oldp+43,(((0x67U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))
                                  ? (0xfffffffeU & 
                                     (vlSelfRef.top__DOT__CORE__DOT__rs1_val 
                                      + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm))
                                  : (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc 
                                     + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm))),32);
        bufp->chgIData(oldp+44,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc),32);
        bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr),2);
        bufp->chgCData(oldp+47,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next),2);
        bufp->chgCData(oldp+48,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr),2);
        bufp->chgCData(oldp+49,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next),2);
        bufp->chgCData(oldp+50,(((2U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                                  ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                                      ? 0x18U : 0x10U)
                                  : ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                                      ? 8U : 0U))),5);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[1]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[2]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[3]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[4]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[5]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[6]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[7]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[8]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[9]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[10]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[11]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[12]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[13]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[14]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[15]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[16]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[17]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[18]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[19]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[20]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[21]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[22]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[23]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[24]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[25]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[26]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[27]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[28]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[29]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[30]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[31]),32);
        bufp->chgCData(oldp+83,(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr),2);
        bufp->chgCData(oldp+84,(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__next),2);
        bufp->chgQData(oldp+85,(vlSelfRef.top__DOT__sram__DOT__mtime),64);
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__sram__DOT__dout),32);
        bufp->chgBit(oldp+88,(vlSymsp->TOP__top__DOT__axi_sram.awready));
        bufp->chgBit(oldp+89,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awvalid)
                                : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid)))));
        bufp->chgIData(oldp+90,(vlSymsp->TOP__top__DOT__axi_sram.awaddr),32);
        bufp->chgBit(oldp+91,(vlSymsp->TOP__top__DOT__axi_sram.wready));
        bufp->chgBit(oldp+92,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wvalid)
                                : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid)))));
        bufp->chgIData(oldp+93,(vlSymsp->TOP__top__DOT__axi_sram.wdata),32);
        bufp->chgCData(oldp+94,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                  ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wstrb)
                                  : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                      ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb)
                                      : 0U))),4);
        bufp->chgBit(oldp+95,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bready)
                                : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready)))));
        bufp->chgBit(oldp+96,(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
        bufp->chgCData(oldp+97,(vlSymsp->TOP__top__DOT__axi_sram.bresp),2);
        bufp->chgBit(oldp+98,(vlSymsp->TOP__top__DOT__axi_sram.arready));
        bufp->chgBit(oldp+99,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid)
                                : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid)))));
        bufp->chgIData(oldp+100,(vlSymsp->TOP__top__DOT__axi_sram.araddr),32);
        bufp->chgBit(oldp+101,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                 ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready)
                                 : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                    & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready)))));
        bufp->chgBit(oldp+102,(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
        bufp->chgCData(oldp+103,(vlSymsp->TOP__top__DOT__axi_sram.rresp),2);
        bufp->chgIData(oldp+104,(vlSymsp->TOP__top__DOT__axi_sram.rdata),32);
        bufp->chgBit(oldp+105,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
        bufp->chgBit(oldp+106,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
        bufp->chgBit(oldp+107,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid))));
        bufp->chgBit(oldp+108,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
        bufp->chgBit(oldp+109,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid));
        bufp->chgBit(oldp+110,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready));
        bufp->chgBit(oldp+111,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid));
        bufp->chgBit(oldp+112,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
        bufp->chgBit(oldp+113,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid));
        bufp->chgIData(oldp+114,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr),32);
        bufp->chgBit(oldp+115,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
        bufp->chgBit(oldp+116,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid));
        bufp->chgIData(oldp+117,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata),32);
        bufp->chgCData(oldp+118,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb),4);
        bufp->chgBit(oldp+119,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid));
        bufp->chgBit(oldp+121,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid));
        bufp->chgIData(oldp+123,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr),32);
        bufp->chgBit(oldp+124,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready));
        bufp->chgBit(oldp+125,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid));
        bufp->chgBit(oldp+126,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid));
        bufp->chgBit(oldp+127,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready));
        bufp->chgIData(oldp+128,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc),32);
        bufp->chgBit(oldp+129,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid));
        bufp->chgBit(oldp+130,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready));
        bufp->chgIData(oldp+131,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.imm),32);
        bufp->chgIData(oldp+132,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.dnpc),32);
        bufp->chgIData(oldp+133,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.sdata),32);
        bufp->chgCData(oldp+134,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set),2);
        bufp->chgCData(oldp+135,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.rd_addr),5);
        bufp->chgCData(oldp+136,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.funct3),3);
        bufp->chgBit(oldp+137,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.load));
        bufp->chgBit(oldp+138,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.store));
        bufp->chgBit(oldp+139,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.wb));
        bufp->chgBit(oldp+140,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.jump));
        bufp->chgBit(oldp+141,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch));
        bufp->chgBit(oldp+142,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid));
        bufp->chgBit(oldp+143,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready));
        bufp->chgIData(oldp+144,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.dnpc),32);
        bufp->chgIData(oldp+145,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.sdata),32);
        bufp->chgIData(oldp+146,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res),32);
        bufp->chgCData(oldp+147,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.rd_addr),5);
        bufp->chgCData(oldp+148,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3),3);
        bufp->chgBit(oldp+149,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load));
        bufp->chgBit(oldp+150,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store));
        bufp->chgBit(oldp+151,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.wb));
        bufp->chgBit(oldp+152,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.jump));
        bufp->chgBit(oldp+153,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.branch));
        bufp->chgBit(oldp+154,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid));
        bufp->chgBit(oldp+155,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready));
        bufp->chgIData(oldp+156,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.dnpc),32);
        bufp->chgIData(oldp+157,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_res),32);
        bufp->chgCData(oldp+158,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.rd_addr),5);
        bufp->chgBit(oldp+159,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.wb));
        bufp->chgBit(oldp+160,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.jump));
        bufp->chgBit(oldp+161,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.branch));
        bufp->chgBit(oldp+162,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid));
        bufp->chgBit(oldp+163,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready));
        bufp->chgIData(oldp+164,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.dnpc),32);
        bufp->chgBit(oldp+165,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.jump));
        bufp->chgBit(oldp+166,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.branch));
    }
    bufp->chgBit(oldp+167,(vlSelfRef.clk));
    bufp->chgBit(oldp+168,(vlSelfRef.rst));
    bufp->chgBit(oldp+169,((1U & (~ (IData)(vlSelfRef.rst)))));
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
}
