module top(input  logic clock, reset);

ysyx_24080006_axi axi(), axi_sram(), axi_soc();

sram sram( .*, .axi(axi_sram));
ysyx_24080006_xbar XBAR( .* );
ysyx_24080006_core CORE( .* );
endmodule
