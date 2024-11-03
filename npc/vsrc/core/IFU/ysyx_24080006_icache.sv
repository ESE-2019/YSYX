module ysyx_24080006_icache
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    output logic    [IC_N-1:0] ic_index,
    input  icache_t            ic_rdata,
    output logic               ic_we,
    output icache_t            ic_wdata,

    ysyx_24080006_axi.slave  axi_ifu,
    ysyx_24080006_axi.master axi_icache
);

  assign ic_index = axi_ifu.araddr[IC_M+IC_N-1:IC_M];
  wire [31-IC_M-IC_N:0] tag = axi_ifu.araddr[31:IC_M+IC_N];

  wire hit = ic_rdata.valid && (tag == ic_rdata.tag);

  typedef enum logic [1:0] {
    IDLE,
    CHECK,
    EXEC,
    WAIT
  } ICACHE_STATE;
  ICACHE_STATE curr, next;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  wire skip_icache = axi_ifu.araddr < 32'h1000_0000;

  always_comb begin  //fsm 2
    unique case (curr)
      IDLE: begin
        if (axi_ifu.arvalid) begin
          if (skip_icache) begin
            next = EXEC;
          end else begin
            next = CHECK;
          end
        end else begin
          next = IDLE;
        end
      end
      CHECK: begin
        if (hit) begin
          next = WAIT;
        end else begin
          next = EXEC;
        end
      end
      EXEC: begin
        if (axi_icache.rvalid) begin
          next = WAIT;
        end else begin
          next = EXEC;
        end
      end
      WAIT: begin
        if (axi_ifu.rready) begin
          next = IDLE;
        end else begin
          next = WAIT;
        end
      end
    endcase
  end


  assign axi_icache.araddr = axi_ifu.araddr;

  always_ff @(posedge clock) begin  //fsm 3
    if (reset) begin

      axi_ifu.rvalid <= 1'b0;
      axi_ifu.rdata <= 32'b0;
      axi_icache.arvalid <= 1'b0;
      axi_icache.rready <= 1'b0;
      ic_we <= 1'b0;
      ic_wdata <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (axi_ifu.arvalid) begin
            if (skip_icache) begin
              axi_ifu.rvalid <= 1'b0;
              axi_icache.arvalid <= 1'b1;
              axi_icache.rready <= 1'b0;
              ic_we <= 1'b0;
            end else begin
              axi_ifu.rvalid <= 1'b0;
              axi_icache.arvalid <= 1'b0;
              axi_icache.rready <= 1'b0;
              ic_we <= 1'b0;
            end
          end else begin
            axi_ifu.rvalid <= 1'b0;
            axi_icache.arvalid <= 1'b0;
            axi_icache.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        CHECK: begin
          if (hit) begin
            axi_ifu.rvalid <= 1'b1;
            axi_ifu.rdata <= ic_rdata.inst;
            axi_icache.arvalid <= 1'b0;
            axi_icache.rready <= 1'b0;
            ic_we <= 1'b0;
          end else begin
            axi_ifu.rvalid <= 1'b0;
            axi_icache.arvalid <= 1'b1;
            axi_icache.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        EXEC: begin
          if (axi_icache.arready) begin
            axi_icache.arvalid <= 1'b0;
          end
          if (axi_icache.rvalid) begin
            axi_ifu.rvalid <= 1'b1;
            axi_icache.rready <= 1'b1;
            axi_ifu.rdata <= axi_icache.rdata;
            if (!skip_icache) begin
              ic_we <= 1'b1;
              ic_wdata <= {1'b1, tag, axi_icache.rdata};
            end
          end else begin
            axi_ifu.rvalid <= 1'b0;
            axi_icache.rready <= 1'b0;
            ic_we <= 1'b0;
          end
        end
        WAIT: begin
          axi_icache.rready <= axi_icache.rvalid;
          if (axi_ifu.rready) begin
            axi_ifu.rvalid <= 1'b0;
            axi_icache.arvalid <= 1'b0;
            ic_we <= 1'b0;
          end else begin
            axi_ifu.rvalid <= 1'b1;
            axi_icache.arvalid <= 1'b0;
            ic_we <= 1'b0;
          end
        end
      endcase
    end
  end

  assign axi_ifu.arready    = 1'b1;
  assign axi_icache.arid    = 4'h0;
  assign axi_icache.arlen   = 8'h0;
  assign axi_icache.arsize  = 3'h2;
  assign axi_icache.arburst = 2'h1;

`ifdef SIM_MODE
  int hit_num = 0;
  int skip_num = 0;
  int miss_num = 0;
  always_ff @(posedge clock) begin
    case (curr)
      IDLE: begin
        if (axi_ifu.arvalid) begin
          if (skip_icache) begin
            skip_num++;
          end
        end
      end
      CHECK: begin
        if (hit) begin
          hit_num++;
        end else begin
          miss_num++;
        end
      end
      default: ;
    endcase
  end
`endif

endmodule
