module ysyx_24080006_reg (
    input  logic        clock,
    input  logic        reset,
    input  logic        we,
    input  logic [4:0]  rs1_addr,
    input  logic [4:0]  rs2_addr,
    input  logic [4:0]  rd,
    input  logic [31:0] wdata,
    output logic [31:0] rs1_val,
    output logic [31:0] rs2_val
);

    logic [31:0] regfile [32];

    assign rs1_val = regfile[rs1_addr];
    assign rs2_val = regfile[rs2_addr];

    always_ff @(posedge clock) begin
        if (reset) begin
            foreach (regfile[i]) begin
                regfile[i] <= '0;
            end
        end else if (we && rd != 5'b0) begin
            regfile[rd] <= wdata;
        end
    end

endmodule
