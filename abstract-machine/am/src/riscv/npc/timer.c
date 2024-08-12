#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#define RTC_ADDR (0xa0000048)

void __am_timer_init() {}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t rtc_port_base1 = inl(RTC_ADDR + 4) & 0x00000000FFFFFFFF; 
  uint64_t rtc_port_base0 = inl(RTC_ADDR) & 0x00000000FFFFFFFF;
  uptime->us = rtc_port_base0 | (rtc_port_base1 << 32);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
}
