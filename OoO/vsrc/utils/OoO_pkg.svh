package OoO_pkg;

  localparam int unsigned ScoreboardDepth = 4;
  localparam int unsigned ScoreboardIndex = 2;
  localparam int unsigned WriteBackPorts = 2;
  localparam int unsigned InstPerFetch = 1;

  typedef enum logic [3:0] {
    FU_NONE,   // 0
    FU_LOAD,   // 1
    FU_STORE,  // 2
    FU_ALU,    // 3
    FU_BJU,     // 4
    FU_MDU,    // 5
    FU_CSR     // 6
  } fu_e;

  localparam int unsigned RegWidth = 5;

  typedef enum logic [7:0] {
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
    ALU_GEU,
    LSU_LW,
    LSU_SW,
    LSU_LH,
    LSU_LHU,
    LSU_SH,
    LSU_LB,
    LSU_SB,
    LSU_LBU,
    MDU_MUL,
    MDU_MULH,
    MDU_MULHU,
    MDU_MULHSU,
    MDU_DIV,
    MDU_DIVU,
    MDU_REM,
    MDU_REMU,
    CSR_READ,
    CSR_WRITE,
    CSR_SET,
    CSR_CLEAR,

    SYS_ECALL,
    SYS_EBREAK,
    SYS_MRET,
    SYS_FENCE,
    SYS_FENCE_I,
    SYS_WFI,

    BJU_JAL,
    BJU_JALR,
    BJU_BRANCH,

    ALU_SH1ADD,
    ALU_SH2ADD,
    ALU_SH3ADD,

    ALU_ANDN,
    ALU_ORN,
    ALU_XNOR,
    ALU_CLZ,
    ALU_CTZ,
    ALU_CPOP,
    ALU_MAX,
    ALU_MAXU,
    ALU_MIN,
    ALU_MINU,
    ALU_SEXTB,
    ALU_SEXTH,
    ALU_ZEXTH,
    ALU_ROL,
    ALU_ROR,
    ALU_ORCB,
    ALU_REV8,

    ALU_BCLR,
    ALU_BEXT,
    ALU_BINV,
    ALU_BSET,

    ALU_CZERO_EQZ,
    ALU_CZERO_NEZ
  } fu_op_e;

  typedef struct packed {
    logic valid;
    logic [31:0] data;
    logic [ScoreboardIndex-1:0] idx;
    logic [31:0] dbg_pc_wdata; // used for dbg
  } writeback_t;

  typedef struct packed {
    fu_e                        fu;
    fu_op_e                     operation;
    logic [31:0]                operand_a;
    logic [31:0]                operand_b;
    logic [31:0]                imm;
    logic [ScoreboardIndex-1:0] idx;
  } fu_data_t;

  typedef enum logic [2:0] {
    CF_NONE,
    CF_BRANCH,
    CF_JAL,
    CF_JALR,
    CF_RET
  } cf_e;

  typedef struct packed {
    cf_e         cf;
    logic [31:0] predict_addr;
  } bpu_t;

  typedef struct packed {
    logic [31:0] pc;
    logic [31:0] inst;
    bpu_t        bp;
  } frontend_t;

  typedef struct packed {
    logic        valid;
    logic        is_mispredict;
    logic        is_taken;
    cf_e         cf;
    logic [31:0] pc;
    logic [31:0] target_address;
  } bju_t;

  typedef struct packed {
    logic valid;
    logic [31:0] inst;
    logic [31:0] pc;
  } aligner_t;

  typedef struct packed {
    logic valid;
    logic taken;
  } bht_predict_t;

  typedef struct packed {
    logic        valid;
    logic        taken;
    logic [31:0] pc;
  } bht_update_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] target_address;
  } btb_predict_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] target_address;
  } btb_update_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] ra;
  } ras_predict_t;

  typedef struct packed {
    logic push;
    logic pop;
    logic [31:0] ra;
  } ras_update_t;

  typedef struct packed {
    logic branch;
    logic jal;
    logic jalr;
    logic call;
    logic ret;
    logic [31:0] imm;
  } predecoder_t;

  typedef struct packed {
    logic [ScoreboardIndex-1:0] idx;
    fu_e fu;
    fu_op_e op;
    logic [RegWidth-1:0] rs1;
    logic [RegWidth-1:0] rs2;
    logic [RegWidth-1:0] rd;
    logic use_imm;  // operand b
    logic use_zimm;  // operand a
    logic use_pc;  // operand a
    bpu_t bp;
    logic is_rv16;
    logic valid;
    logic [31:0] pc;
    logic [31:0] result;  // imm
    // used for debug
    logic [31:0] dbg_insn;
    logic [31:0] dbg_imm;
    logic [31:0] dbg_rs1;
    logic [31:0] dbg_rs2;
    logic [31:0] dbg_pc_wdata;
  } decoder_t;

  typedef struct packed {
    logic issued;
    decoder_t instr;
  } scoreboard_t;

  typedef struct packed {
    logic [ScoreboardDepth-1:0] issued;
    writeback_t [WriteBackPorts-1:0] wb;
    decoder_t [ScoreboardDepth-1:0] instr;
  } forwarding_t;

  localparam int unsigned IcacheLineSize = 5;  // 4
  localparam int unsigned IcacheLineNum = 1;  // 1

  typedef struct packed {
    logic valid;
    logic [31-IcacheLineSize-IcacheLineNum:0] tag;
    logic [(1<<(IcacheLineSize+3))-1:0] data;
  } icache_t;

  localparam int unsigned DcacheLineSize = 2;
  localparam int unsigned DcacheLineNum = 4;

  typedef struct packed {
    logic valid;
    logic [31-DcacheLineSize-DcacheLineNum:0] tag;
    logic [(1<<(DcacheLineSize+3))-1:0] data;
  } dcache_t;

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
