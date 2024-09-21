module top(input  logic clk, rst);

axi_if axi_sram (.aclk(clk), .aresetn(!rst));
sram sram(axi_sram);

ysyx_24080006_core CORE(clk, rst, axi_sram);
endmodule