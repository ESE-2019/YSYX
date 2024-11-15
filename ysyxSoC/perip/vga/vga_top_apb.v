module vga_top_apb(
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

  output logic [7:0]  vga_r,
  output logic [7:0]  vga_g,
  output logic [7:0]  vga_b,
  output logic        vga_hsync,
  output logic        vga_vsync,
  output logic        vga_valid
);

assign in_pready = 1'b1;
assign in_pslverr = 1'b0;

logic [11:0] vga_data;
logic [ 9:0] x_addr, y_addr;
vga_ctrl VGA_CTRL ( .* );

logic [11:0] vga_buf [524287:0];
assign vga_data = vga_buf[{x_addr, y_addr[8:0]}];

logic [ 9:0] x_paddr;
logic [ 8:0] y_paddr;
assign x_paddr = in_paddr[20:11];
assign y_paddr = in_paddr[10: 2];
always_ff @ (posedge clock) begin
  if (x_addr > 640 || y_addr > 480)
    $display("x %d y %d", x_addr, y_addr);
  if (reset) begin
    foreach (vga_buf[i])
      vga_buf[i] = '1; // veri-lator bug instead of <=
  end else if (in_psel && in_pwrite && in_penable) begin
    vga_buf[{x_paddr      , y_paddr     }] <= in_pwdata[11: 0];
    vga_buf[{x_paddr      , y_paddr+9'd1}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr      , y_paddr+9'd2}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'b1, y_paddr     }] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'b1, y_paddr+9'd1}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'b1, y_paddr+9'd2}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'd2, y_paddr     }] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'd2, y_paddr+9'd1}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'd2, y_paddr+9'd2}] <= in_pwdata[11: 0];
    vga_buf[{x_paddr+10'd3, y_paddr     }] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd3, y_paddr+9'd1}] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd3, y_paddr+9'd2}] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd4, y_paddr     }] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd4, y_paddr+9'd1}] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd4, y_paddr+9'd2}] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd5, y_paddr     }] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd5, y_paddr+9'd1}] <= in_pwdata[27:16];
    vga_buf[{x_paddr+10'd5, y_paddr+9'd2}] <= in_pwdata[27:16];
  end
end


endmodule

module vga_ctrl(
    input  logic          clock,
    input  logic          reset,
    input  logic [11:0]   vga_data, //上层模块提供的VGA颜色数据
    output logic [9:0]    x_addr,   //提供给上层模块的当前扫描像素点坐标
    output logic [9:0]    y_addr,
    output logic          vga_hsync,    //行同步和列同步信号
    output logic          vga_vsync,
    output logic          vga_valid,    //消隐信号
    output logic [7:0]    vga_r,    //红绿蓝颜色信号
    output logic [7:0]    vga_g,
    output logic [7:0]    vga_b
    );

  //640x480分辨率下的VGA参数设置
  parameter    x_frontporch = 10'd96;
  parameter    x_active     = 10'd144;
  parameter    x_backporch  = 10'd784;
  parameter    x_total      = 10'd800;

  parameter    y_frontporch = 10'd2;
  parameter    y_active     = 10'd35;
  parameter    y_backporch  = 10'd515;
  parameter    y_total      = 10'd525;

  //像素计数值
  reg [9:0]    x_cnt;
  reg [9:0]    y_cnt;

  always_ff @(posedge clock) begin
      if(reset) begin
          x_cnt <= 0;
          y_cnt <= 0;
      end
      else begin
          if(x_cnt >= x_total-1)begin
              x_cnt <= 0;
              if(y_cnt >= y_total-1) y_cnt <= 0;
              else y_cnt <= y_cnt + 1;
          end
          else x_cnt <= x_cnt + 1;
      end
  end
  //生成同步信号
  assign vga_hsync = (x_cnt >= x_frontporch) & (x_cnt < x_total);
  assign vga_vsync = (y_cnt >= y_frontporch) & (y_cnt < y_total);
  //生成消隐信号
  //assign vga_valid = 1;//(x_cnt >= x_active) & (x_cnt < x_backporch) & (y_cnt >= y_active) & (y_cnt < y_backporch);
  always_ff @ (posedge clock)
    if (reset == 1'b1)
      vga_valid <= 0;
    else if ( (x_cnt >= x_active) & (x_cnt < x_backporch) & (y_cnt >= y_active) & (y_cnt < y_backporch) )
      vga_valid <= ~vga_valid;
  //计算当前有效像素坐标
  assign x_addr = (x_cnt >= x_active) & (x_cnt < x_backporch) ? (x_cnt - x_active) : {10{1'b0}};
  assign y_addr = (y_cnt >= y_active) & (y_cnt < y_backporch) ? (y_cnt - y_active) : {10{1'b0}};
  //设置输出的颜色值
  assign vga_r = {vga_data[11:8], 4'hf};
  assign vga_g = {vga_data[ 7:4], 4'hf};
  assign vga_b = {vga_data[ 3:0], 4'hf};
endmodule
