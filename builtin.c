#include "shell.h"

/**
<<<<<<< HEAD
 * checkbin - checks if the input
=======
 * checkbin - checks if the input is a built in and executes it
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
 *
 * @input: input
 * @tokens: tokens
 * Return: 0 if succed, -1 if built in doesn´t exist
 */

int checkbin(char *input, char **tokens)
{
	int a, b;
	built_in bi[] = {
<<<<<<< HEAD
		{func_env, "env"},
		{func_exit, "exit"},
=======
		{fenv, "env"},
		{fexit, "exit"},
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
		{NULL, NULL}
	};

	for (a = 0; bi[a].name != NULL; a++)
	{
		if (_strcmp(bi[a].name, input) == 0)
		{
			free(tokens), free(input);
			b = bi[a].func();
			return (b);
		}
	}
	return (-1);
}

/**
<<<<<<< HEAD
 * func_env - prints enviromental variables
=======
 * fenv - prints enviromental variables
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
 *
 * Return: 0
 */

<<<<<<< HEAD
int func_env(void)
=======
int fenv(void)
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
{
	int a;
	size_t b = 0;

	for (a = 0; environ[a] != NULL; a++)
	{
		b = _strlen(environ[a]);
		write(1, environ[a], b + 1);
		write(1, "\n", 2);
	}
	return (0);
}

/**
<<<<<<< HEAD
 * func_exit - exits the shell
=======
 * fexit - exits the shell
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
 *
 * Return: 1
 */

<<<<<<< HEAD
int func_exit(void)
=======
int fexit(void)
>>>>>>> 391e89503915cd3874b29b53f780296d7bd0b3f7
{
	return (1);
}
