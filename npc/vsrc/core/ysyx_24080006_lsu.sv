module ysyx_24080006_lsu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] lsu_addr,
    input logic [1:0] lsu_size,
    input logic lsu_sext,
    input logic lsu_write,
    input logic [31:0] lsu_wdata,
    output logic [31:0] lsu_rdata,

    input  logic exu2lsu_valid,
    output logic lsu2exu_ready,
    input  logic exu2lsu_ready,
    output logic lsu2exu_valid,

    ysyx_24080006_axi.master axi_lsu
);

  typedef enum logic {
    IDLE,
    EXEC
  } ls_fsm_e;
  ls_fsm_e curr, next;

  logic sext_tmp;
  localparam logic [3:0] WSTRB_LUT[4] = '{
      4'b0001,  // funct3 == 3'b000
      4'b0011,  // funct3 == 3'b001
      4'b1111,  // funct3 == 3'b010
      4'b0000
  };
  wire [ 3:0] lsu_strb = WSTRB_LUT[lsu_size] << lsu_addr[1:0];
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
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (exu2lsu_valid & lsu2exu_ready) begin
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
      lsu2exu_valid <= 1'b0;
      lsu2exu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          if (exu2lsu_valid & lsu2exu_ready) begin
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
        EXEC: begin
          if (axi_lsu.rvalid) begin
            lsu2exu_valid <= 1'b1;
            lsu2exu_ready <= 1'b1;
          end else if (axi_lsu.bvalid) begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b1;
          end else begin
            lsu2exu_valid <= 1'b0;
            lsu2exu_ready <= 1'b0;
          end
        end
      endcase
    end
  end

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      axi_lsu.arvalid <= 1'b0;
      axi_lsu.rready <= 1'b0;
      axi_lsu.awvalid <= 1'b0;
      axi_lsu.wvalid <= 1'b0;
      axi_lsu.bready <= 1'b0;
      axi_lsu.wdata <= 32'b0;
      axi_lsu.wstrb <= 4'b0;
      axi_lsu.awsize <= 3'b0;
      axi_lsu.awaddr <= 32'b0;
      axi_lsu.arsize <= 3'b0;
      axi_lsu.araddr <= '0;
      lsu_rdata <= '0;
      sext_tmp <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (exu2lsu_valid & lsu2exu_ready) begin
            if (lsu_write) begin
              axi_lsu.arvalid <= 1'b0;
              axi_lsu.rready  <= 1'b0;
              axi_lsu.awvalid <= 1'b1;
              axi_lsu.wvalid  <= 1'b1;
              axi_lsu.bready  <= 1'b0;
              axi_lsu.wdata   <= lsu_wdata_shifted;
              axi_lsu.awsize  <= {1'b0, lsu_size};
              axi_lsu.wstrb   <= lsu_strb;
              axi_lsu.awaddr  <= lsu_addr;
            end else begin
              axi_lsu.arvalid <= 1'b1;
              axi_lsu.rready  <= 1'b0;
              axi_lsu.awvalid <= 1'b0;
              axi_lsu.wvalid  <= 1'b0;
              axi_lsu.bready  <= 1'b0;
              axi_lsu.arsize  <= {1'b0, lsu_size};
              axi_lsu.araddr  <= lsu_addr;
              sext_tmp        <= lsu_sext;
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
            lsu_rdata <= Mr(axi_lsu.rdata, axi_lsu.araddr[1:0], sext_tmp, axi_lsu.arsize[1:0]);
          end
        end
      endcase
    end
  end

  assign axi_lsu.arid = 4'h1;
  assign axi_lsu.arburst = 2'b10;
  assign axi_lsu.arlen = 8'h0;
  assign axi_lsu.awid = 4'he;
  assign axi_lsu.awlen = 8'h0;
  assign axi_lsu.awburst = 2'b10;
  assign axi_lsu.wlast = 1'b1;

endmodule
