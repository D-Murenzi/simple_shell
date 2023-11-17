/* this function is defined to respect betty in present function*/

#include "main.c"

/**
 * sub_present-function that takes a appointer and searched its path
 * @pointer: the program to search its path
 * Return: pointer to the path or null
 */

char *sub_present(char *pointer)
{
	char *ptr_path, *ptr, *path, **path_array;
	int n, a;

	path = getenv("PATH");
	n = word_count(path, ":");
	ptr_path = strdup(path);
	path_array = strsplit(ptr_path, ":");
	for (a = 0; a < n; a++)
	{
		ptr = malloc(strlen(path_array[a]) + 2 + strlen(pointer));
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
			free(ptr_path);
			free(path_array);
			return (ptr);
		}
	}
	free(ptr_path);
	free(path_array);
	return (NULL);
}
