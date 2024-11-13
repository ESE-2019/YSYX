module ysyx_24080006_icu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic [31:0] pc,
    output logic [31:0] inst,

    input  logic ifu2icu_valid,
    input  logic ifu2icu_ready,
    output logic icu2ifu_valid,
    output logic icu2ifu_ready,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [2:0] {
    IDLE,
    SKIP,
    BURST,
    FLASH_BEGIN,
    FLASH_END
  } ic_fsm_e;
  ic_fsm_e curr, next;

  logic [31:0] ic_pc;

  icache_t ic_rdata_1, ic_rdata_0, ic_wdata;
  logic [31:0] ic_wdata_tmp  [4];
  logic [31:0] ic_rdata_1_tmp[4];
  logic [31:0] ic_rdata_0_tmp[4];
  logic ic_we_1, ic_we_0;
  logic replace_way[IC_2];
  wire [1:0] pc_offset = pc[3:2];
  logic [IC_N-1:0] ic_index, ic_waddr;
  wire [31-IC_M-IC_N:0] tag = pc[31:IC_M+IC_N];
  wire skip_icache = pc < 32'h3000_0000;
  wire burst_icache = pc >= 32'ha000_0000;
  wire hit_1 = ic_rdata_1.valid && (tag == ic_rdata_1.tag);
  wire hit_0 = ic_rdata_0.valid && (tag == ic_rdata_0.tag);
  logic [1:0] burst_offset;
  assign ic_index = pc[IC_M+IC_N-1:IC_M];
  wire [1:0] addr_offset = ic_pc[3:2] + burst_offset;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    next = IDLE;
    unique case (curr)
      IDLE: begin
        if (ifu2icu_valid & icu2ifu_ready) begin
          if (skip_icache) begin
            next = SKIP;
          end else if (hit_1 | hit_0) begin
            next = IDLE;
          end else begin
            if (burst_icache) begin
              next = BURST;
            end else begin
              next = FLASH_BEGIN;
            end
          end
        end else begin
          next = IDLE;
        end
      end
      SKIP: begin
        if (axi_ifu.rvalid) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
      BURST: begin
        if (axi_ifu.rvalid && axi_ifu.rlast) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
      FLASH_BEGIN: begin
        if (axi_ifu.rvalid) begin
          next = FLASH_END;
        end else begin
          next = curr;
        end
      end
      FLASH_END: begin
        if (burst_offset == 2'b00) begin
          next = IDLE;
        end else begin
          next = FLASH_BEGIN;
        end
      end
      default: next = IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      axi_ifu.arvalid <= 1'b0;
      axi_ifu.rready  <= 1'b0;
      axi_ifu.araddr  <= '0;
      axi_ifu.arlen   <= 8'h0;
      foreach (replace_way[i]) replace_way[i] <= 1'b0;
      ic_pc <= 32'b0;
      ic_we_1 <= 1'b0;
      ic_we_0 <= 1'b0;
      ic_wdata_tmp[3] <= '0;
      ic_wdata_tmp[2] <= '0;
      ic_wdata_tmp[1] <= '0;
      ic_wdata_tmp[0] <= '0;
      inst <= '0;
      burst_offset <= 2'b0;
      icu2ifu_valid <= 1'b0;
      icu2ifu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          ic_pc <= pc;
          ic_waddr <= ic_index;
          if (ifu2icu_valid & icu2ifu_ready) begin
            unique if (skip_icache) begin  // SKIP
              axi_ifu.arvalid <= 1'b1;
              axi_ifu.rready <= 1'b0;
              axi_ifu.araddr <= pc;
              axi_ifu.arlen <= 8'h0;
              ic_we_1 <= 1'b0;
              ic_we_0 <= 1'b0;
              burst_offset <= 2'b0;
              icu2ifu_valid <= 1'b0;
              icu2ifu_ready <= 1'b0;
            end else if (hit_1 | hit_0) begin
              axi_ifu.arvalid <= 1'b0;
              axi_ifu.rready <= 1'b0;
              ic_we_1 <= 1'b0;
              ic_we_0 <= 1'b0;
              burst_offset <= 2'b0;
              icu2ifu_valid <= 1'b1;
              icu2ifu_ready <= 1'b1;
              if (hit_1) begin
                inst <= ic_rdata_1_tmp[pc_offset];
                replace_way[ic_index] <= 0;
              end else if (hit_0) begin
                inst <= ic_rdata_0_tmp[pc_offset];
                replace_way[ic_index] <= 1;
              end
            end else begin
              if (burst_icache) begin  // BURST
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready <= 1'b0;
                axi_ifu.araddr <= pc;
                axi_ifu.arlen <= 8'h3;
                ic_we_1 <= 1'b0;
                ic_we_0 <= 1'b0;
                burst_offset <= 2'b0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end else begin  // FLASH
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready <= 1'b0;
                axi_ifu.araddr <= pc;
                axi_ifu.arlen <= 8'h0;
                ic_we_1 <= 1'b0;
                ic_we_0 <= 1'b0;
                burst_offset <= 2'b0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end
            end
          end else begin  // NOP
            axi_ifu.arvalid <= 1'b0;
            axi_ifu.rready <= 1'b0;
            ic_we_1 <= 1'b0;
            ic_we_0 <= 1'b0;
            burst_offset <= 2'b0;
            icu2ifu_valid <= 1'b0;
            icu2ifu_ready <= 1'b1;
          end
        end
        SKIP: begin
          if (axi_ifu.arready) begin
            axi_ifu.arvalid <= 1'b0;
          end
          if (axi_ifu.rvalid) begin
            axi_ifu.rready <= 1'b1;
            inst <= axi_ifu.rdata;
            icu2ifu_valid <= 1'b1;
            icu2ifu_ready <= 1'b1;
          end
        end
        BURST: begin
          if (axi_ifu.arvalid & axi_ifu.arready) begin
            axi_ifu.arvalid <= 1'b0;
          end
          if (axi_ifu.rvalid && !axi_ifu.rready) begin
            axi_ifu.rready <= 1'b1;
            burst_offset <= burst_offset + 2'b1;
            ic_wdata_tmp[addr_offset] <= axi_ifu.rdata;

            if (burst_offset == 2'b00) begin
              inst <= axi_ifu.rdata;
              icu2ifu_valid <= 1'b1;
            end else begin
              icu2ifu_valid <= 1'b0;
            end

            if (axi_ifu.rlast) begin
              if (replace_way[ic_waddr]) ic_we_1 <= 1'b1;
              else ic_we_0 <= 1'b1;
              replace_way[ic_waddr] <= ~replace_way[ic_waddr];
              icu2ifu_ready <= 1'b1;
            end
          end else begin
            axi_ifu.rready <= 1'b0;
            ic_we_1 <= 1'b0;
            ic_we_0 <= 1'b0;
            icu2ifu_valid <= 1'b0;
          end
        end
        FLASH_BEGIN: begin
          icu2ifu_ready <= 1'b0;
          if (axi_ifu.arready) begin
            axi_ifu.arvalid <= 1'b0;
          end
          if (axi_ifu.rvalid) begin
            axi_ifu.rready <= 1'b1;
            inst <= axi_ifu.rdata;
            burst_offset <= burst_offset + 2'b1;
            ic_wdata_tmp[addr_offset] <= axi_ifu.rdata;
            if (burst_offset == 2'b00) begin
              icu2ifu_valid <= 1'b1;
            end else begin
              icu2ifu_valid <= 1'b0;
            end
          end else begin
            axi_ifu.rready <= 1'b0;
          end
        end
        FLASH_END: begin
          icu2ifu_valid  <= 1'b0;
          axi_ifu.rready <= 1'b0;
          axi_ifu.araddr <= {ic_pc[31:4], addr_offset, 2'b0};
          if (burst_offset == 2'b00) begin
            axi_ifu.arvalid <= 1'b0;
            if (replace_way[ic_waddr]) ic_we_1 <= 1'b1;
            else ic_we_0 <= 1'b1;
            replace_way[ic_waddr] <= ~replace_way[ic_waddr];
            icu2ifu_ready <= 1'b1;
          end else begin
            axi_ifu.arvalid <= 1'b1;
            icu2ifu_ready   <= 1'b0;
          end
        end
        default: ;
      endcase
    end
  end  // fsm 3 for axi

  assign axi_ifu.arid = 4'h0;
  assign axi_ifu.arsize = 3'h2;
  assign axi_ifu.arburst = 2'b10;

  assign ic_wdata = {
    1'b1, ic_pc[31:IC_M+IC_N], ic_wdata_tmp[3], ic_wdata_tmp[2], ic_wdata_tmp[1], ic_wdata_tmp[0]
  };
  assign ic_rdata_1_tmp[3] = ic_rdata_1.data[96+:32];
  assign ic_rdata_1_tmp[2] = ic_rdata_1.data[64+:32];
  assign ic_rdata_1_tmp[1] = ic_rdata_1.data[32+:32];
  assign ic_rdata_1_tmp[0] = ic_rdata_1.data[0+:32];
  assign ic_rdata_0_tmp[3] = ic_rdata_0.data[96+:32];
  assign ic_rdata_0_tmp[2] = ic_rdata_0.data[64+:32];
  assign ic_rdata_0_tmp[1] = ic_rdata_0.data[32+:32];
  assign ic_rdata_0_tmp[0] = ic_rdata_0.data[0+:32];

  ysyx_24080006_icache_reg WAY1 (
      .*,
      .ic_rdata(ic_rdata_1),
      .ic_we(ic_we_1)
  );
  ysyx_24080006_icache_reg WAY0 (
      .*,
      .ic_rdata(ic_rdata_0),
      .ic_we(ic_we_0)
  );

`ifdef SIM_MODE
  int hit_num = 0;
  int skip_num = 0;
  int miss_num = 0;

  always_ff @(posedge clock) begin
    if (ifu2icu_valid & icu2ifu_ready && curr == IDLE) begin
      if (skip_icache) begin
        skip_num++;
      end else if (hit_1 | hit_0) begin
        hit_num++;
      end else begin
        miss_num++;
      end
    end
  end
`endif
endmodule
