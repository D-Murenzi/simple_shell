/* this program prints the environmental variables to stdout*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * env-prints the environmental variables to the stdout
 * @env: the environmental variables from the process
 * Return: 0 on success and 1 on failure
 */

void env_function(char *env[])
{
	int a;

	if (env == NULL)
	{
		printf("error loading env variables\n");
		return;
	}
	for (a = 0; env[a] != NULL; a++)
	{
		dprintf(STDOUT_FILENO,"%s\n", env[a]);
	}
}
