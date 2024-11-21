package ysyx_24080006_pkg;

  typedef enum logic [1:0] {
    RS1,
    PC,
    CONST0
  } alu_a_e;

  typedef enum logic [1:0] {
    IMM,
    RS2,
    PC_INCR,
    CSR
  } alu_b_e;

  typedef enum logic [3:0] {
    ADD,
    SUB,
    SLL,
    LT,
    LTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    EQ,
    NE,
    GE,
    GEU
  } alu_op_e;

  typedef struct packed {
    alu_a_e  alu_a;
    alu_b_e  alu_b;
    alu_op_e alu_op;
  } alu_set_t;

  typedef enum logic [6:0] {
    LUI      = 7'b0110111,
    AUIPC    = 7'b0010111,
    OP       = 7'b0110011,
    OP_IMM   = 7'b0010011,
    LOAD     = 7'b0000011,
    STORE    = 7'b0100011,
    JAL      = 7'b1101111,
    JALR     = 7'b1100111,
    BRANCH   = 7'b1100011,
    SYSTEM   = 7'b1110011,  //EBREAK, ECALL, CSR, MRET
    MISC_MEM = 7'b0001111
  } inst_op_e;

  typedef enum logic [11:0] {
    ECALL     = 12'h000,
    EBREAK    = 12'h001,
    MSTATUS   = 12'h300,
    MRET      = 12'h302,
    MTVEC     = 12'h305,
    MEPC      = 12'h341,
    MCAUSE    = 12'h342,
    MVENDORID = 12'hf11,
    MARCHID   = 12'hf12
  } csr_addr_e;

  typedef enum logic [2:0] {
    mstatus,
    mtvec,
    mepc,
    mcause,
    mvendorid,
    marchid
  } csr_name_e;

  typedef enum logic [1:0] {
    READ,
    WRITE,
    SET,
    CLEAR
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
  parameter int unsigned REG_WIDTH = 5;
`else
  parameter int unsigned REG_WIDTH = 4;
`endif

  typedef enum logic [1:0] {
    MULL,
    MULH,
    DIV,
    REM
  } mdu_op_e;

  typedef struct packed {
    logic mdu_enable;
    logic signed_a;
    logic signed_b;
    mdu_op_e mdu_op;
  } mdu_set_t;

  typedef struct packed {
    logic [REG_WIDTH-1:0] rs1_addr;
    logic [REG_WIDTH-1:0] rs2_addr;
    logic [REG_WIDTH-1:0] rd_addr;

    logic [31:0] imm;

    alu_set_t alu_set;
    csr_set_t csr_set;
    lsu_set_t lsu_set;
    mdu_set_t mdu_set;
    csr_name_e csr_name;
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
    logic is_zc;
    logic flush;
    logic valid;
  } stage_t;

  typedef struct packed {
    logic [32:0] a;
    logic [32:0] b;
  } mdu2alu_t;

  typedef struct packed {
    logic [33:0] res_34;
    logic [31:0] res_32;
    logic not_zero;
  } alu2mdu_t;

  parameter int unsigned IC_M = 5;  // 4
  parameter int unsigned IC_N = 1;  // 1
  parameter int unsigned IC_2 = 1 << IC_N;  // 2 ^ n

  typedef struct packed {
    logic valid;
    logic [31-IC_M-IC_N:0] tag;
    logic [(1<<(IC_M+3))-1:0] data;
  } icache_t;

  parameter logic [31:0] EBREAK_INST = 32'b0000000_00001_00000_000_00000_11100_11;
  parameter logic [31:0] NOP = 32'b0000000_00000_00000_000_00000_00100_11;


`ifdef SOC_MODE
  parameter RST_ADDR = 32'h3000_0000;
`else
  parameter RST_ADDR = 32'h8000_0000;
`endif

  typedef struct packed {
    logic        awvalid;
    logic [31:0] awaddr;
    logic [3:0]  awid;
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
    logic       awready;
    logic       wready;
    logic       bvalid;
    logic [1:0] bresp;
    logic [3:0] bid;
  } axi_w_s2m_t;

  typedef struct packed {
    logic        arvalid;
    logic [31:0] araddr;
    logic [3:0]  arid;
    logic [7:0]  arlen;
    logic [2:0]  arsize;
    logic [1:0]  arburst;
    logic        rready;
  } axi_r_m2s_t;

  typedef struct packed {
    logic        arready;
    logic        rvalid;
    logic [1:0]  rresp;
    logic [31:0] rdata;
    logic        rlast;
    logic [3:0]  rid;
  } axi_r_s2m_t;

endpackage
