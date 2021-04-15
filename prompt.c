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