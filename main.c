#ifndef MAIN_C
#define MAIN_C


#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>


char *sub_present(char *pointer);
char *_strcat(char *dest, char *src);
int cd(char *filepath);
int simple_shell(void);
int word_count(char *ptr, char *delimit);
char **strsplit(char *ptr, char *delimit);
char *present(char *pointer);
void env_function(char *env[]);
int excuter(char *name, char *argv[], char *env[]);
int _getline(char *ptr);

int exit_Status(char **args);

int help(char **args);

#endif





