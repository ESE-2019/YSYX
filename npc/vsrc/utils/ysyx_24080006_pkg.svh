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
    ECALL          = 12'h000,
    EBREAK         = 12'h001,
    WFI            = 12'h105,
    MSTATUS        = 12'h300,
    MRET           = 12'h302,
    MTVEC          = 12'h305,
    MCOUNTINHIBIT  = 12'h320,
    MEPC           = 12'h341,
    MCAUSE         = 12'h342,
    MCYCLE         = 12'hB00,
    MINSTRET       = 12'hB02,
    MHPMCOUNTER3   = 12'hB03,
    MHPMCOUNTER4   = 12'hB04,
    MHPMCOUNTER5   = 12'hB05,
    MHPMCOUNTER6   = 12'hB06,
    MHPMCOUNTER7   = 12'hB07,
    MHPMCOUNTER8   = 12'hB08,
    MHPMCOUNTER9   = 12'hB09,
    MHPMCOUNTER10  = 12'hB0A,
    MHPMCOUNTER11  = 12'hB0B,
    MHPMCOUNTER12  = 12'hB0C,
    MHPMCOUNTER13  = 12'hB0D,
    MHPMCOUNTER14  = 12'hB0E,
    MHPMCOUNTER15  = 12'hB0F,
    MHPMCOUNTER16  = 12'hB10,
    MHPMCOUNTER17  = 12'hB11,
    MHPMCOUNTER18  = 12'hB12,
    MHPMCOUNTER19  = 12'hB13,
    MHPMCOUNTER20  = 12'hB14,
    MHPMCOUNTER21  = 12'hB15,
    MHPMCOUNTER22  = 12'hB16,
    MHPMCOUNTER23  = 12'hB17,
    MHPMCOUNTER24  = 12'hB18,
    MHPMCOUNTER25  = 12'hB19,
    MHPMCOUNTER26  = 12'hB1A,
    MHPMCOUNTER27  = 12'hB1B,
    MHPMCOUNTER28  = 12'hB1C,
    MHPMCOUNTER29  = 12'hB1D,
    MHPMCOUNTER30  = 12'hB1E,
    MHPMCOUNTER31  = 12'hB1F,
    MCYCLEH        = 12'hB80,
    MINSTRETH      = 12'hB82,
    MHPMCOUNTER3H  = 12'hB83,
    MHPMCOUNTER4H  = 12'hB84,
    MHPMCOUNTER5H  = 12'hB85,
    MHPMCOUNTER6H  = 12'hB86,
    MHPMCOUNTER7H  = 12'hB87,
    MHPMCOUNTER8H  = 12'hB88,
    MHPMCOUNTER9H  = 12'hB89,
    MHPMCOUNTER10H = 12'hB8A,
    MHPMCOUNTER11H = 12'hB8B,
    MHPMCOUNTER12H = 12'hB8C,
    MHPMCOUNTER13H = 12'hB8D,
    MHPMCOUNTER14H = 12'hB8E,
    MHPMCOUNTER15H = 12'hB8F,
    MHPMCOUNTER16H = 12'hB90,
    MHPMCOUNTER17H = 12'hB91,
    MHPMCOUNTER18H = 12'hB92,
    MHPMCOUNTER19H = 12'hB93,
    MHPMCOUNTER20H = 12'hB94,
    MHPMCOUNTER21H = 12'hB95,
    MHPMCOUNTER22H = 12'hB96,
    MHPMCOUNTER23H = 12'hB97,
    MHPMCOUNTER24H = 12'hB98,
    MHPMCOUNTER25H = 12'hB99,
    MHPMCOUNTER26H = 12'hB9A,
    MHPMCOUNTER27H = 12'hB9B,
    MHPMCOUNTER28H = 12'hB9C,
    MHPMCOUNTER29H = 12'hB9D,
    MHPMCOUNTER30H = 12'hB9E,
    MHPMCOUNTER31H = 12'hB9F,
    MVENDORID      = 12'hF11,
    MARCHID        = 12'hF12
  } system_e;

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
    system_e csr_name;
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
    logic zc_err;
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
  parameter int unsigned IC_N = 5;  // 1
  parameter int unsigned IC_2 = 1 << IC_N;  // 2 ^ n

  typedef struct packed {
    logic valid;
    logic [31-IC_M-IC_N:0] tag;
    logic [(1<<(IC_M+3))-1:0] data;
  } icache_t;

  parameter logic [31:0] EBREAK_INST = 32'b0000000_00001_00000_000_00000_11100_11;
  parameter logic [31:0] WFI_INST = 32'h10500073;
  parameter logic [31:0] NOP = 32'b0000000_00000_00000_000_00000_00100_11;


`ifdef SOC_MODE
  parameter logic [31:0] RST_ADDR = 32'h3000_0000;
`else
  parameter logic [31:0] RST_ADDR = 32'h8000_0000;
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
