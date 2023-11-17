/* this program contains main function that calls other function*/
/*to act as shell*/

#include "main.c"

/**
 * main-entry to the program and function caller
 * @argc: the number of arguments given to the initial program
 * @argv: the array to the arguments
 * @env: the array to environmental variables
 * Return: 0 on success or any number on failure
 */

int main(int argc, char **argv, char **env)
{
	if ((argc > 0) && (argv != NULL))
	{
		while (1)
		{
			char *ptr, *ptr1, **arguments;
			size_t b;
			ssize_t n;

			ptr = NULL;
			ptr1 = getenv("PWD");
			if (isatty(STDIN_FILENO) == 1)
			{
				dprintf(1, "%s($)", ptr1);
			}
			n = getline(&ptr, &b, stdin);
			if ((n <= 0) || (n == EOF))
			{
				break;
			}
			if (ptr[n - 1] == '\n')
			{
				ptr[n - 1] = '\0';
			}
			arguments = strsplit(ptr, " ");
			if (strcmp(arguments[0], "exit") == 0)
			{
				free(arguments);
				free(ptr);
				break;
			}
			excuter(argv[0], arguments, env);
			free(ptr);
			free(arguments);
		}
	}
	return (0);
}
