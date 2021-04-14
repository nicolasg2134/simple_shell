#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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