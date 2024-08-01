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
#include <memory/vaddr.h>

typedef struct token {
    int type;
    char str[32];
} Token;

static Token tokens[256] __attribute__((used)) = { };

static int nr_token __attribute__((used)) = 0;

enum {
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
static struct rule {
    const char *regex;
    int token_type;
} rules[] = {
    { " +", NOTYPE },
    { "\\$[a-zA-Z]*[0-9]*", REG },	//caution $0 $t0 etc
    { "0[xX][0-9a-fA-F]+", HEX },
    { "[0-9]+", DEC },		// must be HEX hou mian
    { "\\+", '+' },
    { "\\-", '-' },
    { "\\*", '*' },
    { "\\/", '/' },
    { "\\(", '(' },
    { "\\)", ')' },
    { "\\=\\=", EQ },
    { "\\!\\=", NOTEQ },
    { "\\|\\|", OR },
    { "\\&\\&", AND },
    { "<=", LEQ },
    { "\\!", '!' },		//must be != hou mian
    { "\\&", '&' },		//must be && hou mian
    { "\\^", '^' },
    { "\\|", '|' }
};


bool check_parentheses(int p, int q)
{
    int i, cnt = 0;
    if (tokens[p].type != '(' || tokens[q].type != ')')
	return false;
    for (i = p; i <= q; i++) {
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

word_t eval(int p, int q)
{
    //Log("eval %d -> %d", p, q);
    if (p > q) {		// Bad expression
	panic("eval_failed %d > %d\n", p, q);
    } else if (p == q) {
	return strtol(tokens[p].str, NULL, 0);
    } else if (check_parentheses(p, q) == true) {
	return eval(p + 1, q - 1);
    } else {
	int op = -1;
	int pri = 0;
	for (int i = p; i <= q; i++) {
	    if (tokens[i].type == '(')	// skip parentheses
	    {
		int cnt = 1;
		while (cnt != 0) {
		    i++;
		    if (tokens[i].type == '(')
			cnt++;
		    else if (tokens[i].type == ')')
			cnt--;
		}
	    }
	    // priority of 14
	    if (pri <= 12 && tokens[i].type == OR) {
		pri = 12;
		op = max(op, i);
	    }
	    if (pri <= 11 && tokens[i].type == AND) {
		pri = 11;
		op = max(op, i);
	    }
	    if (pri <= 10 && tokens[i].type == '|') {
		pri = 10;
		op = max(op, i);
	    }
	    if (pri <= 9 && tokens[i].type == '^') {
		pri = 9;
		op = max(op, i);
	    }
	    if (pri <= 8 && tokens[i].type == '&') {
		pri = 8;
		op = max(op, i);
	    }
	    if (pri <= 7
		&& (tokens[i].type == EQ || tokens[i].type == NOTEQ)) {
		pri = 7;
		op = max(op, i);
	    }
	    if (pri <= 6 && tokens[i].type == LEQ) {
		pri = 6;
		op = max(op, i);
	    }
	    if (pri <= 4
		&& (tokens[i].type == '+' || tokens[i].type == '-')) {
		pri = 4;
		op = max(op, i);
	    }
	    if (pri <= 3
		&& (tokens[i].type == '*' || tokens[i].type == '/')) {
		pri = 3;
		op = max(op, i);
	    }
	}
	sword_t eval_l = eval(p, op - 1);
	sword_t eval_r = eval(op + 1, q);
	//Log("TYPE %c %d\nl=%d\tr=%d",tokens[op].type,tokens[op].type,eval_l,eval_r);
	switch (tokens[op].type) {
	case '+':
	    return eval_l + eval_r;
	case '-':
	    return eval_l - eval_r;
	case '*':
	    return eval_l * eval_r;
	case '/':
	    if (eval_r == 0) {
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
	    printf("NOTYPE? %c %d\nl=%d\tr=%d\n", tokens[op].type,
		   tokens[op].type, eval_l, eval_r);
	    panic();
	}
    }
}

#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = { };

void init_regex()
{
    int i;
    char error_msg[128];
    int ret;

    for (i = 0; i < NR_REGEX; i++) {
	ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
	if (ret != 0) {
	    regerror(ret, &re[i], error_msg, 128);
	    panic("regex compilation failed: %s\n%s", error_msg,
		  rules[i].regex);
	}
    }
}

static bool make_token(char *e)
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;

    while (e[position] != '\0') {
	for (i = 0; i < NR_REGEX; i++) {
	    if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0
		&& pmatch.rm_so == 0) {
		int substr_len = pmatch.rm_eo;
		/*char *substr_start = e + position;
		   Log
		   ("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
		   i, rules[i].regex, position, substr_len, substr_len,
		   substr_start); */

		position += substr_len;

		switch (rules[i].token_type) {
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
		    strncpy(tokens[nr_token].str,
			    &e[position - substr_len], substr_len);
		    nr_token++;
		    break;
		case HEX:
		    tokens[nr_token].type = HEX;
		    strncpy(tokens[nr_token].str,
			    &e[position - substr_len], substr_len);
		    nr_token++;
		    break;
		case DEC:
		    tokens[nr_token].type = DEC;
		    strncpy(tokens[nr_token].str,
			    &e[position - substr_len], substr_len);
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
		    printf("no match at position %d\n%s\n%*.s^\n",
			   position, e, position, "");
		    return false;
		}
		break;
	    }
	}

	if (i == NR_REGEX) {
	    printf("no match at position %d\n%s\n%*.s^\n", position, e,
		   position, "");
	    return false;
	}
    }
    return true;
}


word_t expr(char *e, bool *success)
{
    *success = false;
    for (int ii = 0; ii < 256; ii++)	// reset tokens
    {
	tokens[ii].type = 0;
	memset(tokens[ii].str, 0, sizeof(tokens[ii].str));
    }
    if (!make_token(e))
	return 0;

    //Log ("------befoce process------");
    int tokens_len = 0;		// calc len
    for (int i = 0; i < 256; i++) {
	if (tokens[i].type == 0)	//if == reset value
	    break;
	//Log ("token%d\ttype%d\tstr:%s", i, tokens[i].type, tokens[i].str);
	tokens_len++;
    }
    //Log ("len%d", tokens_len);

    for (int i = 0; i < tokens_len; i++)	// trans reg 2 dec
    {
	if (tokens[i].type == REG) {
	    int reg2dec;
	    bool flag = true;
	    if (strcmp(tokens[i].str, "$0") == 0) {
		reg2dec = isa_reg_str2val("$0", &flag);
	    } else {
		reg2dec = isa_reg_str2val(tokens[i].str, &flag);
	    }
	    if (flag) {
		sprintf(tokens[i].str, "%d", reg2dec);
		tokens[i].type = DEC;
	    } else {
		printf("[ERROR]reg2dec failed \n");
		return 0;
	    }
	}
    }

    for (int i = 0; i < tokens_len; i++)	// trans hex 2 dec
    {
	if (tokens[i].type == HEX) {
	    int hex2dec = strtol(tokens[i].str, NULL, 16);
	    sprintf(tokens[i].str, "%d", hex2dec);
	    tokens[i].type = DEC;
	}
    }

    for (int i = 0; i < tokens_len; i++)	// recognize -1, next token must be dec (reg hex)
    {
	if ((tokens[i].type == '-' && i > 0 && tokens[i - 1].type != DEC
	     && tokens[i - 1].type != ')' && tokens[i + 1].type == DEC)
	    || (tokens[i].type == '-' && i == 0
		&& tokens[i + 1].type == DEC)) {
	    for (int j = 31; j >= 0; j--)	//set minus
		tokens[i + 1].str[j] = tokens[i + 1].str[j - 1];
	    tokens[i + 1].str[0] = '-';
	    for (int k = i + 1; k < tokens_len; k++)
		tokens[k - 1] = tokens[k];
	    tokens_len--;
	}
    }

    for (int i = 0; i < tokens_len; i++)	// recognize !, next token must be dec (reg hex)
    {
	if ((tokens[i].type == '!' && i > 0 && tokens[i - 1].type != DEC
	     && tokens[i - 1].type != ')' && tokens[i + 1].type == DEC)
	    || (tokens[i].type == '!' && i == 0
		&& tokens[i + 1].type == DEC)) {
	    int next_num = strtol(tokens[i + 1].str, NULL, 0);
	    if (next_num == 0) {
		memset(tokens[i + 1].str, 0, sizeof(tokens[i + 1].str));
		tokens[i + 1].str[0] = '1';
	    } else {
		memset(tokens[i + 1].str, 0, sizeof(tokens[i + 1].str));
		tokens[i + 1].str[0] = '0';
	    }
	    for (int k = i + 1; k < tokens_len; k++)
		tokens[k - 1] = tokens[k];
	    tokens_len--;
	}
    }


    for (int i = 0; i < tokens_len; i++)	// DEREF, next token must be dec (reg hex)
    {
	if ((tokens[i].type == '*' && i > 0 && tokens[i - 1].type != DEC
	     && tokens[i - 1].type != ')' && tokens[i + 1].type == DEC)
	    || (tokens[i].type == '*' && i == 0
		&& tokens[i + 1].type == DEC)) {
	    //uintptr_t point = strtoul (tokens[i + 1].str, NULL, 0);
	    //sprintf (tokens[i + 1].str, "%d", *((int *) point));
	    vaddr_t EXPR_DEREF;
	    EXPR_DEREF = strtoul(tokens[i + 1].str, NULL, 0);
	    sprintf(tokens[i + 1].str, "%d", (uint32_t)vaddr_read(EXPR_DEREF, 4));
	    for (int k = i + 1; k < tokens_len; k++)
		tokens[k - 1] = tokens[k];
	    tokens_len--;
	}
    }
    //Log ("------after process------");
    for (int i = 0; i < tokens_len; i++) {
	//Log ("token%d\ttype%d\tstr:%s", i, tokens[i].type, tokens[i].str);
    }
    //Log ("len%d", tokens_len);
    *success = true;
    return eval(0, tokens_len - 1);
}
