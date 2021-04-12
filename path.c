#include "shell.h"

/**
 * check_path - check if command is in the path
 * @string: an array of strings
 * @env: an array of env vars
 * Return: pointer to the linked list
 */
void check_path(char **string, char **env)
{
	char *string1, *string2;
	char *path;
	int i, inicio, final;

	string1 = concatenate_strings("/", string[0]);
	path = _getenv("PATH", env);
	if (path == NULL)
	{
		free(string1);
		exit(0);
	}
        inicio = i = final = 0;
	while (path[i])
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			if (path[i + 1] == '\0')
			{
				i += 1;
				final = 1;
			}
			else
				path[i] = '\0';
			string2 = concatenate_strings(path + inicio, string1);
			if (access(string2, F_OK) == 0)
			{
				free(string[0]);
				string[0] = string2;
				free(string1);
				return;
			}
			free(string2);
			if (final)
				break;
			path[i] = ':';
			inicio = i + 1;
		}
		i += 1;
	}
	free(string1);
}
