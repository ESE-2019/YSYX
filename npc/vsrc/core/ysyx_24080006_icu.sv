module ysyx_24080006_icu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic [31:0] ic_pc,
    output logic [31:0] inst,

    input  logic ifu2icu_valid,
    input  logic ifu2icu_ready,
    output logic icu2ifu_valid,
    output logic icu2ifu_ready,

    ysyx_24080006_axi.master axi_ifu
);

  typedef enum logic [1:0] {
    IDLE,
    SKIP,
    BURST,
    COMMON
  } ic_fsm_e;
  ic_fsm_e curr, next;

  icache_t ic_rdata_1, ic_rdata_0, ic_wdata;
  logic [31:0] ic_wdata_tmp  [4];
  logic [31:0] ic_rdata_1_tmp[4];
  logic [31:0] ic_rdata_0_tmp[4];
  logic ic_we_1, ic_we_0;
  logic choose_way;
  wire [1:0] pc_offset = ic_pc[3:2];
  wire [IC_N-1:0] ic_index = ic_pc[IC_M+IC_N-1:IC_M];
  wire [31-IC_M-IC_N:0] tag = ic_pc[31:IC_M+IC_N];
  wire skip_icache = ic_pc < 32'ha000_0000;
  wire burst_icache = ic_pc >= 32'ha000_0000;
  wire hit_1 = ic_rdata_1.valid && (tag == ic_rdata_1.tag);
  wire hit_0 = ic_rdata_0.valid && (tag == ic_rdata_0.tag);
  logic [1:0] burst_cnt;

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
          unique if (skip_icache) begin
            next = SKIP;
          end else if (hit_1 | hit_0) begin
            next = IDLE;
          end else begin
            if (burst_icache) begin
              next = BURST;
            end else begin
              next = COMMON;
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
      COMMON: begin
        if (&burst_cnt) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      axi_ifu.arvalid <= 1'b0;
      axi_ifu.rready <= 1'b0;
      axi_ifu.araddr <= '0;
      axi_ifu.arlen <= 8'h0;
      choose_way <= '0;
      ic_we_1 <= 1'b0;
      ic_we_0 <= 1'b0;
      ic_wdata_tmp[3] <= '0;
      ic_wdata_tmp[2] <= '0;
      ic_wdata_tmp[1] <= '0;
      ic_wdata_tmp[0] <= '0;
      inst <= '0;
      burst_cnt <= 2'b0;
      icu2ifu_valid <= 1'b0;
      icu2ifu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          if (ifu2icu_valid & icu2ifu_ready) begin
            unique if (skip_icache) begin  // SKIP
              axi_ifu.arvalid <= 1'b1;
              axi_ifu.rready <= 1'b0;
              axi_ifu.araddr <= ic_pc;
              axi_ifu.arlen <= 8'h0;
              ic_we_1 <= 1'b0;
              ic_we_0 <= 1'b0;
              burst_cnt <= 2'b0;
              icu2ifu_valid <= 1'b0;
              icu2ifu_ready <= 1'b0;
            end else if (hit_1 | hit_0) begin
              axi_ifu.arvalid <= 1'b0;
              axi_ifu.rready <= 1'b0;
              ic_we_1 <= 1'b0;
              ic_we_0 <= 1'b0;
              burst_cnt <= 2'b0;
              icu2ifu_valid <= 1'b1;
              if (hit_1) begin
                inst <= ic_rdata_1_tmp[pc_offset];
                choose_way <= 1;
              end else begin
                inst <= ic_rdata_0_tmp[pc_offset];
                choose_way <= 0;
              end
              icu2ifu_ready <= 1'b1;
            end else begin
              if (burst_icache) begin  // BURST
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready <= 1'b0;
                axi_ifu.araddr <= ic_pc;
                axi_ifu.arlen <= 8'h3;
                ic_we_1 <= 1'b0;
                ic_we_0 <= 1'b0;
                burst_cnt <= 2'b0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end else begin  // COMMON
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready  <= 1'b0;
                axi_ifu.araddr  <= ic_pc;
                axi_ifu.arlen   <= 8'h0;
                $finish;
                ic_we_1 <= 1'b0;
                ic_we_0 <= 1'b0;
                burst_cnt <= 2'b0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end
            end
          end else begin  // NOP
            axi_ifu.arvalid <= 1'b0;
            axi_ifu.rready <= 1'b0;
            ic_we_1 <= 1'b0;
            ic_we_0 <= 1'b0;
            burst_cnt <= 2'b0;
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
            burst_cnt <= burst_cnt + 2'b1;
            ic_wdata_tmp[pc_offset+burst_cnt] <= axi_ifu.rdata;

            if (burst_cnt == 2'b00) begin
              inst <= axi_ifu.rdata;
              //icu2ifu_valid <= 1'b1;
            end else begin
              //icu2ifu_valid <= 1'b0;
            end

            if (axi_ifu.rlast) begin
              if (choose_way) ic_we_1 <= 1'b1;
              else ic_we_0 <= 1'b1;
              choose_way <= ~choose_way;
              icu2ifu_ready <= 1'b1;
              icu2ifu_valid <= 1'b1;
            end
          end else begin
            axi_ifu.rready <= 1'b0;
            ic_we_1 <= 1'b0;
            ic_we_0 <= 1'b0;
            icu2ifu_valid <= 1'b0;
          end
        end
        COMMON:  ;
        default: ;
      endcase
    end
  end  // fsm 3 for axi

  assign axi_ifu.arid = 4'h0;
  assign axi_ifu.arsize = 3'h2;
  assign axi_ifu.arburst = 2'b10;

  assign ic_wdata = {1'b1, tag, ic_wdata_tmp[3], ic_wdata_tmp[2], ic_wdata_tmp[1], ic_wdata_tmp[0]};
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

endmodule
