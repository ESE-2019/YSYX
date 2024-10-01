module top(input  logic clock, reset);

ysyx_24080006_axi axi ();
sram sram( .* );

ysyx_24080006_core CORE( .* );
endmodule