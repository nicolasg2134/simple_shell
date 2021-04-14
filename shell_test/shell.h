#ifndef SHELL_H
#define SHELL_H
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);

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
#endif