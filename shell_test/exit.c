#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
   @brief Builtin command: exit.
   @param args List of args.
   @return Always returns 0.
*/
int sh_exit(char **args)
{
	return 0;
}