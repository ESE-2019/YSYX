package OoO_pkg;

  localparam int unsigned ScoreboardDepth = 4;
  localparam int unsigned ScoreboardIndex = 2;
  localparam int unsigned WriteBackPorts = 2;

  typedef enum logic [3:0] {
    FU_NONE,   // 0
    FU_LOAD,   // 1
    FU_STORE,  // 2
    FU_ALU,    // 3
    FU_BU,     // 4
    FU_MDU,    // 5
    FU_CSR     // 6
  } fu_e;

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

  localparam int unsigned RegWidth = 5;

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
    CF_ECALL,
    CF_MRET,
    CF_FENCE,
    CF_FENCE_I,
    CF_WFI,
    CF_JALR,
    CF_BRANCH
  } fu_op_e;

  typedef struct packed {
    logic valid;  // wb data is valid
    logic [31:0] data;  //wb data
    logic ex_valid;  // exception from WB
    logic [ScoreboardDepth-1:0] trans_id;  //transaction ID
  } writeback_t;

  typedef struct packed {
    fu_e                        fu;
    fu_op_e                     operation;
    logic [31:0]                operand_a;
    logic [31:0]                operand_b;
    logic [31:0]                imm;
    logic [ScoreboardIndex-1:0] trans_id;
  } fu_data_t;

  typedef enum logic [2:0] {
    NoCF,    // No control flow prediction
    Branch,  // Branch
    Jump,    // Jump to address from immediate
    JumpR,   // Jump to address from registers
    Return   // Return Address Prediction
  } cf_e;

  typedef struct packed {
    cf_e         cf;               // type of control flow prediction
    logic [31:0] predict_address;  // target address at which to jump, or not
  } bpu_t;

  typedef struct packed {
    logic        valid;           // prediction with all its values is valid
    logic [31:0] pc;              // PC of predict or mis-predict
    logic [31:0] target_address;  // target address at which to jump, or not
    logic        is_mispredict;   // set if this was a mis-predict
    logic        is_taken;        // branch is taken
    cf_t         cf_type;         // Type of control flow change
  } bp_resolve_t;

  typedef struct packed {
    logic [31:0] pc;
    logic [ScoreboardIndex-1:0] trans_id;
    fu_e fu;
    fu_op_e op;
    logic [RegWidth-1:0] rs1;
    logic [RegWidth-1:0] rs2;
    logic [RegWidth-1:0] rd;
    logic [31:0] result;  // imm
    logic valid;
    logic use_imm;  // operand b
    logic use_zimm;  // operand a
    logic use_pc;  // operand a
    exception_t ex;  // exception has occurred
    bpu_t bp;  // branch predict scoreboard data structure
    logic is_rv16;
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
