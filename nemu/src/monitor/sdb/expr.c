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

#include <isa.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct token
{
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = { };

static int nr_token __attribute__((used)) = 0;

enum
{
  TK_NOTYPE = 256,
  NUM = 1,
  REG = 2,
  HEX = 3,
  EQ = 4,
  NOTEQ = 5,
  OR = 6,
  AND = 7,
  LEQ = 8,
  DEREF
};
static struct rule
{
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},
  {"\\+", '+'},
  {"\\-", '-'},
  {"\\*", '*'},
  {"\\/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"\\<\\=", LEQ},
  {"\\=\\=", EQ},
  {"\\!\\=", NOTEQ},
  {"\\|\\|", OR},
  {"\\&\\&", AND},
  {"\\!", '!'},
  {"\\$[a-zA-Z]*[0-9]*", REG},
  {"0[xX][0-9a-fA-F]+", HEX},
  {"[0-9]+", NUM}
};


bool
check_parentheses (int p, int q)
{
  int i, cnt = 0;
  if (tokens[p].type != '(' || tokens[q].type != ')')
    return false;
  for (i = p; i <= q; i++)
    {
      if (tokens[p].type == '(')
	cnt++;
      else if (tokens[q].type == ')')
	cnt--;
      if (cnt == 0 && i < q)
	return false;
    }
  if (cnt < 0)
    return false;
  return true;
}

int
max (int a, int b)
{
  return (a > b) ? a : b;
}

uint32_t
eval (int p, int q)
{
  if (p > q)
    {				// Bad expression
      assert (0);
      return -1;
    }
  else if (p == q)
    {
      return strtol (tokens[p].str, NULL, 0);
    }
  else if (check_parentheses (p, q) == true)
    {
      return eval (p + 1, q - 1);
    }
  else
    {
      int op = -1;
      int flag = -1;
      for (int i = p; i <= q; i++)
	{
	  if (tokens[i].type == '(')	// skip parentheses
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
	  // priority
	  if (flag <= 7 && tokens[i].type == OR)
	    {
	      flag = 7;
	      op = max (op, i);
	    }
	  if (flag <= 6 && tokens[i].type == AND)
	    {
	      flag = 6;
	      op = max (op, i);
	    }
	  if (flag <= 5 && tokens[i].type == NOTEQ)
	    {
	      flag = 5;
	      op = max (op, i);
	    }
	  if (flag <= 4 && tokens[i].type == EQ)
	    {
	      flag = 4;
	      op = max (op, i);
	    }
	  if (flag <= 3 && tokens[i].type == LEQ)
	    {
	      flag = 3;
	      op = max (op, i);
	    }
	  if (flag <= 2 && (tokens[i].type == '+' || tokens[i].type == '-'))
	    {
	      flag = 2;
	      op = max (op, i);
	    }
	  if (flag <= 1 && (tokens[i].type == '*' || tokens[i].type == '/'))
	    {
	      flag = 1;
	      op = max (op, i);
	    }
	}
      int op_type = tokens[op].type;

      uint32_t val1 = eval (p, op - 1);
      uint32_t val2 = eval (op + 1, q);

      switch (op_type)
	{
	case '+':
	  return val1 + val2;
	case '-':
	  return val1 - val2;
	case '*':
	  return val1 * val2;
	case '/':
	  if (val2 == 0)
	    {
	      printf ("----------\n[INFO] div by 0\n----------\n");
	      return 0;
	    }
	  return val1 / val2;
	case 3:
	  return val1 <= val2;
	case 4:
	  return val1 == val2;
	case 5:
	  return val1 != val2;
	case 6:
	  return val1 || val2;
	case 7:
	  return val1 && val2;
	default:
	  printf ("No Op type.");
	  assert (0);
	}
    }
}

#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = { };

void
init_regex ()
{
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++)
    {
      ret = regcomp (&re[i], rules[i].regex, REG_EXTENDED);
      if (ret != 0)
	{
	  regerror (ret, &re[i], error_msg, 128);
	  panic ("regex compilation failed: %s\n%s", error_msg,
		 rules[i].regex);
	}
    }
}

static bool
make_token (char *e)
{
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0')
    {
      for (i = 0; i < NR_REGEX; i++)
	{
	  if (regexec (&re[i], e + position, 1, &pmatch, 0) == 0
	      && pmatch.rm_so == 0)
	    {
	      char *substr_start = e + position;
	      int substr_len = pmatch.rm_eo;

	      Log
		("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
		 i, rules[i].regex, position, substr_len, substr_len,
		 substr_start);

	      position += substr_len;

	      switch (rules[i].token_type)
		{
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
		case 256:
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

		  // Special
		case NUM:	// num
		  tokens[nr_token].type = 1;
		  strncpy (tokens[nr_token].str,
			   &e[position - substr_len], substr_len);
		  nr_token++;
		  break;
		case REG:	// regex
		  tokens[nr_token].type = 2;
		  strncpy (tokens[nr_token].str,
			   &e[position - substr_len], substr_len);
		  nr_token++;
		  break;
		case HEX:	// HEX
		  tokens[nr_token].type = 3;
		  strncpy (tokens[nr_token].str,
			   &e[position - substr_len], substr_len);
		  nr_token++;
		  break;
		case 4:
		  tokens[nr_token].type = 4;
		  strcpy (tokens[nr_token].str, "==");
		  nr_token++;
		  break;
		case 5:
		  tokens[nr_token].type = 5;
		  strcpy (tokens[nr_token].str, "!=");
		  nr_token++;
		  break;
		case 6:
		  tokens[nr_token].type = 6;
		  strcpy (tokens[nr_token].str, "||");
		  nr_token++;
		  break;
		case 7:
		  tokens[nr_token].type = 7;
		  strcpy (tokens[nr_token].str, "&&");
		  nr_token++;
		  break;
		case 8:
		  tokens[nr_token].type = 8;
		  strcpy (tokens[nr_token].str, "<=");
		  nr_token++;
		  break;
		default:
		  printf ("i = %d and No rules is com.\n", i);
		  break;
		}
	      break;
	    }
	}

      if (i == NR_REGEX)
	{
	  printf ("no match at position %d\n%s\n%*.s^\n", position, e,
		  position, "");
	  return false;
	}
    }
  return true;
}


uint32_t
expr (char *e, bool *success)
{
  for (int ii = 0; ii < 32; ii++)
    {				// reset tokens
      tokens[ii].type = 0;
      memset (tokens[ii].str, 0, sizeof (tokens[ii].str));
    }
  if (!make_token (e))
    {
      *success = false;
      return 0;
    }
  Log ("------befoce process------");
  int tokens_len = 0;		// calc len
  for (int i = 0; i < 32; i++)
    {
      if (tokens[i].type == 0)
	break;
      Log ("token%d\ttype%d\tstr:%s", i, tokens[i].type, tokens[i].str);
      tokens_len++;
    }
  Log ("len%d", tokens_len);

  for (int i = 0; i < tokens_len; i++)	// trans reg 2 num
    {
      if (tokens[i].type == 2)
	{
	  int reg2num;
	  bool flag = true;
	  if (strcmp (tokens[i].str, "$0") == 0)
	    {
	      reg2num = isa_reg_str2val ("$0", &flag);
	    }
	  else
	    {
	      reg2num = isa_reg_str2val (tokens[i].str, &flag);
	    }
	  if (flag)
	    {
	      sprintf (tokens[i].str, "%d", reg2num);
	      tokens[i].type = 1;
	    }
	  else
	    {
	      printf ("Transfrom error. \n");
	      assert (0);
	    }
	}
    }

  for (int i = 0; i < tokens_len; i++)	// trans hex 2 num
    {
      if (tokens[i].type == 3)	// Hex num
	{
	  int hex2num = strtol (tokens[i].str, NULL, 16);
	  sprintf (tokens[i].str, "%d", hex2num);
	  tokens[i].type = 1;
	}
    }

  // recognize e.g. +-1

  for (int i = 0; i < tokens_len; i++)
    {
      if ((tokens[i].type == '-' && i > 0 && tokens[i - 1].type != NUM
	   && tokens[i + 1].type == NUM) || (tokens[i].type == '-' && i == 0))
	{
	  tokens[i].type = TK_NOTYPE;

	  for (int j = 31; j >= 0; j--)
	    {
	      tokens[i + 1].str[j] = tokens[i + 1].str[j - 1];
	    }
	  tokens[i + 1].str[0] = '-';
	  for (int j = 0; j < tokens_len; j++)
	    {
	      if (tokens[j].type == TK_NOTYPE)
		{
		  for (int k = j + 1; k < tokens_len; k++)
		    {
		      tokens[k - 1] = tokens[k];
		    }
		  tokens_len--;
		}
	    }
	}
    }

  // bit !
  for (int i = 0; i < tokens_len; i++)
    {
      if (tokens[i].type == '!')
	{
	  tokens[i].type = TK_NOTYPE;
	  int tmp = strtol (tokens[i + 1].str, NULL, 0);
	  if (tmp == 0)
	    {
	      memset (tokens[i + 1].str, 0, sizeof (tokens[i + 1].str));
	      tokens[i + 1].str[0] = '1';
	    }
	  else
	    {
	      memset (tokens[i + 1].str, 0, sizeof (tokens[i + 1].str));
	    }
	  for (int j = 0; j < tokens_len; j++)
	    {
	      if (tokens[j].type == TK_NOTYPE)
		{
		  for (int k = j + 1; k < tokens_len; k++)
		    {
		      tokens[k - 1] = tokens[k];
		    }
		  tokens_len--;
		}
	    }
	}
    }
  // DEREF
  for (int i = 0; i < tokens_len; i++)
    {
      if (tokens[i].type == '*'
	  && (i == 0 || (i > 0 && tokens[i - 1].type != NUM)))
	{
	  tokens[i].type = DEREF;
	}
    }
  for (int i = 0; i < tokens_len; i++)
    {
      if ((tokens[i].type == '*' && i > 0
	   && tokens[i - 1].type != NUM && tokens[i + 1].type == NUM)
	  || (tokens[i].type == '*' && i == 0))
	{
	  tokens[i].type = TK_NOTYPE;
	  int tmp = strtol (tokens[i + 1].str, NULL, 0);
	  uintptr_t a = (uintptr_t) tmp;
	  sprintf (tokens[i + 1].str, "%d", *((int *) a));
	  for (int j = 0; j < tokens_len; j++)
	    {
	      if (tokens[j].type == TK_NOTYPE)
		{
		  for (int k = j + 1; k < tokens_len; k++)
		    {
		      tokens[k - 1] = tokens[k];
		    }
		  tokens_len--;
		}
	    }
	}
    }
  Log ("------after process------");
  for (int i = 0; i < tokens_len; i++)
    {
      Log ("token%d\ttype%d\tstr:%s", i, tokens[i].type, tokens[i].str);
    }
  Log ("len%d", tokens_len);
  *success = true;
  return eval (0, tokens_len - 1);
}
