#include "main.c"

/**
 * exit_status - causes normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int exit_status(char **args)
{
	/* exit with status of the terminated process */
 
	if (args[1])
	{
		return (atoi(args[1]));
	}

	/* exit success */

	else
	{
		return (0);
	}
}
