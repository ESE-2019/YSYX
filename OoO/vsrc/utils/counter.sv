module counter (
    input logic clock,
    input logic reset,

    input  logic        counter_incr_en,
    input  logic        counter_high_we,
    input  logic        counter_low_we,
    input  logic [31:0] counter_wdata,
    output logic [31:0] counter_high_rdata,
    output logic [31:0] counter_low_rdata
);

  logic [31:0] counter_high_d, counter_high_q;
  logic [31:0] counter_low_d, counter_low_q;

  always_comb begin
    if (counter_high_we) begin
      counter_high_d = counter_wdata;
      counter_low_d  = counter_low_q;
    end else if (counter_low_we) begin
      counter_high_d = counter_high_q;
      counter_low_d  = counter_wdata;
    end else if (counter_incr_en) begin
      {counter_high_d, counter_low_d} = {counter_high_q, counter_low_q} + 64'h1;
    end else begin
      {counter_high_d, counter_low_d} = {counter_high_q, counter_low_q};
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      counter_high_q <= 32'b0;
      counter_low_q  <= 32'b0;
    end else begin
      counter_high_q <= counter_high_d;
      counter_low_q  <= counter_low_d;
    end
  end

  assign counter_high_rdata = counter_high_q;
  assign counter_low_rdata  = counter_low_q;

endmodule
