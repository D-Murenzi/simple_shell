/* this is a build in cd function*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * cd-changes the workking directory
 * @filepath: this is the new working directory's path
 * Return: 0 on success or -1 on fail
 */

int cd(char *filepath)
{
	int a, b;

	if (filepath == NULL)
	{
		printf("cd:usage:./cd argument");
	}
	a = chdir(filepath) != 0;
	if (a == 0)
	{
		b = setenv("PWD", filepath, 1);
		if (b != 0)
		{
			perror("setenv");
		}
	}
	else
	{
			perror("cd");
	}

	return (0);
}
