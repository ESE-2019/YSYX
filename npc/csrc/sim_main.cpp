bool LOG = 0;
bool WAVE = 1;
bool TRAP = false;
bool SDB = false;
bool QUIT = false;

bool DIFF_EN = false;
bool IT_EN = 0;
bool FT_EN = false;

#define ABORT_NUM 0//0xffff

#include <verilated.h>
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_fst_c.h"
#include "svdpi.h"
#include <getopt.h>
#include <time.h>
#include <math.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>
#include <regex.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/mman.h>
#include <nvboard.h>

#define STRLEN(CONST_STR) (sizeof(CONST_STR) - 1)
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data)  { assert(0); }
extern "C"
{
    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    void difftest_memcpy(uint32_t addr, void *buf, uint32_t n, bool direction);
    void difftest_regcpy(void *dut, bool direction);
    void difftest_exec(uint64_t n);
    void difftest_init(int port);
}

uint32_t expr(char *e, bool *success);

FILE *log_file;

#define MAX_IMG 0x2000000
#define MEM_BASE 0x80000000

bool ebreak_n = true;
VerilatedContext *contextp;
VysyxSoCFull *top;
extern "C" void ebreak()
{

    ebreak_n = false;
    //if (0 == top->rootp->top__DOT__CORE__DOT__REG__DOT__regfile[10])
        TRAP = true;
}

int64_t cycle = 0; // to controll sdb
uint64_t inst_ipc = 0;
static char iringbuf[16][128];
int iringbuf_index = 0;
void print_iringbuf()
{
    // Log("print_iringbuf begin");
    for (int i = 0; i < 16; i++)
    {
        if (i == iringbuf_index)
            printf("^^^^^^^^^^^-^^-^^-^^-^^\n");
        else
            printf("%s\n", iringbuf[i]);
    }
    // Log("print_iringbuf end");
}

#define NR_WP 32
typedef struct watchpoint
{
    int NO;
    struct watchpoint *next;
    char expr[65536];
    uint32_t value;

} WP;

static WP wp_pool[NR_WP] = {};

static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
    for (int i = 0; i < NR_WP; i++)
    {
        wp_pool[i].NO = i;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

    head = NULL;
    free_ = wp_pool;
}

WP *new_wp()
{
    WP *ret = NULL;
    if (free_ != NULL)
    {
        ret = free_; // get from free
        free_ = free_->next;
        ret->next = NULL;
        if (head == NULL) // put to head
            head = ret;
        else
        {
            WP *i;
            for (i = head; i->next != NULL; i = i->next)
                ;
            i->next = ret;
        }
        return ret;
    }
    else
        return NULL;
}

void free_wp(WP *wp)
{
    if (head == wp)
    {
        head = head->next; // set head
    }
    else
    {
        for (WP *i = head; i != NULL; i = i->next)
        {
            if (i->next == wp)
            {
                i->next = wp->next; // get from head
                break;
            }
        }
    }
    wp->next = free_; // put to free
    free_ = wp;
    return;
}

void wp_exec()
{
    for (WP *i = head; i != NULL; i = i->next)
    {
        bool success = false;
        uint32_t ans = expr(i->expr, &success);
        if (success == true)
        {
            if (ans != i->value)
            {
                printf("wp_NO%2d: %s changed:\n[DEC] %010d -> %010d\n", i->NO, i->expr,
                       i->value, ans);
                printf("[HEX] 0x%08x -> 0x%08x\n", i->value, ans);
                cycle = 0;
            }
        }
        else
            printf("[PANIC] set watchpoint failed, invalid expr\n");
    }
}

void print_wp()
{
    for (WP *i = head; i != NULL; i = i->next)
    {
        printf("[print_wp] NO%02d: %10s [DEC] %010d [HEX] 0x%08x\n", i->NO,
               i->expr, i->value, i->value);
    }
}

void set_wp(char *e)
{
    WP *set = new_wp();
    if (set != NULL)
    {
        strcpy(set->expr, e);
        bool success = false;
        uint32_t value = expr(e, &success);
        if (success == false)
            printf("[PANIC] set watchpoint failed, invalid expr\n");
        set->value = value;
        printf("[set_wp] NO%02d: %10s [DEC] %010d [HEX] 0x%08x\n", set->NO,
               set->expr, set->value, set->value);
        return;
    }
    printf("------watchpoint is full, set_wp failed------\n");
}

void del_wp(int N)
{
    for (WP *i = head; i != NULL; i = i->next)
    {
        if (i->NO == N)
        {
            printf("[del_wp] NO%02d: %10s [DEC] %010d [HEX] 0x%08x\n", i->NO,
                   i->expr, i->value, i->value);
            free_wp(i);
        }
    }
}

uint32_t PC = 0x80000000;

#define NR_FT 256
char FT_name[NR_FT][256] = {};
uint32_t FT_addr[NR_FT] = {};
void get_elf_function(const char *filename)
{
    int index = 0;
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Open elf failed %s", filename);
        return;
    }
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1)
    {
        perror("lseek");
        close(fd);
        return;
    }
    void *map = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return;
    }
    Elf32_Ehdr *ehdr = (Elf32_Ehdr *)map;
    if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0)
    {
        fprintf(stderr, "Not an ELF file\n");
        munmap(map, file_size);
        close(fd);
        return;
    }
    Elf32_Shdr *shdr = (Elf32_Shdr *)(map + ehdr->e_shoff);
    for (int i = 0; i < ehdr->e_shnum; i++)
    {
        if (shdr[i].sh_type == SHT_SYMTAB || shdr[i].sh_type == SHT_DYNSYM)
        {
            Elf32_Sym *sym = (Elf32_Sym *)(map + shdr[i].sh_offset);
            char *strtab = (char *)(map + shdr[shdr[i].sh_link].sh_offset);
            for (int j = 0; j < shdr[i].sh_size / shdr[i].sh_entsize; j++)
            {
                if (ELF32_ST_TYPE(sym[j].st_info) == STT_FUNC)
                {
                    printf("Function: %s, Address: 0x%08x\n", strtab + sym[j].st_name, sym[j].st_value);
                    strncpy(FT_name[index], strtab + sym[j].st_name, 256);
                    FT_addr[index] = sym[j].st_value;
                    index++;
                }
            }
        }
    }
    munmap(map, file_size);
    close(fd);
    strncpy(FT_name[index], "UNKNOWN", 256);
    FT_addr[index] = 0;
}
char *bin2elf(const char *input)
{
    const char *bin_suffix = ".bin";
    const char *elf_suffix = ".elf";
    size_t bin_len = strlen(bin_suffix);
    size_t input_len = strlen(input);
    if (input_len < bin_len || strcmp(input + input_len - bin_len, bin_suffix) != 0)
    {
        return NULL;
    }
    size_t new_len = input_len - bin_len + strlen(elf_suffix) + 1;
    char *result = (char *)malloc(new_len);
    if (result == NULL)
    {
        return NULL;
    }
    strncpy(result, input, input_len - bin_len);
    strcpy(result + input_len - bin_len, elf_suffix);
    return result;
}
static uint32_t FT_local[4096] = {};
static uint32_t FT_ret[4096] = {};
static uint16_t FT_index = 0;
char ftrace_buf[16 * 65536] = "";
// jump to addr, curr pc, store to reg
static void ftrace_jump(const uint32_t addr, const uint32_t pc, const uint32_t reg)
{
    for (int i = 0; FT_addr[i] != 0; i++) // add
    {
        if (FT_addr[i] == addr)
        {
            FT_ret[FT_index] = reg;
            FT_local[FT_index++] = i;
            char tmp[4096] = "";
            for (int j = 0; j < FT_index - 1; j++)
            {
                strncat(tmp, "| ", sizeof(tmp) - strlen(tmp) - 1);
            }
            char tmp2[1024];
            snprintf(tmp2, 1024, "0x%08x: call [%s@0x%08x]\n", pc, FT_name[i], FT_addr[i]);
            strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
            strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf) - 1);
            return;
        }
    }
    for (int i = FT_index - 1; i >= 0; i--)
    {
        if (FT_ret[i] == addr)
        {
            FT_index = i;
            char tmp[4096] = "";
            for (int j = 0; j < FT_index - 1; j++)
            {
                strncat(tmp, "| ", sizeof(tmp) - strlen(tmp) - 1);
            }
            char tmp2[1024];
            snprintf(tmp2, 1024, "0x%08x: ret [%s]\n", pc, FT_name[FT_local[i]]);
            strncat(tmp, tmp2, sizeof(tmp) - strlen(tmp) - 1);
            strncat(ftrace_buf, tmp, sizeof(ftrace_buf) - strlen(ftrace_buf) - 1);
            return;
        }
    }
}
static void ftrace_print()
{
    printf("%s\n", ftrace_buf);
}
bool initial = true;
extern "C" void dbg(uint32_t inst, uint32_t pc, uint32_t ft_pc)
{
    uint32_t ist = inst;
    cycle--;
    inst_ipc++;
    PC = pc;
    if (IT_EN)
    {
        char logbuf[128];
        char *p = logbuf;
        p += snprintf(p, sizeof(logbuf), "0x%08x:", pc);
        int ilen = 4;
        int i;
        uint8_t *tmp = (uint8_t *)&ist;
        for (i = ilen - 1; i >= 0; i--)
        {
            p += snprintf(p, 4, " %02x", tmp[i]);
        }
        int ilen_max = 4;
        int space_len = ilen_max - ilen;
        if (space_len < 0)
            space_len = 0;
        space_len = space_len * 3 + 1;
        memset(p, ' ', space_len);
        p += space_len;

        // void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
        disassemble(p, logbuf + sizeof(logbuf) - p, pc, (uint8_t *)&ist, ilen);

        printf("%s\n", logbuf);
        strcpy(iringbuf[iringbuf_index], logbuf);
        if (iringbuf_index++ >= 15)
            iringbuf_index = 0;
    }
    wp_exec(); // watchpoint

    if (FT_EN && ft_pc != 0)
        ftrace_jump(pc, ft_pc, ft_pc + 4); // ftrace

    // diff test
    if (DIFF_EN)
        if (initial)
        {
            initial = false;
        }
        else
        {
            difftest_exec(1);
            uint32_t check[16];
            difftest_regcpy(check, 0);
            for (int j = 0; j < 16; j++)
            {
                if (j == 0)
                {
                    if (check[j] != pc)
                    {
                        printf("pc: REF(nemu) 0x%08x DUT(npc) 0x%08x\n", check[j], pc);
                        cycle = 0;
                    }
                }
                else
                {
                    //if (check[j] != top->rootp->top__DOT__CORE__DOT__REG__DOT__regfile[j])
                    {
                        //printf("%02d: REF(nemu) 0x%08x DUT(npc) 0x%08x\n", j, check[j], top->rootp->top__DOT__CORE__DOT__REG__DOT__regfile[j]);
                        //cycle = 0;
                    }
                }
            }
        }
}

static uint32_t mem[MAX_IMG] = {
    0x00000413,
    0x00009117,
    0xffc10113,
    0x00c000ef,
    0x00000513,
    0x00008067,
    0xff410113,
    0x00000517,
    0x01c50513,
    0x00112423,
    0xfe9ff0ef,
    0x00050513,
    0x00100073};

uint32_t pmem_readC(uint32_t addr)
{
    uint32_t add = (((addr & ~0x3u) - MEM_BASE) / 0x4) % MAX_IMG;
    uint32_t ret = mem[add];
    if (LOG)
        fprintf(log_file, "read] addr: 0x%08x value: 0x%08x\n", addr & ~0x3u,
                ret);
    return ret;
}

static char *img_file = NULL;
static long load_img()
{
    if (img_file == NULL)
    {
        printf("use default img\n");
        return MAX_IMG; // built-in image size
    }
    if (FT_EN)
    {
        char *img_elf = bin2elf(img_file);
        get_elf_function(img_elf);
        free(img_elf);
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

extern "C" int pmem_read(uint32_t raddr)
{

    if (LOG)
        fprintf(log_file, "[CPU");
    return pmem_readC(raddr & ~0x3u);
}

extern "C" void pmem_write(uint32_t waddr, uint32_t wdata, uint32_t wmask)
{ // mask: 1 3 15
    uint32_t shamt = waddr & 0x3;
    wmask = wmask >> shamt;//new
    switch (shamt)
    {
    case 0:
        shamt = 0;
        break;
    case 1:
        shamt = 8;
        break;
    case 2:
        shamt = 16;
        break;
    case 3:
        shamt = 24;
        break;
    default:
        printf("[0]pmem_write err\n");
        assert(0);
        break;
    }
	wdata = wdata >> shamt;
    uint32_t add = (((waddr & ~0x3u) - MEM_BASE) / 0x4) % MAX_IMG;
    uint32_t data1, data2;
    switch (wmask)
    {
    case 1:
        if (LOG)
            fprintf(log_file, "[lb-");
        data1 = pmem_readC(waddr);
        data1 = data1 & (~(0x000000FF << shamt));
        data2 = (wdata & 0x000000FF) << shamt;
        mem[add] = data1 | data2;
        break;
    case 3:
        if (LOG)
            fprintf(log_file, "[lh-");
        data1 = pmem_readC(waddr);
        data1 = data1 & (~(0x0000FFFF << shamt));
        data2 = (wdata & 0x0000FFFF) << shamt;
        mem[add] = data1 | data2;
        break;
    case 15:
        mem[add] = wdata;
        break;
    default:
        printf("[1]pmem_write err\n");
        assert(0);
        break;
    }
    if (LOG)
        fprintf(log_file, "[WRITE-%d] addr: 0x%08x value: 0x%08x\n", wmask,
                waddr & ~0x3u, mem[add]);
}

typedef struct token
{
    int type;
    char str[32];
} Token;

static Token tokens[256] __attribute__((used)) = {};

static int nr_token __attribute__((used)) = 0;

enum
{
    NOTYPE = 256,
    DEC = 'd',
    REG = 'r',
    HEX = 'h',
    EQ = 'e',
    NOTEQ = 'n',
    OR = 'o',
    AND = 'a',
    LEQ = 'l',
    DEREF = 'D'
};
static struct rule
{
    const char *regex;
    int token_type;
} rules[] = {{" +", NOTYPE},
             {"\\$[a-zA-Z]*[0-9]*", REG}, // caution $0 $t0 etc
             {"0[xX][0-9a-fA-F]+", HEX},
             {"[0-9]+", DEC}, // must be HEX hou mian
             {"\\+", '+'},
             {"\\-", '-'},
             {"\\*", '*'},
             {"\\/", '/'},
             {"\\(", '('},
             {"\\)", ')'},
             {"\\=\\=", EQ},
             {"\\!\\=", NOTEQ},
             {"\\|\\|", OR},
             {"\\&\\&", AND},
             {"<=", LEQ},
             {"\\!", '!'}, // must be != hou mian
             {"\\&", '&'}, // must be && hou mian
             {"\\^", '^'},
             {"\\|", '|'}};

bool check_parentheses(int p, int q)
{
    int i, cnt = 0;
    if (tokens[p].type != '(' || tokens[q].type != ')')
        return false;
    for (i = p; i <= q; i++)
    {
        if (tokens[i].type == '(')
            cnt++;
        else if (tokens[i].type == ')')
            cnt--;
        if (cnt == 0 && i < q)
            return false;
    }
    if (cnt < 0)
        return false;
    return true;
}

int max(int a, int b) { return (a > b) ? a : b; }

uint32_t eval(int p, int q)
{
    if (p > q)
    { // Bad expression
        printf("eval_failed %d > %d\n", p, q);
        return 0;
    }
    else if (p == q)
    {
        return strtol(tokens[p].str, NULL, 0);
    }
    else if (check_parentheses(p, q) == true)
    {
        return eval(p + 1, q - 1);
    }
    else
    {
        int op = -1;
        int pri = 0;
        for (int i = p; i <= q; i++)
        {
            if (tokens[i].type == '(') // skip parentheses
            {
                int cnt = 1;
                while (cnt != 0)
                {
                    i++;
                    if (tokens[i].type == '(')
                        cnt++;
                    else if (tokens[i].type == ')')
                        cnt--;
                }
            }
            // priority of 14
            if (pri <= 12 && tokens[i].type == OR)
            {
                pri = 12;
                op = max(op, i);
            }
            if (pri <= 11 && tokens[i].type == AND)
            {
                pri = 11;
                op = max(op, i);
            }
            if (pri <= 10 && tokens[i].type == '|')
            {
                pri = 10;
                op = max(op, i);
            }
            if (pri <= 9 && tokens[i].type == '^')
            {
                pri = 9;
                op = max(op, i);
            }
            if (pri <= 8 && tokens[i].type == '&')
            {
                pri = 8;
                op = max(op, i);
            }
            if (pri <= 7 && (tokens[i].type == EQ || tokens[i].type == NOTEQ))
            {
                pri = 7;
                op = max(op, i);
            }
            if (pri <= 6 && tokens[i].type == LEQ)
            {
                pri = 6;
                op = max(op, i);
            }
            if (pri <= 4 && (tokens[i].type == '+' || tokens[i].type == '-'))
            {
                pri = 4;
                op = max(op, i);
            }
            if (pri <= 3 && (tokens[i].type == '*' || tokens[i].type == '/'))
            {
                pri = 3;
                op = max(op, i);
            }
        }
        int eval_l = eval(p, op - 1);
        int eval_r = eval(op + 1, q);
        switch (tokens[op].type)
        {
        case '+':
            return eval_l + eval_r;
        case '-':
            return eval_l - eval_r;
        case '*':
            return eval_l * eval_r;
        case '/':
            if (eval_r == 0)
            {
                printf("----------\n[WARNING] div by 0\n----------\n");
                return 0;
            }
            return eval_l / eval_r;
        case '&':
            return eval_l & eval_r;
        case '^':
            return eval_l ^ eval_r;
        case '|':
            return eval_l | eval_r;
        case LEQ:
            return eval_l <= eval_r;
        case EQ:
            return eval_l == eval_r;
        case NOTEQ:
            return eval_l != eval_r;
        case OR:
            return eval_l || eval_r;
        case AND:
            return eval_l && eval_r;
        default:
            printf("NOTYPE? %c %d\nl=%d\tr=%d\n", tokens[op].type, tokens[op].type,
                   eval_l, eval_r);
            return 0;
        }
    }
}

#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = {};

void init_regex()
{
    int i;
    char error_msg[128];
    int ret;

    for (i = 0; i < NR_REGEX; i++)
    {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0)
        {
            regerror(ret, &re[i], error_msg, 128);
            printf("regex compilation failed: %s\n%s\n", error_msg, rules[i].regex);
            assert(0);
        }
    }
}

static bool make_token(char *e)
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;

    while (e[position] != '\0')
    {
        for (i = 0; i < NR_REGEX; i++)
        {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
                pmatch.rm_so == 0)
            {
                int substr_len = pmatch.rm_eo;
                position += substr_len;

                switch (rules[i].token_type)
                {
                case NOTYPE:
                    break;
                case '+':
                    tokens[nr_token++].type = '+';
                    break;
                case '-':
                    tokens[nr_token++].type = '-';
                    break;
                case '*':
                    tokens[nr_token++].type = '*';
                    break;
                case '/':
                    tokens[nr_token++].type = '/';
                    break;
                case '!':
                    tokens[nr_token++].type = '!';
                    break;
                case ')':
                    tokens[nr_token++].type = ')';
                    break;
                case '(':
                    tokens[nr_token++].type = '(';
                    break;
                case '&':
                    tokens[nr_token++].type = '&';
                    break;
                case '^':
                    tokens[nr_token++].type = '^';
                    break;
                case '|':
                    tokens[nr_token++].type = '|';
                    break;
                case REG:
                    tokens[nr_token].type = REG;
                    strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
                    nr_token++;
                    break;
                case HEX:
                    tokens[nr_token].type = HEX;
                    strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
                    nr_token++;
                    break;
                case DEC:
                    tokens[nr_token].type = DEC;
                    strncpy(tokens[nr_token].str, &e[position - substr_len], substr_len);
                    nr_token++;
                    break;
                case EQ:
                    tokens[nr_token].type = EQ;
                    strcpy(tokens[nr_token].str, "==");
                    nr_token++;
                    break;
                case NOTEQ:
                    tokens[nr_token].type = NOTEQ;
                    strcpy(tokens[nr_token].str, "!=");
                    nr_token++;
                    break;
                case OR:
                    tokens[nr_token].type = OR;
                    strcpy(tokens[nr_token].str, "||");
                    nr_token++;
                    break;
                case AND:
                    tokens[nr_token].type = AND;
                    strcpy(tokens[nr_token].str, "&&");
                    nr_token++;
                    break;
                case LEQ:
                    tokens[nr_token].type = LEQ;
                    strcpy(tokens[nr_token].str, "<=");
                    nr_token++;
                    break;
                default:
                    printf("no match at position %d\n%s\n%*.s^\n", position, e, position,
                           "");
                    return false;
                }
                break;
            }
        }

        if (i == NR_REGEX)
        {
            printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
            return false;
        }
    }
    return true;
}

uint32_t expr(char *e, bool *success)
{
    *success = false;
    for (int ii = 0; ii < 256; ii++) // reset tokens
    {
        tokens[ii].type = 0;
        memset(tokens[ii].str, 0, sizeof(tokens[ii].str));
    }
    if (!make_token(e))
        return 0;

    int tokens_len = 0; // calc len
    for (int i = 0; i < 256; i++)
    {
        if (tokens[i].type == 0) // if == reset value
            break;
        tokens_len++;
    }

    for (int i = 0; i < tokens_len; i++) // trans reg 2 dec
    {
        if (tokens[i].type == REG)
        {

            if (strcmp(tokens[i].str, "$pc") == 0 || strcmp(tokens[i].str, "$PC") == 0)
            {
                sprintf(tokens[i].str, "%d", PC);
                tokens[i].type = DEC;
            }
            else
            {
                int reg2dec;
                char tmpstr[10];
                strncpy(tmpstr, tokens[i].str + 1, 10);
                reg2dec = atoi(tmpstr);
                if (reg2dec >= 0 && reg2dec < 16)
                {
                    //sprintf(tokens[i].str, "%d", top->rootp->top__DOT__CORE__DOT__REG__DOT__regfile[reg2dec]);
                    tokens[i].type = DEC;
                }
                else
                {
                    printf("[ERROR]reg2dec failed \n");
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < tokens_len; i++) // trans hex 2 dec
    {
        if (tokens[i].type == HEX)
        {
            int hex2dec = strtol(tokens[i].str, NULL, 16);
            sprintf(tokens[i].str, "%d", hex2dec);
            tokens[i].type = DEC;
        }
    }

    for (int i = 0; i < tokens_len; i++) // recognize -1, next token must be dec (reg hex)
    {
        if ((tokens[i].type == '-' && i > 0 && tokens[i - 1].type != DEC &&
             tokens[i - 1].type != ')' && tokens[i + 1].type == DEC) ||
            (tokens[i].type == '-' && i == 0 && tokens[i + 1].type == DEC))
        {
            for (int j = 31; j > 0; j--) // set minus
                tokens[i + 1].str[j] = tokens[i + 1].str[j - 1];
            tokens[i + 1].str[0] = '-';
            for (int k = i + 1; k < tokens_len; k++)
                tokens[k - 1] = tokens[k];
            tokens_len--;
        }
    }

    for (int i = 0; i < tokens_len; i++) // recognize !, next token must be dec (reg hex)
    {
        if ((tokens[i].type == '!' && i > 0 && tokens[i - 1].type != DEC &&
             tokens[i - 1].type != ')' && tokens[i + 1].type == DEC) ||
            (tokens[i].type == '!' && i == 0 && tokens[i + 1].type == DEC))
        {
            int next_num = strtol(tokens[i + 1].str, NULL, 0);
            if (next_num == 0)
            {
                memset(tokens[i + 1].str, 0, sizeof(tokens[i + 1].str));
                tokens[i + 1].str[0] = '1';
            }
            else
            {
                memset(tokens[i + 1].str, 0, sizeof(tokens[i + 1].str));
                tokens[i + 1].str[0] = '0';
            }
            for (int k = i + 1; k < tokens_len; k++)
                tokens[k - 1] = tokens[k];
            tokens_len--;
        }
    }

    for (int i = 0; i < tokens_len; i++) // DEREF, next token must be dec (reg hex)
    {
        if ((tokens[i].type == '*' && i > 0 && tokens[i - 1].type != DEC &&
             tokens[i - 1].type != ')' && tokens[i + 1].type == DEC) ||
            (tokens[i].type == '*' && i == 0 && tokens[i + 1].type == DEC))
        {
            uint32_t EXPR_DEREF;
            EXPR_DEREF = strtoul(tokens[i + 1].str, NULL, 0);
            sprintf(tokens[i + 1].str, "%d", (uint32_t)pmem_readC(EXPR_DEREF));
            for (int k = i + 1; k < tokens_len; k++)
                tokens[k - 1] = tokens[k];
            tokens_len--;
        }
    }
    *success = true;
    return eval(0, tokens_len - 1);
}

static char *rl_gets()
{
    static char *line_read = NULL;

    if (line_read)
    {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read)
    {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_help(char *args);

static int cmd_c(char *args)
{
    cycle = INT64_MAX;
    return 0;
}

static int cmd_q(char *args)
{
    QUIT = true;
    return -1;
}

static int cmd_si(char *args)
{
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i = 1;

    if (arg == NULL)
    {
        /* no argument given */
        cycle++;
    }
    else
    {
        i = atoi(arg);
        if (i >= 1)
        {
            cycle += i;
        }
        else
        {
            printf("Unknown command\n");
        }
    }
    return 0;
}

// extern void print_iringbuf();
static int cmd_info(char *args)
{
    char *arg = strtok(NULL, " ");
    if (arg == NULL)
        printf("Unknown command\n");
    else if (strcmp(arg, "r") == 0)
    {
        printf("PC:  0x%08x\n", PC);
        for (int i = 0; i < 16; i++);
            //printf("x%02d: 0x%08x\n", i, top->rootp->top__DOT__CORE__DOT__REG__DOT__regfile[i]);
        for (int i = 0; i < 4; i++);
            //printf("x%02d: 0x%08x\n", i, top->rootp->top__DOT__CORE__DOT__CSR__DOT__regfile[i]);
    }
    else if (strcmp(arg, "w") == 0)
        print_wp();
    else if (strcmp(arg, "i") == 0)
        print_iringbuf();
    else
        printf("Unknown command '%s'\n", arg);
    return 0;
}

static int cmd_x(char *args)
{
    if (args == NULL)
    {
        printf("No args\n");
        return 0;
    }
    char *arg_N = strtok(NULL, " ");
    char *arg_EXPR = strtok(NULL, " ");

    int N;
    uint32_t EXPR;

    if (sscanf(arg_N, "%d", &N) == 1 && sscanf(arg_EXPR, "%x", &EXPR) == 1)
        for (int i = 0; i < N; i++)
        {
            if (LOG)
                fprintf(log_file, "[SDB");
            printf("0x%08x: 0x%08x\n", EXPR, pmem_readC(EXPR));
            EXPR += 4;
        }
    else
        printf("Unknown command");
    return 0;
}

// biao da shi qiu zhi
static int cmd_p(char *args)
{
    if (args == NULL)
    {
        printf("No args\n");
        return 0;
    }
    bool flag = false;
    uint32_t ans = expr(args, &flag);
    if (flag == true)
        printf("DEC: %010d\nHEX: 0x%08x\n", ans, ans);
    else
        printf("[WARNING] some bugs occur\n[WARNING] some bugs occur\n[WARNING] "
               "some bugs occur\n");
    return 0;
}

static int cmd_w(char *args)
{
    if (args == NULL)
    {
        printf("No args\n");
        return 0;
    }
    set_wp(args);
    return 0;
}

static int cmd_d(char *args)
{
    if (args == NULL)
    {
        printf("No args\n");
        return 0;
    }
    del_wp(strtol(args, NULL, 0));
    return 0;
}

static struct
{
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "dan bu zhi xing, e.g., si 10", cmd_si},
    {"info", "da yin cheng xu zhuang tai, e.g., info r, info w", cmd_info},
    {"x", "sao miao nei cun, e.g., x 10 $esp", cmd_x},
    {"p", "biao da shi qiu zhi, e.g., p $eax + 1", cmd_p},
    {"w", "she zhi jian shi dian, e.g., w *0x2000", cmd_w},
    {"d", "shan chu jian shi dian, e.g., d 2", cmd_d},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL)
    {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++)
        {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else
    {
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(arg, cmd_table[i].name) == 0)
            {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

extern "C" void init_disasm(const char *triple);
void nvboard_bind_all_pins(TOP_NAME* top);

int main(int argc, char **argv)
{

    init_regex();
    init_wp_pool();
    init_disasm("riscv32-pc-linux-gnu");
    difftest_init(0);
    const char *prefix = "-IMG=";

    for (int i_argc = 1; i_argc < argc; i_argc++)
    {
        if (strncmp(argv[i_argc], prefix, strlen(prefix)) == 0)
        {
            img_file = (char *)malloc(strlen(argv[i_argc]) + 1);
            strcpy(img_file, argv[i_argc] + strlen(prefix));
        }
        if (strcmp(argv[i_argc], "-sdb") == 0)
        {
            SDB = true;
        }
    }
    load_img();
    log_file =
        fopen("/home/ubuntu/ysyx-workbench/npc/build/debug.log",
              "w");
    if (log_file == NULL)
    {
        perror("Failed to open log file");
        return -1;
    }
    difftest_memcpy(MEM_BASE, mem, MAX_IMG, 0);
    Verilated::commandArgs(argc, argv);
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new VysyxSoCFull{contextp};
    nvboard_bind_all_pins(top);//nvboard
    nvboard_init();
    
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
    uint64_t abort_endless_loop = 0;

    uint32_t reg_mirror[16];
    for (int i = 0; i < 16; i++)
    {
        reg_mirror[i] = 0;
    }
    while (!contextp->gotFinish() && ebreak_n && (abort_endless_loop < (uint64_t)ABORT_NUM || ABORT_NUM == 0))
    {

        contextp->timeInc(1);
        top->clock = !top->clock;
	nvboard_update();
        if (!top->clock)
        {
            if (contextp->time() > 1 && contextp->time() < 20)
            {
                top->reset = 1; // Assert reset
            }
            else
            {
                top->reset = 0; // Deassert reset
                while (SDB && cycle <= 0)
                {
                    char *str;
                    if ((str = rl_gets()) != NULL)
                    { // endless loop
                        char *str_end = str + strlen(str);

                        /* extract the first token as the command */
                        char *cmd = strtok(str, " ");
                        if (cmd == NULL)
                        {
                            continue;
                        }

                        /* treat the remaining string as the arguments,
                         * which may need further parsing
                         */
                        char *args = cmd + strlen(cmd) + 1;
                        if (args >= str_end)
                        {
                            args = NULL;
                        }

                        int i;
                        for (i = 0; i < NR_CMD; i++)
                        {
                            if (strcmp(cmd, cmd_table[i].name) == 0)
                            {
                                cmd_table[i].handler(args);
                                if (QUIT)
                                    return 0;
                                break;
                            }
                        }

                        if (i == NR_CMD)
                        {
                            printf("Unknown command '%s'\n", cmd);
                        }
                    }
                }
                
                abort_endless_loop++;
            }
            // Assign some other inputs
        }
        top->eval();
        if (WAVE)
            tfp->dump(wave++); // dump wave
    }
    
    // Final model cleanup
    top->final();
    fclose(log_file);
    // Destroy model
nvboard_quit();
    delete top;
    if (WAVE)
        tfp->close();
    free(img_file);
    // Return good completion status
    if (FT_EN)
        ftrace_print();

    double ipc_num;
    ipc_num = (double)inst_ipc / (double)abort_endless_loop;
    printf("\033[1;33mINST = %ld\nCYCLE / MAX_CYCLE = %ld / %ld\n\033[1;36mIPC = %.3f\033[0m\n", inst_ipc, abort_endless_loop,
           (uint64_t)ABORT_NUM, ipc_num);
    if (!TRAP)
    {
        printf("\033[1;31mHIT BAD TRAP\033[0m\n");
        return -1;
    }
    else
        printf("\033[1;32mHIT GOOD TRAP\033[0m\n");

    return 0;
}
/*
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
#define ABORT_NUM 0xFFFFFFF
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
*/
