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
			size_t  n;

			ptr = malloc(sizeof(char) * 9);
			if (ptr == NULL)
			{
				return (1);
			}
			ptr1 = getenv("PWD");
			dprintf(STDOUT_FILENO, "%s ($)", ptr1);

			getline(&ptr, &n, stdin);
			if (ptr[strlen(ptr) - 1] == '\n')
			{
				ptr[strlen(ptr) - 1] = '\0';
			}
			arguments = strsplit(ptr, " ");
			dprintf(STDOUT_FILENO, "%s\n", arguments[0]);
			if ((strcmp(arguments[0], "exit") == 0) || (*arguments[0] == EOF))
			{
				break;
			}
			excuter(argv[0], arguments, env);
			free(ptr);
			free(arguments);
		}
	}
	return (0);
}
