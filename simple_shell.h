#ifndef SIMPLE_SHELL_H
#define SIMPLE_ SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

extern char **environ;
int biultin_checker(char **cmd, char *buf);
int builtin_func(char **cmd, char *new_line);
void exitcmd(char **cmd, char *newline);
void printenv(void);
void execution_prog(char *command, char **cmd);
void free_buff(char **buffer);
void handle_signal(int n);
char *findpath(void);
char *testpath(char **path, char *cd);
char *_append_path(char *path, char *cmd);
void print_result(int n);
void prompt(void);
int _strlen(char *str);
char *_strchr(char *str, char ctr);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, int n);
int _strcmp(char *str1, char *str2);
char **tokenizing(char *new_line);

#endif
