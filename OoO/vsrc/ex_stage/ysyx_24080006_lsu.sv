`default_nettype none

module ysyx_24080006_lsu
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

    input  logic [ScoreboardIndex-1:0] lsu_idx_i,
    output logic [ScoreboardIndex-1:0] lsu_idx,

    input  logic exu2lsu_valid,
    output logic lsu2exu_ready,
    input  logic exu2lsu_ready,
    output logic lsu2exu_valid,

    output axi_w_m2s_t lsu_w_m2s,
    input  axi_w_s2m_t lsu_w_s2m,
    output axi_r_m2s_t lsu_r_m2s,
    input  axi_r_s2m_t lsu_r_s2m
);

  typedef enum logic {
    LS_IDLE,
    LS_EXEC
  } ls_fsm_e;
  ls_fsm_e curr, next;

  logic sext_tmp;
  localparam logic [3:0] WSTRB[4] = '{
      4'b0001,  // funct3 == 3'b000
      4'b0011,  // funct3 == 3'b001
      4'b1111,  // funct3 == 3'b010
      4'b0000
  };
  wire [ 3:0] lsu_strb = WSTRB[lsu_size] << lsu_addr[1:0];
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
          next = LS_EXEC;
        end else begin
          next = LS_IDLE;
        end
      end
      LS_EXEC: begin
        if (lsu_r_s2m.rvalid || lsu_w_s2m.bvalid) begin
          next = LS_IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = LS_IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      lsu2exu_valid <= 1'b0;
      lsu2exu_ready <= 1'b1;
      lsu_idx <= '0;
    end else begin
      unique case (curr)
        LS_IDLE: begin
          if (exu2lsu_valid & lsu2exu_ready) begin
            lsu_idx <= lsu_idx_i;
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
        LS_EXEC: begin
          if (lsu_r_s2m.rvalid) begin
            lsu2exu_valid <= 1'b1;
            lsu2exu_ready <= 1'b1;
          end else if (lsu_w_s2m.bvalid) begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b1;
          end else begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b0;
          end
        end
        default: begin
          lsu2exu_valid <= 1'b0;
          lsu2exu_ready <= 1'b1;
        end
      endcase
    end
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      //lsu_r_m2s.arid <= 4'h0;
      lsu_r_m2s.arburst <= 2'b10;
      lsu_r_m2s.arlen <= 8'h0;
      //lsu_w_m2s.awid <= 4'h0;
      lsu_w_m2s.awlen <= 8'h0;
      lsu_w_m2s.awburst <= 2'b10;
      lsu_w_m2s.wlast <= 1'b1;
      lsu_r_m2s.arvalid <= 1'b0;
      lsu_r_m2s.rready <= 1'b0;
      lsu_w_m2s.awvalid <= 1'b0;
      lsu_w_m2s.wvalid <= 1'b0;
      lsu_w_m2s.bready <= 1'b0;
      lsu_w_m2s.wdata <= 32'b0;
      lsu_w_m2s.wstrb <= 4'b0;
      lsu_w_m2s.awsize <= 3'b0;
      lsu_w_m2s.awaddr <= 32'b0;
      lsu_r_m2s.arsize <= 3'b0;
      lsu_r_m2s.araddr <= '0;
      lsu_rdata <= '0;
      sext_tmp <= '0;
    end else begin
      unique case (curr)
        LS_IDLE: begin
          if (exu2lsu_valid & lsu2exu_ready) begin
            if (lsu_write) begin
              lsu_r_m2s.arvalid <= 1'b0;
              lsu_r_m2s.rready  <= 1'b0;
              lsu_w_m2s.awvalid <= 1'b1;
              lsu_w_m2s.wvalid  <= 1'b1;
              lsu_w_m2s.bready  <= 1'b0;
              lsu_w_m2s.wdata   <= lsu_wdata_shifted;
              lsu_w_m2s.awsize  <= {1'b0, lsu_size};
              lsu_w_m2s.wstrb   <= lsu_strb;
              lsu_w_m2s.awaddr  <= lsu_addr;
            end else begin
              lsu_r_m2s.arvalid <= 1'b1;
              lsu_r_m2s.rready  <= 1'b0;
              lsu_w_m2s.awvalid <= 1'b0;
              lsu_w_m2s.wvalid  <= 1'b0;
              lsu_w_m2s.bready  <= 1'b0;
              lsu_r_m2s.arsize  <= {1'b0, lsu_size};
              lsu_r_m2s.araddr  <= lsu_addr;
              sext_tmp          <= lsu_sext;
            end
          end else begin
            lsu_r_m2s.arvalid <= 1'b0;
            lsu_r_m2s.rready  <= 1'b0;
            lsu_w_m2s.awvalid <= 1'b0;
            lsu_w_m2s.wvalid  <= 1'b0;
            lsu_w_m2s.bready  <= 1'b0;
          end
        end
        LS_EXEC: begin
          if (lsu_r_s2m.arready) lsu_r_m2s.arvalid <= 1'b0;
          if (lsu_w_s2m.awready) lsu_w_m2s.awvalid <= 1'b0;
          if (lsu_w_s2m.wready) begin
            lsu_w_m2s.wvalid <= 1'b0;
          end
          if (lsu_w_s2m.bvalid) lsu_w_m2s.bready <= 1'b1;
          if (lsu_r_s2m.rvalid) begin
            lsu_r_m2s.rready <= 1'b1;
            lsu_rdata <= Mr(
                lsu_r_s2m.rdata, lsu_r_m2s.araddr[1:0], sext_tmp, lsu_r_m2s.arsize[1:0]
            );
          end
        end
        default: begin
          //lsu_r_m2s.arid <= 4'h0;
          lsu_r_m2s.arburst <= 2'b10;
          lsu_r_m2s.arlen <= 8'h0;
          //lsu_w_m2s.awid <= 4'h0;
          lsu_w_m2s.awlen <= 8'h0;
          lsu_w_m2s.awburst <= 2'b10;
          lsu_w_m2s.wlast <= 1'b1;
          lsu_r_m2s.arvalid <= 1'b0;
          lsu_r_m2s.rready <= 1'b0;
          lsu_w_m2s.awvalid <= 1'b0;
          lsu_w_m2s.wvalid <= 1'b0;
          lsu_w_m2s.bready <= 1'b0;
          lsu_w_m2s.wdata <= 32'b0;
          lsu_w_m2s.wstrb <= 4'b0;
          lsu_w_m2s.awsize <= 3'b0;
          lsu_w_m2s.awaddr <= 32'b0;
          lsu_r_m2s.arsize <= 3'b0;
          lsu_r_m2s.araddr <= '0;
          lsu_rdata <= '0;
          sext_tmp <= '0;
        end
      endcase
    end
  end

endmodule

`default_nettype wire
