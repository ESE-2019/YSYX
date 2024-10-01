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

    always_ff @(posedge clock) begin // write
        if (reset) begin
            foreach (regfile[i]) begin
                regfile[i] <= '0;
            end
        end else if (we && rd != 5'b0) begin
            regfile[rd] <= wdata;
        end
    end

    // always_ff @(posedge clock) begin // read
    //     if (reset) begin
    //         rs1_val <= '0;
    //         rs2_val <= '0;
    //     end else begin
    //         rs1_val <= regfile[rs1_addr];
    //         rs2_val <= regfile[rs2_addr];
    //     end
    // end

        always_comb  begin // will be aborted
        begin
            rs1_val = regfile[rs1_addr];
            rs2_val = regfile[rs2_addr];
        end
    end

endmodule
