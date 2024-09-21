// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Varb.h for the primary calling header

#ifndef VERILATED_VARB_XXU_IF_H_
#define VERILATED_VARB_XXU_IF_H_  // guard

#include "verilated.h"


class Varb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Varb_xxu_if final : public VerilatedModule {
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
    Varb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Varb_xxu_if(Varb__Syms* symsp, const char* v__name);
    ~Varb_xxu_if();
    VL_UNCOPYABLE(Varb_xxu_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Varb_xxu_if* obj);

#endif  // guard
