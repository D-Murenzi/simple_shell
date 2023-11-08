/* this function splits the string and returns an array of each word*/

#include <stdio.h>
#include "main.c"
#include <string.h>

/**
 * strsplit-splits the string into each words
 * @ptr:pointer to string
 * @delimit: the separator for strings to count as words
 * Return: array to the array of words
 */

char **strsplit(char *ptr, char *delimit)
{
	char *newptr;
	char **strarray;
	int n;
	int i;

	n = word_count(ptr, delimit);
	strarray = malloc(sizeof(char *) * n);
	if (strarray == NULL)
	{
		return (NULL);
	}
	newptr = strtok(ptr, delimit);
	for (i = 0; i < n; i++)
	{
		strarray[i] = newptr;
		newptr = strtok(NULL, delimit);
	}
	strarray[n] = NULL;
	return (strarray);
}
