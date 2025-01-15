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
    [FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
    [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
    [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
    // file path, file size, offset in disk
    {"/bin/hello", 37792, 0},
    {"/bin/dummy", 37528, 37792},
    {"/share/music/little-star.ogg", 140946, 75320},
    {"/share/music/rhythm/Do.ogg", 6473, 216266},
    {"/share/music/rhythm/Mi.ogg", 6611, 222739},
    {"/share/music/rhythm/empty.ogg", 4071, 229350},
    {"/share/music/rhythm/La.ogg", 6542, 233421},
    {"/share/music/rhythm/Re.ogg", 6503, 239963},
    {"/share/music/rhythm/Fa.ogg", 6625, 246466},
    {"/share/music/rhythm/Si.ogg", 6647, 253091},
    {"/share/music/rhythm/So.ogg", 6538, 259738},
    {"/share/fonts/Courier-8.bdf", 20114, 266276},
    {"/share/fonts/Courier-12.bdf", 24339, 286390},
    {"/share/fonts/Courier-9.bdf", 20488, 310729},
    {"/share/fonts/Courier-7.bdf", 19567, 331217},
    {"/share/fonts/Courier-13.bdf", 25677, 350784},
    {"/share/fonts/Courier-10.bdf", 21440, 376461},
    {"/share/fonts/Courier-11.bdf", 23272, 397901},
    {"/share/pictures/projectn.bmp", 49290, 421173},
    {"/share/files/num", 5000, 470463},
    {"总计", 475463, 475463},
};

static int file_table_len;
void init_fs()
{
  file_table_len = sizeof(file_table) / sizeof(file_table[0]);
  // TODO: initialize the size of /dev/fb
}

int fs_open(const char *pathname, int flags, int mode)
{
  for (int i = 0; i < file_table_len; i++)
  {
    if (strcmp(pathname, file_table[i].name) == 0)
    {
      file_table[i].lseek = 0;
      return i;
    }
  }
  panic("should not reach here");
  return -1;
}

size_t fs_read(int fd, void *buf, size_t len)
{
  assert(fd >= 0 && fd < file_table_len);
  len = (file_table[fd].lseek + len - 1) > file_table[fd].size ? file_table[fd].size - file_table[fd].lseek + 1 : len;
  return ramdisk_read(buf, file_table[fd].disk_offset + file_table[fd].lseek, len);
}

size_t fs_write(int fd, const void *buf, size_t len)
{
  assert(fd >= 0 && fd < file_table_len);
  return 0;
}

size_t fs_lseek(int fd, size_t offset, int whence)
{
  assert(fd >= 0 && fd < file_table_len);
  switch (whence)
  {
  case SEEK_SET:
    file_table[fd].lseek = offset;
    break;
  case SEEK_CUR:
    file_table[fd].lseek += offset;
    break;
  case SEEK_END:
    file_table[fd].lseek = file_table[fd].size + offset;
    break;
  default:
    panic("should not reach here");
  }
  assert(file_table[fd].lseek >= 0);
  assert(file_table[fd].lseek <= file_table[fd].size);
  return file_table[fd].lseek;
}

int fs_close(int fd)
{
  assert(fd >= 0 && fd < file_table_len);
  return 0;
}
