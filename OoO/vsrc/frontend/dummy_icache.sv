module dummy_icache
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,
    input logic flush_inside,

    input  logic [31:0] fetch_addr,
    output logic [31:0] ic_val,
    output logic [31:0] ic_addr,

    input  logic ifu2icu_valid,
    input  logic ifu2icu_ready,
    output logic icu2ifu_valid,
    output logic icu2ifu_ready,

    output logic icache_hit,
    output logic icache_miss,
    output logic icache_skip,

    output logic data_req_o,
    output logic [31:0] data_addr_o,
    input logic data_gnt_i,
    input logic data_rvalid_i,
    input logic [31:0] data_rdata_i,

    output axi_r_m2s_t ifu_r_m2s,
    input  axi_r_s2m_t ifu_r_s2m
);

  typedef enum logic [1:0] {
    IC_IDLE,
    IC_READ,
    IC_FLUSH
  } ic_fsm_e;
  ic_fsm_e curr, next;

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
        if (ifu2icu_valid & icu2ifu_ready & !flush_inside) begin
          next = IC_READ;
        end else begin
          next = IC_IDLE;
        end
      end
      IC_READ: begin
        if (data_rvalid_i) begin
          next = IC_IDLE;
        end else if (flush_inside) begin
          next = IC_FLUSH;
        end else begin
          next = curr;
        end
      end
      IC_FLUSH: begin
        if (data_rvalid_i) begin
          next = IC_IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = IC_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      icu2ifu_ready <= 1'b0;
      icu2ifu_valid <= 1'b0;
      ic_val <= 32'b0;
      ic_addr <= 32'b0;
      data_req_o <= 1'b0;
      data_addr_o <= 32'b0;
    end else begin
      unique case (curr)
        IC_IDLE: begin
          if (ifu2icu_valid & icu2ifu_ready & !flush_inside) begin
            icu2ifu_ready <= 1'b0;
            icu2ifu_valid <= 1'b0;
            data_req_o <= 1'b1;
            data_addr_o <= fetch_addr;
            ic_addr <= fetch_addr;
          end else begin
            icu2ifu_ready <= 1'b1;
            icu2ifu_valid <= 1'b0;
            data_req_o <= 1'b0;
          end
        end
        IC_READ: begin
          if (data_gnt_i) begin
            data_req_o <= 1'b0;
          end
          if (flush_inside) begin
            icu2ifu_ready <= 1'b0;
            icu2ifu_valid <= 1'b0;
          end else if (data_rvalid_i) begin
            ic_val <= data_rdata_i;
            icu2ifu_ready <= 1'b0;
            icu2ifu_valid <= 1'b1;
          end else begin
            icu2ifu_ready <= 1'b0;
            icu2ifu_valid <= 1'b0;
          end
        end
        IC_FLUSH: begin
          if (data_gnt_i) begin
            data_req_o <= 1'b0;
          end
          icu2ifu_ready <= 1'b0;
          icu2ifu_valid <= 1'b0;
        end
        default: begin
          icu2ifu_ready <= 1'b0;
          icu2ifu_valid <= 1'b0;
        end
      endcase
    end
  end

  always_comb begin
    ifu_r_m2s.arsize = 3'd2;
    ifu_r_m2s.arburst = 2'b10;
    ifu_r_m2s.arvalid = 1'b0;
    ifu_r_m2s.rready = 1'b0;
    ifu_r_m2s.araddr = 32'b0;
    ifu_r_m2s.arlen = 8'h0;
    icache_hit = 1'b0;
    icache_miss = 1'b0;
    icache_skip = 1'b0;
  end

endmodule
