module ysyx_24080006_lsu (
    input  logic        clock,
    input  logic        reset,

    ysyx_24080006_axi.master  axi_lsu,
    ysyx_24080006_uif.prev    exu,
    ysyx_24080006_uif.next    wbu
);

    enum logic [1:0] {
        IDLE,
        EXEC,
        WAIT
    } curr, next;

    always_ff @ (posedge clock) begin //fsm 1
        if (reset) begin
            curr <= IDLE;
        end
        else begin
            curr <= next;
        end
    end

    always_comb begin //fsm 2
        unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load || exu.store)
                        next = EXEC;
                    else
                        next = WAIT;
                end
                else
                    next = IDLE;
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid)
                    next = WAIT;
                else
                    next = EXEC;
            end
            WAIT: begin
                if (wbu.ready)
                    next = IDLE;
                else
                    next = WAIT;
            end
        endcase
    end

    always_ff @ (posedge clock) begin//fsm 3 for control
        unique if (reset) begin
            exu.ready <= 1;
            wbu.valid <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load || exu.store) begin
                        exu.ready <= 0;
                        wbu.valid <= 0;
                    end
                    else begin // bypass
                        exu.ready <= 0;
                        wbu.valid <= 1;
                    end
                end
                else begin
                    exu.ready <= 1;
                    wbu.valid <= 0;
                end
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid) begin
                    exu.ready <= 0;
                    wbu.valid <= 1;
                end
                else begin
                    exu.ready <= 0;
                    wbu.valid <= 0;
                end
            end
            WAIT: begin
                if (wbu.ready) begin
                    exu.ready <= 1;
                    wbu.valid <= 0;
                end
                else begin
                    exu.ready <= 0;
                    wbu.valid <= 1;
                end
            end
        endcase
        end
    end

    logic [31:0] alu_res, ldata;
    logic [4:0] rshamt;
    always_comb begin // process alu_res and ldata

        case (exu.alu_res[1:0])
			2'b00: rshamt = 0;
			2'b01: rshamt = 8;
			2'b10: rshamt = 16;
			2'b11: rshamt = 24; 
		endcase

        // if (exu.load)
        //     alu_res = ldata >> rshamt;
        // else
        //     alu_res = exu.alu_res;
    end

function automatic logic [31:0] Mr(input logic [31:0] tmp, input logic [2:0] funct_3);
	unique case (funct_3)
		3'b000: Mr = { {24{tmp[7]}}, tmp[7:0]};
		3'b001: Mr = { {16{tmp[15]}}, tmp[15:0]};
		3'b010: Mr = tmp[31:0];
		3'b100: Mr = {24'b0, tmp[7:0]};
		3'b101: Mr = {16'b0, tmp[15:0]};
		default: begin Mr = 0; 
`ifdef SIM_MODE
        $display("unknown type"); $finish; 
`endif
        end
	endcase
    //$display("load %08x", Mr);
endfunction

    always_ff @ (posedge clock) begin//fsm 3 for axi
        unique if (reset) begin
            axi_lsu.arvalid <= 0;
            axi_lsu.rready  <= 1;
            axi_lsu.awvalid <= 0;
            axi_lsu.wvalid  <= 0;
            axi_lsu.bready  <= 1;
            axi_lsu.araddr  <= 0;
            axi_lsu.awaddr  <= 0;
            axi_lsu.wdata   <= 0;
            axi_lsu.wstrb   <= 0;
            wbu.alu_res <= 0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load) begin //load
                        axi_lsu.arvalid <= 1;
                        axi_lsu.rready  <= 1;
                        axi_lsu.awvalid <= 0;
                        axi_lsu.wvalid  <= 0;
                        axi_lsu.bready  <= 0;
                        axi_lsu.araddr  <= exu.alu_res;//{exu.alu_res[31:2], 2'b00};
                    end
                    else if (exu.store) begin //write
                        axi_lsu.arvalid <= 0;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 1;
                        axi_lsu.wvalid  <= 1;
                        axi_lsu.bready  <= 1;
                        axi_lsu.awaddr  <= exu.alu_res;//{exu.alu_res[31:2], 2'b00};
                        axi_lsu.wdata   <= exu.sdata;
                        axi_lsu.wstrb   <=  (exu.funct3==3'b000)?4'b0001:
                                            (exu.funct3==3'b001)?4'b0011:
                                            (exu.funct3==3'b010)?4'b1111:4'b0;
                    end
                    else begin // bypass
                        axi_lsu.arvalid <= 0;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 0;
                        axi_lsu.wvalid  <= 0;
                        axi_lsu.bready  <= 0;
                        wbu.alu_res <= exu.alu_res;
                    end
                end
                else begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 1;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 1;
                end
            end
            EXEC: begin
                if (axi_lsu.rvalid || axi_lsu.bvalid) begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
                    //ldata <= axi_lsu.rdata;
                    wbu.alu_res <= Mr(axi_lsu.rdata >> rshamt, exu.funct3);
                    //$display("araddr %x rdata %x rshamt %d funct %b", exu.alu_res, axi_lsu.rdata, rshamt, exu.funct3);
                end
                else
                    ;
            end
            WAIT: begin
                if (wbu.ready) begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 1;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 1;
                end
                else begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
                end
            end
        endcase
        end
    end

    

    always_ff @ (posedge clock) begin
        if (reset) begin
            wbu.dnpc <= '0;
            wbu.rd_addr <= '0;
            //wbu.alu_res <= '0; //move to upper
            wbu.wb <= '0;
            wbu.jump <= '0;
            wbu.branch <= '0;
            wbu.csr_addr <= '0;
            wbu.csr_we <= '0;
            wbu.csr_wdata <= '0;
            wbu.ecall <= '0;
        end
        else begin
            wbu.dnpc <= exu.dnpc;
            wbu.rd_addr <= exu.rd_addr;
            //wbu.alu_res <= alu_res;
            wbu.wb <= exu.wb;
            wbu.jump <= exu.jump; //may be merged
            wbu.branch <= exu.branch; //^^^^^^^^^
            wbu.csr_addr <= exu.csr_addr;
            wbu.csr_we <= exu.csr_we;
            wbu.csr_wdata <= exu.csr_wdata;
            wbu.ecall <= exu.ecall;
        end

    end


endmodule
