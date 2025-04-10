/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "sdb.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <memory/vaddr.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin.
 */
static char *rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i = 1;

  if (arg == NULL) {
    /* no argument given */
    cpu_exec(1);
  } else {
    i = atoi(arg);
    if (i >= 1) {
      cpu_exec(i);
    } else {
      printf("Unknown command\n");
    }
  }
  return 0;
}

extern void print_iringbuf();
static int cmd_info(char *args) {
  char *arg = strtok(NULL, " ");
  if (arg == NULL)
    printf("Unknown command\n");
  else if (strcmp(arg, "r") == 0)
    isa_reg_display();
  else if (strcmp(arg, "w") == 0)
    print_wp();
  else if (strcmp(arg, "i") == 0)
    print_iringbuf();
  else
    printf("Unknown command '%s'\n", arg);
  return 0;
}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }
  char *arg_N = strtok(NULL, " ");
  char *arg_EXPR = strtok(NULL, " ");

  int N;
  vaddr_t EXPR;

  if (sscanf(arg_N, "%d", &N) == 1 && sscanf(arg_EXPR, "%x", &EXPR) == 1)
    for (int i = 0; i < N; i++) {
      printf(FMT_WORD ": " FMT_WORD "\n", EXPR, vaddr_read(EXPR, 4));
      EXPR += 4;
    }
  else
    printf("Unknown command");
  return 0;
}

// biao da shi qiu zhi
static int cmd_p(char *args) {
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }
  bool flag = false;
  uint32_t ans = expr(args, &flag);
  if (flag == true)
    printf("DEC: %010d\nHEX: " FMT_WORD "\n", ans, ans);
  else
    printf("[WARNING] some bugs occur\n[WARNING] some bugs occur\n[WARNING] "
           "some bugs occur\n");
  return 0;
}

// merge of x and p
static int cmd_xp(char *args) {
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }
  char *arg_N = strtok(NULL, " ");
  char *arg_EXPR = strtok(NULL, " ");

  int N;
  bool flag = false;
  vaddr_t ans = expr(arg_EXPR, &flag);

  if (sscanf(arg_N, "%d", &N) == 1 && flag)
    for (int i = 0; i < N; i++) {
      printf(FMT_WORD ": " FMT_WORD "\n", ans, vaddr_read(ans, 4));
      ans += 4;
    }
  else
    printf("Unknown command");
  return 0;
}

static int cmd_w(char *args) {
  MUXDEF(CONFIG_WATCHPOINT, , printf("undef CONFIG_WATCHPOINT\n"); return 0;);
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }
  set_wp(args);
  return 0;
}

// merge of x and w
static int cmd_xw(char *args) {
  MUXDEF(CONFIG_WATCHPOINT, , printf("undef CONFIG_WATCHPOINT\n"); return 0;);
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }

  bool flag = false;
  word_t ans = expr(args, &flag);

  if (flag) {
    char prepro[65536] = {};
    sprintf(prepro, "*" FMT_WORD, ans);
    set_wp(prepro);
  } else
    printf("Unknown command");
  return 0;
}

static int cmd_d(char *args) {
  MUXDEF(CONFIG_WATCHPOINT, , printf("undef CONFIG_WATCHPOINT\n"); return 0;);
  if (args == NULL) {
    printf("No args\n");
    return 0;
  }
  del_wp(strtol(args, NULL, 0));
  return 0;
}

static int cmd_panic(char *args) {
  panic("%s", args);
  return -1;
}

int cmd_test() {
  FILE *fp = fopen("./tools/gen-expr/input", "r");
  assert(fp != NULL);
  word_t ans, ret;
  bool success;
  int cnt = 0;
  char str[65536] = {};
  char line[65536 + 128] = {};
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (sscanf(line, "%d %[^\n]", &ans, str) == 2) {
      cnt++;
      Log("tc%d exp = %s\n\tans = %d", cnt, str, ans);
      success = false;
      ret = expr(str, &success);
      if (success != true || ret != ans) {
        Log(ANSI_FMT("[fail_case]expr_test%s\nans should be %d but %d\nans should be %08x but %08x\n", ANSI_FG_RED), str, ans, ret, ans, ret);
        break;
      }
    } else {
      panic("Error parsing line\n");
    }
  }
  Log(ANSI_FMT("expr_test end with %d tc passed\n", ANSI_FG_GREEN), cnt);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "dan bu zhi xing, e.g., si 10", cmd_si},
    {"info", "da yin cheng xu zhuang tai, e.g., info r, info w", cmd_info},
    {"x", "sao miao nei cun, e.g., x 10 $esp", cmd_x},
    {"p", "biao da shi qiu zhi, e.g., p $eax + 1", cmd_p},
    {"xp", "merge of x and p", cmd_xp},
    {"w", "she zhi jian shi dian, e.g., w *0x2000", cmd_w},
    {"xw", "merge of x and w", cmd_xw},
    {"d", "shan chu jian shi dian, e.g., d 2", cmd_d},
    {"panic", "panic", cmd_panic},
    {"test", "expr_test", cmd_test},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() { is_batch_mode = true; }

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;) { // endless loop
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }
#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return; // if cmd return -1 then return
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
