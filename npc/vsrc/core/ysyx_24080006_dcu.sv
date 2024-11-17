module ysyx_24080006_dcu
  import ysyx_24080006_pkg::*;
(
    input logic clock,
    input logic reset,

    input logic [31:0] dcu_addr,
    input logic [1:0] dcu_size,
    input logic dcu_write,
    input logic [31:0] dcu_wdata,
    output logic [31:0] dcu_rdata,

    input logic lsu2dcu_valid,
    input logic lsu2dcu_ready,
    output logic dcu2lsu_valid,
    output logic dcu2lsu_ready,
    input logic fencei,  //todo

    ysyx_24080006_axi.master axi_lsu
);

  typedef enum logic [2:0] {
    IDLE,
    SKIP,
    WRITE,
    READ,
    RAW,
    HALF_READ
  } dc_fsm_e;
  dc_fsm_e curr, next;

  logic [31:0] ic_addr;


  typedef struct packed {
    logic valid;
    logic [3:0] strb;
    logic [3:0] modify;
    logic [29:0] tag;
    logic [31:0] data;
  } dcache_t;
  dcache_t dcache;

  wire [3:0] dcu_strb = WSTRB_LUT[dcu_size] << dcu_addr[1:0];
  wire [31:0] dcu_wdata_shifted = dcu_wdata << {dcu_addr[1:0], 3'b0};
  wire [31:0] dcu_mask = {{8{dcu_strb[3]}}, {8{dcu_strb[2]}}, {8{dcu_strb[1]}}, {8{dcu_strb[0]}}};
  wire tag_hit = dcache.valid && dcache.tag == dcu_addr[31:2];
  logic read_hit;
  logic [31:0] half_read_data;
  wire hit = tag_hit & (dcu_write | read_hit);
  wire skip_dcache = 1;//dcu_addr < 32'ha000_0000;
  logic [31:0] dcache_hit_wdata;

  always_ff @(posedge clock) begin  //fsm 1
    if (reset) begin
      curr <= IDLE;
    end else begin
      curr <= next;
    end
  end

  always_comb begin  //fsm 2
    next = IDLE;
    unique case (curr)
      IDLE: begin
        if (lsu2dcu_valid & dcu2lsu_ready) begin
          if (skip_dcache) begin
            next = SKIP;
          end else if (hit) begin
            next = IDLE;
          end else begin
            if (dcu_write) begin  // write
              if (dcache.valid && dcache.modify != 4'b0) begin
                next = WRITE;
              end else begin
                next = IDLE;
              end
            end else begin  // read
              if (tag_hit) begin
                next = HALF_READ;
              end else if (dcache.valid && dcache.modify != 4'b0) begin
                next = RAW;
              end else begin
                next = READ;
              end
            end
          end
        end else begin
          next = IDLE;
        end
      end

      SKIP: begin
        if (axi_lsu.rvalid || axi_lsu.bvalid) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end

      WRITE: begin
        if (axi_lsu.bvalid) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end

      RAW: begin
        if (axi_lsu.bvalid) begin
          next = READ;
        end else begin
          next = curr;
        end
      end

      READ, HALF_READ: begin
        if (axi_lsu.rvalid) begin
          next = IDLE;
        end else begin
          next = curr;
        end
      end
      default: next = IDLE;
    endcase
  end

  always_ff @(posedge clock) begin  // fsm 3 for handshake
    if (reset) begin
      dcu2lsu_valid <= 1'b0;
      dcu2lsu_ready <= 1'b1;
    end else begin
      unique case (curr)
        IDLE: begin
          if (lsu2dcu_valid & dcu2lsu_ready) begin
            if (skip_dcache) begin  // SKIP
              if (dcu_write) begin
                dcu2lsu_valid <= 1'b1;
                dcu2lsu_ready <= 1'b0;
              end else begin
                dcu2lsu_valid <= 1'b0;
                dcu2lsu_ready <= 1'b0;
              end
            end else if (hit) begin  // HIT
              dcu2lsu_valid <= 1'b1;
              dcu2lsu_ready <= 1'b1;
            end else begin  // MISS
              if (dcu_write) begin
                if (dcache.valid && dcache.modify != 4'b0) begin
                  dcu2lsu_valid <= 1'b1;
                  dcu2lsu_ready <= 1'b0;
                end else begin
                  dcu2lsu_valid <= 1'b1;
                  dcu2lsu_ready <= 1'b1;
                end
              end else begin
                dcu2lsu_valid <= 1'b0;
                dcu2lsu_ready <= 1'b0;
              end

            end
          end else begin  // NOP
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b1;
          end
        end

        SKIP: begin
          if (axi_lsu.rvalid) begin
            dcu2lsu_valid <= 1'b1;
            dcu2lsu_ready <= 1'b1;
          end else if (axi_lsu.bvalid) begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b1;
          end else begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b0;
          end
        end

        WRITE: begin
          if (axi_lsu.bvalid) begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b1;
          end else begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b0;
          end
        end

        RAW: begin
          dcu2lsu_valid <= 1'b0;
          dcu2lsu_ready <= 1'b0;
        end

        READ, HALF_READ: begin
          if (axi_lsu.rvalid) begin
            dcu2lsu_valid <= 1'b1;
            dcu2lsu_ready <= 1'b1;
          end else begin
            dcu2lsu_valid <= 1'b0;
            dcu2lsu_ready <= 1'b0;
          end
        end

        default: ;
      endcase
    end
  end  // fsm 3 for axi

  always_ff @(posedge clock) begin  // fsm 3 for axi
    if (reset) begin
      axi_lsu.arvalid <= '0;
      axi_lsu.rready <= '0;
      axi_lsu.awvalid <= '0;
      axi_lsu.wvalid <= '0;
      axi_lsu.bready <= '0;
      axi_lsu.araddr <= '0;
      axi_lsu.awaddr <= '0;
      axi_lsu.wdata <= '0;
      axi_lsu.arsize <= '0;
      axi_lsu.awsize <= '0;
      axi_lsu.wstrb <= '0;
      dcu_rdata <= '0;
      dcache <= '0;
    end else begin
      unique case (curr)
        IDLE: begin
          if (lsu2dcu_valid & dcu2lsu_ready) begin
            unique if (skip_dcache) begin  // SKIP

              if (dcu_write) begin
                axi_lsu.arvalid <= 1'b0;
                axi_lsu.rready  <= 1'b0;
                axi_lsu.awvalid <= 1'b1;
                axi_lsu.wvalid  <= 1'b1;
                axi_lsu.bready  <= 1'b0;
                axi_lsu.awaddr  <= dcu_addr;
                axi_lsu.wdata   <= dcu_wdata_shifted;
                axi_lsu.awsize  <= {1'b0, dcu_size};
                axi_lsu.wstrb   <= dcu_strb;
              end else begin
                axi_lsu.arvalid <= 1'b1;
                axi_lsu.rready  <= 1'b0;
                axi_lsu.awvalid <= 1'b0;
                axi_lsu.wvalid  <= 1'b0;
                axi_lsu.bready  <= 1'b0;
                axi_lsu.arsize  <= {1'b0, dcu_size};
                axi_lsu.araddr  <= dcu_addr;
              end

            end else if (hit) begin
              axi_lsu.arvalid <= 1'b0;
              axi_lsu.rready  <= 1'b0;
              axi_lsu.awvalid <= 1'b0;
              axi_lsu.wvalid  <= 1'b0;
              axi_lsu.bready  <= 1'b0;
              if (dcu_write) begin
                dcache.data   <= dcache_hit_wdata;
                dcache.modify <= dcache.modify | dcu_strb;
                dcache.strb   <= dcache.strb | dcu_strb;
              end else begin
                dcu_rdata <= dcache.data;
              end
            end else begin  // MISS

              if (dcu_write) begin  // write
                dcache.data <= dcache_hit_wdata;
                dcache.modify <= dcu_strb;
                dcache.strb <= dcu_strb;
                dcache.tag <= dcu_addr[31:2];
                dcache.valid <= 1'b1;
                if (dcache.valid && dcache.modify != 4'b0) begin  // need write back
                  axi_lsu.arvalid <= 1'b0;
                  axi_lsu.rready  <= 1'b0;
                  axi_lsu.awvalid <= 1'b1;
                  axi_lsu.wvalid  <= 1'b1;
                  axi_lsu.bready  <= 1'b0;
                  axi_lsu.awaddr  <= {dcache.tag, 2'b00};
                  axi_lsu.wdata   <= dcache.data;
                  axi_lsu.awsize  <= 3'd2;
                  axi_lsu.wstrb   <= dcache.modify;
                end
              end else begin  // read
                axi_lsu.arsize <= 3'd2;
                axi_lsu.araddr <= {dcu_addr[31:2], 2'b00};
                axi_lsu.awaddr <= {dcache.tag, 2'b00};
                axi_lsu.wdata <= dcache.data;
                axi_lsu.awsize <= 3'd2;
                axi_lsu.wstrb <= dcache.modify;
                dcache.strb <= 4'b1111;
                dcache.tag <= dcu_addr[31:2];
                dcache.valid <= 1'b1;
                if (tag_hit) begin  // half read
                  axi_lsu.arvalid <= 1'b1;
                  axi_lsu.rready  <= 1'b0;
                  axi_lsu.awvalid <= 1'b0;
                  axi_lsu.wvalid  <= 1'b0;
                  axi_lsu.bready  <= 1'b0;
                end else if (dcache.valid && dcache.modify != 4'b0) begin // need write back before read
                  dcache.modify   <= 4'b0000;
                  axi_lsu.arvalid <= 1'b0;
                  axi_lsu.rready  <= 1'b0;
                  axi_lsu.awvalid <= 1'b1;
                  axi_lsu.wvalid  <= 1'b1;
                  axi_lsu.bready  <= 1'b0;
                end else begin
                  dcache.modify   <= 4'b0000;
                  axi_lsu.arvalid <= 1'b1;
                  axi_lsu.rready  <= 1'b0;
                  axi_lsu.awvalid <= 1'b0;
                  axi_lsu.wvalid  <= 1'b0;
                  axi_lsu.bready  <= 1'b0;
                end
              end
            end

          end else begin  // NOP
            axi_lsu.arvalid <= 1'b0;
            axi_lsu.rready  <= 1'b0;
            axi_lsu.awvalid <= 1'b0;
            axi_lsu.wvalid  <= 1'b0;
            axi_lsu.bready  <= 1'b0;
          end
        end

        SKIP: begin
          if (axi_lsu.arready) axi_lsu.arvalid <= 1'b0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 1'b0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 1'b0;
          if (axi_lsu.bvalid) axi_lsu.bready <= 1'b1;
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1'b1;
            dcu_rdata <= axi_lsu.rdata;
          end
        end

        WRITE: begin
          axi_lsu.arvalid <= 1'b0;
          axi_lsu.rready  <= 1'b0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 1'b0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 1'b0;
          if (axi_lsu.bvalid) begin
            axi_lsu.bready <= 1'b1;
          end else begin
            axi_lsu.bready <= 1'b0;
          end
        end

        RAW: begin
          axi_lsu.rready <= 1'b0;
          if (axi_lsu.awready) axi_lsu.awvalid <= 1'b0;
          if (axi_lsu.wready) axi_lsu.wvalid <= 1'b0;
          if (axi_lsu.bvalid) begin
            axi_lsu.bready  <= 1'b1;
            axi_lsu.arvalid <= 1'b1;
          end else begin
            axi_lsu.bready  <= 1'b0;
            axi_lsu.arvalid <= 1'b0;
          end
        end

        READ: begin
          if (axi_lsu.arready) axi_lsu.arvalid <= 1'b0;
          axi_lsu.awvalid <= 1'b0;
          axi_lsu.wvalid  <= 1'b0;
          axi_lsu.bready  <= 1'b0;
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1'b1;
            dcu_rdata <= axi_lsu.rdata;
            dcache.data <= axi_lsu.rdata;
          end
        end

        HALF_READ: begin
          if (axi_lsu.arready) axi_lsu.arvalid <= 1'b0;
          axi_lsu.awvalid <= 1'b0;
          axi_lsu.wvalid  <= 1'b0;
          axi_lsu.bready  <= 1'b0;
          if (axi_lsu.rvalid) begin
            axi_lsu.rready <= 1'b1;
            dcu_rdata <= half_read_data;
            dcache.data <= half_read_data;
          end
        end

        default: ;
      endcase
    end
  end  // fsm 3 for axi

  wire [31:0] half_read_mask = {
    {8{dcache.modify[3]}}, {8{dcache.modify[2]}}, {8{dcache.modify[1]}}, {8{dcache.modify[0]}}
  };
  assign half_read_data = (axi_lsu.rdata & (~half_read_mask)) | (dcache.data & half_read_mask);
  assign dcache_hit_wdata = (dcache.data & (~dcu_mask)) | (dcu_wdata_shifted & dcu_mask);

  assign read_hit = (dcu_strb[3] <= dcache.strb[3])&
    (dcu_strb[2] <= dcache.strb[2])&
    (dcu_strb[1] <= dcache.strb[1])&
    (dcu_strb[0] <= dcache.strb[0]);

  assign axi_lsu.arid = 4'h0;
  assign axi_lsu.arburst = 2'b10;
  assign axi_lsu.arlen = 8'h0;
  assign axi_lsu.awid = 4'h0;
  assign axi_lsu.awlen = 8'h0;
  assign axi_lsu.awburst = 2'h0;
  assign axi_lsu.wlast = 1'b1;

  `ifdef SIM_MODE
  int hit_num = 0;
  int miss_num = 0;
  always_ff @(posedge clock) begin
    if (lsu2dcu_valid & dcu2lsu_ready && curr == IDLE) begin
      if (skip_dcache) begin
        
      end else if (hit) begin
        hit_num++;
      end else begin
        miss_num++;
      end
    end
  end
`endif

endmodule


// always_comb begin  // dcache_hit_wdata
//   dcache_hit_wdata = dcache.data;
//   unique case (dcu_size)
//     2'b00: begin
//       unique case (dcu_addr)
//         2'b00: dcache_hit_wdata = {dcache.data[31:8], dcu_wdata[7:0]};
//         2'b01: dcache_hit_wdata = {dcache.data[31:16], dcu_wdata[7:0], dcache.data[7:0]};
//         2'b10: dcache_hit_wdata = {dcache.data[31:24], dcu_wdata[7:0], dcache.data[16:0]};
//         2'b11: dcache_hit_wdata = {dcu_wdata[7:0], dcache.data[23:0]};
//       endcase
//     end
//     2'b01: begin
//       unique case (dcu_addr)
//         2'b00: dcache_hit_wdata = {dcache.data[31:16], dcu_wdata[15:0]};
//         2'b10: dcache_hit_wdata = {dcu_wdata[15:0], dcache.data[15:0]};
//       endcase
//     end
//     2'b10:   dcache_hit_wdata = dcu_wdata;
//     default: ;
//   endcase
// end
