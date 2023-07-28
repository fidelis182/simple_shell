#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

extern char **environ;
char *s;
int global_history;
alias *global_alias;


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
}biultin;

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
} alias;

/**
 * struct lists - defining new list
 * @s: new list path
 * @another: next list path
 */
typedef struct lists
{
        char *s;
        struct lists *another;
} list;

void print_result(int n);
int main(int ac, char **av[]);
void free_env(void);
void free_env(void);
char **copy_env(void);
char **_replace_alias(char **args);
void set_alias(char *s, char *count);
int builtin_alias(char **args, char __attribute__((__unused__)) **begin);
void print_alias(alias *alias);
int current_env(char **args, char __attribute__((__unused__)) **begin);
int _setenv(char **args, char __attribute__((__unused__)) **begin);
int _unsetenv(char **args, char __attribute__((__unused__)) **begin);
char *error_exit(char **args);
char *biultin_cd_error(char **args);
char *syntax_error(char **args);
char *biultin_alias_error(char **args);
char *biultin_env_error(char **args);
int (*get_builtin(char *command))(char **args, char **begin);
int exit_biultin(char **args, char **begin);
int builtin_command(char **args, char __attribute__((__unused__)) **begin);
int changeDirectory(char **args, char *pwd, char *old_pwd);
int generate_error(char **args, int error_value);
char *_itoa(int num);
int num_length(int num);
int file_comment(char *file, int *addrep);
int split_CallAndFree(ssize_t a, char *line, int *addrep, unsigned int new);
int free_list(list *head);
char *denied_permission(char **args;
char *command_error(char **args);
int arguments(int *command);
char *get_args(char *line, int *command);
int check_args(char **args);
int call_args(char **args, char **begin, int *command);
int run_args(char **args, char **begin, int *command);
void handle_signal(int n);
char *_strcpy(char *dest, char *src);
char **_strtok(char *line, char *deli);
char *_strchr(char *src, char j);
unsigned int _strspn(char *stng, char *string);
int str_len(char *c);
int _strcmp(char *string1, char *string2);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _strncmp(char *string1, char *string2, size_t n);

#endif
