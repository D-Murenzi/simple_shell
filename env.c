/* this program prints the environmental variables to stdout*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * env-prints the environmental variables to the stdout
 * @env: the environmental variables from the process
 * Return: 0 on success and 1 on failure
 */

void env(char *env[])
{
	int a;

	if (env == NULL)
	{
		printf("error loading env variables\n");
		return (1);
	}
	for (a = 0; env[a] != NULL; a++)
	{
		printf("%s\n", env[a]);
	}
	return (0);
}
