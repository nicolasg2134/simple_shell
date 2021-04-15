#include "shell.h"
/**
 *  sh_loop - entry point.
 *  
 *  return: status code
 */
void sh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = sh_read_line();
		args = sh_split_line(line);
		status = sh_execute(args);

		free(line);
		free(args);
	} while (status);
}

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
