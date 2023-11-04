/* this  function reads a line from stdin */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * t.h>getline-reads a string from stdin
 * @ptr: the buffer to store the string
 * Return: number of characters it reads
 */

int getline(char *ptr)
{
	int a;
	char *buff;

	a = 0;
	buff = ptr;
	while (buff)
	{
		read(STDIN_FILENO, buff, 1);
		if (*buff == '\n')
		{
			break;
		}
		a++;
		buff++;
	}
	return (a);
}
