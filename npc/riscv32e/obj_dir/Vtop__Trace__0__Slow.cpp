// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_ifu__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_lsu__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+116,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+116,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+27,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("regmap", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+28+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+60,0,"rs1_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"rs2_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"mem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+65,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"csr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+67,0,"alu_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"alu_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"alu_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+125,0,"B_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+126,0,"I_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+127,0,"R_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+128,0,"Jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+129,0,"Jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+71,0,"alu_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"not_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi_ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_sram", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+73,0,"iv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"ir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"dv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"dr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"ev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"er",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"lv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"lr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"ic",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+118,0,"in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+119,0,"dc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+120,0,"dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+80,0,"lc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+121,0,"ln",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+130,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+131,0,"EXEC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+132,0,"WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+133,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+122,0,"rshamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+112,0,"ldata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("Imm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("axi_0", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_1", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("out", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+1,0,"arbiter_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+130,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+131,0,"M0_ACTIVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+132,0,"M1_ACTIVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("axi", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+2,0,"en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ysyx_24080006_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+67,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"ctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+69,0,"res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+135,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+136,0,"SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+137,0,"SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+138,0,"SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+139,0,"XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+140,0,"SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+141,0,"SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+142,0,"OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+143,0,"AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declQuad(c+81,0,"add_res_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+83,0,"srcA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+85,0,"srcB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+87,0,"srcB_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+89,0,"add_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+90,0,"comp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"shift_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+93,0,"shift_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"bit_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+95,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+96,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_ifu__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_ifu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+116,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+145,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+147,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+148,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+149,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+4,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+151,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+153,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+155,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+7,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+157,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+158,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+159,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+98,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+109,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+160,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_lsu__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_lsu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+116,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+163,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+165,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+10,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+166,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+167,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+11,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+169,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+170,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+171,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+107,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+109,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+172,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__axi_sram__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+116,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+175,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+176,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+177,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+13,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+178,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+179,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+15,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+181,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+182,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+183,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+22,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+109,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+184,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+185,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
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

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+125,(0x63U),7);
    bufp->fullCData(oldp+126,(0x13U),7);
    bufp->fullCData(oldp+127,(0x33U),7);
    bufp->fullCData(oldp+128,(0x6fU),7);
    bufp->fullCData(oldp+129,(0x67U),7);
    bufp->fullCData(oldp+130,(0U),2);
    bufp->fullCData(oldp+131,(1U),2);
    bufp->fullCData(oldp+132,(2U),2);
    bufp->fullCData(oldp+133,(vlSelfRef.top__DOT__wstrb),4);
    bufp->fullCData(oldp+134,(0U),4);
    bufp->fullCData(oldp+135,(8U),4);
    bufp->fullCData(oldp+136,(1U),4);
    bufp->fullCData(oldp+137,(2U),4);
    bufp->fullCData(oldp+138,(3U),4);
    bufp->fullCData(oldp+139,(4U),4);
    bufp->fullCData(oldp+140,(5U),4);
    bufp->fullCData(oldp+141,(0xdU),4);
    bufp->fullCData(oldp+142,(6U),4);
    bufp->fullCData(oldp+143,(7U),4);
    bufp->fullBit(oldp+144,(vlSymsp->TOP__top__DOT__axi_ifu.awvalid));
    bufp->fullIData(oldp+145,(vlSymsp->TOP__top__DOT__axi_ifu.awaddr),32);
    bufp->fullCData(oldp+146,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__awid),4);
    bufp->fullCData(oldp+147,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__awlen),8);
    bufp->fullCData(oldp+148,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__awsize),3);
    bufp->fullCData(oldp+149,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__awburst),2);
    bufp->fullBit(oldp+150,(vlSymsp->TOP__top__DOT__axi_ifu.wvalid));
    bufp->fullIData(oldp+151,(vlSymsp->TOP__top__DOT__axi_ifu.wdata),32);
    bufp->fullCData(oldp+152,(vlSymsp->TOP__top__DOT__axi_ifu.wstrb),4);
    bufp->fullBit(oldp+153,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__wlast));
    bufp->fullBit(oldp+154,(vlSymsp->TOP__top__DOT__axi_ifu.bready));
    bufp->fullCData(oldp+155,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__bid),4);
    bufp->fullCData(oldp+156,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__arid),4);
    bufp->fullCData(oldp+157,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__arlen),8);
    bufp->fullCData(oldp+158,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__arsize),3);
    bufp->fullCData(oldp+159,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__arburst),2);
    bufp->fullBit(oldp+160,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__rlast));
    bufp->fullCData(oldp+161,(vlSymsp->TOP__top__DOT__axi_ifu.__PVT__rid),4);
    bufp->fullCData(oldp+162,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__awid),4);
    bufp->fullCData(oldp+163,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__awlen),8);
    bufp->fullCData(oldp+164,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__awsize),3);
    bufp->fullCData(oldp+165,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__awburst),2);
    bufp->fullBit(oldp+166,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__wlast));
    bufp->fullCData(oldp+167,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__bid),4);
    bufp->fullCData(oldp+168,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__arid),4);
    bufp->fullCData(oldp+169,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__arlen),8);
    bufp->fullCData(oldp+170,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__arsize),3);
    bufp->fullCData(oldp+171,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__arburst),2);
    bufp->fullBit(oldp+172,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__rlast));
    bufp->fullCData(oldp+173,(vlSymsp->TOP__top__DOT__axi_lsu.__PVT__rid),4);
    bufp->fullCData(oldp+174,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awid),4);
    bufp->fullCData(oldp+175,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awlen),8);
    bufp->fullCData(oldp+176,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awsize),3);
    bufp->fullCData(oldp+177,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awburst),2);
    bufp->fullBit(oldp+178,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__wlast));
    bufp->fullCData(oldp+179,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__bid),4);
    bufp->fullCData(oldp+180,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arid),4);
    bufp->fullCData(oldp+181,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arlen),8);
    bufp->fullCData(oldp+182,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arsize),3);
    bufp->fullCData(oldp+183,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arburst),2);
    bufp->fullBit(oldp+184,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__rlast));
    bufp->fullCData(oldp+185,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__rid),4);
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
    bufp->fullCData(oldp+1,(vlSelfRef.top__DOT__arb__DOT__arbiter_state),2);
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__sram__DOT__en));
    bufp->fullBit(oldp+3,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
    bufp->fullBit(oldp+4,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
    bufp->fullBit(oldp+5,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid))));
    bufp->fullCData(oldp+6,(vlSymsp->TOP__top__DOT__axi_sram.bresp),2);
    bufp->fullBit(oldp+7,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
    bufp->fullCData(oldp+8,(vlSymsp->TOP__top__DOT__axi_sram.rresp),2);
    bufp->fullBit(oldp+9,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
    bufp->fullBit(oldp+10,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                            & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
    bufp->fullBit(oldp+11,(((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                            & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
    bufp->fullBit(oldp+12,(vlSymsp->TOP__top__DOT__axi_sram.awready));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__top__DOT__axi_sram.wready));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__top__DOT__axi_sram.arready));
    bufp->fullBit(oldp+16,(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    bufp->fullIData(oldp+17,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                               ? vlSymsp->TOP__top__DOT__axi_ifu.awaddr
                               : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                   ? vlSymsp->TOP__top__DOT__axi_lsu.awaddr
                                   : 0U))),32);
    bufp->fullIData(oldp+18,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                               ? vlSymsp->TOP__top__DOT__axi_ifu.wdata
                               : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                   ? vlSymsp->TOP__top__DOT__axi_lsu.wdata
                                   : 0U))),32);
    bufp->fullCData(oldp+19,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                               ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.wstrb)
                               : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                   ? (IData)(vlSymsp->TOP__top__DOT__axi_lsu.wstrb)
                                   : 0U))),4);
    bufp->fullBit(oldp+20,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                             ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.arvalid)
                             : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.arvalid)))));
    bufp->fullIData(oldp+21,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                               ? vlSelfRef.top__DOT__pc
                               : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                                   ? vlSymsp->TOP__top__DOT__axi_lsu.araddr
                                   : 0U))),32);
    bufp->fullBit(oldp+22,(((1U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state))
                             ? (IData)(vlSymsp->TOP__top__DOT__axi_ifu.rready)
                             : ((2U == (IData)(vlSelfRef.top__DOT__arb__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__axi_lsu.rready)))));
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__inst),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__pc),32);
    bufp->fullCData(oldp+25,((0x1fU & (vlSelfRef.top__DOT__inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+26,((0x1fU & (vlSelfRef.top__DOT__inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+27,((0x1fU & (vlSelfRef.top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__regmap[0]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__regmap[1]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__regmap[2]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__regmap[3]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__regmap[4]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__regmap[5]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.top__DOT__regmap[6]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.top__DOT__regmap[7]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__regmap[8]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.top__DOT__regmap[9]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.top__DOT__regmap[10]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.top__DOT__regmap[11]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.top__DOT__regmap[12]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.top__DOT__regmap[13]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__regmap[14]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.top__DOT__regmap[15]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.top__DOT__regmap[16]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.top__DOT__regmap[17]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__regmap[18]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.top__DOT__regmap[19]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.top__DOT__regmap[20]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.top__DOT__regmap[21]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.top__DOT__regmap[22]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.top__DOT__regmap[23]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.top__DOT__regmap[24]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.top__DOT__regmap[25]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.top__DOT__regmap[26]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__regmap[27]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.top__DOT__regmap[28]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__regmap[29]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__regmap[30]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__regmap[31]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__rs1_val),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__rs2_val),32);
    bufp->fullIData(oldp+62,(vlSelfRef.top__DOT__imm),32);
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__mem_addr),32);
    bufp->fullCData(oldp+64,((0x7fU & vlSelfRef.top__DOT__inst)),7);
    bufp->fullCData(oldp+65,((7U & (vlSelfRef.top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+66,(vlSelfRef.top__DOT__csr_reg),5);
    bufp->fullIData(oldp+67,(vlSelfRef.top__DOT__alu_1),32);
    bufp->fullIData(oldp+68,(vlSelfRef.top__DOT__alu_2),32);
    bufp->fullIData(oldp+69,(vlSelfRef.top__DOT__alu_3),32);
    bufp->fullCData(oldp+70,(vlSelfRef.top__DOT__alu_c),4);
    bufp->fullIData(oldp+71,(vlSelfRef.top__DOT__alu_out),32);
    bufp->fullBit(oldp+72,((0U != vlSelfRef.top__DOT__alu_3)));
    bufp->fullBit(oldp+73,(vlSelfRef.top__DOT__iv));
    bufp->fullBit(oldp+74,(vlSelfRef.top__DOT__ir));
    bufp->fullBit(oldp+75,(vlSelfRef.top__DOT__dv));
    bufp->fullBit(oldp+76,(vlSelfRef.top__DOT__dr));
    bufp->fullBit(oldp+77,(vlSelfRef.top__DOT__lr));
    bufp->fullBit(oldp+78,(vlSelfRef.top__DOT__lv));
    bufp->fullCData(oldp+79,(vlSelfRef.top__DOT__ic),2);
    bufp->fullCData(oldp+80,(vlSelfRef.top__DOT__lc),2);
    bufp->fullQData(oldp+81,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t),34);
    bufp->fullQData(oldp+83,((1ULL | ((QData)((IData)(vlSelfRef.top__DOT__alu_1)) 
                                      << 1U))),33);
    bufp->fullQData(oldp+85,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__srcB),33);
    bufp->fullQData(oldp+87,(((QData)((IData)(vlSelfRef.top__DOT__alu_2)) 
                              << 1U)),33);
    bufp->fullIData(oldp+89,((IData)((vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__add_res_t 
                                      >> 1U))),32);
    bufp->fullBit(oldp+90,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__comp_res));
    bufp->fullIData(oldp+91,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_res),32);
    bufp->fullCData(oldp+92,((0x1fU & vlSelfRef.top__DOT__alu_2)),5);
    bufp->fullIData(oldp+93,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__shift_src),32);
    bufp->fullIData(oldp+94,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__bit_res),32);
    bufp->fullIData(oldp+95,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+96,(vlSelfRef.top__DOT__ysyx_24080006_alu__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+97,(vlSymsp->TOP__top__DOT__axi_ifu.arvalid));
    bufp->fullBit(oldp+98,(vlSymsp->TOP__top__DOT__axi_ifu.rready));
    bufp->fullBit(oldp+99,(vlSymsp->TOP__top__DOT__axi_lsu.awvalid));
    bufp->fullIData(oldp+100,(vlSymsp->TOP__top__DOT__axi_lsu.awaddr),32);
    bufp->fullBit(oldp+101,(vlSymsp->TOP__top__DOT__axi_lsu.wvalid));
    bufp->fullIData(oldp+102,(vlSymsp->TOP__top__DOT__axi_lsu.wdata),32);
    bufp->fullCData(oldp+103,(vlSymsp->TOP__top__DOT__axi_lsu.wstrb),4);
    bufp->fullBit(oldp+104,(vlSymsp->TOP__top__DOT__axi_lsu.bready));
    bufp->fullBit(oldp+105,(vlSymsp->TOP__top__DOT__axi_lsu.arvalid));
    bufp->fullIData(oldp+106,(vlSymsp->TOP__top__DOT__axi_lsu.araddr),32);
    bufp->fullBit(oldp+107,(vlSymsp->TOP__top__DOT__axi_lsu.rready));
    bufp->fullBit(oldp+108,(vlSymsp->TOP__top__DOT__axi_ifu.rvalid));
    bufp->fullIData(oldp+109,(vlSymsp->TOP__top__DOT__axi_sram.rdata),32);
    bufp->fullBit(oldp+110,(vlSymsp->TOP__top__DOT__axi_lsu.bvalid));
    bufp->fullBit(oldp+111,(vlSymsp->TOP__top__DOT__axi_lsu.rvalid));
    bufp->fullIData(oldp+112,(vlSelfRef.top__DOT__ldata),32);
    bufp->fullBit(oldp+113,(vlSymsp->TOP__top__DOT__axi_sram.awvalid));
    bufp->fullBit(oldp+114,(vlSymsp->TOP__top__DOT__axi_sram.wvalid));
    bufp->fullBit(oldp+115,(vlSymsp->TOP__top__DOT__axi_sram.bready));
    bufp->fullBit(oldp+116,(vlSelfRef.clk));
    bufp->fullBit(oldp+117,(vlSelfRef.rst));
    bufp->fullCData(oldp+118,(((0U == (IData)(vlSelfRef.top__DOT__ic))
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
    bufp->fullCData(oldp+119,(vlSelfRef.top__DOT__dc),2);
    bufp->fullCData(oldp+120,(((0U == (IData)(vlSelfRef.top__DOT__dc))
                                ? ((IData)(vlSelfRef.top__DOT__iv)
                                    ? 1U : 0U) : ((
                                                   (1U 
                                                    == (IData)(vlSelfRef.top__DOT__dc)) 
                                                   || (2U 
                                                       == (IData)(vlSelfRef.top__DOT__dc)))
                                                   ? 
                                                  ((IData)(vlSelfRef.top__DOT__lr)
                                                    ? 0U
                                                    : 2U)
                                                   : 0U))),2);
    bufp->fullCData(oldp+121,(((0U == (IData)(vlSelfRef.top__DOT__lc))
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
                                         ? 0U : 2U)
                                     : 0U)))),2);
    bufp->fullCData(oldp+122,(vlSelfRef.top__DOT__rshamt),5);
    bufp->fullBit(oldp+123,(vlSymsp->TOP__top__DOT__axi_ifu.aresetn));
    bufp->fullBit(oldp+124,((1U & (~ (IData)(vlSelfRef.rst)))));
}
