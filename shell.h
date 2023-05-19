#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char** environ;

#define MAX_COMMAND_LENGTH 100

void prompt_user();
char *_strtok(char *src, char *delimeters);
int _strlen(char *src);
char **StrToArr(char *src, char *delimeters, int *n);
void execute_command(char* command);
ssize_t _getline(char **line, int *initialSize);
size_t _strcspn(const char *str);
#endif
