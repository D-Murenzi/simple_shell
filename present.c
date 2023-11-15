/* this function checks if a program is in the directories specified by path */
/* variable and returns actual path for the file */

#include "main.c"

/**
 * present-checks if a program exist and the path in which it exists
 * @pointer: the program to checks it's existance
 * Return: pointer to the path in which the program exists
 */

char *present(char *pointer)
{
	if (pointer)
	{
		char *ptr_path, *ptr, *path, **path_array;
		int n, a;

		path = getenv("PATH");
		n = word_count(path, ":");
		ptr_path = strdup(path);
		path_array = strsplit(ptr_path, ":");
		for (a = 0; a < n; a++)
		{
			ptr = malloc(strlen(path_array[a]) + 1 + strlen(pointer));
			if (ptr == NULL)
			{
				free(path_array);
				return (NULL);
			}
			strcpy(ptr, path_array[a]);
			if (ptr[strlen(path_array[a]) - 1] != '/')
			{
				strcat(ptr, "/");
			}
			strcat(ptr, pointer);
			if (access(ptr, F_OK | X_OK) != 0)
			{
				free(ptr);
			}
			else
			{
				free(path_array);
				return (ptr);
			}
		}
		free(path_array);
	}
	return (NULL);
}
