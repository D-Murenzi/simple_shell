/* this program contains main function that calls other function to act as shell*/

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
		char *ptr, *ptr1, **arguments;
		
		ptr = malloc(sizeof(char) * INT_MAX);
		if (ptr == NULL)
		{
			return (1);
		}
		while (1)
		{
			ptr1 = getenv("PWD");
			dprintf(STDOUT_FILENO,"%s ($)", ptr1);
			_getline(ptr);
			arguments = strsplit(ptr," ");
			excuter(arguments, env);
		}
	}
	return (0);
}
