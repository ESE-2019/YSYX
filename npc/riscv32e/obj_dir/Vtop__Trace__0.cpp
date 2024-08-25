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
        bufp->chgCData(oldp+0,(vlSelfRef.top__DOT__arb__DOT__arbiter_state),2);
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__sram__DOT__en));
        bufp->chgBit(oldp+2,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
        bufp->chgBit(oldp+3,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
        bufp->chgBit(oldp+4,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid))));
        bufp->chgCData(oldp+5,(vlSymsp->TOP__top__DOT__axi_sram.bresp),2);
        bufp->chgBit(oldp+6,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
        bufp->chgCData(oldp+7,(vlSymsp->TOP__top__DOT__axi_sram.rresp),2);
        bufp->chgBit(oldp+8,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
        bufp->chgBit(oldp+9,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                              & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
        bufp->chgBit(oldp+10,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                               & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__top__DOT__axi_sram.awready));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__top__DOT__axi_sram.wready));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__top__DOT__axi_sram.arready));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgIData(oldp+16,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                  ? vlSymsp->TOP__top__DOT__axi_ifu.awaddr
                                  : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                      ? vlSymsp->TOP__top__DOT__axi_lsu.awaddr
                                      : 0U))),32);
        bufp->chgIData(oldp+17,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                  ? vlSymsp->TOP__top__DOT__axi_ifu.wdata
                                  : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                      ? vlSymsp->TOP__top__DOT__axi_lsu.wdata
                                      : 0U))),32);
        bufp->chgCData(oldp+18,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                  ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wstrb)
                                  : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                      ? (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wstrb)
                                      : 0U))),4);
        bufp->chgBit(oldp+19,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid)
                                : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid)))));
        bufp->chgIData(oldp+20,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                  ? vlSelfRef.top__DOT__pc
                                  : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                      ? vlSymsp->TOP__top__DOT__axi_lsu.araddr
                                      : 0U))),32);
        bufp->chgBit(oldp+21,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.rready)
                                : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                   & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.rready)))));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__inst),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__pc),32);
        bufp->chgCData(oldp+24,((0x1fU & (vlSelfRef.top__DOT__inst 
                                          >> 7U))),5);
        bufp->chgCData(oldp+25,((0x1fU & (vlSelfRef.top__DOT__inst 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+26,((0x1fU & (vlSelfRef.top__DOT__inst 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__regmap[0]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__regmap[1]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__regmap[2]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__regmap[3]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__regmap[4]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__regmap[5]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__regmap[6]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__regmap[7]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__regmap[8]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__regmap[9]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__regmap[10]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__regmap[11]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__regmap[12]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__regmap[13]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__regmap[14]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__regmap[15]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__regmap[16]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top__DOT__regmap[17]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__regmap[18]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.top__DOT__regmap[19]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.top__DOT__regmap[20]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__regmap[21]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__regmap[22]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__regmap[23]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__regmap[24]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__regmap[25]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__regmap[26]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__regmap[27]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__regmap[28]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__regmap[29]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__regmap[30]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__regmap[31]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__rs1_val),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__rs2_val),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__imm),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__mem_addr),32);
        bufp->chgCData(oldp+63,((0x7fU & vlSelfRef.top__DOT__inst)),7);
        bufp->chgCData(oldp+64,((7U & (vlSelfRef.top__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+65,(vlSelfRef.top__DOT__csr_reg),5);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__alu_1),32);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__alu_2),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__alu_3),32);
        bufp->chgCData(oldp+69,(vlSelfRef.top__DOT__alu_c),4);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__alu_out),32);
        bufp->chgBit(oldp+71,((0U != vlSelfRef.top__DOT__alu_3)));
        bufp->chgBit(oldp+72,(vlSelfRef.top__DOT__iv));
        bufp->chgBit(oldp+73,(vlSelfRef.top__DOT__ir));
        bufp->chgBit(oldp+74,(vlSelfRef.top__DOT__dv));
        bufp->chgBit(oldp+75,(vlSelfRef.top__DOT__dr));
        bufp->chgBit(oldp+76,(vlSelfRef.top__DOT__lr));
        bufp->chgBit(oldp+77,(vlSelfRef.top__DOT__lv));
        bufp->chgCData(oldp+78,(vlSelfRef.top__DOT__ic),2);
        bufp->chgCData(oldp+79,(vlSelfRef.top__DOT__lc),2);
        bufp->chgQData(oldp+80,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t),34);
        bufp->chgQData(oldp+82,((1ULL | ((QData)((IData)(vlSelfRef.top__DOT__alu_1)) 
                                         << 1U))),33);
        bufp->chgQData(oldp+84,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB),33);
        bufp->chgQData(oldp+86,(((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                                 << 1U)),33);
        bufp->chgIData(oldp+88,((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                         >> 1U))),32);
        bufp->chgBit(oldp+89,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res));
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res),32);
        bufp->chgCData(oldp+91,((0x1fU & vlSelfRef.top__DOT__alu_2)),5);
        bufp->chgIData(oldp+92,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res),32);
        bufp->chgBit(oldp+93,(vlSymsp->TOP__top__DOT__axi_ifu.arvalid));
        bufp->chgBit(oldp+94,(vlSymsp->TOP__top__DOT__axi_ifu.rready));
        bufp->chgBit(oldp+95,(vlSymsp->TOP__top__DOT__axi_lsu.awvalid));
        bufp->chgIData(oldp+96,(vlSymsp->TOP__top__DOT__axi_lsu.awaddr),32);
        bufp->chgBit(oldp+97,(vlSymsp->TOP__top__DOT__axi_lsu.wvalid));
        bufp->chgIData(oldp+98,(vlSymsp->TOP__top__DOT__axi_lsu.wdata),32);
        bufp->chgCData(oldp+99,(vlSymsp->TOP__top__DOT__axi_lsu.wstrb),4);
        bufp->chgBit(oldp+100,(vlSymsp->TOP__top__DOT__axi_lsu.bready));
        bufp->chgBit(oldp+101,(vlSymsp->TOP__top__DOT__axi_lsu.arvalid));
        bufp->chgIData(oldp+102,(vlSymsp->TOP__top__DOT__axi_lsu.araddr),32);
        bufp->chgBit(oldp+103,(vlSymsp->TOP__top__DOT__axi_lsu.rready));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+104,(vlSymsp->TOP__top__DOT__axi_ifu.rvalid));
        bufp->chgIData(oldp+105,(vlSymsp->TOP__top__DOT__axi_sram.rdata),32);
        bufp->chgBit(oldp+106,(vlSymsp->TOP__top__DOT__axi_lsu.bvalid));
        bufp->chgBit(oldp+107,(vlSymsp->TOP__top__DOT__axi_lsu.rvalid));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__ldata),32);
        bufp->chgBit(oldp+109,(vlSymsp->TOP__top__DOT__axi_sram.awvalid));
        bufp->chgBit(oldp+110,(vlSymsp->TOP__top__DOT__axi_sram.wvalid));
        bufp->chgBit(oldp+111,(vlSymsp->TOP__top__DOT__axi_sram.bready));
    }
    bufp->chgBit(oldp+112,(vlSelfRef.clk));
    bufp->chgBit(oldp+113,(vlSelfRef.rst));
    bufp->chgCData(oldp+114,(((0U == (IData)(vlSelfRef.top__DOT__ic))
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
                                                   : 0U)))),2);
    bufp->chgCData(oldp+115,(vlSelfRef.top__DOT__dc),2);
    bufp->chgCData(oldp+116,(((0U == (IData)(vlSelfRef.top__DOT__dc))
                               ? ((IData)(vlSelfRef.top__DOT__iv)
                                   ? 1U : 0U) : (((1U 
                                                   == (IData)(vlSelfRef.top__DOT__dc)) 
                                                  || (2U 
                                                      == (IData)(vlSelfRef.top__DOT__dc)))
                                                  ? 
                                                 ((IData)(vlSelfRef.top__DOT__lr)
                                                   ? 0U
                                                   : 2U)
                                                  : 0U))),2);
    bufp->chgCData(oldp+117,(((0U == (IData)(vlSelfRef.top__DOT__lc))
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
                                        ? 0U : 2U) : 0U)))),2);
    bufp->chgCData(oldp+118,(vlSelfRef.top__DOT__rshamt),5);
    bufp->chgBit(oldp+119,(vlSymsp->TOP__top__DOT__axi_ifu.aresetn));
    bufp->chgBit(oldp+120,((1U & (~ (IData)(vlSelfRef.rst)))));
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
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
