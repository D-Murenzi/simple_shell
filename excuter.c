/* this function determines if the function is a build in or not and then excute it*/

#include "main.c"

/**
 * excuter-determines built ins and excutes the non built in commands
 * @argv[]:array containing command and its arguments
 * @env[]: array containing environmental variables
 * Return: 0 on success or any number on failure
 */

int excuter(char **argv, char **env)
{
	int a;
	char *ptr_path;
	pid_t my_pid;
	
	if (strcmp(argv[0], "cd") == 0)
	{
		cd(argv[1]);
		return (0);
	}
	if (strcmp(argv[0], "env") == 0)
	{
		env_function(env);
		return (0);
	}
	else
	{
		ptr_path = present(argv[0]);
		dprintf(STDOUT_FILENO, "%s\n ", ptr_path);
		if (ptr_path != NULL)
		{
			my_pid = fork();
			if (my_pid == 0)
			{
				a = execvp(argv[0], argv);
				if (a)
				{
					perror(argv[0]);
					return (1);
				}
			}
			if (my_pid != 0)
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
