// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VARB__SYMS_H_
#define VERILATED_VARB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Varb.h"

// INCLUDE MODULE CLASSES
#include "Varb___024root.h"
#include "Varb_axi_if.h"
#include "Varb_xxu_if.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Varb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Varb* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Varb___024root                 TOP;
    Varb_axi_if                    TOP__top__DOT__CORE__DOT__axi_ifu;
    Varb_axi_if                    TOP__top__DOT__CORE__DOT__axi_lsu;
    Varb_xxu_if                    TOP__top__DOT__CORE__DOT__exu2lsu;
    Varb_xxu_if                    TOP__top__DOT__CORE__DOT__idu2exu;
    Varb_xxu_if                    TOP__top__DOT__CORE__DOT__ifu2idu;
    Varb_xxu_if                    TOP__top__DOT__CORE__DOT__lsu2wbu;
    Varb_xxu_if                    TOP__top__DOT__CORE__DOT__wbu2ifu;
    Varb_axi_if                    TOP__top__DOT__axi_sram;

    // SCOPE NAMES
    VerilatedScope __Vscope_top__CORE__EXU;
    VerilatedScope __Vscope_top__CORE__IDU;
    VerilatedScope __Vscope_top__CORE__IFU;
    VerilatedScope __Vscope_top__CORE__LSU;
    VerilatedScope __Vscope_top__sram;

    // CONSTRUCTORS
    Varb__Syms(VerilatedContext* contextp, const char* namep, Varb* modelp);
    ~Varb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
