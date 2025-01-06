package ysyx_24080006_pkg;

  typedef enum logic [1:0] {
    ALU_A_RS1,
    ALU_A_PC,
    ALU_A_0
  } alu_a_e;

  typedef enum logic [1:0] {
    ALU_B_IMM,
    ALU_B_RS2,
    ALU_B_PC_INCR,
    ALU_B_CSR
  } alu_b_e;

  typedef enum logic [3:0] {
    ALU_ADD,
    ALU_SUB,
    ALU_SLL,
    ALU_LT,
    ALU_LTU,
    ALU_XOR,
    ALU_SRL,
    ALU_SRA,
    ALU_OR,
    ALU_AND,
    ALU_EQ,
    ALU_NE,
    ALU_GE,
    ALU_GEU
  } alu_op_e;

  typedef struct packed {
    alu_a_e  alu_a;
    alu_b_e  alu_b;
    alu_op_e alu_op;
  } alu_set_t;

  typedef enum logic [1:0] {
    CSR_READ,
    CSR_WRITE,
    CSR_SET,
    CSR_CLEAR
  } csr_op_e;

  typedef struct packed {
    logic csr_enable;
    logic csr_uimm;
    csr_op_e csr_op;
  } csr_set_t;

  typedef struct packed {
    logic lsu_enable;
    logic lsu_write;
    logic lsu_sext;
    logic [1:0] lsu_size;
  } lsu_set_t;

`ifdef SIM_MODE
  localparam int unsigned RegWidth = 5;
`else
  localparam int unsigned RegWidth = 4;
`endif

  typedef enum logic [1:0] {
    ALU_MULL,
    ALU_MULH,
    ALU_DIV,
    ALU_REM
  } mdu_op_e;

  typedef struct packed {
    logic mdu_enable;
    logic signed_a;
    logic signed_b;
    mdu_op_e mdu_op;
  } mdu_set_t;

  typedef struct packed {
    logic [RegWidth-1:0] rs1_addr;
    logic [RegWidth-1:0] rs2_addr;
    logic [RegWidth-1:0] rd_addr;

    logic [31:0] imm;

    alu_set_t alu_set;
    csr_set_t csr_set;
    lsu_set_t lsu_set;
    mdu_set_t mdu_set;
    logic [11:0] csr_name;
    logic reg_we;

    logic jal;
    logic jalr;
    logic branch;
    logic ecall;
    logic mret;
  } decoder_t;

  typedef struct packed {
    logic [31:0] pc, dnpc;
    logic [31:0] alu_a, alu_b;
    logic [31:0] rs1_data, rs2_data, csr_rdata;
    logic jump, branch;
    logic rv16;
    logic rv16_err;
    logic flush;
    logic valid;
  } stage_t;

  typedef struct packed {
    logic [32:0] a;
    logic [32:0] b;
  } mdu2alu_t;

  typedef struct packed {
    logic [33:0] res;
    logic not_zero;
  } alu2mdu_t;

  localparam int unsigned IcacheLineSize = 5;  // 4
  localparam int unsigned IcacheLineNum = 11;  // 1

  typedef struct packed {
    logic valid;
    logic [31-IcacheLineSize-IcacheLineNum:0] tag;
    logic [(1<<(IcacheLineSize+3))-1:0] data;
  } icache_t;

`ifdef SOC_MODE
  localparam logic [31:0] RstAddr = 32'h3000_0000;
`else
  localparam logic [31:0] RstAddr = 32'h8000_0000;
`endif

  typedef struct packed {
    logic        awvalid;
    logic [31:0] awaddr;
    //logic [3:0]  awid;
    logic [7:0]  awlen;
    logic [2:0]  awsize;
    logic [1:0]  awburst;
    logic        wvalid;
    logic [31:0] wdata;
    logic [3:0]  wstrb;
    logic        wlast;
    logic        bready;
  } axi_w_m2s_t;

  typedef struct packed {
    logic awready;
    logic wready;
    logic bvalid;
    //logic [1:0] bresp;
    //logic [3:0] bid;
  } axi_w_s2m_t;

  typedef struct packed {
    logic        arvalid;
    logic [31:0] araddr;
    //logic [3:0]  arid;
    logic [7:0]  arlen;
    logic [2:0]  arsize;
    logic [1:0]  arburst;
    logic        rready;
  } axi_r_m2s_t;

  typedef struct packed {
    logic        arready;
    logic        rvalid;
    //logic [1:0]  rresp;
    logic [31:0] rdata;
    logic        rlast;
    //logic [3:0]  rid;
  } axi_r_s2m_t;

endpackage
