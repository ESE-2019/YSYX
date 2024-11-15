module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
  input  logic        clock,
  input  logic        reset,
  input  logic [31:0] in_paddr,
  input  logic        in_psel,
  input  logic        in_penable,
  input  logic [2:0]  in_pprot,
  input  logic        in_pwrite,
  input  logic [31:0] in_pwdata,
  input  logic [3:0]  in_pstrb,
  output logic        in_pready,
  output logic [31:0] in_prdata,
  output logic        in_pslverr,

  output logic                  spi_sck,
  output logic [spi_ss_num-1:0] spi_ss,
  output logic                  spi_mosi,
  input  logic                  spi_miso,
  output logic                  spi_irq_out
);

logic [31:0] paddr, pwdata, prdata;
logic [ 3:0] pstrb;
logic penable, pwrite, pready;
spi_entity SPI_ENTITY (.*,
  .in_paddr(paddr),
  .in_penable(penable),
  .in_pwrite(pwrite),
  .in_pwdata(pwdata),
  .in_pstrb(pstrb),
  .in_pready(pready),
  .in_prdata(prdata));

logic [31:0] paddr_xip, pwdata_xip, prdata_xip;
logic [ 3:0] pstrb_xip;
logic penable_xip, pwrite_xip, pready_xip;
assign pstrb_xip = '1;

assign paddr   = in_paddr < flash_addr_start ? in_paddr   :   paddr_xip;
assign pwdata  = in_paddr < flash_addr_start ? in_pwdata  :  pwdata_xip;
assign pstrb   = in_paddr < flash_addr_start ? in_pstrb   :   pstrb_xip;
assign penable = in_paddr < flash_addr_start ? in_penable : penable_xip;
assign pwrite  = in_paddr < flash_addr_start ? in_pwrite  :  pwrite_xip;

assign in_prdata = in_paddr < flash_addr_start ? prdata : prdata_xip;
assign in_pready = in_paddr < flash_addr_start ? pready : pready_xip;

enum {
  IDLE,
  SS01,
  TX01,
  CTRL,
  WAIT,
  RX00,
  RESP
} state;

localparam CTRL_VALUE = (32'h1 << 13) | (32'h1 << 8) | 32'd64;
always_ff @ (posedge clock) begin
  if (reset | !in_psel) begin
    state <= IDLE;
    paddr_xip <= '0;
    pwrite_xip <= '0;
    pwdata_xip <= '0;
    prdata_xip <= '0;
    pready_xip <= '0;
    penable_xip <= '0;
  end
  else begin
    case(state)
    IDLE: begin
      if (in_paddr >= flash_addr_start && in_psel && in_penable && !in_pwrite) begin
        state <= SS01;
        paddr_xip <= 32'h10001018;
        pwrite_xip <= 1;
        pwdata_xip <= 32'h1;
        penable_xip <= 1;
      end
      else if (in_paddr >= flash_addr_start && in_psel && in_penable && in_pwrite) begin
        $display("cannot write flash");
        $finish;
      end
      else begin
        state <= IDLE;
        paddr_xip <= '0;
        pwrite_xip <= '0;
        pwdata_xip <= '0;
        prdata_xip <= '0;
        pready_xip <= '0;
        penable_xip <= '0;
      end
    end
    SS01: begin
      if (penable_xip & pready) begin
        state <= TX01;
        paddr_xip <= 32'h10001004;
        pwrite_xip <= 1;
        pwdata_xip <= {8'h03, in_paddr[23:0]};
        penable_xip <= 0;
      end
      else begin
        state <= SS01;
        paddr_xip <= 32'h10001018;
        pwrite_xip <= 1;
        pwdata_xip <= 32'h1;
        penable_xip <= 1;
      end
    end
    TX01: begin
      if (penable_xip & pready) begin
        state <= CTRL;
        paddr_xip <= 32'h10001010;
        pwrite_xip <= 1;
        pwdata_xip <= CTRL_VALUE;
        penable_xip <= 0;
      end
      else begin
        state <= TX01;
        paddr_xip <= 32'h10001004;
        pwrite_xip <= 1;
        pwdata_xip <= {8'h03, in_paddr[23:0]};
        penable_xip <= 1;
      end
    end
    CTRL: begin
      if (penable_xip & pready) begin
        state <= WAIT;
        paddr_xip <= 32'h10001010;
        pwrite_xip <= 0;
        penable_xip <= 0;
      end
      else begin
        state <= CTRL;
        paddr_xip <= 32'h10001010;
        pwrite_xip <= 1;
        pwdata_xip <= CTRL_VALUE;
        penable_xip <= 1;
      end
    end
    WAIT: begin
      if (penable_xip & pready) begin
        penable_xip <= 0;
        if(!prdata[8]) begin
          state <= RX00;
          paddr_xip <= 32'h10001000;
          pwrite_xip <= 0;
        end
      end
      else begin
        state <= WAIT;
        paddr_xip <= 32'h10001010;
        pwrite_xip <= 0;
        penable_xip <= 1;
      end
    end
    RX00: begin
      if (penable_xip & pready) begin
        penable_xip <= 0;
        prdata_xip <= {prdata[7:0], prdata[15:8], prdata[23:16], prdata[31:24]};
        state <= RESP;
      end
      else begin
        state <= RX00;
        paddr_xip <= 32'h10001000;
        pwrite_xip <= 0;
        penable_xip <= 1;
      end
    end
    RESP: begin
      if (in_penable)
        state <= RESP;
      else
        state <= IDLE;
      pready_xip <= '1;
      penable_xip <= '0;
    end
    default: state <= IDLE;
    endcase
  end

end


endmodule

module spi_entity #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
  input  logic        clock,
  input  logic        reset,
  input  logic [31:0] in_paddr,
  input  logic        in_psel,
  input  logic        in_penable,
  input  logic [2:0]  in_pprot,
  input  logic        in_pwrite,
  input  logic [31:0] in_pwdata,
  input  logic [3:0]  in_pstrb,
  output logic        in_pready,
  output logic [31:0] in_prdata,
  output logic        in_pslverr,

  output logic                  spi_sck,
  output logic [spi_ss_num-1:0] spi_ss,
  output logic                  spi_mosi,
  input  logic                  spi_miso,
  output logic                  spi_irq_out
);

spi_top u0_spi_top (
  .wb_clk_i(clock),
  .wb_rst_i(reset),
  .wb_adr_i(in_paddr[4:0]),
  .wb_dat_i(in_pwdata),
  .wb_dat_o(in_prdata),
  .wb_sel_i(in_pstrb),
  .wb_we_i (in_pwrite),
  .wb_stb_i(in_psel),
  .wb_cyc_i(in_penable),
  .wb_ack_o(in_pready),
  .wb_err_o(in_pslverr),
  .wb_int_o(spi_irq_out),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

endmodule
