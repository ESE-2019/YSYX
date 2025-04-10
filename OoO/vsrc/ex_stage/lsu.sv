`default_nettype none

module lsu
  import OoO_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] lsu_addr,
    input logic [1:0] lsu_size,
    input logic lsu_sext,
    input logic lsu_write,
    input logic [31:0] lsu_wdata,
    output logic [31:0] lsu_rdata,

    input logic commit_lsu,
    input logic [ScoreboardIndex-1:0] lsu_idx_i,
    output logic [ScoreboardIndex-1:0] lsu_idx,

    output logic data_req_o,
    input  logic data_gnt_i,
    input  logic data_rvalid_i,

    output logic [31:0] data_addr_o,
    output logic        data_we_o,
    output logic [ 3:0] data_be_o,
    output logic [31:0] data_wdata_o,
    input  logic [31:0] data_rdata_i,

    input  logic exu2lsu_valid,
    output logic lsu2exu_ready,
    input  logic exu2lsu_ready,
    output logic lsu2exu_valid,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m
);

  typedef enum logic [1:0] {
    LS_IDLE,
    LS_WRITE,
    LS_READ
  } ls_fsm_e;
  ls_fsm_e curr, next;

  logic sext_tmp;
  logic [1:0] addr_tmp, size_tmp;  // will be del
  localparam logic [3:0] WSTRB[4] = '{
      4'b0001,  // funct3 == 3'b000
      4'b0011,  // funct3 == 3'b001
      4'b1111,  // funct3 == 3'b010
      4'b0000
  };
  wire [3:0] lsu_strb = WSTRB[lsu_size] << lsu_addr[1:0];
  wire [31:0] lsu_wdata_shifted = lsu_wdata << {lsu_addr[1:0], 3'b0};

  function automatic logic [31:0] Mr(input logic [31:0] Mr_rdata, input logic [1:0] Mr_raddr,
                                     input logic Mr_sext, input logic [1:0] Mr_size);
    logic [31:0] tmp;
    tmp = Mr_rdata >> {Mr_raddr, 3'b0};
    unique case ({
      Mr_sext, Mr_size
    })
      3'b000:  Mr = {{24{tmp[7]}}, tmp[7:0]};
      3'b001:  Mr = {{16{tmp[15]}}, tmp[15:0]};
      3'b010:  Mr = tmp[31:0];
      3'b100:  Mr = {24'b0, tmp[7:0]};
      3'b101:  Mr = {16'b0, tmp[15:0]};
      default: Mr = tmp[31:0];
    endcase
  endfunction

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= LS_IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      LS_IDLE: begin
        if (exu2lsu_valid & lsu2exu_ready) begin
          if (lsu_write) begin
            next = LS_WRITE;
          end else begin
            next = LS_READ;
          end
        end else begin
          next = LS_IDLE;
        end
      end
      LS_WRITE: begin
        if (data_gnt_i) begin
          next = LS_IDLE;
        end else begin
          next = curr;
        end
      end
      LS_READ: begin
        if (data_rvalid_i) begin
          next = LS_IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = LS_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3
    if (reset) begin
      lsu2exu_valid <= 1'b0;
      lsu2exu_ready <= 1'b1;
      lsu_idx <= '0;
      data_req_o <= 1'b0;
    end else begin
      unique case (curr)
        LS_IDLE: begin
          if (exu2lsu_valid & lsu2exu_ready) begin
            lsu_idx      <= lsu_idx_i;
            data_req_o   <= 1'b1;
            data_addr_o  <= {lsu_addr[31:2], 2'b0};
            data_we_o    <= lsu_write;
            data_be_o    <= lsu_strb;
            data_wdata_o <= lsu_wdata_shifted;
            sext_tmp     <= lsu_sext;
            addr_tmp     <= lsu_addr[1:0];
            size_tmp     <= lsu_size;
            if (lsu_write) begin
              lsu2exu_valid <= 1'b1;
              lsu2exu_ready <= 1'b0;
            end else begin
              lsu2exu_valid <= 1'b0;
              lsu2exu_ready <= 1'b0;
            end
          end else begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b1;
          end
        end
        LS_WRITE: begin
          if (data_gnt_i) begin
            data_req_o <= 1'b0;
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b1;
          end else begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b0;
          end
        end
        LS_READ: begin
          if (data_gnt_i) data_req_o <= 1'b0;
          if (data_rvalid_i) begin
            lsu_rdata <= Mr(data_rdata_i, addr_tmp, sext_tmp, size_tmp);
            lsu2exu_valid <= 1'b1;
            lsu2exu_ready <= 1'b1;
          end else begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b0;
          end
        end
        default: ;
      endcase
    end
  end

endmodule

`default_nettype wire
