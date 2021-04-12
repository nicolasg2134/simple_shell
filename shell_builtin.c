#include "shell.h"

/**
 * sh_env - prints environmental variable
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int sh_env(char **args, char **env)
{
	int i, len;

	i = 0;
	while (env[i] != NULL)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_array(args);
	return (1);
}

/**
 * sh_exit - exits the shells
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int sh_exit(char **args, char **env)
{
	int status;
	(void)env;

	status = 0;
	if (args[1])
		status = convert_to_int(args[1]);
	free_array(args);
	exit(status);
}

/**
 * sh_built - checks for built-in commands
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int sh_built(char **args, char **env)
{
	built_t b_ins[] = {
		{"env", sh_env},
		{"exit", sh_exit},
		{NULL, NULL}
	};
	int i;

	if (args[0] == NULL)
		return (0);
	for (i = 0; i < 2; i++)
	{
		if (_strcompare(args[0], b_ins[i].comand) == 0)
		{
			return (b_ins[i].p(args, env));
		}
	}
	return (0);
}
