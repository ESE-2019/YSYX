package ysyx_24080006_sim_pkg;

  parameter real DELAYER = 6;

  function automatic logic INSIDE(input logic [31:0] addr, input logic [31:0] left, input logic [31:0] right);
    INSIDE = addr >= left && addr <= right;
  endfunction
  function automatic logic INSIDE_PERIP(input logic [31:0] addr);
    INSIDE_PERIP = INSIDE(addr, 32'h0200_0000, 32'h0200_ffff) ||  // CLINT
        INSIDE(addr, 32'h1000_0000, 32'h1000_0fff) ||  // UART
        INSIDE(addr, 32'h1000_2000, 32'h1000_200f) ||  // GPIO
        INSIDE(addr, 32'h1001_1000, 32'h1001_1007) ||  // PS2
        INSIDE(addr, 32'h2100_0000, 32'h211f_ffff);  // VGA
  endfunction
  function automatic logic INSIDE_MEM(input logic [31:0] addr);
    INSIDE_MEM = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) ||  // FLASH
        `ifdef NPC_MODE
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff) ||  // NPC SRAM
        `endif
        INSIDE(addr, 32'ha000_0000, 32'ha3ff_ffff);  // SDRAM
  endfunction
  function automatic logic INSIDE_STORE(input logic [31:0] addr);
    INSIDE_STORE = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
    `ifdef NPC_MODE
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff) ||  // NPC SRAM
        `endif
        INSIDE(addr, 32'ha000_0000, 32'ha3ff_ffff) ||  // SDRAM
        INSIDE(addr, 32'h1000_0000, 32'h1000_0fff) ||  // UART
        INSIDE(addr, 32'h1000_2000, 32'h1000_200f) ||  // GPIO
        INSIDE(addr, 32'h2100_0000, 32'h211f_ffff);  // VGA
  endfunction
  function automatic logic INSIDE_LOAD(input logic [31:0] addr);
    INSIDE_LOAD = INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) ||  // SRAM
        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) ||  // FLASH
        `ifdef NPC_MODE
        INSIDE(addr, 32'h8000_0000, 32'h87ff_ffff) ||  // NPC SRAM
        `endif
        INSIDE(addr, 32'ha000_0000, 32'ha3ff_ffff) ||  // SDRAM
        INSIDE(addr, 32'h0200_0000, 32'h0200_ffff) ||  // CLINT
        INSIDE(addr, 32'h1000_0000, 32'h1000_0fff) ||  // UART
        INSIDE(addr, 32'h1000_2000, 32'h1000_200f) ||  // GPIO
        INSIDE(addr, 32'h1001_1000, 32'h1001_1007) ||  // PS2
        INSIDE(addr, 32'h2100_0000, 32'h211f_ffff);  // VGA
  endfunction

endpackage
