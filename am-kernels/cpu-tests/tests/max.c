#include "trap.h"

int max(int x, int y) {
  int z;
  if (x > y) {
    z = x;
  } else {
    z = y;
  }
  return z;
}

int test_data[] = {0,          1,          2,          0x7fffffff,
                   0x80000000, 0x80000001, 0xfffffffe, 0xffffffff};

int ans[] = {
    0,          0x1,        0x2,        0x7fffffff, 0,          0,
    0,          0,          0x1,        0x1,        0x2,        0x7fffffff,
    0x1,        0x1,        0x1,        0x1,        0x2,        0x2,
    0x2,        0x7fffffff, 0x2,        0x2,        0x2,        0x2,
    0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff,
    0x7fffffff, 0x7fffffff, 0,          0x1,        0x2,        0x7fffffff,
    0x80000000, 0x80000001, 0xfffffffe, 0xffffffff, 0,          0x1,
    0x2,        0x7fffffff, 0x80000001, 0x80000001, 0xfffffffe, 0xffffffff,
    0,          0x1,        0x2,        0x7fffffff, 0xfffffffe, 0xfffffffe,
    0xfffffffe, 0xffffffff, 0,          0x1,        0x2,        0x7fffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};

#define NR_DATA LENGTH(test_data)

int main() {
  int i, j, ans_idx = 0;
  for (i = 0; i < NR_DATA; i++) {
    for (j = 0; j < NR_DATA; j++) {
      check(max(test_data[i], test_data[j]) == ans[ans_idx++]);
    }
    check(j == NR_DATA);
  }

  check(i == NR_DATA);

  return 0;
}
