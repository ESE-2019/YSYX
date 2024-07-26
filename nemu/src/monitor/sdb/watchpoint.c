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

  /* TODO: Add more members if necessary */
  bool status;
  char expr[32];
  int value;

} WP;

static WP wp_pool[NR_WP] = { };

static WP *head = NULL, *free_ = NULL;

void
init_wp_pool ()
{
  int i;
  for (i = 0; i < NR_WP; i++)
    {
      wp_pool[i].NO = i;
      wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP *new_wp ();
void free_wp (WP * wp);

WP *
new_wp ()
{
  for (WP * i = free_; i->next != NULL; i = i->next)
    {
      if (i->status == false)
	{
	  i->status = true;
	  if (head == NULL)
	    head = i;
	  free_ = i->next;
	  return i;
	}
    }
  printf ("------watchpoint is full------\n------failed to new_wp------\n");
  assert (0);
  return NULL;
}

void
free_wp (WP * wp)
{
  for (WP * i = head; i->next != NULL; i = i->next)
    {
      if (i->NO == wp->NO)
	{
	  i->status = false;
	  if (i == head)
	    {
	      if (i->next->status == false)
		head = NULL;
	      else
		head = i->next;
	    }
	  Log ("free_wp done");
	  break;
	}
    }
}

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
	      printf ("watch point %s changed %d -> %d\n", i->expr, i->value,
		      ans);
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
	printf ("NO%2d:\texpr:%s\tvalue:[DEC]%10d \t[HEX]0x%8x\n",
		wp_pool[i].NO, wp_pool[i].expr, wp_pool[i].value,
		wp_pool[i].value);
    }
}

void
set_wp (char *e)
{
  WP *set = new_wp ();
  if (set != NULL)
    {
      strcpy (set->expr, e);
      bool success = false;
      uint32_t value = expr (e, &success);
      if (success == false)
	assert (0);
      set->value = value;
      print_wp ();
    }
  else
    assert (0);
  printf ("set_wp done\n");
}

void
del_wp (int N)
{
  WP *del = NULL;
  for (WP * i = head; i->next != NULL; i = i->next)
    {
      if (i->NO == N)
	{
	  del = i;
	  break;
	}
    }
  if (del == NULL)
    assert (0);
  free_wp (del);
}
