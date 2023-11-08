/* this function concatenates two strings */
#include "main.c"

/**
 * _strcat- concatenates two strings
 * @dest: pointer to dest string
 * @src: pointer to the string src which is second argument
 * Return: a pointer to new string array
 */

char *_strcat(char *dest, char *src)
{
	char *first;

	first = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (first);
}
