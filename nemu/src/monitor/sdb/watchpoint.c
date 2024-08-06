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
#include <cpu/decode.h>
extern CPU_state cpu;

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  bool status; // legacy
  char expr[65536];
  word_t value;

} WP;

static WP wp_pool[NR_WP] = {};

static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  for (int i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

WP *new_wp() {
  WP *ret = NULL;
  if (free_ != NULL) {
    ret = free_; // get from free
    free_ = free_->next;
    ret->next = NULL;
    if (head == NULL) // put to head
      head = ret;
    else {
      WP *i;
      for (i = head; i->next != NULL; i = i->next)
        ;
      i->next = ret;
    }
    return ret;
  } else
    return NULL;
}

void free_wp(WP *wp) {
  if (head == wp) {
    head = head->next; // set head
  } else {
    for (WP *i = head; i != NULL; i = i->next) {
      if (i->next == wp) {
        i->next = wp->next; // get from head
        break;
      }
    }
  }
  wp->next = free_; // put to free
  free_ = wp;
  return;
}

void wp_exec() {
  for (WP *i = head; i != NULL; i = i->next) {
    bool success = false;
    word_t ans = expr(i->expr, &success);
    if (success == true) {
      if (ans != i->value) {
        printf("wp_NO%2d: %s changed:\n[DEC] %010d -> %010d\n", i->NO, i->expr,
               i->value, ans);
        printf("[HEX] " FMT_WORD " -> " FMT_WORD "\n", i->value, ans);
        // nemu_state.state = NEMU_STOP;
        if (nemu_state.state == NEMU_RUNNING)
          set_nemu_state(NEMU_STOP, cpu.pc, -1);
      }
    } else
      panic("[PANIC] set watchpoint failed, invalid expr");
  }
  /* Legacy
     for (int i = 0; i < NR_WP; i++) {
     if (wp_pool[i].status == true) {
     bool success = false;
     uint32_t ans = expr(wp_pool[i].expr, &success);
     if (success == true) {
     if (ans != wp_pool[i].value) {
     printf("[Legacy] wp_NO%2d: %s changed [DEC] %010d -> %010d\n",
     wp_pool[i].NO, wp_pool[i].expr,
     wp_pool[i].value, ans);
     printf("[Legacy] wp_NO%2d: %s changed [HEX] " FMT_WORD " -> "
     FMT_WORD "\n", wp_pool[i].NO, wp_pool[i].expr,
     wp_pool[i].value, ans);
     nemu_state.state = NEMU_STOP;
     break;
     }
     } else
     panic("[PANIC] set watchpoint failed, invalid expr");

     }
     } */
}

void print_wp() {
  Log("begin");
  /* Legacy
     for (int i = 0; i < NR_WP; i++) {
     if (wp_pool[i].status)
     printf("[Legacy] NO%02d: \texpr:%s \tvalue: [DEC] %d \t[HEX] " FMT_WORD
     "\n", wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].value,
     wp_pool[i].value);
     } */
  for (WP *i = head; i != NULL; i = i->next) {
    printf("[print_wp] NO%02d: %10s [DEC] %010d [HEX] " FMT_WORD "\n", i->NO,
           i->expr, i->value, i->value);
  }
}

void set_wp(char *e) {
  WP *set = new_wp();
  if (set != NULL) {
    strcpy(set->expr, e);
    bool success = false;
    word_t value = expr(e, &success);
    if (success == false)
      panic("[PANIC] set watchpoint failed, invalid expr");
    set->value = value;
    printf("[set_wp] NO%02d: %10s [DEC] %010d [HEX] " FMT_WORD "\n", set->NO,
           set->expr, set->value, set->value);
    return;
  }
  /* Legacy
     for (int i = 0; i < NR_WP; i++) {
     if (wp_pool[i].status == false) {
     wp_pool[i].status = true;
     strcpy(wp_pool[i].expr, e);
     bool success = false;
     word_t value = expr(e, &success);
     if (success == false)
     assert(0);
     wp_pool[i].value = value;
     print_wp();
     printf("[Legacy] set_wp NO%2d done\n", wp_pool[i].NO);
     return;
     }
     } */

  printf("------watchpoint is full, set_wp failed------\n");
}

void del_wp(int N) {
  // wp_pool[N].status = false;
  // printf("[Legacy] del_wp NO%2d\n", N);
  for (WP *i = head; i != NULL; i = i->next) {
    if (i->NO == N) {
      printf("[del_wp] NO%02d: %10s [DEC] %010d [HEX] " FMT_WORD "\n", i->NO,
             i->expr, i->value, i->value);
      free_wp(i);
    }
  }
}
