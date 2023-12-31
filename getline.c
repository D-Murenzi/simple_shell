/* this  function reads a line from stdin */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * _getline-reads a string from stdin
 * @ptr: the buffer to store the string
 * Return: number of characters it reads
 */

void _getline(char *ptr)
{
	char *buff;
	int a;

	dprintf(STDOUT_FILENO, "am in getline");
	buff = ptr;
	a = read(STDIN_FILENO, buff, 1);
	if (a < 0)
	{
		perror("can't read fron stdin");
	}
	while (*buff != '\n')
	{
		buff++;
		a = read(STDIN_FILENO, buff, 1);
		if (a == 0)
		{
			break;
		}
	}
	if (*buff == '\n')
	{
		*buff = '\0';
	}
}
