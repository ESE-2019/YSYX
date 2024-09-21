// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Varb__Syms.h"


VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0(Varb___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0(Varb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+169,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi_sram", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("CORE", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ifu2idu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("idu2exu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("exu2lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("lsu2wbu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("wbu2ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+1,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"rs1_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs2_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ARB", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("axi_0", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("axi_1", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("out", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+8,0,"arbiter_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+172,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+173,0,"M0_ACTIVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+174,0,"M1_ACTIVE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("EXU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("idu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+9,0,"curr",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"next",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+11,0,"alu_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+13,0,"not_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+15,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"ctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+11,0,"res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+176,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+177,0,"SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+178,0,"SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+179,0,"SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+180,0,"XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+181,0,"SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+182,0,"SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+183,0,"OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+184,0,"AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declQuad(c+18,0,"add_res_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+20,0,"srcA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+22,0,"srcB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+24,0,"srcB_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+26,0,"add_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+27,0,"comp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"shift_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+30,0,"shift_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"bit_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("IDU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"rs1_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs2_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("exu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+34,0,"curr",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+35,0,"next",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+185,0,"B_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+186,0,"I_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+187,0,"R_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+188,0,"S_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+189,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+190,0,"jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+191,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+192,0,"lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+193,0,"auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+194,0,"system",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+36,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+38,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+43,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+44,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("Imm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+45,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("IFU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi_ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("wbu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("idu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+46,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+195,0,"RST_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"curr",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+48,0,"next",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("LSU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("axi_lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("exu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("wbu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+49,0,"curr",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+50,0,"next",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+51,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"ldata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"rshamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("REG", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+4,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"rs1_val",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"rs2_val",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+54+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("WBU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+169,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+5,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("lsu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ifu", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+86,0,"curr",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+87,0,"next",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("axi", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declQuad(c+88,0,"mtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+90,0,"dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__axi_sram__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+169,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+196,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+197,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+199,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+94,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+200,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+201,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+101,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+204,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+205,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+104,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+206,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+207,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_ifu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+169,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+209,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+211,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+212,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+213,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+109,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+215,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+217,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+219,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+111,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+221,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+222,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+223,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+113,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+224,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+225,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__axi_lsu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+169,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+227,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+228,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+229,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+118,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+230,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+231,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+124,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+232,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+233,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+235,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+127,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+236,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__ifu2idu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+129,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"sdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+241,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+244,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+245,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+247,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+248,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__idu2exu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+132,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"sdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+255,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+256,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+138,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+139,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+140,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__exu2lsu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+144,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+257,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"sdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+260,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+263,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+148,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+150,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+151,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__lsu2wbu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+156,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"sdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+271,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+159,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+272,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+273,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+274,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+163,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_sub__TOP__top__DOT__CORE__DOT__wbu2ifu__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+164,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+275,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"sdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+279,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"alu_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+282,0,"alu_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+283,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+284,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+285,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+286,0,"load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+287,0,"store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Varb___024root__trace_init_top(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_init_top\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Varb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Varb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Varb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Varb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Varb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Varb___024root__trace_register(Varb___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_register\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Varb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Varb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Varb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Varb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Varb___024root__trace_const_0_sub_0(Varb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Varb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_const_0\n"); );
    // Init
    Varb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Varb___024root*>(voidSelf);
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Varb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Varb___024root__trace_const_0_sub_0(Varb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_const_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+172,(0U),2);
    bufp->fullCData(oldp+173,(1U),2);
    bufp->fullCData(oldp+174,(2U),2);
    bufp->fullCData(oldp+175,(0U),4);
    bufp->fullCData(oldp+176,(8U),4);
    bufp->fullCData(oldp+177,(1U),4);
    bufp->fullCData(oldp+178,(2U),4);
    bufp->fullCData(oldp+179,(3U),4);
    bufp->fullCData(oldp+180,(4U),4);
    bufp->fullCData(oldp+181,(5U),4);
    bufp->fullCData(oldp+182,(0xdU),4);
    bufp->fullCData(oldp+183,(6U),4);
    bufp->fullCData(oldp+184,(7U),4);
    bufp->fullCData(oldp+185,(0x63U),7);
    bufp->fullCData(oldp+186,(0x13U),7);
    bufp->fullCData(oldp+187,(0x33U),7);
    bufp->fullCData(oldp+188,(0x23U),7);
    bufp->fullCData(oldp+189,(3U),7);
    bufp->fullCData(oldp+190,(0x6fU),7);
    bufp->fullCData(oldp+191,(0x67U),7);
    bufp->fullCData(oldp+192,(0x37U),7);
    bufp->fullCData(oldp+193,(0x17U),7);
    bufp->fullCData(oldp+194,(0x73U),7);
    bufp->fullIData(oldp+195,(0x80000000U),32);
    bufp->fullCData(oldp+196,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awid),4);
    bufp->fullCData(oldp+197,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awlen),8);
    bufp->fullCData(oldp+198,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awsize),3);
    bufp->fullCData(oldp+199,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__awburst),2);
    bufp->fullBit(oldp+200,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__wlast));
    bufp->fullCData(oldp+201,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__bid),4);
    bufp->fullCData(oldp+202,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arid),4);
    bufp->fullCData(oldp+203,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arlen),8);
    bufp->fullCData(oldp+204,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arsize),3);
    bufp->fullCData(oldp+205,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__arburst),2);
    bufp->fullBit(oldp+206,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__rlast));
    bufp->fullCData(oldp+207,(vlSymsp->TOP__top__DOT__axi_sram.__PVT__rid),4);
    bufp->fullBit(oldp+208,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awvalid));
    bufp->fullIData(oldp+209,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awaddr),32);
    bufp->fullCData(oldp+210,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__awid),4);
    bufp->fullCData(oldp+211,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__awlen),8);
    bufp->fullCData(oldp+212,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__awsize),3);
    bufp->fullCData(oldp+213,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__awburst),2);
    bufp->fullBit(oldp+214,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wvalid));
    bufp->fullIData(oldp+215,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wdata),32);
    bufp->fullCData(oldp+216,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wstrb),4);
    bufp->fullBit(oldp+217,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__wlast));
    bufp->fullBit(oldp+218,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bready));
    bufp->fullCData(oldp+219,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__bid),4);
    bufp->fullCData(oldp+220,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__arid),4);
    bufp->fullCData(oldp+221,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__arlen),8);
    bufp->fullCData(oldp+222,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__arsize),3);
    bufp->fullCData(oldp+223,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__arburst),2);
    bufp->fullBit(oldp+224,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__rlast));
    bufp->fullCData(oldp+225,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.__PVT__rid),4);
    bufp->fullCData(oldp+226,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__awid),4);
    bufp->fullCData(oldp+227,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__awlen),8);
    bufp->fullCData(oldp+228,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__awsize),3);
    bufp->fullCData(oldp+229,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__awburst),2);
    bufp->fullBit(oldp+230,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__wlast));
    bufp->fullCData(oldp+231,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__bid),4);
    bufp->fullCData(oldp+232,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__arid),4);
    bufp->fullCData(oldp+233,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__arlen),8);
    bufp->fullCData(oldp+234,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__arsize),3);
    bufp->fullCData(oldp+235,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__arburst),2);
    bufp->fullBit(oldp+236,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__rlast));
    bufp->fullCData(oldp+237,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.__PVT__rid),4);
    bufp->fullIData(oldp+238,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.imm),32);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.dnpc),32);
    bufp->fullIData(oldp+240,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.sdata),32);
    bufp->fullIData(oldp+241,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.alu_src1),32);
    bufp->fullIData(oldp+242,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.alu_src2),32);
    bufp->fullCData(oldp+243,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.alu_ctrl),4);
    bufp->fullCData(oldp+244,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.alu_set),2);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.alu_res),32);
    bufp->fullCData(oldp+246,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.rd_addr),5);
    bufp->fullCData(oldp+247,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.funct3),3);
    bufp->fullBit(oldp+248,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.load));
    bufp->fullBit(oldp+249,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.store));
    bufp->fullBit(oldp+250,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.wb));
    bufp->fullBit(oldp+251,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.jump));
    bufp->fullBit(oldp+252,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.branch));
    bufp->fullIData(oldp+253,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.pc),32);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.inst),32);
    bufp->fullCData(oldp+255,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set),2);
    bufp->fullIData(oldp+256,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_res),32);
    bufp->fullIData(oldp+257,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.pc),32);
    bufp->fullIData(oldp+258,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.inst),32);
    bufp->fullIData(oldp+259,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.imm),32);
    bufp->fullIData(oldp+260,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_src1),32);
    bufp->fullIData(oldp+261,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_src2),32);
    bufp->fullCData(oldp+262,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_ctrl),4);
    bufp->fullCData(oldp+263,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_set),2);
    bufp->fullIData(oldp+264,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.pc),32);
    bufp->fullIData(oldp+265,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.inst),32);
    bufp->fullIData(oldp+266,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.imm),32);
    bufp->fullIData(oldp+267,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.sdata),32);
    bufp->fullIData(oldp+268,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_src1),32);
    bufp->fullIData(oldp+269,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_src2),32);
    bufp->fullCData(oldp+270,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_ctrl),4);
    bufp->fullCData(oldp+271,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_set),2);
    bufp->fullCData(oldp+272,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.funct3),3);
    bufp->fullBit(oldp+273,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.load));
    bufp->fullBit(oldp+274,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.store));
    bufp->fullIData(oldp+275,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.pc),32);
    bufp->fullIData(oldp+276,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.inst),32);
    bufp->fullIData(oldp+277,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.imm),32);
    bufp->fullIData(oldp+278,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.sdata),32);
    bufp->fullIData(oldp+279,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.alu_src1),32);
    bufp->fullIData(oldp+280,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.alu_src2),32);
    bufp->fullCData(oldp+281,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.alu_ctrl),4);
    bufp->fullCData(oldp+282,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.alu_set),2);
    bufp->fullIData(oldp+283,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.alu_res),32);
    bufp->fullCData(oldp+284,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.rd_addr),5);
    bufp->fullCData(oldp+285,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.funct3),3);
    bufp->fullBit(oldp+286,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.load));
    bufp->fullBit(oldp+287,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.store));
    bufp->fullBit(oldp+288,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.wb));
}

VL_ATTR_COLD void Varb___024root__trace_full_0_sub_0(Varb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Varb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_full_0\n"); );
    // Init
    Varb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Varb___024root*>(voidSelf);
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Varb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Varb___024root__trace_full_0_sub_0(Varb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root__trace_full_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.top__DOT__CORE__DOT__we));
    bufp->fullCData(oldp+2,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+3,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+4,(vlSelfRef.top__DOT__CORE__DOT__rd),5);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__CORE__DOT__wdata),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__CORE__DOT__rs1_val),32);
    bufp->fullIData(oldp+7,(vlSelfRef.top__DOT__CORE__DOT__rs2_val),32);
    bufp->fullCData(oldp+8,(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state),2);
    bufp->fullCData(oldp+9,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr),2);
    bufp->fullCData(oldp+10,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next),2);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res),32);
    bufp->fullBit(oldp+13,((0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out)));
    bufp->fullBit(oldp+14,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__branch));
    bufp->fullIData(oldp+15,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1),32);
    bufp->fullIData(oldp+16,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2),32);
    bufp->fullCData(oldp+17,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl),4);
    bufp->fullQData(oldp+18,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t),34);
    bufp->fullQData(oldp+20,((1ULL | ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1)) 
                                      << 1U))),33);
    bufp->fullQData(oldp+22,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB),33);
    bufp->fullQData(oldp+24,(((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                              << 1U)),33);
    bufp->fullIData(oldp+26,((IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                      >> 1U))),32);
    bufp->fullBit(oldp+27,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res));
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res),32);
    bufp->fullCData(oldp+29,((0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)),5);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+33,(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i),32);
    bufp->fullCData(oldp+34,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr),2);
    bufp->fullCData(oldp+35,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next),2);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm),32);
    bufp->fullCData(oldp+37,((0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)),7);
    bufp->fullCData(oldp+38,((7U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+39,((0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+40,(((0x40U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                               ? ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                   ? ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                       ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                                       : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                           ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                               ? ((1U 
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
                                           : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                               ? ((2U 
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
                                       : vlSelfRef.top__DOT__CORE__DOT__rs1_val)))),32);
    bufp->fullIData(oldp+41,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2),32);
    bufp->fullCData(oldp+42,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl),4);
    bufp->fullCData(oldp+43,(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_set),2);
    bufp->fullIData(oldp+44,(((0x67U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))
                               ? (vlSelfRef.top__DOT__CORE__DOT__rs1_val 
                                  + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                               : (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc 
                                  + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm))),32);
    bufp->fullIData(oldp+45,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc),32);
    bufp->fullCData(oldp+47,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr),2);
    bufp->fullCData(oldp+48,(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next),2);
    bufp->fullCData(oldp+49,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr),2);
    bufp->fullCData(oldp+50,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next),2);
    bufp->fullIData(oldp+51,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__alu_res),32);
    bufp->fullIData(oldp+52,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__ldata),32);
    bufp->fullCData(oldp+53,(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__rshamt),5);
    bufp->fullIData(oldp+54,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[1]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[2]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[3]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[4]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[5]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[6]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[7]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[8]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[9]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[10]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[11]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[12]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[13]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[14]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[15]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[16]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[17]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[18]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[19]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[20]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[21]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[22]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[23]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[24]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[25]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[26]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[27]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[28]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[29]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[30]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[31]),32);
    bufp->fullCData(oldp+86,(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr),2);
    bufp->fullCData(oldp+87,(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__next),2);
    bufp->fullQData(oldp+88,(vlSelfRef.top__DOT__sram__DOT__mtime),64);
    bufp->fullIData(oldp+90,(vlSelfRef.top__DOT__sram__DOT__dout),32);
    bufp->fullBit(oldp+91,(vlSymsp->TOP__top__DOT__axi_sram.awready));
    bufp->fullBit(oldp+92,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                             ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awvalid)
                             : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid)))));
    bufp->fullIData(oldp+93,(vlSymsp->TOP__top__DOT__axi_sram.awaddr),32);
    bufp->fullBit(oldp+94,(vlSymsp->TOP__top__DOT__axi_sram.wready));
    bufp->fullBit(oldp+95,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                             ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wvalid)
                             : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid)))));
    bufp->fullIData(oldp+96,(vlSymsp->TOP__top__DOT__axi_sram.wdata),32);
    bufp->fullCData(oldp+97,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                               ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wstrb)
                               : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                   ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb)
                                   : 0U))),4);
    bufp->fullBit(oldp+98,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                             ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bready)
                             : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready)))));
    bufp->fullBit(oldp+99,(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    bufp->fullCData(oldp+100,(vlSymsp->TOP__top__DOT__axi_sram.bresp),2);
    bufp->fullBit(oldp+101,(vlSymsp->TOP__top__DOT__axi_sram.arready));
    bufp->fullBit(oldp+102,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                              ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid)
                              : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                 & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid)))));
    bufp->fullIData(oldp+103,(vlSymsp->TOP__top__DOT__axi_sram.araddr),32);
    bufp->fullBit(oldp+104,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                              ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready)
                              : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                                 & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready)))));
    bufp->fullBit(oldp+105,(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    bufp->fullCData(oldp+106,(vlSymsp->TOP__top__DOT__axi_sram.rresp),2);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__top__DOT__axi_sram.rdata),32);
    bufp->fullBit(oldp+108,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
    bufp->fullBit(oldp+109,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
    bufp->fullBit(oldp+110,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid))));
    bufp->fullBit(oldp+111,(((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
    bufp->fullBit(oldp+112,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid));
    bufp->fullBit(oldp+113,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready));
    bufp->fullBit(oldp+114,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid));
    bufp->fullBit(oldp+115,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready))));
    bufp->fullBit(oldp+116,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid));
    bufp->fullIData(oldp+117,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr),32);
    bufp->fullBit(oldp+118,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready))));
    bufp->fullBit(oldp+119,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid));
    bufp->fullIData(oldp+120,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata),32);
    bufp->fullCData(oldp+121,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb),4);
    bufp->fullBit(oldp+122,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready));
    bufp->fullBit(oldp+123,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid));
    bufp->fullBit(oldp+124,(((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready))));
    bufp->fullBit(oldp+125,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid));
    bufp->fullIData(oldp+126,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr),32);
    bufp->fullBit(oldp+127,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready));
    bufp->fullBit(oldp+128,(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid));
    bufp->fullBit(oldp+129,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid));
    bufp->fullBit(oldp+130,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready));
    bufp->fullIData(oldp+131,(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc),32);
    bufp->fullBit(oldp+132,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid));
    bufp->fullBit(oldp+133,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready));
    bufp->fullIData(oldp+134,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.imm),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.dnpc),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.sdata),32);
    bufp->fullCData(oldp+137,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.rd_addr),5);
    bufp->fullCData(oldp+138,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.funct3),3);
    bufp->fullBit(oldp+139,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.load));
    bufp->fullBit(oldp+140,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.store));
    bufp->fullBit(oldp+141,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.wb));
    bufp->fullBit(oldp+142,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.jump));
    bufp->fullBit(oldp+143,(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch));
    bufp->fullBit(oldp+144,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid));
    bufp->fullBit(oldp+145,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready));
    bufp->fullIData(oldp+146,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.dnpc),32);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.sdata),32);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res),32);
    bufp->fullCData(oldp+149,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.rd_addr),5);
    bufp->fullCData(oldp+150,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3),3);
    bufp->fullBit(oldp+151,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load));
    bufp->fullBit(oldp+152,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store));
    bufp->fullBit(oldp+153,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.wb));
    bufp->fullBit(oldp+154,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.jump));
    bufp->fullBit(oldp+155,(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.branch));
    bufp->fullBit(oldp+156,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid));
    bufp->fullBit(oldp+157,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready));
    bufp->fullIData(oldp+158,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.dnpc),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_res),32);
    bufp->fullCData(oldp+160,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.rd_addr),5);
    bufp->fullBit(oldp+161,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.wb));
    bufp->fullBit(oldp+162,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.jump));
    bufp->fullBit(oldp+163,(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.branch));
    bufp->fullBit(oldp+164,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid));
    bufp->fullBit(oldp+165,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready));
    bufp->fullIData(oldp+166,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.dnpc),32);
    bufp->fullBit(oldp+167,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.jump));
    bufp->fullBit(oldp+168,(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.branch));
    bufp->fullBit(oldp+169,(vlSelfRef.clk));
    bufp->fullBit(oldp+170,(vlSelfRef.rst));
    bufp->fullBit(oldp+171,((1U & (~ (IData)(vlSelfRef.rst)))));
}
