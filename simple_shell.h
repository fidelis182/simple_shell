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

int str_len(char *c);
int builtin_env(char **args, char __attribute__((__unused__)) **begin);
void print_result(int n);
int main(int ac, char **av[]);
void handle_signal(int n);
void prompt(void);
void execution_prog(char *cp, char **cmd);
void buffers(char **buffer);


struct flags
{
	bool interactive;
} flags;
/**
 * struct builtin - defining builtin
 * @s: source of builtin
 * @func: function pointer to the builtin command passed
 */
typedef struct builtin
{
	char *s;
	int (*funcp)(char **args, char **begin);
}biultin_t;

/**
 * struct alias - defining alias
 * @s: source of alias
 * @count: count of alias
 * @another: another alias
 */
typedef struct alias
{
	char *s;
	char *count;
	struct alias *another;
} alias_t;

/**
 * struct lists - defining new list
 * @s: new list path
 * @another: next list path
 */
typedef struct lists
{
	char *s;
	struct lists *another;
} list_t;

extern char **environ;
char *s;
int global_history;
alias_t *global_alias;
#endif
