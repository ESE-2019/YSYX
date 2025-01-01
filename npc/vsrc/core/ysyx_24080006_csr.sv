`default_nettype none

module ysyx_24080006_csr
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input csr_set_t csr_set,
    input logic [11:0] csr_name,
    input logic [31:0] csr_pc,

    input logic instret,
    input logic icache_hit,
    input logic icache_miss,
    input logic icache_skip,
    input logic load_num,
    input logic load_cycle,
    input logic store_num,
    input logic store_cycle,
    input logic is_compressed,
    input logic fetch_cycle,

    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  localparam int unsigned MSTATUS_MIE = 3;
  localparam int unsigned MSTATUS_MPIE = 7;
  localparam int unsigned MSTATUS_MPP_LOW = 11;
  localparam int unsigned MSTATUS_MPP_HIGH = 12;

  logic [31:0] csr_wdata_masked;
  logic illegal_csr;

  logic [31:0] mstatus_ecall, mstatus_mret;
  wire [31:0] csr_cause = 32'd11;

  logic [31:0] mstatus_q, mstatus_d;
  logic [31:0] mtvec_q, mtvec_d;
  logic [31:0] mcountinhibit_q, mcountinhibit_d;
  logic [31:0] mepc_q, mepc_d;
  logic [31:0] mcause_q, mcause_d;
  logic [31:0] counter_low[32];
  logic [31:0] counter_high[32];

  logic [31:0] counter_incr_en;
  wire [4:0] counter_addr = csr_name[4:0];

  always_comb begin
    csr_rdata   = 32'b0;
    illegal_csr = 1'b0;
    unique case (csr_name)
      riscv_instr::CSR_MSTATUS: csr_rdata = mstatus_q;
      riscv_instr::CSR_MTVEC: csr_rdata = mtvec_q;
      riscv_instr::CSR_MCOUNTINHIBIT: csr_rdata = mcountinhibit_q;
      riscv_instr::CSR_MEPC: csr_rdata = mepc_q;
      riscv_instr::CSR_MCAUSE: csr_rdata = mcause_q;
      riscv_instr::CSR_MCYCLE, riscv_instr::CSR_MINSTRET, riscv_instr::CSR_MHPMCOUNTER3,
      riscv_instr::CSR_MHPMCOUNTER4,  riscv_instr::CSR_MHPMCOUNTER5,  riscv_instr::CSR_MHPMCOUNTER6,  riscv_instr::CSR_MHPMCOUNTER7,
      riscv_instr::CSR_MHPMCOUNTER8,  riscv_instr::CSR_MHPMCOUNTER9,  riscv_instr::CSR_MHPMCOUNTER10, riscv_instr::CSR_MHPMCOUNTER11,
      riscv_instr::CSR_MHPMCOUNTER12, riscv_instr::CSR_MHPMCOUNTER13, riscv_instr::CSR_MHPMCOUNTER14, riscv_instr::CSR_MHPMCOUNTER15,
      riscv_instr::CSR_MHPMCOUNTER16, riscv_instr::CSR_MHPMCOUNTER17, riscv_instr::CSR_MHPMCOUNTER18, riscv_instr::CSR_MHPMCOUNTER19,
      riscv_instr::CSR_MHPMCOUNTER20, riscv_instr::CSR_MHPMCOUNTER21, riscv_instr::CSR_MHPMCOUNTER22, riscv_instr::CSR_MHPMCOUNTER23,
      riscv_instr::CSR_MHPMCOUNTER24, riscv_instr::CSR_MHPMCOUNTER25, riscv_instr::CSR_MHPMCOUNTER26, riscv_instr::CSR_MHPMCOUNTER27,
      riscv_instr::CSR_MHPMCOUNTER28, riscv_instr::CSR_MHPMCOUNTER29, riscv_instr::CSR_MHPMCOUNTER30, riscv_instr::CSR_MHPMCOUNTER31:
      csr_rdata = counter_low[counter_addr];
      riscv_instr::CSR_MCYCLEH, riscv_instr::CSR_MINSTRETH, riscv_instr::CSR_MHPMCOUNTER3H,
      riscv_instr::CSR_MHPMCOUNTER4H,  riscv_instr::CSR_MHPMCOUNTER5H,  riscv_instr::CSR_MHPMCOUNTER6H,  riscv_instr::CSR_MHPMCOUNTER7H,
      riscv_instr::CSR_MHPMCOUNTER8H,  riscv_instr::CSR_MHPMCOUNTER9H,  riscv_instr::CSR_MHPMCOUNTER10H, riscv_instr::CSR_MHPMCOUNTER11H,
      riscv_instr::CSR_MHPMCOUNTER12H, riscv_instr::CSR_MHPMCOUNTER13H, riscv_instr::CSR_MHPMCOUNTER14H, riscv_instr::CSR_MHPMCOUNTER15H,
      riscv_instr::CSR_MHPMCOUNTER16H, riscv_instr::CSR_MHPMCOUNTER17H, riscv_instr::CSR_MHPMCOUNTER18H, riscv_instr::CSR_MHPMCOUNTER19H,
      riscv_instr::CSR_MHPMCOUNTER20H, riscv_instr::CSR_MHPMCOUNTER21H, riscv_instr::CSR_MHPMCOUNTER22H, riscv_instr::CSR_MHPMCOUNTER23H,
      riscv_instr::CSR_MHPMCOUNTER24H, riscv_instr::CSR_MHPMCOUNTER25H, riscv_instr::CSR_MHPMCOUNTER26H, riscv_instr::CSR_MHPMCOUNTER27H,
      riscv_instr::CSR_MHPMCOUNTER28H, riscv_instr::CSR_MHPMCOUNTER29H, riscv_instr::CSR_MHPMCOUNTER30H, riscv_instr::CSR_MHPMCOUNTER31H:
      csr_rdata = counter_high[counter_addr];
      riscv_instr::CSR_MVENDORID: csr_rdata = 32'h79737978;
      riscv_instr::CSR_MARCHID: csr_rdata = 32'd24080006;
      default: illegal_csr = 1'b1;
    endcase
  end


  always_comb begin
    unique case (csr_set.csr_op)
      CSR_READ:  csr_wdata_masked = csr_wdata;
      CSR_WRITE: csr_wdata_masked = csr_wdata;
      CSR_SET:   csr_wdata_masked = csr_wdata | csr_rdata;
      CSR_CLEAR: csr_wdata_masked = ~csr_wdata & csr_rdata;
      default:   csr_wdata_masked = csr_wdata;
    endcase
  end

  wire csr_we = csr_set.csr_enable & ~illegal_csr & csr_set.csr_op inside {CSR_WRITE, CSR_SET, CSR_CLEAR};

  always_comb begin
    mstatus_d = mstatus_q;
    mtvec_d = mtvec_q;
    mcountinhibit_d = mcountinhibit_q;
    mepc_d = mepc_q;
    mcause_d = mcause_q;
    if (csr_we) begin  // TODO add more csr
      unique case (csr_name)
        riscv_instr::CSR_MSTATUS: begin
          mstatus_d = 32'b0;
          mstatus_d[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW] = csr_wdata_masked[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW];
          mstatus_d[MSTATUS_MPIE] = csr_wdata_masked[MSTATUS_MPIE];
          mstatus_d[MSTATUS_MIE] = csr_wdata_masked[MSTATUS_MIE];
        end
        riscv_instr::CSR_MTVEC: mtvec_d = {csr_wdata_masked[31:2], 2'b00};
        riscv_instr::CSR_MCOUNTINHIBIT:
        mcountinhibit_d = {csr_wdata_masked[31:2], 1'b0, csr_wdata_masked[0]};
        riscv_instr::CSR_MEPC: mepc_d = {csr_wdata_masked[31:1], 1'b0};
        riscv_instr::CSR_MCAUSE: mcause_d = csr_wdata_masked;
        default: ;
      endcase
    end
  end

  always_comb begin
    mstatus_ecall = 32'b0;
    mstatus_ecall[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW] = 2'b11;
    mstatus_ecall[MSTATUS_MPIE] = mstatus_q[MSTATUS_MIE];
    mstatus_ecall[MSTATUS_MIE] = 1'b0;
  end

  always_comb begin
    mstatus_mret = 32'b0;
    mstatus_mret[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW] = 2'b11;
    mstatus_mret[MSTATUS_MPIE] = 1'b1;
    mstatus_mret[MSTATUS_MIE] = mstatus_q[MSTATUS_MPIE];
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      mstatus_q <= {{(31 - MSTATUS_MPP_HIGH) {1'b0}}, 2'b11, {MSTATUS_MPP_LOW{1'b0}}};
      mtvec_q <= 32'b0;
      mcountinhibit_q <= 32'b0;
      mepc_q <= 32'b0;
      mcause_q <= 32'b0;
    end else begin
      if (ecall) begin
        mstatus_q <= mstatus_ecall;
        mcause_q <= csr_cause;
        mepc_q <= {csr_pc[31:1], 1'b0};
      end else if (mret) begin
        mstatus_q <= mstatus_mret;
      end else begin
        mstatus_q <= mstatus_d;
        mtvec_q <= mtvec_d;
        mcountinhibit_q <= mcountinhibit_d;
        mepc_q <= mepc_d;
        mcause_q <= mcause_d;
      end
    end
  end

  always_comb begin
    counter_incr_en = 32'b0;
    counter_incr_en[0] = 1'b1;
    counter_incr_en[2] = instret;
    counter_incr_en[3] = icache_hit;
    counter_incr_en[4] = icache_miss;
    counter_incr_en[5] = icache_skip;
    counter_incr_en[6] = load_num;
    counter_incr_en[7] = load_cycle;
    counter_incr_en[8] = store_num;
    counter_incr_en[9] = store_cycle;
    counter_incr_en[10] = is_compressed;
    counter_incr_en[11] = fetch_cycle;
  end

  for (genvar i = 0; i < 32; i++) begin : gen_counter
    ysyx_24080006_counter HPM (
        .clock             (clock),
        .reset             (reset),
        .counter_incr_en   (counter_incr_en[i] & ~mcountinhibit_q[i]),
        .counter_high_we   (1'b0),
        .counter_low_we    (1'b0),
        .counter_wdata     (32'b0),
        .counter_high_rdata(counter_high[i]),
        .counter_low_rdata (counter_low[i])
    );
  end

`ifdef SIM_MODE
  import "DPI-C" function void SKIP_DIFFTEST();
  always_ff @(posedge clock) begin
    if (csr_set.csr_enable)
      unique case (csr_name)
        riscv_instr::CSR_MSTATUS, riscv_instr::CSR_MTVEC, riscv_instr::CSR_MEPC, riscv_instr::CSR_MCAUSE, riscv_instr::CSR_MVENDORID, riscv_instr::CSR_MARCHID:
        ;
        default: SKIP_DIFFTEST();
      endcase
  end

`endif

endmodule

`default_nettype wire
