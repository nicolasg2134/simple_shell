#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  Function Declarations for builtin shell commands:
 */

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);

void sh_loop(void);
char *sh_read_line(void);
char **sh_split_line(char *line);
int sh_launch(char **args);
int sh_num_builtins();
int (*builtin_func[]) (char **);
int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
#endif