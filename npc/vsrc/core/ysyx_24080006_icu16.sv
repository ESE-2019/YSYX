module ysyx_24080006_icu16
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input  logic [31:0] fetch_addr,
    output logic [31:0] ic_val,

    input  logic ifu2icu_valid,
    input  logic ifu2icu_ready,
    output logic icu2ifu_valid,
    output logic icu2ifu_ready,
    input  logic fencei,

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

  logic [31:0] ic_addr;

  icache_t ic_rdata, ic_wdata;
  logic [31:0] ic_wdata_tmp[8];
  logic [31:0] ic_rdata_tmp[8];
  logic ic_we;
  wire [IC_M-3:0] pc_offset = fetch_addr[IC_M-1:2];
  logic [IC_N-1:0] ic_index, ic_waddr;
  wire [31-IC_M-IC_N:0] tag = fetch_addr[31:IC_M+IC_N];
  wire skip_icache = fetch_addr < 32'h3000_0000;
  wire burst_icache = fetch_addr >= 32'ha000_0000;
  wire hit = ic_rdata.valid && (tag == ic_rdata.tag);
  logic [IC_M-3:0] burst_offset;
  assign ic_index = fetch_addr[IC_M+IC_N-1:IC_M];
  wire [IC_M-3:0] addr_offset = ic_addr[IC_M-1:2] + burst_offset;

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
          end else if (hit) begin
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
        if (burst_offset == '0) begin
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
      axi_ifu.rready <= 1'b0;
      axi_ifu.araddr <= 32'b0;
      axi_ifu.arlen <= 8'h0;
      ic_addr <= 32'b0;
      ic_we <= 1'b0;
      foreach (ic_wdata_tmp[i]) ic_wdata_tmp[i] <= 32'b0;
      ic_val <= 32'b0;
      burst_offset <= '0;
      icu2ifu_valid <= 1'b0;
      icu2ifu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          ic_addr  <= fetch_addr;
          ic_waddr <= ic_index;
          if (ifu2icu_valid & icu2ifu_ready) begin
            unique if (skip_icache) begin  // SKIP
              axi_ifu.arvalid <= 1'b1;
              axi_ifu.rready <= 1'b0;
              axi_ifu.araddr <= fetch_addr;
              axi_ifu.arlen <= 8'h0;
              ic_we <= 1'b0;
              burst_offset <= '0;
              icu2ifu_valid <= 1'b0;
              icu2ifu_ready <= 1'b0;
            end else if (hit) begin
              axi_ifu.arvalid <= 1'b0;
              axi_ifu.rready <= 1'b0;
              ic_we <= 1'b0;
              burst_offset <= '0;
              icu2ifu_valid <= 1'b1;
              icu2ifu_ready <= 1'b1;
              ic_val <= ic_rdata_tmp[pc_offset];
            end else begin
              if (burst_icache) begin  // SDRAM
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready <= 1'b0;
                axi_ifu.araddr <= fetch_addr;
                axi_ifu.arlen <= 8'h7;
                ic_we <= 1'b0;
                burst_offset <= '0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end else begin  // FLASH
                axi_ifu.arvalid <= 1'b1;
                axi_ifu.rready <= 1'b0;
                axi_ifu.araddr <= fetch_addr;
                axi_ifu.arlen <= 8'h0;
                ic_we <= 1'b0;
                burst_offset <= '0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end
            end
          end else begin  // NOP
            axi_ifu.arvalid <= 1'b0;
            axi_ifu.rready <= 1'b0;
            ic_we <= 1'b0;
            burst_offset <='0;
            icu2ifu_valid <= 1'b0;
            icu2ifu_ready <= 1'b1;
          end
        end
        SKIP: begin
          ic_we <= 1'b0;
          if (axi_ifu.arready) begin
            axi_ifu.arvalid <= 1'b0;
          end
          if (axi_ifu.rvalid) begin
            axi_ifu.rready <= 1'b1;
            ic_val <= axi_ifu.rdata;
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
            burst_offset <= burst_offset + 3'b1;
            ic_wdata_tmp[addr_offset] <= axi_ifu.rdata;

            if (burst_offset == '0) begin
              ic_val <= axi_ifu.rdata;
              icu2ifu_valid <= 1'b1;
            end else begin
              icu2ifu_valid <= 1'b0;
            end

            if (axi_ifu.rlast) begin
              ic_we <= 1'b1;
              icu2ifu_ready <= 1'b1;
              icu2ifu_valid <= 1'b0;
            end
          end else begin
            ic_we <= 1'b0;
            axi_ifu.rready <= 1'b0;
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
            ic_val <= axi_ifu.rdata;
            burst_offset <= burst_offset + 3'b1;
            ic_wdata_tmp[addr_offset] <= axi_ifu.rdata;
            if (burst_offset == '0) begin
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
          axi_ifu.araddr <= {ic_addr[31:IC_M], addr_offset, 2'b0};
          if (burst_offset == '0) begin
            axi_ifu.arvalid <= 1'b0;
            ic_we <= 1'b1;
            icu2ifu_ready <= 1'b1;
          end else begin
            ic_we <= 1'b0;
            axi_ifu.arvalid <= 1'b1;
            icu2ifu_ready <= 1'b0;
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
    1'b1,
    ic_addr[31:IC_M+IC_N],
    ic_wdata_tmp[7],
    ic_wdata_tmp[6],
    ic_wdata_tmp[5],
    ic_wdata_tmp[4],
    ic_wdata_tmp[3],
    ic_wdata_tmp[2],
    ic_wdata_tmp[1],
    ic_wdata_tmp[0]
  };
  assign ic_rdata_tmp[7] = ic_rdata.data[224+:32];
  assign ic_rdata_tmp[6] = ic_rdata.data[192+:32];
  assign ic_rdata_tmp[5] = ic_rdata.data[160+:32];
  assign ic_rdata_tmp[4] = ic_rdata.data[128+:32];
  assign ic_rdata_tmp[3] = ic_rdata.data[96+:32];
  assign ic_rdata_tmp[2] = ic_rdata.data[64+:32];
  assign ic_rdata_tmp[1] = ic_rdata.data[32+:32];
  assign ic_rdata_tmp[0] = ic_rdata.data[0+:32];

  ysyx_24080006_icache_reg16 WAY1 (
      .*,
      .ic_rdata(ic_rdata),
      .ic_we(ic_we)
  );

`ifdef SIM_MODE
  int hit_num = 0;
  int skip_num = 0;
  int miss_num = 0;

  always_ff @(posedge clock) begin
    if (ifu2icu_valid & icu2ifu_ready && curr == IDLE) begin
      if (skip_icache) begin
        skip_num++;
      end else if (hit) begin
        hit_num++;
        //$display("\thit:");
      end else begin
        miss_num++;
        //$display("\tmiss:");
      end
    end
  end
`endif
endmodule
