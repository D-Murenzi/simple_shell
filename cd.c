/* this is a build in cd function*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.c"

/**
 * path_exp-expands the arguments to cd
 * @filepath: pointer to the path to change the directory to
 * Return: pointer to the expanded path
 */

char *path_exp(char *filepath)
{
	char *home, *oldwd, *exppath;

	home = getenv("HOME");
	oldwd = getenv("OLDPWD");

	if (filepath[0] == '~')
	{
		exppath = malloc(strlen(home) + strlen(filepath) + 1);
		if (exppath == NULL)
		{
			perror("mamory allocation in cd");
			return (NULL);
		}
		strcpy(exppath, home);
		strcat(exppath, filepath + 1);
		return (exppath);
	}
	if (filepath[0] == '-')
	{
		exppath = malloc(strlen(oldwd) + strlen(filepath) + 1);
		if (exppath == NULL)
		{
			perror("mamory allocation in cd");
			return (NULL);
		}
		strcpy(exppath, oldwd);
		strcat(exppath, filepath + 1);
		return (exppath);
	}
	return (filepath);
}

/**
 * cd-changes the workking directory
 * @filepath: this is the new working directory's path
 * Return: 0 on success or -1 on fail
 */

int cd(char *filepath)
{
	char *pwd, *home;

	home = getenv("HOME");
	if (filepath == NULL)
	{
		filepath = home;
	}
	if ((filepath[0] == '~') || (filepath[0] == '-'))
	{
		filepath = path_exp(filepath);
		if (filepath == NULL)
		{
			return (-1);
		}
	}
	dprintf(STDOUT_FILENO, "filepath = %s\n", filepath);
	if (chdir(filepath) == 0)
	{
		pwd = getcwd(NULL, 0);
		if (pwd != NULL)
		{
			if (setenv("PWD", pwd, 1) != 0)
			{
				perror("setenv");
			}
			free(pwd);
		}
		else
		{
			perror("getcwd");
		}
	}
	else
	{
		perror("cd");
		return (-1);
	}
	free(filepath);
	return (0);
}
