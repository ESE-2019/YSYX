// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Varb__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Varb::Varb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Varb__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , __PVT__top__DOT__axi_sram{vlSymsp->TOP.__PVT__top__DOT__axi_sram}
    , __PVT__top__DOT__CORE__DOT__ifu2idu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__ifu2idu}
    , __PVT__top__DOT__CORE__DOT__idu2exu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__idu2exu}
    , __PVT__top__DOT__CORE__DOT__exu2lsu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__exu2lsu}
    , __PVT__top__DOT__CORE__DOT__lsu2wbu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__lsu2wbu}
    , __PVT__top__DOT__CORE__DOT__wbu2ifu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__wbu2ifu}
    , __PVT__top__DOT__CORE__DOT__axi_ifu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__axi_ifu}
    , __PVT__top__DOT__CORE__DOT__axi_lsu{vlSymsp->TOP.__PVT__top__DOT__CORE__DOT__axi_lsu}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Varb::Varb(const char* _vcname__)
    : Varb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Varb::~Varb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Varb___024root___eval_debug_assertions(Varb___024root* vlSelf);
#endif  // VL_DEBUG
void Varb___024root___eval_static(Varb___024root* vlSelf);
void Varb___024root___eval_initial(Varb___024root* vlSelf);
void Varb___024root___eval_settle(Varb___024root* vlSelf);
void Varb___024root___eval(Varb___024root* vlSelf);

void Varb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Varb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Varb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Varb___024root___eval_static(&(vlSymsp->TOP));
        Varb___024root___eval_initial(&(vlSymsp->TOP));
        Varb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Varb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Varb::eventsPending() { return false; }

uint64_t Varb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Varb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Varb___024root___eval_final(Varb___024root* vlSelf);

VL_ATTR_COLD void Varb::final() {
    Varb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Varb::hierName() const { return vlSymsp->name(); }
const char* Varb::modelName() const { return "Varb"; }
unsigned Varb::threads() const { return 1; }
void Varb::prepareClone() const { contextp()->prepareClone(); }
void Varb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Varb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Varb___024root__trace_decl_types(VerilatedFst* tracep);

void Varb___024root__trace_init_top(Varb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Varb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Varb___024root*>(voidSelf);
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Varb___024root__trace_decl_types(tracep);
    Varb___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Varb___024root__trace_register(Varb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Varb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Varb::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Varb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
