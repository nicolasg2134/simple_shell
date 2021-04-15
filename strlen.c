#include "holberton.h"
/**
 * _strlen_const - finds the length of a constant string
 * @name: string to find length of
 *
 * Return: length of the constant string
 */
unsigned int _strlen_const(const char *name)
{
	unsigned int i = 0;

	while (name[i])
		++i;
	return (i);
}
/**
 * _strlen - finds the length of a string
 * @s: string to find the length of
 *
 * Return: unsigned int length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int counter = 0;

	while (s[counter] != '\0')
		++counter;

	return (counter);
}