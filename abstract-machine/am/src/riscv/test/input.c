#include <am.h>
#include <riscv/riscv.h>

#define KBD_ADDR 0x10011000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint8_t k = AM_KEY_NONE;
  k = inb(KBD_ADDR);
  kbd->keydown = k ? true : false;
  kbd->keycode = k;
  //kbd->keydown = 0;
  //kbd->keycode = AM_KEY_NONE;
}

void __am_uart_rx(AM_UART_RX_T *uart) {
  if ((inb(UART_LSR) & (1)) == 0)
    uart -> data = 0xff;
  else
    uart -> data = inb(UART_RBR);
}