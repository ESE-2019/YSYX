`default_nettype none

module csr_regfile
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic ecall,
    input logic mret,

    input fu_op_e csr_op,

    input logic [11:0] csr_addr,
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

    output logic [31:0] mtvec_addr,
    output logic mret_valid,
    output logic [31:0] mepc_addr,

    input  logic [31:0] csr_wdata,
    output logic [31:0] csr_rdata
);

  import riscv_instr::*;

  localparam int unsigned MstatusMie = 3;
  localparam int unsigned MstatusMpie = 7;
  localparam int unsigned MstatusMppLow = 11;
  localparam int unsigned MstatusMppHigh = 12;

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
  wire [4:0] counter_addr = csr_addr[4:0];

  assign mtvec_addr = mtvec_q;
  assign mepc_addr  = mepc_q;

  always_comb begin
    csr_rdata   = 32'b0;
    illegal_csr = 1'b0;
    unique case (csr_addr)
      CSR_MSTATUS: csr_rdata = mstatus_q;
      CSR_MTVEC: csr_rdata = mtvec_q;
      CSR_MCOUNTINHIBIT: csr_rdata = mcountinhibit_q;
      CSR_MEPC: csr_rdata = mepc_q;
      CSR_MCAUSE: csr_rdata = mcause_q;
      CSR_MCYCLE, CSR_MINSTRET,
      CSR_MHPMCOUNTER3,
      CSR_MHPMCOUNTER4,  CSR_MHPMCOUNTER5,
      CSR_MHPMCOUNTER6,  CSR_MHPMCOUNTER7,
      CSR_MHPMCOUNTER8,  CSR_MHPMCOUNTER9,
      CSR_MHPMCOUNTER10, CSR_MHPMCOUNTER11,
      CSR_MHPMCOUNTER12, CSR_MHPMCOUNTER13,
      CSR_MHPMCOUNTER14, CSR_MHPMCOUNTER15,
      CSR_MHPMCOUNTER16, CSR_MHPMCOUNTER17,
      CSR_MHPMCOUNTER18, CSR_MHPMCOUNTER19,
      CSR_MHPMCOUNTER20, CSR_MHPMCOUNTER21,
      CSR_MHPMCOUNTER22, CSR_MHPMCOUNTER23,
      CSR_MHPMCOUNTER24, CSR_MHPMCOUNTER25,
      CSR_MHPMCOUNTER26, CSR_MHPMCOUNTER27,
      CSR_MHPMCOUNTER28, CSR_MHPMCOUNTER29,
      CSR_MHPMCOUNTER30, CSR_MHPMCOUNTER31:
      csr_rdata = counter_low[counter_addr];
      CSR_MCYCLEH, CSR_MINSTRETH,
      CSR_MHPMCOUNTER3H,
      CSR_MHPMCOUNTER4H,  CSR_MHPMCOUNTER5H,
      CSR_MHPMCOUNTER6H,  CSR_MHPMCOUNTER7H,
      CSR_MHPMCOUNTER8H,  CSR_MHPMCOUNTER9H,
      CSR_MHPMCOUNTER10H, CSR_MHPMCOUNTER11H,
      CSR_MHPMCOUNTER12H, CSR_MHPMCOUNTER13H,
      CSR_MHPMCOUNTER14H, CSR_MHPMCOUNTER15H,
      CSR_MHPMCOUNTER16H, CSR_MHPMCOUNTER17H,
      CSR_MHPMCOUNTER18H, CSR_MHPMCOUNTER19H,
      CSR_MHPMCOUNTER20H, CSR_MHPMCOUNTER21H,
      CSR_MHPMCOUNTER22H, CSR_MHPMCOUNTER23H,
      CSR_MHPMCOUNTER24H, CSR_MHPMCOUNTER25H,
      CSR_MHPMCOUNTER26H, CSR_MHPMCOUNTER27H,
      CSR_MHPMCOUNTER28H, CSR_MHPMCOUNTER29H,
      CSR_MHPMCOUNTER30H, CSR_MHPMCOUNTER31H:
      csr_rdata = counter_high[counter_addr];
      CSR_MVENDORID: csr_rdata = 32'h79737978;
      CSR_MARCHID: csr_rdata = 32'd24080006;
      default: illegal_csr = 1'b1;
    endcase
  end


  always_comb begin
    unique case (csr_op)
      CSR_READ:  csr_wdata_masked = csr_wdata;
      CSR_WRITE: csr_wdata_masked = csr_wdata;
      CSR_SET:   csr_wdata_masked = csr_wdata | csr_rdata;
      CSR_CLEAR: csr_wdata_masked = ~csr_wdata & csr_rdata;
      default:   csr_wdata_masked = csr_wdata;
    endcase
  end

  wire csr_we = ~illegal_csr & csr_op inside {CSR_WRITE, CSR_SET, CSR_CLEAR};

  always_comb begin
    mstatus_d = mstatus_q;
    mtvec_d = mtvec_q;
    mcountinhibit_d = mcountinhibit_q;
    mepc_d = mepc_q;
    mcause_d = mcause_q;
    if (csr_we) begin  // TODO add more csr
      unique case (csr_addr)
        CSR_MSTATUS: begin
          mstatus_d = 32'b0;
          mstatus_d[MstatusMppHigh:MstatusMppLow] = csr_wdata_masked[MstatusMppHigh:MstatusMppLow];
          mstatus_d[MstatusMpie] = csr_wdata_masked[MstatusMpie];
          mstatus_d[MstatusMie] = csr_wdata_masked[MstatusMie];
        end
        CSR_MTVEC: mtvec_d = {csr_wdata_masked[31:2], 2'b00};
        CSR_MCOUNTINHIBIT: mcountinhibit_d = {csr_wdata_masked[31:2], 1'b0, csr_wdata_masked[0]};
        CSR_MEPC: mepc_d = {csr_wdata_masked[31:1], 1'b0};
        CSR_MCAUSE: mcause_d = csr_wdata_masked;
        default: ;
      endcase
    end
  end

  always_comb begin
    mstatus_ecall = 32'b0;
    mstatus_ecall[MstatusMppHigh:MstatusMppLow] = 2'b11;
    mstatus_ecall[MstatusMpie] = mstatus_q[MstatusMie];
    mstatus_ecall[MstatusMie] = 1'b0;
  end

  always_comb begin
    mstatus_mret = 32'b0;
    mstatus_mret[MstatusMppHigh:MstatusMppLow] = 2'b11;
    mstatus_mret[MstatusMpie] = 1'b1;
    mstatus_mret[MstatusMie] = mstatus_q[MstatusMpie];
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      mstatus_q <= {{(31 - MstatusMppHigh) {1'b0}}, 2'b11, {MstatusMppLow{1'b0}}};
      mtvec_q <= 32'b0;
      mcountinhibit_q <= 32'b0;
      mepc_q <= 32'b0;
      mcause_q <= 32'b0;
      mret_valid <= 1'b0;
    end else begin
      if (ecall) begin
        mstatus_q <= mstatus_ecall;
        mcause_q <= csr_cause;
        mepc_q <= {csr_pc[31:1], 1'b0};
        mret_valid <= 1'b0;
      end else if (mret) begin
        mret_valid <= 1'b1;
        mstatus_q  <= mstatus_mret;
      end else begin
        mstatus_q <= mstatus_d;
        mtvec_q <= mtvec_d;
        mcountinhibit_q <= mcountinhibit_d;
        mepc_q <= mepc_d;
        mcause_q <= mcause_d;
        mret_valid <= 1'b0;
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
    counter HPM (
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

endmodule

`default_nettype wire
