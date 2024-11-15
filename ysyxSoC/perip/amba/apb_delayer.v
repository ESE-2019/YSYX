module apb_delayer(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output [31:0] out_paddr,
  output        out_psel,
  output        out_penable,
  output [2:0]  out_pprot,
  output        out_pwrite,
  output [31:0] out_pwdata,
  output [3:0]  out_pstrb,
  input         out_pready,
  input  [31:0] out_prdata,
  input         out_pslverr
);

  assign out_paddr   = in_paddr;
  assign out_psel    = in_psel;
  assign out_penable = in_penable;
  assign out_pprot   = in_pprot;
  assign out_pwrite  = in_pwrite;
  assign out_pwdata  = in_pwdata;
  assign out_pstrb   = in_pstrb;
  assign in_pslverr  = out_pslverr;

  `ifdef NPC_MODE
  assign in_pready = out_pready;
  assign in_prdata = out_prdata;  
  `else
  localparam r = 32'd6; // freq(npc) / 100 MHz
  localparam s = 32'h100; // ratio

  logic entity_pready, latch_pready;
  assign in_pready = entity_pready;
  logic [31:0] latch_prdata;
  assign in_prdata   = latch_prdata;
  always_latch begin
    if (reset) begin
      latch_pready = 0;
      latch_prdata = 0;
    end
    else if (in_psel && in_penable) begin
      if (out_pready) begin
        latch_pready = 1;
        latch_prdata = out_prdata;
      end
    end
    else begin
      latch_pready = 0;
      latch_prdata = 0;
    end
  end

  logic [31:0] cnt_before, cnt_after;
  always_ff @( posedge clock ) begin
    if (reset)
      cnt_before <= 1;
    else if (in_psel && in_penable) begin
      if (latch_pready)
        cnt_before <= cnt_before;
      else
        cnt_before <= cnt_before + 1;
    end
    else
      cnt_before <= 1;
  end

  always_ff @( posedge clock ) begin
    if (reset) begin
      cnt_after <= s;
      entity_pready <= 0;
    end
    else if (latch_pready) begin
      cnt_after <= cnt_after + s;
      if (cnt_after >= cnt_before*(r-1)*s)
        entity_pready <= 1;
      else
        entity_pready <= 0;
    end
    else begin
      cnt_after <= s;
      entity_pready <= 0;
    end
  end
  `endif


endmodule
