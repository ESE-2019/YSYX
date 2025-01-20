#include <fs.h>

typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);

typedef struct
{
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t lseek;
} Finfo;

enum
{
  FD_STDIN,
  FD_STDOUT,
  FD_STDERR,
  FD_FB
};

size_t invalid_read(void *buf, size_t offset, size_t len)
{
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len)
{
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
    [FD_STDIN] = {"stdin", -1, 0, invalid_read, invalid_write},
    [FD_STDOUT] = {"stdout", -1, 0, invalid_read, serial_write},
    [FD_STDERR] = {"stderr", -1, 0, invalid_read, serial_write},
    [FD_FB] = {"/dev/fb", -1, 0, invalid_read, fb_write},
    {"/proc/dispinfo", -1, 0, dispinfo_read, invalid_write},
    {"/dev/events", -1, 0, events_read, invalid_write},
#include "files.h"
};

static int file_table_len;
int screen_w, screen_h;
void init_fs()
{
  file_table_len = sizeof(file_table) / sizeof(file_table[0]);
  for (int i = 0; i < file_table_len; i++)
  {
    Finfo *f = &file_table[i];
    f->lseek = 0;
    if (f->read == NULL)
      f->read = ramdisk_read;
    if (f->write == NULL)
      f->write = ramdisk_write;
  }
  screen_w = io_read(AM_GPU_CONFIG).width;
  screen_h = io_read(AM_GPU_CONFIG).height;
  file_table[FD_FB].size = screen_w * screen_h * 4;
}

int fs_open(const char *pathname, int flags, int mode)
{
  for (int i = 0; i < file_table_len; i++)
  {
    Finfo *f = &file_table[i];
    if (strcmp(pathname, f->name) == 0)
    {
#ifdef STRACE
      Log("%s\n", f->name);
#endif
      f->lseek = 0;
      return i;
    }
  }
  panic("[%s] can not open", pathname);
  return -1;
}

size_t fs_read(int fd, void *buf, size_t len)
{
  if (fd < 0 || fd >= file_table_len)
    panic("illegal fd %d", fd);
  Finfo *f = &file_table[fd];
#ifdef STRACE
  Log("%s\n", f->name);
#endif
  len = (f->lseek + len - 1) > f->size ? f->size - f->lseek + 1 : len;
  size_t ret = f->read(buf, f->disk_offset + f->lseek, len);
  f->lseek += ret;
  return ret;
}

size_t fs_write(int fd, const void *buf, size_t len)
{
  if (fd < 0 || fd >= file_table_len)
    panic("illeagal fd %d", fd);
  Finfo *f = &file_table[fd];
#ifdef STRACE
  Log("%s\n", f->name);
#endif
  len = (f->lseek + len - 1) > f->size ? f->size - f->lseek + 1 : len;
  size_t ret = f->write(buf, f->disk_offset + f->lseek, len);
  f->lseek += ret;
  return ret;
}

size_t fs_lseek(int fd, size_t offset, int whence)
{
  if (fd < 0 || fd >= file_table_len)
    panic("illeagal fd %d", fd);
  Finfo *f = &file_table[fd];
#ifdef STRACE
  Log("%s\n", f->name);
#endif
  switch (whence)
  {
  case SEEK_SET:
    f->lseek = offset;
    break;
  case SEEK_CUR:
    f->lseek += offset;
    break;
  case SEEK_END:
    f->lseek = f->size + offset;
    break;
  default:
    panic("should not reach here");
  }
  if (f->lseek < 0)
    return -1;
  return f->lseek;
}

int fs_close(int fd)
{
  if (fd < 0 || fd >= file_table_len)
    panic("illeagal fd %d", fd);
#ifdef STRACE
  Finfo *f = &file_table[fd];
  Log("%s\n", f->name);
#endif
  return 0;
}
