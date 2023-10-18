#ifndef MAIN_C
#define MAIN_C

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

int cd(char *filepath);
int simple_shell(void);
int word_count(char *ptr);
char **strsplit(char *ptr);

#endif
