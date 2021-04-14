#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 *  Main - entry point.
 *  @argc: Argument count.
 *  @argv: Argument vector.
 *  return: status code
 */
int main(int argc, char **argv)
{
	sh_loop();
	return EXIT_SUCCESS;
}
