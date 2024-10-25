module ysyx_24080006_core (
    input logic clock,
    input logic reset,
    ysyx_24080006_axi.master axi
);

ysyx_24080006_uif ifu2idu(), idu2exu(), exu2lsu(), lsu2wbu(), wbu2ifu();

ysyx_24080006_axi axi_ifu(), axi_lsu();
ysyx_24080006_arb ARB( .* );

logic we;
logic [4:0]  rs1_addr;
logic [4:0]  rs2_addr;
logic [4:0]  rd;
logic [31:0] wdata;
logic [31:0] rs1_val;
logic [31:0] rs2_val;

logic        csr_we;
logic [31:0] mepc_val;
logic        mepc_en;
logic [11:0] csr_addr;
logic [11:0] csr_waddr;
logic [31:0] csr_wdata;
logic [31:0] csr_rdata;

ysyx_24080006_reg REG ( .* );

ysyx_24080006_csr CSR ( .* );

ysyx_24080006_ifu IFU (
    .*,
    .wbu(wbu2ifu),
    .idu(ifu2idu)
);

ysyx_24080006_idu IDU (
    .*,
    .ifu(ifu2idu),
    .exu(idu2exu)
);

ysyx_24080006_exu EXU (
    .*,
    .idu(idu2exu),
    .lsu(exu2lsu)
);

ysyx_24080006_lsu LSU (
    .*,
    .exu(exu2lsu),
    .wbu(lsu2wbu)
);

ysyx_24080006_wbu WBU (
    .*,
    .lsu(lsu2wbu),
    .ifu(wbu2ifu)
);

endmodule
