// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_XXU_IF_H_
#define VERILATED_VTOP_XXU_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_xxu_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ valid;
    CData/*0:0*/ ready;
    CData/*3:0*/ alu_ctrl;
    CData/*1:0*/ alu_set;
    CData/*4:0*/ rd_addr;
    CData/*2:0*/ funct3;
    CData/*0:0*/ load;
    CData/*0:0*/ store;
    CData/*0:0*/ wb;
    CData/*0:0*/ jump;
    CData/*0:0*/ branch;
    IData/*31:0*/ pc;
    IData/*31:0*/ inst;
    IData/*31:0*/ imm;
    IData/*31:0*/ dnpc;
    IData/*31:0*/ sdata;
    IData/*31:0*/ alu_src1;
    IData/*31:0*/ alu_src2;
    IData/*31:0*/ alu_res;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_xxu_if(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_xxu_if();
    VL_UNCOPYABLE(Vtop_xxu_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_xxu_if* obj);

#endif  // guard
