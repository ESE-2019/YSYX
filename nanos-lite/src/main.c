#include <common.h>

void init_mm(void);
void init_device(void);
void init_ramdisk(void);
void init_irq(void);
void init_fs(void);
void init_proc(void);

void print_logo()
{
  extern const char logo[];
  size_t len = strlen(logo);
  size_t printed = 0;
  while (printed < len)
  {
    size_t chunk_size = (len - printed > 99) ? 99 : len - printed;
    char buffer[100];
    strncpy(buffer, logo + printed, chunk_size);
    buffer[chunk_size] = '\0';
    printf("%s", buffer);
    printed += chunk_size;
  }
}

int main()
{
  print_logo();
  Log("'Hello World!' from Nanos-lite");
  Log("Build time: %s, %s", __TIME__, __DATE__);

  init_mm();

  init_device();

  init_ramdisk();

  init_irq();

  init_fs();

  init_proc();

  Log("Finish initialization");

  yield();

  panic("Should not reach here");
}
