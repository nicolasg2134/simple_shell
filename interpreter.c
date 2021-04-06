#include "shell.h"

/**
 * main - Entry point
 * @argc: argument cont
 * @argv: Entry of arguments
 * @env: list of vars
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char **env)
{
	(void)argc;
	char *ptr = NULL;
	char **string = NULL;
	int stat;
	pid_t part;


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
		part = fork();
		if (part == 0)
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
			if (!wait(&stat))
				break;
		}
	}
	return (0);
}

/**
 * pormpt - prompts the user for commands
 * @ptr: ptr will hold the string of commands
 * Return: 1 for success
 */

int prompt(char **ptr)
{
	size_t size = 0;
	int len;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "~$ ", 3);
	len = getline(ptr, &size, stdin);
	if (len == EOF) /*si es el taao de el espacio de memoria igual al fn del archivo 
			  liberame la string en la posicion  -1 1 dewsde el puntero asociado*/ 
		free_string(-1, 1, *ptr); 
	(*ptr)[len - 1] = '\0';
	if (*(*ptr) == '\0' || (*(*ptr) == '.' && (*ptr)[1] == '\0')) /*si el puntero del puntero es igual a nullo o a un punto o esta en la posicion 1 */
	{
		free_string(99, 1, *ptr); /*liverame el alrgo de la string y retorname menos a la poscion de -1 sino es asi retorname true*/ 
		return (-1);
	}
	else
		return (1);
}/* Propmt functions is crete a prompt*/
