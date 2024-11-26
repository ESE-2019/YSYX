#include <am.h>
#include <riscv/riscv.h>

#define KBD_ADDR 0x10011000

typedef enum
{
  ps2_KEY_NONE = 0,
  ps2_KEY_ESCAPE,
  ps2_KEY_F1,
  ps2_KEY_F2,
  ps2_KEY_F3,
  ps2_KEY_F4,
  ps2_KEY_F5,
  ps2_KEY_F6,
  ps2_KEY_F7,
  ps2_KEY_F8,
  ps2_KEY_F9,
  ps2_KEY_F10,
  ps2_KEY_F11,
  ps2_KEY_F12,
  ps2_KEY_GRAVE,
  ps2_KEY_1,
  ps2_KEY_2,
  ps2_KEY_3,
  ps2_KEY_4,
  ps2_KEY_5,
  ps2_KEY_6,
  ps2_KEY_7,
  ps2_KEY_8,
  ps2_KEY_9,
  ps2_KEY_0,
  ps2_KEY_MINUS,
  ps2_KEY_EQUALS,
  ps2_KEY_BACKSPACE,
  ps2_KEY_TAB,
  ps2_KEY_Q,
  ps2_KEY_W,
  ps2_KEY_E,
  ps2_KEY_R,
  ps2_KEY_T,
  ps2_KEY_Y,
  ps2_KEY_U,
  ps2_KEY_I,
  ps2_KEY_O,
  ps2_KEY_P,
  ps2_KEY_LEFTBRACKET,
  ps2_KEY_RIGHTBRACKET,
  ps2_KEY_BACKSLASH,
  ps2_KEY_CAPSLOCK,
  ps2_KEY_A,
  ps2_KEY_S,
  ps2_KEY_D,
  ps2_KEY_F,
  ps2_KEY_G,
  ps2_KEY_H,
  ps2_KEY_J,
  ps2_KEY_K,
  ps2_KEY_L,
  ps2_KEY_SEMICOLON,
  ps2_KEY_APOSTROPHE,
  ps2_KEY_RETURN,
  ps2_KEY_LSHIFT,
  ps2_KEY_Z,
  ps2_KEY_X,
  ps2_KEY_C,
  ps2_KEY_V,
  ps2_KEY_B,
  ps2_KEY_N,
  ps2_KEY_M,
  ps2_KEY_COMMA,
  ps2_KEY_PERIOD,
  ps2_KEY_SLASH,
  ps2_KEY_RSHIFT,
  ps2_KEY_LCTRL,
  ps2_KEY_APPLICATION,
  ps2_KEY_LALT,
  ps2_KEY_SPACE,
  ps2_KEY_RALT,
  ps2_KEY_RCTRL,
  ps2_KEY_UP,
  ps2_KEY_DOWN,
  ps2_KEY_LEFT,
  ps2_KEY_RIGHT,
  ps2_KEY_INSERT,
  ps2_KEY_DELETE,
  ps2_KEY_HOME,
  ps2_KEY_END,
  ps2_KEY_PAGEUP,
  ps2_KEY_PAGEDOWN
} ps2_key;

static inline ps2_key ps2_scan_code_to_enum(int scan_code)
{
  switch (scan_code)
  {
  case 0x76:
    return ps2_KEY_ESCAPE; // ESC
  case 0x05:
    return ps2_KEY_F1; // F1
  case 0x06:
    return ps2_KEY_F2; // F2
  case 0x04:
    return ps2_KEY_F3; // F3
  case 0x0C:
    return ps2_KEY_F4; // F4
  case 0x03:
    return ps2_KEY_F5; // F5
  case 0x0B:
    return ps2_KEY_F6; // F6
  case 0x83:
    return ps2_KEY_F7; // F7
  case 0x0A:
    return ps2_KEY_F8; // F8
  case 0x01:
    return ps2_KEY_F9; // F9
  case 0x09:
    return ps2_KEY_F10; // F10
  case 0x78:
    return ps2_KEY_F11; // F11
  case 0x07:
    return ps2_KEY_F12; // F12
  case 0x0E:
    return ps2_KEY_GRAVE; // ` (Grave accent)
  case 0x16:
    return ps2_KEY_1; // 1
  case 0x1E:
    return ps2_KEY_2; // 2
  case 0x26:
    return ps2_KEY_3; // 3
  case 0x25:
    return ps2_KEY_4; // 4
  case 0x2E:
    return ps2_KEY_5; // 5
  case 0x36:
    return ps2_KEY_6; // 6
  case 0x3D:
    return ps2_KEY_7; // 7
  case 0x3E:
    return ps2_KEY_8; // 8
  case 0x46:
    return ps2_KEY_9; // 9
  case 0x45:
    return ps2_KEY_0; // 0
  case 0x4E:
    return ps2_KEY_MINUS; // -
  case 0x55:
    return ps2_KEY_EQUALS; // =
  case 0x66:
    return ps2_KEY_BACKSPACE; // Backspace
  case 0x0D:
    return ps2_KEY_TAB; // Tab
  case 0x15:
    return ps2_KEY_Q; // Q
  case 0x1D:
    return ps2_KEY_W; // W
  case 0x24:
    return ps2_KEY_E; // E
  case 0x2D:
    return ps2_KEY_R; // R
  case 0x2C:
    return ps2_KEY_T; // T
  case 0x35:
    return ps2_KEY_Y; // Y
  case 0x3C:
    return ps2_KEY_U; // U
  case 0x43:
    return ps2_KEY_I; // I
  case 0x44:
    return ps2_KEY_O; // O
  case 0x4D:
    return ps2_KEY_P; // P
  case 0x54:
    return ps2_KEY_LEFTBRACKET; // [
  case 0x5B:
    return ps2_KEY_RIGHTBRACKET; // ]
  case 0x5D:
    return ps2_KEY_BACKSLASH; // Backslash
  case 0x58:
    return ps2_KEY_CAPSLOCK; // Caps Lock
  case 0x1C:
    return ps2_KEY_A; // A
  case 0x1B:
    return ps2_KEY_S; // S
  case 0x23:
    return ps2_KEY_D; // D
  case 0x2B:
    return ps2_KEY_F; // F
  case 0x34:
    return ps2_KEY_G; // G
  case 0x33:
    return ps2_KEY_H; // H
  case 0x3B:
    return ps2_KEY_J; // J
  case 0x42:
    return ps2_KEY_K; // K
  case 0x4B:
    return ps2_KEY_L; // L
  case 0x4C:
    return ps2_KEY_SEMICOLON; // ;
  case 0x52:
    return ps2_KEY_APOSTROPHE; // '
  case 0x5A:
    return ps2_KEY_RETURN; // Enter
  case 0x12:
    return ps2_KEY_LSHIFT; // Left Shift
  case 0x1A:
    return ps2_KEY_Z; // Z
  case 0x22:
    return ps2_KEY_X; // X
  case 0x21:
    return ps2_KEY_C; // C
  case 0x2A:
    return ps2_KEY_V; // V
  case 0x32:
    return ps2_KEY_B; // B
  case 0x31:
    return ps2_KEY_N; // N
  case 0x3A:
    return ps2_KEY_M; // M
  case 0x41:
    return ps2_KEY_COMMA; // ,
  case 0x49:
    return ps2_KEY_PERIOD; // .
  case 0x4A:
    return ps2_KEY_SLASH; // /
  case 0x59:
    return ps2_KEY_RSHIFT; // Right Shift
  case 0x14:
    return ps2_KEY_LCTRL; // Left Ctrl
  case 0x11:
    return ps2_KEY_LALT; // Left Alt
  case 0x29:
    return ps2_KEY_SPACE; // Space
  // case 0x11:
  //   return ps2_KEY_RALT;          // Right Alt (extended)
  // case 0x14:
  //   return ps2_KEY_RCTRL;         // Right Ctrl (extended)
  case 0x75:
    return ps2_KEY_UP; // Up Arrow (extended)
  case 0x72:
    return ps2_KEY_DOWN; // Down Arrow (extended)
  case 0x6B:
    return ps2_KEY_LEFT; // Left Arrow (extended)
  case 0x74:
    return ps2_KEY_RIGHT; // Right Arrow (extended)
  case 0x70:
    return ps2_KEY_INSERT; // Insert (extended)
  case 0x71:
    return ps2_KEY_DELETE; // Delete (extended)
  case 0x6C:
    return ps2_KEY_HOME; // Home (extended)
  case 0x69:
    return ps2_KEY_END; // End (extended)
  case 0x7D:
    return ps2_KEY_PAGEUP; // Page Up (extended)
  case 0x7A:
    return ps2_KEY_PAGEDOWN; // Page Down (extended)
  case 0x2F:
    return ps2_KEY_APPLICATION; // Application/Menu (extended)
  default:
    return ps2_KEY_NONE; // 未识别的扫描码
  }
}

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  static bool F0 = 0;
  uint8_t k = ps2_KEY_NONE;
  k = inb(KBD_ADDR);
  if (F0)
  {
    kbd->keydown = false;
    kbd->keycode = ps2_scan_code_to_enum(k);
    F0 = 0;
  }
  else
  {
    kbd->keydown = k ? true : false;
    kbd->keycode = ps2_scan_code_to_enum(k);
    F0 = k == 0xF0;
  }
}

void __am_uart_rx(AM_UART_RX_T *uart)
{
  if ((inb(SOC_UART_LSR) & (1)) == 0)
    uart->data = 0xff;
  else
    uart->data = inb(SOC_UART_RBR);
}