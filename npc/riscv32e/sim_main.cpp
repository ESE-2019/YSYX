// Include common routines
#include <verilated.h>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"
#include "Vtop___024root.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_fst_c.h"
//#include "verilated_vcd_c.h"
#include "svdpi.h"
#include <getopt.h>
#include <time.h>
#include <math.h>
FILE *log_file;
bool LOG = false;
bool WAVE = false;
    struct timespec start_time, end_time;
    uint64_t start_microseconds, end_microseconds;
#define MAX_IMG   0xFFFFFFF
#define MEM_BASE  0x80000000
#define ABORT_NUM 0xFFFFFFFF
bool ebreak_n = true;
VerilatedContext *contextp;
Vtop *top;
extern "C" void ebreak()
{
  ebreak_n = false;
}

static uint32_t mem [MAX_IMG] ={
0x00000093,
0xFFF00093,
0xFFE08113,
0x00000093,
0xFFF00093,
0xFFE08113,
0x00000093,
0xFFF00093,
0xFFE08113,
0x00000093,
0xFFF00093,
0xFFE08113,
0x00100073};

uint32_t pmem_readC(uint32_t addr)
{
	uint32_t add = (((addr & ~0x3u)- MEM_BASE)/0x4)%MAX_IMG;
	uint32_t ret = mem[add];
	if(LOG) fprintf(log_file, "read] addr: 0x%08x value: 0x%08x\n", addr & ~0x3u, ret);
	return ret;
}

static char *img_file = NULL;
static long load_img()
{
  if (img_file == NULL) {
    printf("use default img\n");
    return MAX_IMG; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if (!fp) {
        perror("Could not open file");
        assert(0);
        return -1;
    }
    printf("use img: %s\n", img_file);
  long index = 0;
    while (index < MAX_IMG && fread(const_cast<void*>(static_cast<const volatile void*>(&mem[index])), sizeof(uint32_t), 1, fp) == 1) {
        index++;
    }

  fclose(fp);
  return index;
}

#define MMIO_BASE 0xa0000000
#define MMIO_MAX 0x1300000
static uint32_t mmio [MMIO_MAX] = {};
uint32_t mmio_read(uint32_t addr)
{
	uint32_t ret;//printf("MMIO%08x\n",addr);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
    end_microseconds = (uint64_t)end_time.tv_sec * 1000000 + (uint64_t)end_time.tv_nsec / 1000;
    uint64_t elapsed_microseconds = end_microseconds - start_microseconds;
	switch (addr) {
	case 0xa0000048: return elapsed_microseconds;
	case 0xa000004c: return elapsed_microseconds >> 32;
        default:             
	uint32_t add = (((addr & ~0x3u)- MMIO_BASE)/0x4)%MMIO_MAX;
	ret = mmio[add];
	if(LOG) fprintf(log_file, "[MMIOread]addr: 0x%08x value: 0x%08x\n", addr & ~0x3u, ret);
	}
	return ret;
}

void mmio_write(uint32_t addr, uint32_t data)
{
	//printf("SERIAL_PORT write: 0x%08x  %c\n\033[0m", data, (char)data);
	if (addr == (MMIO_BASE + 0x00003f8))
	{
		//printf("SERIAL_PORT write: 0x%08x  [%c]\n\033[0m", data, (char)data);
		putchar(data);
	}
}

extern "C" int pmem_read(uint32_t raddr) {
  if (raddr >= MMIO_BASE)
  {
  	return mmio_read(raddr);
  }
  if(LOG) fprintf(log_file, "[CPU");
  return pmem_readC(raddr & ~0x3u);
}
extern "C" void pmem_write(uint32_t waddr, uint32_t wdata, uint8_t wmask) {//mask: 1 2 4
  uint32_t shamt = waddr & 0x3;
  switch (shamt) {
  case 0: shamt = 0; break;
  case 1: shamt = 8; break;
  case 2: shamt = 16; break;
  case 3: shamt = 24; break;
  default: printf("[0]pmem_write err\n");assert(0);break;
  }
  if (waddr >= MMIO_BASE)
  {
  	mmio_write(waddr, wdata);//TODO
  	return;
  }
  uint32_t add = (((waddr & ~0x3u)- MEM_BASE)/0x4)%MAX_IMG;
  uint32_t data1, data2;
  switch (wmask) {
  case 1:
  	if(LOG) fprintf(log_file, "[lb-");
  	data1 = pmem_readC (waddr);
  	data1 = data1 & (~(0x000000FF << shamt));
  	data2 = (wdata & 0x000000FF) << shamt;
  	mem[add] = data1 | data2;
	break;
  case 2:
  	if(LOG) fprintf(log_file, "[lh-");
  	data1 = pmem_readC (waddr);
  	data1 = data1 & (~(0x0000FFFF << shamt));
  	data2 = (wdata & 0x0000FFFF) << shamt;
  	mem[add] = data1 | data2;
	break;
  case 4:
  	mem[add] = wdata;
	break;
  default: printf("[1]pmem_write err\n");assert(0);break;
  }
  if(LOG) fprintf(log_file, "[WRITE-%d] addr: 0x%08x value: 0x%08x\n", wmask, waddr & ~0x3u, mem[add]);
}

 
int main(int argc, char **argv)
{
   clock_gettime(CLOCK_MONOTONIC, &start_time);
   start_microseconds = (uint64_t)start_time.tv_sec * 1000000 + (uint64_t)start_time.tv_nsec / 1000;
   const char *prefix = "-IMG=";
   bool sdb_mode = false;
   for (int i_argc = 1; i_argc < argc; i_argc++)
   {
	    if (strncmp(argv[i_argc], prefix, strlen(prefix)) == 0) {
	        img_file = (char *)malloc(strlen(argv[i_argc]) + 1);
		strcpy(img_file, argv[i_argc] + strlen(prefix));
	    }
	    if (strcmp(argv[i_argc], "-sdb") == 0) {
	        sdb_mode = true;
	    }
    }
    load_img();
    log_file = fopen("/home/ubuntu/Desktop/PA0/ysyx-workbench/npc/riscv32e/npcdebug.log", "w");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return -1;
    }
  // See a similar example walkthrough in the verilator manpage.

  // This is intended to be a minimal example.  Before copying this to start a
  // real project, it is better to start with a more complete example,
  // e.g. examples/c_tracing.

  // Construct a VerilatedContext to hold simulation time, etc.
  contextp = new VerilatedContext;

  // Pass arguments so Verilated code can see them, e.g. $value$plusargs
  // This needs to be called before you create any model
  contextp->commandArgs(argc, argv);

  // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
  top = new Vtop { contextp };
  
  VerilatedFstC *tfp = new VerilatedFstC;
  if (WAVE) contextp->traceEverOn(true);
  if (WAVE) top->trace(tfp, 0);
  if (WAVE) tfp->open("/home/ubuntu/Desktop/PA0/ysyx-workbench/npc/riscv32e/logs/wave.fst");
  // Simulate until $finish
  ebreak_n = true;
  uint64_t wave = 0;
  uint32_t abort_endless_loop = 0;
  if (sdb_mode)
  {
  
  }
  while (!contextp->gotFinish() && ebreak_n && abort_endless_loop++ < ABORT_NUM) {

	contextp->timeInc(1);  // 1 timeprecision period passes...
        // Historical note, before Verilator 4.200 a sc_time_stamp()
        // function was required instead of using timeInc.  Once timeInc()
        // is called (with non-zero), the Verilated libraries assume the
        // new API, and sc_time_stamp() will no longer work.

        // Toggle a fast (time/2 period) clock
        top->clk = !top->clk;

        // Toggle control signals on an edge that doesn't correspond
        // to where the controls are sampled; in this example we do
        // this only on a negedge of clk, because we know
        // reset is not sampled there.
        if (!top->clk) {
            if (contextp->time() > 1 && contextp->time() < 10) {
                top->rst = 1;  // Assert reset
            } else {
                top->rst = 0;  // Deassert reset
            }
            // Assign some other inputs
            if(LOG) fprintf(log_file, "\t\t\t[IFU");
            top->inst = pmem_readC((uint32_t)top->pc);
        }
    top->eval();
    if (WAVE) tfp->dump(wave++);	//dump wave  //need ii++
    /*for (int i = 0; i<16; i++)
    if (top->rootp->top__DOT__regmap[i] != 0 && top->clk)
    if(LOG) fprintf(log_file, "\treg[%02d]: 0x%08x\n", i, top->rootp->top__DOT__regmap[i]);
    */
  }

  // Final model cleanup
  top->final();
fclose(log_file); 
  // Destroy model
  delete top;
  if (WAVE) tfp->close();
  free(img_file);
  // Return good completion status
  if (ebreak_n)
  {
  	printf("\033[1;31mabort_endless_loop = %d / %d\033[0m\n", abort_endless_loop, (uint32_t)ABORT_NUM);
  	printf("\033[1;31mHIT BAD TRAP\033[0m\n");  
  	return -1;
  	}
  else
  	printf("\033[1;32mHIT GOOD TRAP\033[0m\n"); 
  return 0;
}
