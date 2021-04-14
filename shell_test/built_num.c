#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}