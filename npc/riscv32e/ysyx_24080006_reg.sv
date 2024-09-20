module ysyx_24080006_reg (
    input  logic        clock,
    input  logic        reset,
    input  logic        we,
    input  logic [4:0]  rs1,
    input  logic [4:0]  rs2,
    input  logic [4:0]  rd,
    input  logic [31:0] wdata,
    output logic [31:0] rs1_data,
    output logic [31:0] rs2_data
);

    logic [31:0] regfile [32];

    assign rs1_data = regfile[rs1];
    assign rs2_data = regfile[rs2];

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
