module psram_top_apb (
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

  output logic qspi_sck,
  output logic qspi_ce_n,
  inout  [3:0] qspi_dio
);
  
  assign in_pready = 1;
  assign in_pslverr = 0;
  
  logic [19:0] addr;
  logic [31:0] ram [1048576];
  assign addr = in_paddr[21:2];
  assign in_prdata = ram[addr];



  always_ff @(posedge clock) begin
    if (in_psel && in_penable && in_pwrite) begin
      if (in_pstrb[0]) ram[addr][ 7: 0] <= in_pwdata[ 7: 0];
      if (in_pstrb[1]) ram[addr][15: 8] <= in_pwdata[15: 8];
      if (in_pstrb[2]) ram[addr][23:16] <= in_pwdata[23:16];
      if (in_pstrb[3]) ram[addr][31:24] <= in_pwdata[31:24];
    end
  end
  
  assign qspi_dio[0] = 1'bz;
  assign qspi_dio[1] = 1'bz;
  assign qspi_dio[2] = 1'bz;
  assign qspi_dio[3] = 1'bz;

endmodule


// module psram_top_apb (
//   input  logic        clock,
//   input  logic        reset,
//   input  logic [31:0] in_paddr,
//   input  logic        in_psel,
//   input  logic        in_penable,
//   input  logic [2:0]  in_pprot,
//   input  logic        in_pwrite,
//   input  logic [31:0] in_pwdata,
//   input  logic [3:0]  in_pstrb,
//   output logic        in_pready,
//   output logic [31:0] in_prdata,
//   output logic        in_pslverr,

//   output logic qspi_sck,
//   output logic qspi_ce_n,
//   inout  [3:0] qspi_dio
// );

//   wire [3:0] din, dout, douten;
//   wire ack;
//   EF_PSRAM_CTRL_wb u0 (
//     .clk_i(clock),
//     .rst_i(reset),
//     .adr_i(in_paddr),
//     .dat_i(in_pwdata),
//     .dat_o(in_prdata),
//     .sel_i(in_pstrb),
//     .cyc_i(in_psel),
//     .stb_i(in_psel),
//     .ack_o(ack),
//     .we_i(in_pwrite),
  
//     .sck(qspi_sck),
//     .ce_n(qspi_ce_n),
//     .din(din),
//     .dout(dout),
//     .douten(douten)
//   );
  
//   assign in_pready = ack && in_psel;
//   assign in_pslverr = 1'b0;
//   assign qspi_dio[0] = douten[0] ? dout[0] : 1'bz;
//   assign qspi_dio[1] = douten[1] ? dout[1] : 1'bz;
//   assign qspi_dio[2] = douten[2] ? dout[2] : 1'bz;
//   assign qspi_dio[3] = douten[3] ? dout[3] : 1'bz;
//   assign din = qspi_dio;

// endmodule
