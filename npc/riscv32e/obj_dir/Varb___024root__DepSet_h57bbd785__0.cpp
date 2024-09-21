// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varb.h for the primary calling header

#include "Varb__pch.h"
#include "Varb__Syms.h"
#include "Varb___024root.h"

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, int wmask);

VL_INLINE_OPT void Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, IData/*31:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    int wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Varb___024root___dump_triggers__act(Varb___024root* vlSelf);
#endif  // VL_DEBUG

void Varb___024root___eval_triggers__act(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Varb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*0:0*/, 32> Varb__ConstPool__TABLE_h51a550a5_0;
extern const VlUnpacked<CData/*0:0*/, 32> Varb__ConstPool__TABLE_h69c58c6b_0;
extern const VlUnpacked<CData/*1:0*/, 16> Varb__ConstPool__TABLE_h0e900e07_0;
extern const VlUnpacked<CData/*1:0*/, 16> Varb__ConstPool__TABLE_h588dbbb1_0;

VL_INLINE_OPT void Varb___024root___nba_sequent__TOP__0(Varb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Varb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varb___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout;
    __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*1:0*/ __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state;
    __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__CORE__DOT__REG__DOT__regfile__v32;
    __VdlyVal__top__DOT__CORE__DOT__REG__DOT__regfile__v32 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__CORE__DOT__REG__DOT__regfile__v32;
    __VdlyDim0__top__DOT__CORE__DOT__REG__DOT__regfile__v32 = 0;
    IData/*31:0*/ __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc;
    __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc = 0;
    CData/*0:0*/ __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v0;
    __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v32;
    __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v32 = 0;
    CData/*0:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__awready;
    TOP__top__DOT__axi_sram__DOT____Vdly__awready = 0;
    CData/*0:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__wready;
    TOP__top__DOT__axi_sram__DOT____Vdly__wready = 0;
    CData/*0:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__bvalid;
    TOP__top__DOT__axi_sram__DOT____Vdly__bvalid = 0;
    CData/*0:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__arready;
    TOP__top__DOT__axi_sram__DOT____Vdly__arready = 0;
    CData/*0:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__rvalid;
    TOP__top__DOT__axi_sram__DOT____Vdly__rvalid = 0;
    IData/*31:0*/ TOP__top__DOT__axi_sram__DOT____Vdly__rdata;
    TOP__top__DOT__axi_sram__DOT____Vdly__rdata = 0;
    CData/*0:0*/ TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0;
    IData/*31:0*/ TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst = 0;
    IData/*31:0*/ TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc = 0;
    CData/*0:0*/ TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid;
    TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 0;
    CData/*0:0*/ TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid;
    TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 0;
    CData/*0:0*/ TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid;
    TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0;
    CData/*0:0*/ TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready;
    TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 0;
    // Body
    if (VL_UNLIKELY((0x73U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)))) {
        VL_FINISH_MT("ysyx_24080006_idu.sv", 216, "");
    }
    TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid 
        = vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid;
    TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid 
        = vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid;
    TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid 
        = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid 
        = vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid;
    TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready 
        = vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready;
    __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v0 = 0U;
    __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v32 = 0U;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc 
        = vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc;
    __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc = vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc;
    TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst 
        = vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst;
    TOP__top__DOT__axi_sram__DOT____Vdly__wready = vlSymsp->TOP__top__DOT__axi_sram.wready;
    TOP__top__DOT__axi_sram__DOT____Vdly__awready = vlSymsp->TOP__top__DOT__axi_sram.awready;
    TOP__top__DOT__axi_sram__DOT____Vdly__bvalid = vlSymsp->TOP__top__DOT__axi_sram.bvalid;
    TOP__top__DOT__axi_sram__DOT____Vdly__rdata = vlSymsp->TOP__top__DOT__axi_sram.rdata;
    TOP__top__DOT__axi_sram__DOT____Vdly__arready = vlSymsp->TOP__top__DOT__axi_sram.arready;
    TOP__top__DOT__axi_sram__DOT____Vdly__rvalid = vlSymsp->TOP__top__DOT__axi_sram.rvalid;
    __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state 
        = vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state;
    vlSelfRef.top__DOT__sram__DOT__mtime = ((IData)(vlSelfRef.rst)
                                             ? 0ULL
                                             : (1ULL 
                                                + vlSelfRef.top__DOT__sram__DOT__mtime));
    if (vlSelfRef.rst) {
        TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 1U;
        TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:57: Assertion failed in %Ntop.CORE.IFU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_ifu.sv", 57, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:57: Assertion failed in %Ntop.CORE.IFU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_ifu.sv", 57, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid) {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 0U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0U;
            } else {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 1U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid) {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 0U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 1U;
            } else {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 0U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready) {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 1U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 0U;
            } else {
                TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready = 0U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid = 1U;
            }
        }
    }
    if (vlSelfRef.rst) {
        __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v0 = 1U;
        __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.imm = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 = 0U;
    } else {
        if (((IData)(vlSelfRef.top__DOT__CORE__DOT__we) 
             & (0U != (IData)(vlSelfRef.top__DOT__CORE__DOT__rd)))) {
            __VdlyVal__top__DOT__CORE__DOT__REG__DOT__regfile__v32 
                = vlSelfRef.top__DOT__CORE__DOT__wdata;
            __VdlyDim0__top__DOT__CORE__DOT__REG__DOT__regfile__v32 
                = vlSelfRef.top__DOT__CORE__DOT__rd;
            __VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v32 = 1U;
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
            if (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awvalid) 
                 | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid))) {
                __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 1U;
            } else if (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid) 
                        | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid))) {
                __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 2U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
            if ((((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bvalid) 
                  & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bready)) 
                 | ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready) 
                    & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid)))) {
                __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
            if ((((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid) 
                  & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready)) 
                 | ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready) 
                    & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid)))) {
                __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0U;
            }
        } else {
            __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state = 0U;
        }
        if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
             & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.imm 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch 
                = (0x63U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst));
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2;
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl;
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                = ((0x40U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                    ? ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                        ? ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                            : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                    ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
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
                                    ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                        ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                            ? 0U : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                        : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                    : vlSelfRef.top__DOT__CORE__DOT__rs1_val))
                            : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                        : ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                ? vlSelfRef.top__DOT__CORE__DOT__rs1_val
                                : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                    ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                        ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                            ? vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc
                                            : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                        : vlSelfRef.top__DOT__CORE__DOT__rs1_val)
                                    : vlSelfRef.top__DOT__CORE__DOT__rs1_val))
                            : vlSelfRef.top__DOT__CORE__DOT__rs1_val)));
        }
    }
    if (vlSelfRef.rst) {
        TOP__top__DOT__axi_sram__DOT____Vdly__awready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__wready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__bvalid = 0U;
    } else if (((((((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                     ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awvalid)
                     : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                        & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid))) 
                   & ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                       ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wvalid)
                       : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                          & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid)))) 
                  & (IData)(vlSymsp->TOP__top__DOT__axi_sram.awready)) 
                 & (IData)(vlSymsp->TOP__top__DOT__axi_sram.wready)) 
                & (~ (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid)))) {
        if (VL_UNLIKELY((0xa00003f8U == vlSymsp->TOP__top__DOT__axi_sram.awaddr))) {
            VL_WRITEF_NX("%c",0,8,(0xffU & vlSymsp->TOP__top__DOT__axi_sram.wdata));
            Verilated::runFlushCallbacks();
        } else {
            Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_write_TOP(vlSymsp->TOP__top__DOT__axi_sram.awaddr, vlSymsp->TOP__top__DOT__axi_sram.wdata, 
                                                                             ((1U 
                                                                               == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                                                               ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wstrb)
                                                                               : 
                                                                              ((2U 
                                                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                                                                                ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb)
                                                                                : 0U)));
        }
        TOP__top__DOT__axi_sram__DOT____Vdly__awready = 0U;
        TOP__top__DOT__axi_sram__DOT____Vdly__wready = 0U;
        TOP__top__DOT__axi_sram__DOT____Vdly__bvalid = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.bresp = 0U;
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                 ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bready)
                 : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                    & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready)))) {
        TOP__top__DOT__axi_sram__DOT____Vdly__awready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__wready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__bvalid = 0U;
    }
    if (vlSelfRef.rst) {
        TOP__top__DOT__axi_sram__DOT____Vdly__arready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__rvalid = 0U;
    } else if (((((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                   ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid)
                   : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                      & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid))) 
                 & (IData)(vlSymsp->TOP__top__DOT__axi_sram.arready)) 
                & (~ (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid)))) {
        TOP__top__DOT__axi_sram__DOT____Vdly__arready = 0U;
        TOP__top__DOT__axi_sram__DOT____Vdly__rdata 
            = ((0xa0000000U <= vlSymsp->TOP__top__DOT__axi_sram.araddr)
                ? vlSelfRef.top__DOT__sram__DOT__dout
                : ([&]() {
                    Varb___024root____Vdpiimwrap_top__DOT__sram__DOT__pmem_read_TOP(vlSymsp->TOP__top__DOT__axi_sram.araddr, __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout);
                }(), __Vfunc_top__DOT__sram__DOT__pmem_read__1__Vfuncout));
        TOP__top__DOT__axi_sram__DOT____Vdly__rvalid = 1U;
        vlSymsp->TOP__top__DOT__axi_sram.rresp = 0U;
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))
                 ? (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready)
                 : ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
                    & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready)))) {
        TOP__top__DOT__axi_sram__DOT____Vdly__arready = 1U;
        TOP__top__DOT__axi_sram__DOT____Vdly__rvalid = 0U;
    }
    if (__VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v0) {
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[1U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[2U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[3U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[4U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[5U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[6U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[7U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[8U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[9U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xaU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xbU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xcU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xdU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xeU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0xfU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x10U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x11U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x12U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x13U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x14U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x15U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x16U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x17U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x18U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x19U] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1aU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1bU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1cU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1dU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1eU] = 0U;
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[0x1fU] = 0U;
    }
    if (__VdlySet__top__DOT__CORE__DOT__REG__DOT__regfile__v32) {
        vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile[__VdlyDim0__top__DOT__CORE__DOT__REG__DOT__regfile__v32] 
            = __VdlyVal__top__DOT__CORE__DOT__REG__DOT__regfile__v32;
    }
    vlSymsp->TOP__top__DOT__axi_sram.awready = TOP__top__DOT__axi_sram__DOT____Vdly__awready;
    vlSymsp->TOP__top__DOT__axi_sram.wready = TOP__top__DOT__axi_sram__DOT____Vdly__wready;
    vlSymsp->TOP__top__DOT__axi_sram.bvalid = TOP__top__DOT__axi_sram__DOT____Vdly__bvalid;
    vlSymsp->TOP__top__DOT__axi_sram.arready = TOP__top__DOT__axi_sram__DOT____Vdly__arready;
    vlSymsp->TOP__top__DOT__axi_sram.rvalid = TOP__top__DOT__axi_sram__DOT____Vdly__rvalid;
    vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state 
        = __Vdly__top__DOT__CORE__DOT__ARB__DOT__arbiter_state;
    vlSelfRef.top__DOT__CORE__DOT__we = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                         && (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr)) 
                                              & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid)) 
                                             && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.wb)));
    if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk2__DOT__i = 0x20U;
                }
            }
        }
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
        = ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
           << 1U);
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
        = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
           & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    if ((7U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    } else if ((6U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               | vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    } else if ((4U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res 
            = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
               ^ vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2);
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
        = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1;
    if ((1U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__unnamedblk1__DOT__i = 0x20U;
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffffff8U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((4U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                         >> 0x1bU)) | ((2U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                              >> 0x1dU)) 
                                       | (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                          >> 0x1fU))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffffffc7U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                            >> 0x15U)) | ((0x10U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0x17U)) 
                                          | (8U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   >> 0x19U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffffe3fU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x100U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                             >> 0xfU)) | ((0x80U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0x11U)) 
                                          | (0x40U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                >> 0x13U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffff1ffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x800U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                             >> 9U)) | ((0x400U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   >> 0xbU)) 
                                        | (0x200U & 
                                           (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                            >> 0xdU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffff8fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x4000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                              >> 3U)) | ((0x2000U & 
                                          (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               >> 7U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xfffc7fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                               << 3U)) | ((0x10000U 
                                           & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                              << 1U)) 
                                          | (0x8000U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                >> 1U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xffe3ffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x100000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                << 9U)) | ((0x80000U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 << 5U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xff1fffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x800000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                << 0xfU)) | ((0x400000U 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 << 0xdU)) 
                                             | (0x200000U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   << 0xbU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xf8ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x4000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                 << 0x15U)) | ((0x2000000U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                   << 0x13U)) 
                                               | (0x1000000U 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                     << 0x11U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0xc7ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((0x20000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                  << 0x1bU)) | ((0x10000000U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                    << 0x19U)) 
                                                | (0x8000000U 
                                                   & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                      << 0x17U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = ((0x3fffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src) 
               | ((vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                   << 0x1fU) | (0x40000000U & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                               << 0x1dU))));
    } else if (((5U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)) 
                || (0xdU == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1;
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.bvalid 
        = ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    if ((8U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                        = (0x1ffffffffULL & (~ ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                                                << 1U)));
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                         >> 2U)))) {
        if ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
            vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                = (0x1ffffffffULL & (~ ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                                        << 1U)));
        } else if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
            vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB 
                = ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2)) 
                   << 1U);
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__CORE__DOT__wdata = 0U;
        vlSelfRef.top__DOT__CORE__DOT__rd = 0U;
    } else if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr)) 
                & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid))) {
        if (vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.wb) {
            vlSelfRef.top__DOT__CORE__DOT__wdata = vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_res;
            vlSelfRef.top__DOT__CORE__DOT__rd = vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.rd_addr;
        } else {
            vlSelfRef.top__DOT__CORE__DOT__wdata = 0U;
            vlSelfRef.top__DOT__CORE__DOT__rd = 0U;
        }
    } else {
        vlSelfRef.top__DOT__CORE__DOT__wdata = 0U;
        vlSelfRef.top__DOT__CORE__DOT__rd = 0U;
    }
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 1U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 1U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb = 0U;
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__ldata = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:115: Assertion failed in %Ntop.CORE.LSU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_lsu.sv", 115, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:115: Assertion failed in %Ntop.CORE.LSU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_lsu.sv", 115, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid) {
                if (vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load) {
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 1U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 1U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr 
                        = (0xfffffffcU & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res);
                } else if (vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store) {
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 1U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 1U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 1U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr 
                        = (0xfffffffcU & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res);
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata 
                        = vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.sdata;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wstrb 
                        = ((0U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3))
                            ? 1U : ((1U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3))
                                     ? 3U : ((2U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3))
                                              ? 0xfU
                                              : 0U)));
                } else {
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 0U;
                }
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid) 
                 | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid))) {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 0U;
                vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__ldata 
                    = vlSymsp->TOP__top__DOT__axi_sram.rdata;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready) {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 1U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 1U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rready = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bready = 0U;
            }
        }
    }
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 1U;
        TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst = 0U;
        __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc = 0x80000000U;
        TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:103: Assertion failed in %Ntop.CORE.IFU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_ifu.sv", 103, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:103: Assertion failed in %Ntop.CORE.IFU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_ifu.sv", 103, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid) {
                __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc 
                    = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.jump) 
                        | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.branch))
                        ? vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.dnpc
                        : ((IData)(4U) + vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc));
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 1U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 1U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid) {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 0U;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst 
                    = vlSymsp->TOP__top__DOT__axi_sram.rdata;
                TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc 
                    = vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 1U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready) {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.arvalid = 0U;
                vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rready = 1U;
            }
        }
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
        = (0x3ffffffffULL & ((1ULL | ((QData)((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1)) 
                                      << 1U)) + vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__srcB));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
        = (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
           >> (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    if (((1U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)) 
         || (5U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
            = (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src 
               >> (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    } else if ((0xdU == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
            = VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_src, 
                             (0x1fU & vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2));
    }
    vlSymsp->TOP__top__DOT__axi_sram.rdata = TOP__top__DOT__axi_sram__DOT____Vdly__rdata;
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid 
        = ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc = __Vdly__top__DOT__CORE__DOT__IFU__DOT__pc;
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.wb = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.wb));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
        = (1U & (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                         >> 0x21U)));
    if ((2U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
            = (1U & ((IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                              >> 0x20U)) ^ (((~ (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                 >> 0x1fU)) 
                                             & ((vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 
                                                 >> 0x1fU) 
                                                & (IData)(
                                                          (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                                           >> 0x20U)))) 
                                            | ((~ (
                                                   (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src2 
                                                    >> 0x1fU) 
                                                   | (IData)(
                                                             (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                                              >> 0x20U)))) 
                                               & (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_src1 
                                                  >> 0x1fU)))));
    } else if ((3U == (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res 
            = (1U & (~ (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                                >> 0x21U))));
    }
    if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__pc;
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state))) {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.awaddr;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.wdata;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.araddr;
    } else {
        vlSymsp->TOP__top__DOT__axi_sram.awaddr = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.wdata = 0U;
        vlSymsp->TOP__top__DOT__axi_sram.araddr = 0U;
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.branch 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.branch));
    vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.jump 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.jump));
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_res = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.rd_addr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.sdata = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3 = 0U;
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.dnpc = 0U;
    } else {
        vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.alu_res 
            = vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__alu_res;
        vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.rd_addr 
            = vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.rd_addr;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res 
            = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.sdata 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.sdata;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.funct3 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.funct3;
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr 
            = vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next;
        vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.dnpc 
            = vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.dnpc;
    }
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready = 1U;
        TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:53: Assertion failed in %Ntop.CORE.IDU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_idu.sv", 53, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:53: Assertion failed in %Ntop.CORE.IDU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_idu.sv", 53, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid) {
                vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready = 0U;
                TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready = 1U;
                TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 0U;
            }
        } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                    || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready) {
                vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready = 1U;
                TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready = 0U;
                TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid = 1U;
            }
        }
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
        = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                   >> 1U));
    if ((8U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        if ((4U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
                    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
                        = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res;
                }
            }
        } else if ((1U & (~ ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl) 
                             >> 1U)))) {
            if ((1U & (~ (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl)))) {
                vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
                    = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                               >> 1U));
            }
        }
    } else if ((4U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))
                ? vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res
                : ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))
                    ? vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res
                    : vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__bit_res));
    } else if ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__comp_res;
    } else if ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_ctrl))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffffff8U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((4U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                         >> 0x1bU)) | ((2U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                              >> 0x1dU)) 
                                       | (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                          >> 0x1fU))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffffffc7U & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                            >> 0x15U)) | ((0x10U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0x17U)) 
                                          | (8U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   >> 0x19U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffffe3fU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x100U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                             >> 0xfU)) | ((0x80U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0x11U)) 
                                          | (0x40U 
                                             & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                >> 0x13U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffff1ffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x800U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                             >> 9U)) | ((0x400U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   >> 0xbU)) 
                                        | (0x200U & 
                                           (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                            >> 0xdU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffff8fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x4000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                              >> 3U)) | ((0x2000U & 
                                          (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                           >> 5U)) 
                                         | (0x1000U 
                                            & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               >> 7U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xfffc7fffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                               << 3U)) | ((0x10000U 
                                           & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                              << 1U)) 
                                          | (0x8000U 
                                             & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                >> 1U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xffe3ffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x100000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                << 9U)) | ((0x80000U 
                                            & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               << 7U)) 
                                           | (0x40000U 
                                              & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                 << 5U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xff1fffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x800000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                << 0xfU)) | ((0x400000U 
                                              & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                 << 0xdU)) 
                                             | (0x200000U 
                                                & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   << 0xbU)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xf8ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x4000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                 << 0x15U)) | ((0x2000000U 
                                                & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                   << 0x13U)) 
                                               | (0x1000000U 
                                                  & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                     << 0x11U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0xc7ffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((0x20000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                  << 0x1bU)) | ((0x10000000U 
                                                 & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                    << 0x19U)) 
                                                | (0x8000000U 
                                                   & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                                      << 0x17U)))));
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = ((0x3fffffffU & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out) 
               | ((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                   << 0x1fU) | (0x40000000U & (vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__shift_res 
                                               << 0x1dU))));
    } else {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out 
            = (IData)((vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__ALU__DOT__add_res_t 
                       >> 1U));
    }
    if ((1U & (~ VL_ONEHOT_I((((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr) 
                               << 1U) | (0xa0000048U 
                                         == vlSymsp->TOP__top__DOT__axi_sram.araddr)))))) {
        if ((0U != (((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr) 
                     << 1U) | (0xa0000048U == vlSymsp->TOP__top__DOT__axi_sram.araddr)))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: sram.sv:19: Assertion failed in %Ntop.sram: unique case, but multiple matches found for '32'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),32,
                             vlSymsp->TOP__top__DOT__axi_sram.araddr);
                Verilated::runFlushCallbacks();
                VL_STOP_MT("sram.sv", 19, "");
            }
        }
    }
    vlSelfRef.top__DOT__sram__DOT__dout = 0U;
    if ((0xa0000048U == vlSymsp->TOP__top__DOT__axi_sram.araddr)) {
        vlSelfRef.top__DOT__sram__DOT__dout = (IData)(vlSelfRef.top__DOT__sram__DOT__mtime);
    } else if ((0xa000004cU == vlSymsp->TOP__top__DOT__axi_sram.araddr)) {
        vlSelfRef.top__DOT__sram__DOT__dout = (IData)(
                                                      (vlSelfRef.top__DOT__sram__DOT__mtime 
                                                       >> 0x20U));
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.wb = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.wb));
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.rd_addr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.sdata = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.funct3 = 0U;
    } else {
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.rd_addr 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.rd_addr;
        if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
             & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.sdata 
                = vlSelfRef.top__DOT__CORE__DOT__rs2_val;
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.funct3 
                = (7U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                         >> 0xcU));
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:29: Assertion failed in %Ntop.CORE.IFU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_ifu.sv", 29, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_ifu.sv:29: Assertion failed in %Ntop.CORE.IFU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_ifu.sv", 29, "");
        }
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.branch 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.branch));
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.jump 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.jump));
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.dnpc 
        = ((IData)(vlSelfRef.rst) ? 0U : vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.dnpc);
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready = 1U;
        TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:48: Assertion failed in %Ntop.CORE.EXU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_exu.sv", 48, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:48: Assertion failed in %Ntop.CORE.EXU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_exu.sv", 48, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid) {
                vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready = 0U;
                TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready = 1U;
                TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 0U;
            }
        } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                    || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready) {
                vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready = 1U;
                TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready = 0U;
                TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid = 1U;
            }
        }
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid 
        = TOP__top__DOT__CORE__DOT__idu2exu__DOT____Vdly__valid;
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.branch 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__branch));
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.jump 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.jump));
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.rd_addr = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.wb = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.dnpc = 0U;
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr = 0U;
    } else {
        if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
             & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.rd_addr 
                = (0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                            >> 7U));
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.wb 
                = (((((((0x17U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) 
                        | (0x37U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))) 
                       | (0x6fU == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))) 
                      | (0x67U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))) 
                     | (0x13U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))) 
                    | (0x33U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))) 
                   | (3U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)));
        }
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.dnpc 
            = vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.dnpc;
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr 
            = vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next;
    }
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 1U;
        TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0U;
    } else {
        if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                   << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                              << 1U) 
                                             | (0U 
                                                == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))))) {
            if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                         << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                    << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:58: Assertion failed in %Ntop.CORE.LSU: unique case, but none matched for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -9,vlSymsp->name(),
                                 2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                    Verilated::runFlushCallbacks();
                    VL_STOP_MT("ysyx_24080006_lsu.sv", 58, "");
                }
            } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:58: Assertion failed in %Ntop.CORE.LSU: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_lsu.sv", 58, "");
            }
        }
        if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid) {
                if (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load) 
                     | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store))) {
                    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 0U;
                    TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0U;
                } else {
                    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 0U;
                    TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 1U;
                }
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 1U;
                TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid) 
                 | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid))) {
                vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 0U;
                TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 1U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 0U;
                TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
            if (vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready) {
                vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 1U;
                TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 0U;
            } else {
                vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready = 0U;
                TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid = 1U;
            }
        }
    }
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res 
        = ((2U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
            ? ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
                ? (1U & (~ vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))
                : (0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))
            : ((1U & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.alu_set))
                ? (1U & (~ (IData)((0U != vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out))))
                : vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_out));
    vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__branch 
        = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.branch) 
           & vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__alu_res);
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid 
        = TOP__top__DOT__CORE__DOT__exu2lsu__DOT____Vdly__valid;
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid 
        = ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.rvalid));
    vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid 
        = ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__ARB__DOT__arbiter_state)) 
           & (IData)(vlSymsp->TOP__top__DOT__axi_sram.bvalid));
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.jump = 0U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.dnpc = 0U;
    } else if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.jump 
            = ((0x6fU == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) 
               | (0x67U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)));
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.dnpc 
            = ((0x67U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst))
                ? (vlSelfRef.top__DOT__CORE__DOT__rs1_val 
                   + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                : (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc 
                   + vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm));
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:25: Assertion failed in %Ntop.CORE.EXU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_exu.sv", 25, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_exu.sv:25: Assertion failed in %Ntop.CORE.EXU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_exu.sv", 25, "");
        }
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.valid)
                ? 1U : 0U);
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)) 
                || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__curr)))) {
        vlSelfRef.top__DOT__CORE__DOT__EXU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.ready)
                ? 0U : 2U);
    }
    __Vtableidx3 = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid) 
                     << 4U) | (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready) 
                                << 3U) | (((IData)(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr) 
                                           << 1U) | (IData)(vlSelfRef.rst))));
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready 
        = Varb__ConstPool__TABLE_h51a550a5_0[__Vtableidx3];
    vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid 
        = Varb__ConstPool__TABLE_h69c58c6b_0[__Vtableidx3];
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.store));
    vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.load));
    vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.pc = TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__pc;
    vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready 
        = TOP__top__DOT__CORE__DOT__wbu2ifu__DOT____Vdly__ready;
    vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid 
        = TOP__top__DOT__CORE__DOT__lsu2wbu__DOT____Vdly__valid;
    vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr = 
        ((IData)(vlSelfRef.rst) ? 0U : (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next));
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:26: Assertion failed in %Ntop.CORE.LSU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_lsu.sv", 26, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_lsu.sv:26: Assertion failed in %Ntop.CORE.LSU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_lsu.sv", 26, "");
        }
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.valid)
                ? 1U : 0U);
    } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_ifu.rvalid)
                ? 2U : 1U);
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IFU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.ready)
                ? 0U : 2U);
    }
    vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__rshamt 
        = ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
            ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                ? 0x18U : 0x10U) : ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res)
                                     ? 8U : 0U));
    vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__alu_res 
        = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load)
            ? (vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__ldata 
               >> (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__rshamt))
            : vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.alu_res);
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr = 3U;
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.store = 0U;
    } else {
        vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr 
            = vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__next;
        if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
             & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.store 
                = (0x23U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst));
        }
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.valid)
                ? (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.load) 
                    | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__exu2lsu.store))
                    ? 1U : 2U) : 0U);
    } else if ((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.rvalid) 
                | (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__axi_lsu.bvalid))
                ? 2U : 1U);
    } else if ((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__LSU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.ready)
                ? 0U : 2U);
    }
    if (vlSelfRef.rst) {
        vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.load = 0U;
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr = 0U;
    } else {
        if (((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
             & (IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid))) {
            vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.load 
                = (3U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst));
        }
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr 
            = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next;
    }
    vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid 
        = TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__valid;
    vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
        = TOP__top__DOT__CORE__DOT__ifu2idu__DOT____Vdly__inst;
    vlSelfRef.__Vtableidx2 = (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__lsu2wbu.valid) 
                               << 3U) | (((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__wbu2ifu.ready) 
                                          << 2U) | (IData)(vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__curr)));
    vlSelfRef.top__DOT__CORE__DOT__WBU__DOT__next = 
        Varb__ConstPool__TABLE_h0e900e07_0[vlSelfRef.__Vtableidx2];
    vlSelfRef.top__DOT__CORE__DOT__rs1_val = vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile
        [(0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                   >> 0xfU))];
    vlSelfRef.__Vtableidx1 = ((0xeU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                       >> 0xbU)) | 
                              (0x63U == (0x7fU & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)));
    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_set 
        = Varb__ConstPool__TABLE_h588dbbb1_0[vlSelfRef.__Vtableidx1];
    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm = 
        (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                      >> 0x1fU))) << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                              >> 0x14U));
    vlSelfRef.top__DOT__CORE__DOT__rs2_val = vlSelfRef.top__DOT__CORE__DOT__REG__DOT__regfile
        [(0x1fU & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                   >> 0x14U))];
    if ((0x40U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
        if ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 4U)))) {
                if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                    = (((- (IData)(
                                                   (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0x1fU))) 
                                        << 0x14U) | 
                                       ((0xff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst) 
                                        | ((0x800U 
                                            & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                 >> 0x14U)))));
                            }
                        }
                    }
                } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x14U));
                        }
                    }
                } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                            = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0x800U 
                                             & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                     >> 7U)))));
                    }
                }
            }
            if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                        ? ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                ? 4U : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                            : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                        : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm);
            } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                        ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                            ? 4U : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm)
                        : vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm);
            } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                        = ((0U == (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                         >> 0xdU)))
                            ? (8U | (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                           >> 0xdU)))
                            : (3U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                     >> 0xdU)));
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__rs2_val;
                } else {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
                }
            } else {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
        }
    } else if ((0x20U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
        if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (0xfffff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst);
                        }
                    }
                }
            }
            if ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                        = ((8U & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                  >> 0x1bU)) | (7U 
                                                & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                   >> 0xcU)));
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__rs2_val;
                } else {
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                    vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                        = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
                }
            } else {
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
                vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                    = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                              >> 2U)))) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0xfe0U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                      >> 7U))));
                        }
                    }
                }
            }
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
                = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
        }
    } else {
        if ((0x10U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl 
                = ((8U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                    ? 0U : ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                             ? 0U : ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                      ? ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)
                                          ? ((1U == 
                                              (3U & 
                                               (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0xcU)))
                                              ? ((8U 
                                                  & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                     >> 0x1bU)) 
                                                 | (7U 
                                                    & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                       >> 0xcU)))
                                              : (7U 
                                                 & (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                    >> 0xcU)))
                                          : 0U) : 0U)));
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((4U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (0xfffff000U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst);
                        }
                    }
                } else if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                    if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                            = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                            >> 0x14U));
                    }
                }
            }
        } else {
            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_ctrl = 0U;
            if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                          >> 3U)))) {
                if ((1U & (~ (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                              >> 2U)))) {
                    if ((2U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                        if ((1U & vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst)) {
                            vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm 
                                = (((- (IData)((vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.inst 
                                                >> 0x14U));
                        }
                    }
                }
            }
        }
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__alu_src2 
            = vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__imm;
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))))) {
        if ((0U == (((2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                                << 1U) | (0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:30: Assertion failed in %Ntop.CORE.IDU: unique case, but none matched for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
                Verilated::runFlushCallbacks();
                VL_STOP_MT("ysyx_24080006_idu.sv", 30, "");
            }
        } else if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
            VL_WRITEF_NX("[%0t] %%Error: ysyx_24080006_idu.sv:30: Assertion failed in %Ntop.CORE.IDU: unique case, but multiple matches found for '2'h%x'\n",0,
                         64,VL_TIME_UNITED_Q(1),-9,
                         vlSymsp->name(),2,(IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr));
            Verilated::runFlushCallbacks();
            VL_STOP_MT("ysyx_24080006_idu.sv", 30, "");
        }
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr))) {
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__ifu2idu.valid)
                ? 1U : 0U);
    } else if (((1U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)) 
                || (2U == (IData)(vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__curr)))) {
        vlSelfRef.top__DOT__CORE__DOT__IDU__DOT__next 
            = ((IData)(vlSymsp->TOP__top__DOT__CORE__DOT__idu2exu.ready)
                ? 0U : 2U);
    }
}
