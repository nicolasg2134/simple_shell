#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
  @char: Launch a program and wait for it to terminate.
  @args: args Null terminated list of arguments (including program).
  @return Always returns 1
*/

int sh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {

		if (execvp(args[0], args) == -1) {
			perror("sh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
  
		perror("sh");
	} else {
    
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}
