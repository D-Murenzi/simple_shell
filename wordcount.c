/* this is a function to count number of words in input strings*/
#include <stdio.h>
#include "main.c"
#include <stdlib.h>

/**
 * word_count-counts words in the string
 * @ptr: pointer to the string
 * Return: number of words in the string
 */

int word_count(char *ptr)
{
	int n;
	char delimit = ' ';
	const char *newptr;

	if (ptr == NULL)
	{
		return (0);
	}
	n = 0;
	for (newptr = ptr; *newptr != '\0'; newptr++)
	{
		if (*newptr == delimit)
		{
			n++;
		}
	}
	n++;
	return (n);
}
