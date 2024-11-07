// module ifu_pipe_test (
//     input  logic        clock,
//     input  logic        reset,

//     ysyx_24080006_uif.prev    wbu,
//     ysyx_24080006_uif.next    idu
// );

//     logic [31:0] pc, inst;
//     import "DPI-C" function int pmem_read(input int raddr);
//     localparam RST_ADDR = 32'h8000_0000;
//     localparam NOP = 32'h00000013;
//     assign inst = pmem_read(pc);
//     logic [6:0] opcode;
//     logic [2:0] funct3;
//     logic [4:0] rs1_addr, rs2_addr, rd_addr;
//     assign opcode = inst[6:0];
//     assign funct3 = inst[14:12];
//     assign rs1_addr = inst[19:15];
//     assign rs2_addr = inst[24:20];
//     assign rd_addr = inst[11:7];
//     localparam	B_type	= 7'b1100011,
//                 I_type	= 7'b0010011,//except jalr and load
//                 R_type	= 7'b0110011,
//                 S_type  = 7'b0100011,
//                 load    = 7'b0000011,
//                 jal	 	= 7'b1101111,
//                 jalr	= 7'b1100111,
//                 lui     = 7'b0110111,
//                 auipc   = 7'b0010111,
//                 system  = 7'b1110011;//ebreak, ecall, csr

//     logic allow_to_go, raw_hazard;
//     logic [2:0] inst_cnt;
//     logic [4:0] reg_queue [$];
//     always_comb begin
//         case (opcode)
//             jalr,
//             load,
//             I_type: raw_hazard = rs1_addr ? rs1_addr inside reg_queue : 0;
//             B_type,
//             S_type,
//             R_type: raw_hazard = (rs1_addr ? rs1_addr inside reg_queue : 0) || (rs2_addr ? rs2_addr inside reg_queue : 0);
//             default: raw_hazard = 0;
//         endcase
//     end

//     always_ff @ (posedge clock) begin //pipe test
//         if (reset) begin
//             allow_to_go <= 1'b1;
//             inst_cnt <= '0;
//             foreach (reg_lut[1])
//                 reg_lut[i] <= 0;
//         end
//         else begin
//             case (inst[6:0])
//             lui,
//             auipc: begin
//                 allow_to_go <= 0;
//                 reg_lut []
//             end
//             endcase
//         end
//     end

//     enum logic {
//         RST,
//         IDLE,
//         EXEC,
//         WAIT
//     } curr, next;

//     always_ff @ (posedge clock) begin //fsm 1
//         if (reset) begin
//             curr <= RST;
//         end
//         else begin
//             curr <= next;
//         end
//     end

//     always_comb begin //fsm 2
//         unique case (curr)
//             RST:
//                     next = EXEC;
//             IDLE: begin
//                 if (allow_to_go)
//                     next = EXEC;
//                 else
//                     next = IDLE;
//             end
//             EXEC,
//             WAIT: begin
//                 if (idu.ready)
//                     next = IDLE;
//                 else
//                     next = WAIT;
//             end
//         endcase
//     end

//     always_ff @ (posedge clock) begin//fsm 3 for control
//         unique if (reset) begin
//             wbu.ready <= 1;
//             idu.valid <= 0;
//         end
//         else begin
//             unique case (curr)
//             RST: begin
//                     wbu.ready <= 0;
//                     idu.valid <= 1;
//             end
//             IDLE: begin
//                 if (allow_to_go) begin
//                     wbu.ready <= 0;
//                     idu.valid <= 1;
//                 end
//                 else begin
//                     wbu.ready <= 1;
//                     idu.valid <= 0;
//                 end
//             end
//             EXEC,
//             WAIT: begin
//                 if (idu.ready) begin
//                     wbu.ready <= 1;
//                     idu.valid <= 0;
//                 end
//                 else begin
//                     wbu.ready <= 0;
//                     idu.valid <= 1;
//                 end
//             end
//         endcase
//         end
//     end

//     always_ff @ (posedge clock) begin//fsm 3 for axi
//         unique if (reset) begin
//             idu.inst <= NOP;
//             idu.pc <= RST_ADDR;
//             pc <= RST_ADDR;
//         end
//         else begin
//             case (curr)
//             RST: begin
//                 idu.inst <= inst;
//                 idu.pc <= pc;
//                 pc <= pc + 32'h4;
//             end
//             IDLE: begin
//                 if (allow_to_go) begin
//                     idu.inst <= inst;
//                     idu.pc <= pc;
//                     if (wbu.jump || wbu.branch)
//                         pc <= wbu.dnpc;
//                     else
//                         pc <= pc + 32'h4;
//                 end
//             end
//             EXEC,
//             WAIT: begin
//                     ;
//                 end
//         endcase
//         end
//     end

// endmodule
