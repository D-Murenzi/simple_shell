/* this function splits the string and returns an array of each word*/

#include <stdio.h>
#include "main.c"
#include <string.h>

/**
 * strsplit-splits the string into each words
 * @ptr:pointer to string
 * Return: array to the array of words
 */

char **strsplit(char *ptr)
{
	char *newptr;
	char *delimit;
	char **strarray;
	int n;
	int i;

	n = word_count(ptr);
	delimit = " ";
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
	return (strarray);
}
