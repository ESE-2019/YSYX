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

localparam [3:0] WSTRB_LUT [4] = '{
    4'b0001,  // funct3 == 3'b000
    4'b0011,  // funct3 == 3'b001
    4'b1111,  // funct3 == 3'b010
    4'b0000   // others
};

logic [1:0] Mr_param_addr;
logic [2:0] Mr_param_funct3;
function automatic logic [31:0] Mr(input logic [31:0] rdata, input logic [1:0] addr, input logic [2:0] funct3);
	logic [4:0] Mr_shamt;
	logic [31:0] tmp;
	unique case (addr)
		2'b00: Mr_shamt = 0;
		2'b01: Mr_shamt = 8;
		2'b10: Mr_shamt = 16;
		2'b11: Mr_shamt = 24;
	endcase
	tmp = rdata >> Mr_shamt;
	unique case (funct3)
		3'b000: Mr = { {24{tmp[7]}}, tmp[7:0]};
		3'b001: Mr = { {16{tmp[15]}}, tmp[15:0]};
		3'b010: Mr = tmp[31:0];
		3'b100: Mr = {24'b0, tmp[7:0]};
		3'b101: Mr = {16'b0, tmp[15:0]};
		default: begin Mr = 0;end
	endcase
endfunction

assign axi_lsu.arid    = 4'h1;
assign axi_lsu.arlen   = 8'h0;
assign axi_lsu.arburst = 2'h0;

assign axi_lsu.awid    = 4'h2;
assign axi_lsu.awlen   = 8'h0;
assign axi_lsu.awburst = 2'h0;

assign axi_lsu.wlast   = 1'b0;

    always_ff @ (posedge clock) begin//fsm 3 for axi
        unique if (reset) begin
            axi_lsu.arvalid <= '0;
            axi_lsu.rready  <= '0;
            axi_lsu.awvalid <= '0;
            axi_lsu.wvalid  <= '0;
            axi_lsu.bready  <= '0;
            axi_lsu.araddr  <= '0;
            axi_lsu.awaddr  <= '0;
            axi_lsu.wdata   <= '0;
            axi_lsu.wstrb   <= '0;
            axi_lsu.arsize  <= '0;
            axi_lsu.awsize  <= '0;
            wbu.alu_res <= '0;
            Mr_param_addr <= '0;
            Mr_param_funct3 <= '0;
        end
        else begin
            unique case (curr)
            IDLE: begin
                if (exu.valid) begin
                    if (exu.load) begin // load / read
                        axi_lsu.arvalid <= 1;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 0;
                        axi_lsu.wvalid  <= 0;
                        axi_lsu.bready  <= 0;
                        axi_lsu.arsize  <= {1'b0, exu.funct3[1:0]};
                        axi_lsu.araddr  <= exu.alu_res;
                        Mr_param_addr <= exu.alu_res[1:0];
                        Mr_param_funct3 <= exu.funct3;
                    end
                    else if (exu.store) begin // store / write
                        axi_lsu.arvalid <= 0;
                        axi_lsu.rready  <= 0;
                        axi_lsu.awvalid <= 1;
                        axi_lsu.wvalid  <= 1;
                        axi_lsu.bready  <= 0;
                        axi_lsu.awaddr  <= exu.alu_res;
                        axi_lsu.wdata   <= exu.sdata << (8* exu.alu_res[1:0]);
                        axi_lsu.awsize  <= exu.funct3;
                        axi_lsu.wstrb   <= WSTRB_LUT[exu.funct3[1:0]] << exu.alu_res[1:0];
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
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
                end
            end
            EXEC: begin
                if (axi_lsu.arready)
                    axi_lsu.arvalid <= 0;
                if (axi_lsu.awready)
                    axi_lsu.awvalid <= 0;
                if (axi_lsu.wready)
                    axi_lsu.wvalid  <= 0;
                if (axi_lsu.bvalid) begin
                    axi_lsu.bready  <= 1;
                    //$display("[LSU] 0x%08x write [0x%08x]", axi_lsu.awaddr, axi_lsu.wdata);
                end
                if (axi_lsu.rvalid) begin
                    axi_lsu.rready  <= 1;
                    wbu.alu_res <= Mr(axi_lsu.rdata, Mr_param_addr, Mr_param_funct3);
                    //$display("[LSU] 0x%08x read [0x%08x]", axi_lsu.araddr, axi_lsu.rdata);
                end
            end
            WAIT: begin
                if (wbu.ready) begin
                    axi_lsu.arvalid <= 0;
                    axi_lsu.rready  <= 0;
                    axi_lsu.awvalid <= 0;
                    axi_lsu.wvalid  <= 0;
                    axi_lsu.bready  <= 0;
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
            wbu.wb <= '0;
            wbu.jump <= '0;
            wbu.branch <= '0;
            wbu.csr_addr <= '0;
            wbu.csr_we <= '0;
            wbu.csr_wdata <= '0;
            wbu.ecall <= '0;
            wbu.pc <= '0;
        end
        else if (curr == IDLE && exu.valid) begin
            wbu.dnpc <= exu.dnpc;
            wbu.rd_addr <= exu.rd_addr;
            wbu.wb <= exu.wb;
            wbu.jump <= exu.jump; //may be merged
            wbu.branch <= exu.branch; //^^^^^^^^^
            wbu.csr_addr <= exu.csr_addr;
            wbu.csr_we <= exu.csr_we;
            wbu.csr_wdata <= exu.csr_wdata;
            wbu.ecall <= exu.ecall;
            wbu.pc <= exu.pc;
        end

    end

`ifdef SOC_MODE

    function automatic logic INSIDE (
        input logic [31:0] addr, left, right);
        INSIDE = addr >= left && addr <= right;
    endfunction

    function automatic logic INSIDE_PERIP (input logic [31:0] addr);
        INSIDE_PERIP =  INSIDE(addr, 32'h0200_0000, 32'h0200_ffff) || // CLINT
                        INSIDE(addr, 32'h1000_0000, 32'h1000_0fff) || // UART
                        //INSIDE(addr, 32'h1000_1000, 32'h1000_1fff) || // SPI
                        INSIDE(addr, 32'h1000_2000, 32'h1000_200f) || // GPIO
                        INSIDE(addr, 32'h1001_1000, 32'h1001_1007) || // PS2
                        INSIDE(addr, 32'h2100_0000, 32'h211f_ffff) ; // VGA
    endfunction

    function automatic logic INSIDE_MEM (input logic [31:0] addr);
        INSIDE_MEM =    INSIDE(addr, 32'h0f00_0000, 32'h0f00_1fff) || // SRAM
                        //INSIDE(addr, 32'h2000_0000, 32'h2000_0fff) || // MROM
                        INSIDE(addr, 32'h3000_0000, 32'h30ff_ffff) || // FLASH
                        INSIDE(addr, 32'h4000_0000, 32'hffff_ffff) ; // OTHERS
    endfunction

    import "DPI-C" function void SKIP_DIFFTEST();

    always_ff @ (posedge clock) begin
        if (curr == EXEC && exu.store) begin
            if (INSIDE_PERIP(axi_lsu.awaddr)) begin
                SKIP_DIFFTEST();
            end
            else if (INSIDE_MEM(axi_lsu.awaddr))
                ;
            else begin
                $display("[LSU] store addr error 0x%08x", axi_lsu.awaddr);
                $finish;
            end
        end
        if (curr == EXEC && exu.load) begin
            if (INSIDE_PERIP(axi_lsu.araddr)) begin
                SKIP_DIFFTEST();
            end
            else if (INSIDE_MEM(axi_lsu.araddr))
                ;
            else begin
                $display("[LSU] load addr error 0x%08x",axi_lsu.araddr);
                $finish;
            end
        end
    end
`endif
endmodule
