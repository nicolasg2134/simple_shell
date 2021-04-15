#ifndef SHELL_H
#define SHELL_H
#define SH_TOK_BUFSIZE 64
#define SH_RL_BUFSIZE 1024
#define SH_TOK_DELIM " \t\r\n\a"

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>


char *builtin_str[] = {
	"cd",
	"help",
  	"exit"

};

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);
int sh_num_builtins();
int sh_launch(char **args);
int sh_execute(char **args);
char *sh_read_line(void);
void sh_loop(void);
int sh_num_builtins(); 
int main(int argc, char **argv);
char **sh_split_line(char *line);
#endif