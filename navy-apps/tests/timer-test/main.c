#include <stdio.h>
#include <NDL.h>

int main()
{
  uint32_t t0, t1;
  NDL_Init(0);
  t0 = NDL_GetTicks();
  uint32_t flag = 500;
  while (1)
  {
    t1 = NDL_GetTicks();
    if (t1 - t0 >= flag)
    {
      printf("timer-test\n");
      flag += 500;
    }
  }
  NDL_Quit();
  return 0;
}
