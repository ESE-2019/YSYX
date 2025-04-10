`default_nettype none

module ysyx_24080006_icu
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

    output logic icache_hit,
    output logic icache_miss,
    output logic icache_skip,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m
);

  typedef enum logic [2:0] {
    IC_IDLE,
    IC_SKIP,
    IC_BURST,
    IC_FLASH_BEGIN,
    IC_FLASH_END
  } ic_fsm_e;
  ic_fsm_e curr, next;

  logic [31:0] ic_addr;

  icache_t ic_rdata, ic_wdata;
  logic [31:0] ic_wdata_tmp[8];
  logic [31:0] ic_rdata_tmp[8];
  logic ic_we;
  wire [IcacheLineSize-3:0] pc_offset = fetch_addr[IcacheLineSize-1:2];
  logic [IcacheLineNum-1:0] ic_index, ic_waddr;
  wire [31-IcacheLineSize-IcacheLineNum:0] tag = fetch_addr[31:IcacheLineSize+IcacheLineNum];
`ifdef NPC_MODE
  wire skip_icache = 1'b1;
`else
  wire skip_icache = fetch_addr < 32'h3000_0000;
`endif
  wire burst_icache = fetch_addr >= 32'ha000_0000;
  wire hit = ic_rdata.valid && (tag == ic_rdata.tag);
  logic [IcacheLineSize-3:0] burst_offset;
  assign ic_index = fetch_addr[IcacheLineSize+IcacheLineNum-1:IcacheLineSize];
  wire [IcacheLineSize-3:0] addr_offset = ic_addr[IcacheLineSize-1:2] + burst_offset;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IC_IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IC_IDLE: begin
        if (ifu2icu_valid & icu2ifu_ready) begin
          if (skip_icache) begin
            next = IC_SKIP;
          end else if (hit) begin
            next = IC_IDLE;
          end else begin
            if (burst_icache) begin
              next = IC_BURST;
            end else begin
              next = IC_FLASH_BEGIN;
            end
          end
        end else begin
          next = IC_IDLE;
        end
      end
      IC_SKIP: begin
        if (ifu_r_s2m.rvalid) begin
          next = IC_IDLE;
        end else begin
          next = curr;
        end
      end
      IC_BURST: begin
        if (ifu_r_s2m.rvalid && ifu_r_s2m.rlast) begin
          next = IC_IDLE;
        end else begin
          next = curr;
        end
      end
      IC_FLASH_BEGIN: begin
        if (ifu_r_s2m.rvalid) begin
          next = IC_FLASH_END;
        end else begin
          next = curr;
        end
      end
      IC_FLASH_END: begin
        if (burst_offset == '0) begin
          next = IC_IDLE;
        end else begin
          next = IC_FLASH_BEGIN;
        end
      end
      default: next = IC_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      //ifu_r_m2s.arid <= 4'h0;
      ifu_r_m2s.arsize <= 3'd2;
      ifu_r_m2s.arburst <= 2'b10;
      ifu_r_m2s.arvalid <= 1'b0;
      ifu_r_m2s.rready <= 1'b0;
      ifu_r_m2s.araddr <= 32'b0;
      ifu_r_m2s.arlen <= 8'h0;
      ic_addr <= 32'b0;
      ic_we <= 1'b0;
      foreach (ic_wdata_tmp[i]) ic_wdata_tmp[i] <= 32'b0;
      ic_val <= 32'b0;
      burst_offset <= '0;
      icu2ifu_valid <= 1'b0;
      icu2ifu_ready <= 1'b1;
      icache_hit <= 1'b0;
      icache_miss <= 1'b0;
      icache_skip <= 1'b0;
    end else begin
      unique case (curr)
        IC_IDLE: begin
          ic_addr  <= fetch_addr;
          ic_waddr <= ic_index;
          if (ifu2icu_valid & icu2ifu_ready) begin
            unique if (skip_icache) begin  // IC_SKIP
              ifu_r_m2s.arvalid <= 1'b1;
              ifu_r_m2s.rready <= 1'b0;
              ifu_r_m2s.araddr <= fetch_addr;
              ifu_r_m2s.arlen <= 8'h0;
              ic_we <= 1'b0;
              burst_offset <= '0;
              icu2ifu_valid <= 1'b0;
              icu2ifu_ready <= 1'b0;
              icache_hit <= 1'b0;
              icache_miss <= 1'b0;
              icache_skip <= 1'b1;
            end else if (hit) begin
              ifu_r_m2s.arvalid <= 1'b0;
              ifu_r_m2s.rready <= 1'b0;
              ic_we <= 1'b0;
              burst_offset <= '0;
              icu2ifu_valid <= 1'b1;
              icu2ifu_ready <= 1'b1;
              ic_val <= ic_rdata_tmp[pc_offset];
              icache_hit <= 1'b1;
              icache_miss <= 1'b0;
              icache_skip <= 1'b0;
            end else begin
              if (burst_icache) begin  // SDRAM
                ifu_r_m2s.arvalid <= 1'b1;
                ifu_r_m2s.rready <= 1'b0;
                ifu_r_m2s.araddr <= fetch_addr;
                ifu_r_m2s.arlen <= 8'h7;
                ic_we <= 1'b0;
                burst_offset <= '0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end else begin  // FLASH
                ifu_r_m2s.arvalid <= 1'b1;
                ifu_r_m2s.rready <= 1'b0;
                ifu_r_m2s.araddr <= fetch_addr;
                ifu_r_m2s.arlen <= 8'h0;
                ic_we <= 1'b0;
                burst_offset <= '0;
                icu2ifu_valid <= 1'b0;
                icu2ifu_ready <= 1'b0;
              end
              icache_hit  <= 1'b0;
              icache_miss <= 1'b1;
              icache_skip <= 1'b0;
            end
          end else begin  // NOP
            ifu_r_m2s.arvalid <= 1'b0;
            ifu_r_m2s.rready <= 1'b0;
            ic_we <= 1'b0;
            burst_offset <= '0;
            icu2ifu_valid <= 1'b0;
            icu2ifu_ready <= 1'b1;
            icache_hit <= 1'b0;
            icache_miss <= 1'b0;
            icache_skip <= 1'b0;
          end
        end
        IC_SKIP: begin
          ic_we <= 1'b0;
          if (ifu_r_s2m.arready) begin
            ifu_r_m2s.arvalid <= 1'b0;
          end
          if (ifu_r_s2m.rvalid) begin
            ifu_r_m2s.rready <= 1'b1;
            ic_val <= ifu_r_s2m.rdata;
            icu2ifu_valid <= 1'b1;
            icu2ifu_ready <= 1'b1;
          end
          icache_hit  <= 1'b0;
          icache_miss <= 1'b0;
          icache_skip <= 1'b0;
        end
        IC_BURST: begin
          if (ifu_r_m2s.arvalid & ifu_r_s2m.arready) begin
            ifu_r_m2s.arvalid <= 1'b0;
          end
          // if (ifu_r_s2m.rvalid) begin
          //   burst_offset <= burst_offset + 3'b001;
          //   ic_wdata_tmp[addr_offset] <= ifu_r_s2m.rdata;
          //   if (ifu_r_s2m.rlast && ifu_r_m2s.rready) begin
          //     ifu_r_m2s.rready <= 1'b0;
          //     ic_we <= 1'b1;
          //     icu2ifu_ready <= 1'b1;
          //     icu2ifu_valid <= 1'b0;
          //   end else begin
          //     ic_we <= 1'b0;
          //     icu2ifu_ready <= 1'b0;
          //     ifu_r_m2s.rready <= 1'b1;
          //     if (burst_offset == '0) begin
          //       ic_val <= ifu_r_s2m.rdata;
          //       icu2ifu_valid <= 1'b1;
          //     end else begin
          //       icu2ifu_valid <= 1'b0;
          //     end
          //   end
          // end else begin
          //   ic_we <= 1'b0;
          //   icu2ifu_ready <= 1'b0;
          //   icu2ifu_valid <= 1'b0;
          // end

          if (ifu_r_s2m.rvalid && !ifu_r_m2s.rready) begin
            ifu_r_m2s.rready <= 1'b1;
            burst_offset <= burst_offset + 3'b001;
            ic_wdata_tmp[addr_offset] <= ifu_r_s2m.rdata;

            if (burst_offset == '0) begin
              ic_val <= ifu_r_s2m.rdata;
              icu2ifu_valid <= 1'b1;
            end else begin
              icu2ifu_valid <= 1'b0;
            end

            if (ifu_r_s2m.rlast) begin
              ic_we <= 1'b1;
              icu2ifu_ready <= 1'b1;
            end
          end else begin
            ic_we <= 1'b0;
            ifu_r_m2s.rready <= 1'b0;
            icu2ifu_valid <= 1'b0;
          end
          icache_hit  <= 1'b0;
          icache_miss <= 1'b0;
          icache_skip <= 1'b0;
        end

        IC_FLASH_BEGIN: begin
          icu2ifu_ready <= 1'b0;
          if (ifu_r_s2m.arready) begin
            ifu_r_m2s.arvalid <= 1'b0;
          end
          if (ifu_r_s2m.rvalid) begin
            ifu_r_m2s.rready <= 1'b1;
            ic_val <= ifu_r_s2m.rdata;
            burst_offset <= burst_offset + 3'b001;
            ic_wdata_tmp[addr_offset] <= ifu_r_s2m.rdata;
            if (burst_offset == '0) begin
              icu2ifu_valid <= 1'b1;
            end else begin
              icu2ifu_valid <= 1'b0;
            end
          end else begin
            ifu_r_m2s.rready <= 1'b0;
          end
          icache_hit  <= 1'b0;
          icache_miss <= 1'b0;
          icache_skip <= 1'b0;
        end
        IC_FLASH_END: begin
          icu2ifu_valid <= 1'b0;
          ifu_r_m2s.rready <= 1'b0;
          ifu_r_m2s.araddr <= {ic_addr[31:IcacheLineSize], addr_offset, 2'b0};
          if (burst_offset == '0) begin
            ifu_r_m2s.arvalid <= 1'b0;
            ic_we <= 1'b1;
            icu2ifu_ready <= 1'b1;
          end else begin
            ic_we <= 1'b0;
            ifu_r_m2s.arvalid <= 1'b1;
            icu2ifu_ready <= 1'b0;
          end
          icache_hit  <= 1'b0;
          icache_miss <= 1'b0;
          icache_skip <= 1'b0;
        end
        default: begin
          //ifu_r_m2s.arid <= 4'h0;
          ifu_r_m2s.arsize <= 3'd2;
          ifu_r_m2s.arburst <= 2'b10;
          ifu_r_m2s.arvalid <= 1'b0;
          ifu_r_m2s.rready <= 1'b0;
          ifu_r_m2s.araddr <= 32'b0;
          ifu_r_m2s.arlen <= 8'h0;
          ic_addr <= 32'b0;
          ic_we <= 1'b0;
          foreach (ic_wdata_tmp[i]) ic_wdata_tmp[i] <= 32'b0;
          ic_val <= 32'b0;
          burst_offset <= '0;
          icu2ifu_valid <= 1'b0;
          icu2ifu_ready <= 1'b1;
          icache_hit <= 1'b0;
          icache_miss <= 1'b0;
          icache_skip <= 1'b0;
        end
      endcase
    end
  end  // fsm 3 for axi

  assign ic_wdata = {
    1'b1,
    ic_addr[31:IcacheLineSize+IcacheLineNum],
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

  ysyx_24080006_icache_regfile ICR (
      .*,
      .ic_rdata(ic_rdata),
      .ic_we(ic_we)
  );

`ifdef SIM_MODE
  int hit_num = 0;
  int skip_num = 0;
  int miss_num = 0;

  always_ff @(posedge clock) begin
    if (ifu2icu_valid & icu2ifu_ready && curr == IC_IDLE) begin
`ifdef NPC_MODE
      hit_num++;
      miss_num++;
      skip_num++;
`else
      if (skip_icache) begin
        skip_num++;
      end else if (hit) begin
        hit_num++;
        //$display("\thit:");
      end else begin
        miss_num++;
        //$display("\tmiss:");
      end

`endif
    end
  end
`endif
endmodule

`default_nettype wire
