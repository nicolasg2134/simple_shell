#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: list of arguments
 * @env: list of env vars
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char **env)
{
	char *ptr = NULL;
	char **string = NULL;
	int status;
	pid_t parent;
	(void)argc;

	while (1)
	{
		ptr = NULL;
		signal(SIGINT, signal_manipulation);
		if (prompt(&ptr) == -1)
			continue;
		string = strtoken(ptr);
		if (!string)
		{
			free_string(99, 1, ptr);
			continue;
		}
		free_string(99, 1, ptr);
		if (shell_built(string, env))
			continue;
		parent = fork();
		if (parent == 0)
		{
			check_path(string, env);
			if (execve(string[0], string, NULL) == -1)
			{
				perror(*argv);
				free_array(string);
				exit(0);
			}
		}
		else
		{
			free_array(string);
			if (!wait(&status))
				break;
		}
	}
	return (0);
}
