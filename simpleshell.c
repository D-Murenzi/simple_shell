/* this is a customized simple shell, many of the feauture of bash are*/
/* not available, this is for learning pupose which means it will not */
/*replace normal bash*/

#include "main.c"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

/**
 * simple_shell-simple shell
 * Return: 0 on success or -1 on failure
 */

int simple_shell(void)
{
	char *ptr;
	FILE *pipe;
	size_t n;
	char **argv;
	pid_t my_pid;

	ptr = malloc(sizeof(char) * 4);
	if (ptr == NULL)
	{
		return (0);
	}
	printf("$");
	getline(&ptr, &n, stdin);
	argv = strsplit(ptr);


	my_pid = fork();

	if (my_pid == 0)
	{
		char whichCmd[100];

		snprintf(whichCmd, sizeof(whichCmd), "which %s", argv[0]);
		pipe = popen(whichCmd, "r");

		if (pipe != NULL)
		{
			char fullPath[100];

			if (fgets(fullPath, sizeof(fullPath), pipe) != NULL)
			{
				fullPath[strcspn(fullPath, "\n")] = '\0';
				execve(fullPath, argv, NULL);
				perror("execve");
				exit(1);
			}
		}
		else
		{
			printf("%s: command not found\n", argv[0]);
			exit(0);
		}
		pclose(pipe);
	}
	if (my_pid != 0)
	{
		wait(NULL);
		if (strcmp(argv[0], "exit") == 0)
		{
			free(ptr);
			exit(0);
		}
		else
		{
			free(ptr);
			simple_shell();
		}
	}
	return (0);
}

/**
 * main-calls other functions
 * Return: 0 on success
 */

int main(void)
{
	simple_shell();
	return (0);
}
