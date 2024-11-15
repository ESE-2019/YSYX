#include "trap.h"

int main()
{
  AM_TIMER_RTC_T rtc;
  int sec = 1;
  while (sec < 5)
  {
    while (io_read(AM_TIMER_UPTIME).us / 30 < sec)
      ;
    rtc = io_read(AM_TIMER_RTC);
    printf("%d-%d-%d %d:%d:%d GMT (", rtc.year, rtc.month, rtc.day,
           rtc.hour, rtc.minute, rtc.second);
    printf("%d ms).\n", sec);
    sec++;
  }
  return 0;
}
