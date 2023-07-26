#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;

void print_result(int n);
int main(int ac, char **av, char *envp[]);
void handle_signal(int n);
void prompt(void);
void execution_prog(char *cp, char **cmd);
void buffers(char **buffer);

/**
 * struct builtin - defining builtin
 * @env: biultin function
 * @exit: biultin function
 */
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
#endif
