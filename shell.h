#ifndef _SHELL_H
#define _SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &sh_cd,
  &sh_help,
  &sh_exit
};

int sh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  List of protptipe functions.
 */

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
int sh_launch(char **args);
int sh_execute(char **args);
char *sh_read_line(void);
char **sh_split_line(char *line);
int main(int argc, char **argv);
void sh_loop(void);
int main(int argc, char **argv);

#endif