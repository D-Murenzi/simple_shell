/* this is a build in cd function*/

#include <stdio.h>
#include <unistd.h>

/**
 * cd-changes the workking directory
 * @filepath: this is the new working directory's path
 * Return: 0 on success or -1 on fail
 */

int cd(char *filepath)
{
	int a;

	a = chdir(filepath);
	if (a != 0)
	{
		printf("cd: %s: No such file or directory\n", filepath);
	}
	return (a);
}
