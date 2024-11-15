module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 3:0] dqm,
  inout [31:0] dq
);


  logic [31:0] memory [4][8192][512];
  logic [12:0] active_row [4];
  logic [31:0] dq_tmp;
  logic [3:0] cmd;
  logic [1:0] LC;
  always_ff @(posedge clk) begin
    if (cmd == CMD_READ)
      LC <= 1;
    else
      LC <= {LC[0], 1'b0};

  end

  assign dq = (LC[1]) ? dq_tmp : 32'bz;

  localparam CMD_NOP           = 4'b0111;
  localparam CMD_ACTIVE        = 4'b0011;
  localparam CMD_READ          = 4'b0101;
  localparam CMD_WRITE         = 4'b0100;
  localparam CMD_TERMINATE     = 4'b0110;
  localparam CMD_PRECHARGE     = 4'b0010;
  localparam CMD_REFRESH       = 4'b0001;
  localparam CMD_LOAD_MODE     = 4'b0000;
  always_comb begin
    unique case ({cs, ras, cas, we})
    CMD_NOP           : cmd = CMD_NOP;
    CMD_ACTIVE        : cmd = CMD_ACTIVE;
    CMD_READ          : cmd = CMD_READ;
    CMD_WRITE         : cmd = CMD_WRITE;
    CMD_TERMINATE     : cmd = CMD_NOP;
    CMD_PRECHARGE     : cmd = CMD_NOP;
    CMD_REFRESH       : cmd = CMD_NOP;
    CMD_LOAD_MODE     : cmd = CMD_NOP;
    default           : cmd = CMD_NOP;
    endcase
  end

  always_ff @(posedge clk) begin
    if (cke) begin
      case (cmd)
      CMD_ACTIVE: 
        begin
          active_row[ba] <= a;
        end
      CMD_READ: 
        begin
          //$display("[SDRAM_READ]%08x", memory[ba][active_row[ba]][a[8:0]]);
          dq_tmp <= memory[ba][active_row[ba]][a[8:0]];
        end
      CMD_WRITE: 
        begin
          //$display("[SDRAM_WRITE]%08x %04b", dq, ~dqm);
          if (!dqm[0]) memory[ba][active_row[ba]][a[8:0]][ 7: 0] <= dq[ 7: 0];
          if (!dqm[1]) memory[ba][active_row[ba]][a[8:0]][15: 8] <= dq[15: 8];
          if (!dqm[2]) memory[ba][active_row[ba]][a[8:0]][23:16] <= dq[23:16];
          if (!dqm[3]) memory[ba][active_row[ba]][a[8:0]][31:24] <= dq[31:24];
        end
      default:;
      endcase
    end
  end


endmodule
