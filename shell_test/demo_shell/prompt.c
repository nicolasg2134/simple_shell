#include "holberton.h"

/**
 * prompt - write the prompt
 * @sig: signal to handle
 *
 * Return: void
 */
void prompt(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n $ ", 5);
}

/**
 * main - basic shell demo
 * @argc: argument count
 * @argv: argument vector
 * @env: env variables
 *
 * Return: 0 on exit, 1 if any failures
 */
int main(int argc, char **argv, char **env)
{
	char *buffer; char **commands;
	size_t length; ssize_t characters;
	char *simbolp = "$ ", *exit_command = "exit", *env_command = "env";
	pid_t pid; 
    struct stat fileStat;
	int status, count;
	(void)argc;

	buffer = NULL, length = 0, count = 0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, simbolp, 2);
	signal(SIGINT, prompt);
	while ((characters = getline(&buffer, &length, stdin)))
	{
		if (characters == EOF)
			end_of_file(buffer);
		++count;
		commands = array_from_strtok(buffer);
		pid = fork();
		if (pid == -1)
			fork_fail();
		if (pid == 0)
		{
			
			if (commands == NULL)
				command_is_null(buffer);
			else if (_strcmp(exit_command, commands[0]))
				exit_out(buffer, commands);
			else if (_strcmp(env_command, commands[0]))
				env_out(buffer, commands, env);
			else if (stat(commands[0], &fileStat) == 0)
				execve(commands[0], commands, NULL);
			else
				c_path(commands, buffer, env, argv, count);
		}
		else
		{
			wait(&status);
			if (commands == NULL)
				parent_free_buff_commands(buffer, commands);
			else if (_strcmp(exit_command, commands[0]))
				exit_out(buffer, commands);
			else
				parent_free_buff_commands(buffer, commands);
		}
		length = 0; buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, simbolp, 2);
	}
	if (characters == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}