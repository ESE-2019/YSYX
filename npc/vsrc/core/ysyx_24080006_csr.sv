module ysyx_24080006_csr
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input csr_set_t csr_set,
    input system_e csr_name,
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
      MSTATUS: csr_rdata = mstatus_q;
      MTVEC: csr_rdata = mtvec_q;
      MCOUNTINHIBIT: csr_rdata = mcountinhibit_q;
      MEPC: csr_rdata = mepc_q;
      MCAUSE: csr_rdata = mcause_q;
      MCYCLE, MINSTRET, MHPMCOUNTER3,
      MHPMCOUNTER4,  MHPMCOUNTER5,  MHPMCOUNTER6,  MHPMCOUNTER7,
      MHPMCOUNTER8,  MHPMCOUNTER9,  MHPMCOUNTER10, MHPMCOUNTER11,
      MHPMCOUNTER12, MHPMCOUNTER13, MHPMCOUNTER14, MHPMCOUNTER15,
      MHPMCOUNTER16, MHPMCOUNTER17, MHPMCOUNTER18, MHPMCOUNTER19,
      MHPMCOUNTER20, MHPMCOUNTER21, MHPMCOUNTER22, MHPMCOUNTER23,
      MHPMCOUNTER24, MHPMCOUNTER25, MHPMCOUNTER26, MHPMCOUNTER27,
      MHPMCOUNTER28, MHPMCOUNTER29, MHPMCOUNTER30, MHPMCOUNTER31:
      csr_rdata = counter_low[counter_addr];
      MCYCLEH, MINSTRETH, MHPMCOUNTER3H,
      MHPMCOUNTER4H,  MHPMCOUNTER5H,  MHPMCOUNTER6H,  MHPMCOUNTER7H,
      MHPMCOUNTER8H,  MHPMCOUNTER9H,  MHPMCOUNTER10H, MHPMCOUNTER11H,
      MHPMCOUNTER12H, MHPMCOUNTER13H, MHPMCOUNTER14H, MHPMCOUNTER15H,
      MHPMCOUNTER16H, MHPMCOUNTER17H, MHPMCOUNTER18H, MHPMCOUNTER19H,
      MHPMCOUNTER20H, MHPMCOUNTER21H, MHPMCOUNTER22H, MHPMCOUNTER23H,
      MHPMCOUNTER24H, MHPMCOUNTER25H, MHPMCOUNTER26H, MHPMCOUNTER27H,
      MHPMCOUNTER28H, MHPMCOUNTER29H, MHPMCOUNTER30H, MHPMCOUNTER31H:
      csr_rdata = counter_high[counter_addr];
      MVENDORID: csr_rdata = 32'h79737978;
      MARCHID: csr_rdata = 32'd24080006;
      default: illegal_csr = 1'b1;
    endcase
  end


  always_comb begin
    unique case (csr_set.csr_op)
      READ:    csr_wdata_masked = csr_wdata;
      WRITE:   csr_wdata_masked = csr_wdata;
      SET:     csr_wdata_masked = csr_wdata | csr_rdata;
      CLEAR:   csr_wdata_masked = ~csr_wdata & csr_rdata;
      default: csr_wdata_masked = csr_wdata;
    endcase
  end

  wire csr_we = csr_set.csr_enable & ~illegal_csr & csr_set.csr_op inside {WRITE, SET, CLEAR};

  always_comb begin
    mstatus_d = mstatus_q;
    mtvec_d = mtvec_q;
    mcountinhibit_d = mcountinhibit_q;
    mepc_d = mepc_q;
    mcause_d = mcause_q;
    if (csr_we) begin
      unique case (csr_name)
        MSTATUS: begin
          mstatus_d = 32'b0;
          mstatus_d[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW] = csr_wdata_masked[MSTATUS_MPP_HIGH:MSTATUS_MPP_LOW];
          mstatus_d[MSTATUS_MPIE] = csr_wdata_masked[MSTATUS_MPIE];
          mstatus_d[MSTATUS_MIE] = csr_wdata_masked[MSTATUS_MIE];
        end
        MTVEC: mtvec_d = {csr_wdata_masked[31:2], 2'b00};
        MCOUNTINHIBIT: mcountinhibit_d = {csr_wdata_masked[31:2], 1'b0, csr_wdata_masked[0]};
        MEPC: mepc_d = {csr_wdata_masked[31:1], 1'b0};
        MCAUSE: mcause_d = csr_wdata_masked;
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
        MSTATUS, MTVEC, MEPC, MCAUSE, MVENDORID, MARCHID: ;
        default: SKIP_DIFFTEST();
      endcase
  end

`endif

endmodule
