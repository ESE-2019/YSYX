// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_axi_if.h"
#include "Vtop_xxu_if.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_axi_if                    TOP__top__DOT__CORE__DOT__axi_ifu;
    Vtop_axi_if                    TOP__top__DOT__CORE__DOT__axi_lsu;
    Vtop_xxu_if                    TOP__top__DOT__CORE__DOT__exu2lsu;
    Vtop_xxu_if                    TOP__top__DOT__CORE__DOT__idu2exu;
    Vtop_xxu_if                    TOP__top__DOT__CORE__DOT__ifu2idu;
    Vtop_xxu_if                    TOP__top__DOT__CORE__DOT__lsu2wbu;
    Vtop_xxu_if                    TOP__top__DOT__CORE__DOT__wbu2ifu;
    Vtop_axi_if                    TOP__top__DOT__axi_sram;

    // SCOPE NAMES
    VerilatedScope __Vscope_top__CORE__EXU;
    VerilatedScope __Vscope_top__CORE__IDU;
    VerilatedScope __Vscope_top__CORE__IFU;
    VerilatedScope __Vscope_top__CORE__LSU;
    VerilatedScope __Vscope_top__sram;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
