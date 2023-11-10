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
		char *ptr_path, *ptr, **path_array;
		int n, a, b, c, d;

		ptr_path = getenv("PATH");
		n = word_count(ptr_path, ":");
		path_array = strsplit(ptr_path, ":");
		for (a = 0; a < n; a++)
		{
			d = strlen(path_array[a]) + 1 + strlen(pointer);
			ptr = malloc(d);
			if (ptr == NULL)
			{
				return (NULL);
			}
			strcpy(ptr, path_array[a]);
			if (ptr[strlen(path_array[a]) - 1] != '/')
			{
				strcat(ptr, "/");
			}
			strcat(ptr, pointer);
			path_array[a] = ptr;
		}
		for (b = 0; b < n; b++)
		{
			c = access(path_array[b], F_OK | X_OK);
			if (c != 0)
			{
				free(path_array[b]);
			}
			else
			{
					return (path_array[b]);
			}
		}
	}
	return (NULL);
}
