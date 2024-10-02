// Include common routines
#include <verilated.h>
// Include model header, generated from Verilating "top.v"
#include "VysyxSoCFull.h"

#include "VysyxSoCFull___024root.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_fst_c.h"
// #include "verilated_vcd_c.h"
#include "svdpi.h"
#include <getopt.h>
#include <time.h>
#include <math.h>
FILE *log_file;
bool LOG = true;
bool WAVE = true;
bool TRAP = false;

#define MAX_IMG   0xFFFFFF
#define MEM_BASE  0x80000000
#define ABORT_NUM 0xFFFF
bool ebreak_n = true;
VerilatedContext *contextp;
VysyxSoCFull *top;
extern "C" void ebreak()
{

    ebreak_n = false;
        TRAP = true;
}

static uint32_t mem[MAX_IMG] = {
0x100007b7,
0x04100713,
0x00e78023,
0x04200713,
0x00e78023,
0x04300713,
0x00e78023,
0x04400713,
0x00e78023,
0x00a00713,
0x00e78023,
0x00100073};

static char *img_file = NULL;
static long load_img()
{
    if (img_file == NULL)
    {
        printf("use default img\n");
        return MAX_IMG; // built-in image size
    }

    FILE *fp = fopen(img_file, "rb");
    if (!fp)
    {
        perror("Could not open file");
        assert(0);
        return -1;
    }
    printf("use img: %s\n", img_file);
    long index = 0;
    while (index < MAX_IMG && fread(const_cast<
                                        void *>(static_cast<const volatile void *>(&mem[index])),
                                    sizeof(uint32_t), 1, fp) == 1)
    {
        index++;
    }

    fclose(fp);
    return index;
}

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) { 
uint32_t add = (((addr & ~0x3u) - 0x20000000) / 0x4) % MAX_IMG;
    uint32_t ret = mem[add];
    //printf("\taddr=0x%08x: value=0x%08x\n", addr, ret);
    *data=ret; }



int main(int argc, char **argv)
{
    for(int i=0; i<MAX_IMG; i++) {
    	//mem[i] = 0x00100073;
    }
    const char *prefix = "-IMG=";
    bool sdb_mode = false;
    for (int i_argc = 1; i_argc < argc; i_argc++)
    {
        if (strncmp(argv[i_argc], prefix, strlen(prefix)) == 0)
        {
            img_file = (char *)malloc(strlen(argv[i_argc]) + 1);
            strcpy(img_file, argv[i_argc] + strlen(prefix));
        }
        if (strcmp(argv[i_argc], "-sdb") == 0)
        {
            sdb_mode = true;
        }
    }
    //img_file="/home/ubuntu/Desktop/PA0/pre_study/char-test/char-test.bin";

    load_img();
    log_file =
        fopen("/home/ubuntu/ysyx-workbench/npc/build/debug.log",
              "w");
    if (log_file == NULL)
    {
        perror("Failed to open log file");
        return -1;
    }
    Verilated::commandArgs(argc, argv);
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new VysyxSoCFull{
        contextp};

    VerilatedFstC *tfp = new VerilatedFstC;
    if (WAVE)
        contextp->traceEverOn(true);
    if (WAVE)
        top->trace(tfp, 0);
    if (WAVE)
        tfp->open("/home/ubuntu/ysyx-workbench/npc/build/wave.fst");
    // Simulate until $finish
    ebreak_n = true;
    uint64_t wave = 0;
    uint32_t abort_endless_loop = 0;
    if (sdb_mode)
    {
    }
    while (!contextp->gotFinish() && ebreak_n && abort_endless_loop < ABORT_NUM)
    {

        contextp->timeInc(1);
        top->clock = !top->clock;

        if (!top->clock)
        {
            if (contextp->time() > 1 && contextp->time() < 20)
            {
                top->reset = 1; // Assert reset
            }
            else
            {
                top->reset = 0; // Deassert reset
                abort_endless_loop++;
            }
            // Assign some other inputs
        }
        top->eval();
        if (WAVE)
            tfp->dump(wave++); // dump wave  //need ii++
    }

    // Final model cleanup
    top->final();
    fclose(log_file);
    // Destroy model
    delete top;
    if (WAVE)
        tfp->close();
    //free(img_file);
    // Return good completion status
    printf("\033[1;33mLOOP / MAX_LOOP = %d / %d\033[0m\n", abort_endless_loop,
           (uint32_t)ABORT_NUM);
    if (!TRAP)
    {
        printf("\033[1;31mHIT BAD TRAP\033[0m\n");
        return -1;
    }
    else
        printf("\033[1;32mHIT GOOD TRAP\033[0m\n");
    return 0;
}
