module ysyx_24080006_dcu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] dcu_addr,
    input logic [1:0] dcu_size,
    input logic dcu_sext,
    input logic dcu_write,
    input logic [31:0] dcu_wdata,
    output logic [31:0] dcu_rdata,

    input  logic lsu2dcu_valid,
    input  logic lsu2dcu_ready,
    output logic dcu2lsu_valid,
    output logic dcu2lsu_ready,

    ysyx_24080006_axi.master axi_lsu
);

  typedef enum logic {
    IDLE,
    EXEC
  } dc_fsm_e;
  dc_fsm_e curr, next;

  logic sext;
  wire [3:0] dcu_strb = WSTRB_LUT[dcu_size] << dcu_addr[1:0];
  wire [31:0] dcu_wdata_shifted = dcu_wdata << {dcu_addr[1:0], 3'b0};

  function automatic logic [31:0] Mr(input logic [31:0] rdata, input logic [1:0] raddr,
                                     input logic sext, input logic [1:0] size);
    logic [31:0] tmp;
    tmp = rdata >> {raddr, 3'b0};
    unique case ({
      sext, size
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
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (lsu2dcu_valid & dcu2lsu_ready) begin
          next = EXEC;
        end else begin
          next = IDLE;
        end
      end
      EXEC: begin
        if (axi_lsu.rvalid || axi_lsu.bvalid) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      dcu2lsu_valid <= 1'b0;
      dcu2lsu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          if (lsu2dcu_valid & dcu2lsu_ready) begin
            if (dcu_write) begin
              dcu2lsu_valid <= 1'b1;
              dcu2lsu_ready <= 1'b0;
            end else begin
              dcu2lsu_valid <= 1'b0;
              dcu2lsu_ready <= 1'b0;
            end
          end else begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b1;
          end
        end
        EXEC: begin
          if (axi_lsu.rvalid) begin
            dcu2lsu_valid <= 1'b1;
            dcu2lsu_ready <= 1'b1;
          end else if (axi_lsu.bvalid) begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b1;
          end else begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b0;
          end
        end
      endcase
    end
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      axi_lsu.arvalid <= '0;
      axi_lsu.rready  <= '0;
      axi_lsu.awvalid <= '0;
      axi_lsu.wvalid  <= '0;
      axi_lsu.bready  <= '0;
      axi_lsu.wdata   <= '0;
      axi_lsu.wstrb   <= '0;
      axi_lsu.awsize  <= '0;
      axi_lsu.awaddr  <= '0;
      axi_lsu.arsize  <= '0;
      axi_lsu.araddr  <= '0;
      sext <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (lsu2dcu_valid & dcu2lsu_ready) begin
            if (dcu_write) begin
              axi_lsu.arvalid <= 1'b0;
              axi_lsu.rready  <= 1'b0;
              axi_lsu.awvalid <= 1'b1;
              axi_lsu.wvalid  <= 1'b1;
              axi_lsu.bready  <= 1'b0;
              axi_lsu.wdata   <= dcu_wdata_shifted;
              axi_lsu.awsize  <= {1'b0, dcu_size};
              axi_lsu.wstrb   <= dcu_strb;
              axi_lsu.awaddr  <= dcu_addr;
            end else begin
              axi_lsu.arvalid <= 1'b1;
              axi_lsu.rready  <= 1'b0;
              axi_lsu.awvalid <= 1'b0;
              axi_lsu.wvalid  <= 1'b0;
              axi_lsu.bready  <= 1'b0;
              axi_lsu.arsize  <= {1'b0, dcu_size};
              axi_lsu.araddr  <= dcu_addr;
              sext <= dcu_sext;
            end
          end else begin
            axi_lsu.arvalid <= 1'b0;
            axi_lsu.rready  <= 1'b0;
            axi_lsu.awvalid <= 1'b0;
            axi_lsu.wvalid  <= 1'b0;
            axi_lsu.bready  <= 1'b0;
          end
        end
        EXEC: begin
          if (axi_lsu.arready) axi_lsu.arvalid <= 1'b0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 1'b0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 1'b0;
          if (axi_lsu.bvalid) axi_lsu.bready <= 1'b1;
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1'b1;
          end
        end
      endcase
    end
  end

  assign axi_lsu.arid    = 4'h0;
  assign axi_lsu.arburst = 2'b10;
  assign axi_lsu.arlen   = 8'h0;
  assign axi_lsu.awid    = 4'h0;
  assign axi_lsu.awlen   = 8'h0;
  assign axi_lsu.awburst = 2'h0;
  assign axi_lsu.wlast   = 1'b1;

  assign dcu_rdata = Mr(axi_lsu.rdata, axi_lsu.araddr[1:0], sext, axi_lsu.arsize[1:0]);  // use reg?

endmodule
