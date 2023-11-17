/* this function checks if a program is in the directories specified by path */
/* variable and returns actual path for the file */

#include "main.c"

/**
 * present-checks if a program exist and the path in which it exists
 * @pointer: the program to checks it's existance
 * Return: pointer to the path in which the program exists
 */

char *present(char *pointer)
{
	if (pointer)
	{
		if (pointer[0] != '/')
		{
			char *ptr;

			ptr = sub_present(pointer);
			return (ptr);
		}
		else
		{
			return (pointer);
		}
	}
	return (NULL);
}
