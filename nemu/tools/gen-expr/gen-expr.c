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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// this should be enough
static char buf[65536] = { };
static char code_buf[65536 + 128] = { };	// a little larger than `buf`

static char *code_format =
  "#include <stdio.h>\n"
  "int main() { "
  "  unsigned result = %s; " "  printf(\"%%u\", result); " "  return 0; " "}";

//my code
static int cnt = 0;
unsigned int buff;		//index of buf

unsigned int
choose (unsigned int in)
{
  unsigned int out = rand () % in;
  return out;
}

void
gen_num2 ()
{
  switch (choose (5))
    {
    case 0:
      gen_num2 ();
      gen_num2 ();
      break;
    default:
      buf[buff] = '0' + choose (10);
      buff++;
      break;
    }
}

void
gen_num ()
{
  switch (choose (12))
    {
    case 0:
      buf[buff++] = '0';
      break;
    case 10:
      buf[buff++] = '0';
      buf[buff++] = 'x';
      gen_num2 ();
      break;
    case 11:
      buf[buff++] = '0';
      buf[buff++] = 'X';
      gen_num2 ();
      break;
    default:
      buf[buff] = '1' + choose (9);
      buff++;
      gen_num2 ();
      break;
    }
}

void
gen (char in)
{
  buf[buff++] = in;
}

void
gen_rand_op2 ()
{
  char op[] = { '+', '-', '*', '/', '^', '&', '|' };
  int len = sizeof (op) / sizeof (op[0]);
  buf[buff++] = op[choose (len)];
}

void
gen_rand_op ()
{
  switch (choose (14))
    {
    case 0:
      buf[buff++] = '=';
      buf[buff++] = '=';
      break;
    case 1:
      buf[buff++] = '!';
      buf[buff++] = '=';
      break;
    case 2:
      buf[buff++] = '|';
      buf[buff++] = '|';
      break;
    case 3:
      buf[buff++] = '&';
      buf[buff++] = '&';
      break;
    case 4:
      buf[buff++] = '<';
      buf[buff++] = '=';
      break;
    default:
      gen_rand_op2 ();
      break;
    }
}

static void
gen_rand_expr (bool * flag)
{
if(cnt>32 || *flag==false) {*flag=false; return;}
  switch (choose (3))
    {
    case 0:
      cnt++;
      gen_num ();
      break;
    case 1:
      cnt++;
      cnt++;
      gen ('(');
      gen_rand_expr (flag);
      gen (')');
      break;
    default:
      cnt++;
      gen_rand_expr (flag);
      gen_rand_op ();
      gen_rand_expr (flag);
      break;
    }
}


//end of my code

int
main (int argc, char *argv[])
{
  int seed = time (0);
  srand (seed);
  int loop = 1;
  if (argc > 1)
    {
      sscanf (argv[1], "%d", &loop);
    }
  int i;
  for (i = 0; i < loop; i++)
    {
      memset (buf, 0, 65536);
      buff = 0;
      cnt = 0;
      bool flag=true;
      gen_rand_expr (&flag);
      if (cnt > 32)
	continue;
      buf[buff] = '\0';

      sprintf (code_buf, code_format, buf);

      FILE *fp = fopen ("/tmp/.code.c", "w");
      assert (fp != NULL);
      fputs (code_buf, fp);
      fclose (fp);

      int ret = system ("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");
      if (ret != 0)
	continue;

      fp = popen ("/tmp/.expr", "r");
      assert (fp != NULL);

      int result;
      ret = fscanf (fp, "%d", &result);
      pclose (fp);

      printf ("%u %s\n", result, buf);
    }
  return 0;
}
