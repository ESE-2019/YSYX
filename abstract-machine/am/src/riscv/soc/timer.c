#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#define RTC_ADDR (0x0200BFF8)

void  __attribute__((section(".klib"))) __am_timer_init() {}

void  __attribute__((section(".klib"))) __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t rtc_port_base1 = inl(RTC_ADDR + 4) & 0x00000000FFFFFFFF; 
  uint64_t rtc_port_base0 = inl(RTC_ADDR) & 0x00000000FFFFFFFF;
  uptime->us = rtc_port_base0 | (rtc_port_base1 << 32);
}

void  __attribute__((section(".klib"))) __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 10;
  rtc->minute = 10;
  rtc->hour = 10;
  rtc->day = 10;
  rtc->month = 10;
  rtc->year = 2024;
}
