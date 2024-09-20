module ysyx_24080006_csr (
    input  logic        clock,
    input  logic        reset,
    input  logic        we,
    input  logic [11:0] csr_addr,
    input  logic [31:0] wdata,
    output logic [31:0] rdata
);

    logic [31:0] regfile [4];
    
    enum logic [1:0] {
        mstatus = 2'b00,
        mtvec   = 2'b01,
        mepc    = 2'b10,
        mcause  = 2'b11
    } csr;
    
    always_comb begin
	unique case(csr_addr)
	12'h300: csr = mstatus;
	12'h305: csr = mtvec;
	12'h341: csr = mepc;
	12'h342: csr = mcause;
	default: csr = mepc;
	endcase
    end
    
    assign rdata = regfile[csr];

    always_ff @(posedge clock) begin
        if (reset) begin
            foreach (regfile[i]) begin
                regfile[i] <= '0;
            end
        end else if (we) begin
            regfile[csr] <= wdata;
        end
    end

endmodule
