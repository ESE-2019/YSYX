#include <nterm.h>
#include <stdarg.h>
#include <unistd.h>
#include <SDL.h>

char handle_key(SDL_Event *ev);

static void sh_printf(const char *format, ...)
{
  static char buf[256] = {};
  va_list ap;
  va_start(ap, format);
  int len = vsnprintf(buf, 256, format, ap);
  va_end(ap);
  term->write(buf, len);
}

static void sh_banner()
{
  sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt()
{
  sh_printf("sh> ");
}

static inline char **parse_cmd_to_argv(const char *cmd)
{
  char **argv = (char **)malloc(64 * sizeof(char *));
  char *cmd_copy = strdup(cmd); // 复制命令行字符串

  if (!cmd_copy)
    return NULL;
  else if (cmd_copy[0] == '\n')
    return NULL;

  for (int i = 1; i < strlen(cmd_copy); i++)
  {
    if (cmd_copy[i] == '\n')
      cmd_copy[i] = ' ';
  }

  int argc = 0;                        // 参数计数
  char *token = strtok(cmd_copy, " "); // 以空格分割字符串
  while (token)
  {
    printf("nterm-token[%d] = [%s]\n", argc, token);
    argv[argc++] = token;
    if (argc >= 63)
      break; // 防止溢出
    token = strtok(NULL, " ");
  }
  argv[argc] = NULL; // 以 NULL 结尾

  return argv;
}

static void sh_handle_cmd(const char *cmd)
{

  char command[64];
  strcpy(command, cmd);
  command[strlen(command) - 1] = '\0';

  if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
    exit(0);
  } 
  int argc = 0;
  const char *argvv[16];
  char *p = strtok(command, " ");
  while (p) {
    argvv[argc++] = p;
    p[strlen(p)] = '\0';
    p = strtok(NULL, " ");
  }
  argvv[argc] = NULL;
  setenv("PATH", "/usr/bin:/bin", false);
  execvp(command, (char**)argvv);


  if (strncmp(cmd, "exit", sizeof("exit") - 1) == 0)
  {
    exit(0);
  }
  char **argv = parse_cmd_to_argv(cmd);
  if (argv != NULL)
    execvp(argv[0], argv);

  sh_printf("nterm error\n");
}

void builtin_sh_run()
{
  sh_banner();
  sh_prompt();

  while (1)
  {
    SDL_Event ev;
    if (SDL_PollEvent(&ev))
    {
      if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN)
      {
        const char *res = term->keypress(handle_key(&ev));
        if (res)
        {
          sh_handle_cmd(res);
          sh_prompt();
        }
      }
    }
    refresh_terminal();
  }
}
