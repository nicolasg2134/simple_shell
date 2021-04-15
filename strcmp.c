#include "holberton.h"
/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}