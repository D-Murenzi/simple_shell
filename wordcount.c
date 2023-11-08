/* this is a function to count number of words in input strings*/
#include <stdio.h>
#include "main.c"
#include <stdlib.h>

/**
 * word_count-counts words in the string
 * @ptr: pointer to the string
 * @delimit: the separator of strings to count as words
 * Return: number of words in the string
 */

int word_count(char *ptr, char *delimit)
{
	int n;
	const char *newptr;

	if ((ptr == NULL) || (delimit == NULL))
	{
		return (0);
	}
	n = 0;
	for (newptr = ptr; *newptr != '\0'; newptr++)
	{
		if (*newptr == *delimit)
		{
			n++;
		}
	}
	n++;
	return (n);
}
