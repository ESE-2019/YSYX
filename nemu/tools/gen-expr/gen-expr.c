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

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

//my code
int buff;//index of buf
int choose(int in){
	int out=rand()%in;
	return out;
	}
	
void gen_num2(){
	switch (choose(5)){
	case 0:gen_num2();gen_num2();break;
	default:buf[buff++]='0'+choose(10);break;
	}
}

void gen_num(){
	switch (choose(10)){
	case 0:buf[buff++]='0';break;
	default:buf[buff++]='1'+choose(9);gen_num2();break;
	}
}

void gen(char in){buf[buff++]=in;}

void gen_rand_op(){
char op[]={'+','-','*','/'};
int len=sizeof(op)/sizeof(op[0]);
buf[buff++]=op[choose(len)];
}

static void gen_rand_expr() {
//  buf[0] = '\0';
  switch (choose(8)) {
    case 0: case 1: case 2: case 3: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
    case 6: gen('('); gen_rand_expr(); gen(')'); break;
    default: gen_num(); break;
  }
}
//end of my code

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    //buf[0]='"';
    buff=0;
    gen_rand_expr();
//buf[buff++]='"';
for(;buff<65536;buff++){buf[buff]='\0';}

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
