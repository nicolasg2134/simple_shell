#include "holberton.h"
/**
 * _strncpy - copies ones string to another string in memory
 * @dest: destination string to copy from
 * @src: string to copy to
 * @n: the length to copy
 *
 * Return: the dest memory address
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
/**
 * _strncpyconst - copies one constant string to another string
 * @dest: destination string to copy from
 * @src: string to copy to
 * @n: the length to copy
 *
 * Return: the dest memory address
 */
char *_strncpyconst(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}