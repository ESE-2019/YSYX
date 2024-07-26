/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint
{
  int NO;
  struct watchpoint *next;
  bool status;
  char expr[32];
  int value;

} WP;

static WP wp_pool[NR_WP] = { };

static WP *head = NULL, *free_ = NULL;

void
init_wp_pool ()
{
  for (int i = 0; i < NR_WP; i++)
    {
      wp_pool[i].NO = i;
      wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

  head = NULL;
  free_ = wp_pool;
}

/* aborted
WP *new_wp ();
void free_wp (WP * wp);
*/

void
wp_exec ()
{
  for (WP * i = head; i->next != NULL; i = i->next)
    {
      assert (i->status);
      bool success = false;
      uint32_t ans = expr (i->expr, &success);
      if (success == true)
	{
	  if (ans != i->value)
	    {
	      printf ("watch point %s changed %d -> %d\n", i->expr,
		      i->value, ans);
	      nemu_state.state = NEMU_STOP;
	      break;
	    }
	}
      else
	{
	  printf ("wp error\n");
	  assert (0);
	}
    }
}

void
print_wp ()
{
  Log ("info w (print wp) begin");
  for (int i = 0; i < NR_WP; i++)
    {
      if (wp_pool[i].status)
	printf ("NO%02d: \texpr:%s \tvalue: [DEC] %d \t[HEX] 0x%08x\n",
		wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].value,
		wp_pool[i].value);
    }
}

void
set_wp (char *e)
{
  for (int i = 0; i < NR_WP; i++)
    {
      if (wp_pool[i].status == false)
	{
	  wp_pool[i].status = true;
	  strcpy (wp_pool[i].expr, e);
	  bool success = false;
	  uint32_t value = expr (e, &success);
	  if (success == false)
	    assert (0);
	  wp_pool[i].value = value;
	  print_wp ();
	  printf ("set_wp done\n");
	  return;
	}
    }

  printf ("------watchpoint is full, set_wp failed------\n");
}

void
del_wp (int N)
{
  wp_pool[N].status = false;
  printf ("del_wp NO%2d\n", N);
}
