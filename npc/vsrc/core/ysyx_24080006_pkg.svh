package ysyx_24080006_pkg;

  typedef enum logic [3:0] {
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU
  } alu_op_e;

  typedef enum logic [6:0] {
    Branch = 7'b1100011,
    I_type = 7'b0010011,  //except Jalr and Load
    R_type = 7'b0110011,
    Store  = 7'b0100011,
    Load   = 7'b0000011,
    Jal    = 7'b1101111,
    Jalr   = 7'b1100111,
    Lui    = 7'b0110111,
    Auipc  = 7'b0010111,
    System = 7'b1110011   //ebreak, ecall, csr
  } inst_op_e;

  parameter int unsigned REG_WIDTH = 4;

  typedef struct packed {
    logic valid;
    logic [31:0] pc, inst, dnpc;
    inst_op_e inst_op;

    logic [31:0] immB, immI, immJ, immS, immU;

    logic [31:0] sdata;  // store data, i.e., rs2_val

    logic [31:0] alu_src1;
    logic [31:0] alu_src2;
    alu_op_e     alu_op;
    logic [31:0] alu_res;

    logic [REG_WIDTH-1:0] rs1_addr, rs2_addr, rd_addr;

    logic [11:0] csr_addr;
    logic csr_we, ecall;
    logic [31:0] csr_wdata;

    logic [2:0] funct3;  // merged into load / store ?
    logic load, store, wb, jump, branch;

  } stage_t;

  typedef enum logic [1:0] {
    IDLE,
    EXEC,
    WAIT
  } fsm_e;


  parameter int unsigned IC_M = 2;
  parameter int unsigned IC_N = 4;
  parameter int unsigned IC_2 = 1 << IC_N;  // 2 ^ n

  typedef struct packed {
    logic valid;
    logic [31-IC_M-IC_N:0] tag;
    logic [31:0] inst;
  } icache_t;


  parameter logic [31:0] ECALL = 32'b0000000_00000_00000_000_00000_11100_11;
`ifdef SOC_MODE
  parameter RST_ADDR = 32'h3000_0000 - 32'h4;
`else
  parameter RST_ADDR = 32'h8000_0000 - 32'h4;
`endif
  parameter logic [3:0] WSTRB_LUT[4] = '{
      4'b0001,  // funct3 == 3'b000
      4'b0011,  // funct3 == 3'b001
      4'b1111,  // funct3 == 3'b010
      4'b0000  // others
  };
endpackage
