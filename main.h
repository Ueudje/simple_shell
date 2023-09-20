#ifndef MAIN_H
#define MAIN_H

/* Include standard library header files */
#include <stdio.h>      /* Standard Input/Output functions (used in getline) */
#include <unistd.h>     /* System calls for write and execve function */
#include <sys/types.h>  /* Data types like pid_t and size_t */
#include <sys/wait.h>   /* Process wait function */
#include <stdlib.h>     /* Standard library functions like exit and free */
#include <string.h>     /* String manipulation functions like strlen strtok */
#include <sys/stat.h>   /* System call for stat function */
#include <signal.h>     /* Signal handling functions */

/* Define a structure to hold data for our shell */
/**
 * struct input_output_shell - Defines a structure to hold data for our shell.
 * @stored: A string to store user input.
 * @array: An array of strings to hold arguments.
 * @name_shell: A string that stores the name of the executed file.
 * @env: A double pointer to environment variables.
 * @count: An unsigned integer representing the number of processes.
 * @_exit: The exit status of the last executed command.
 */
typedef struct input_output_shell
{
	char *stored;
	char **array;
	const char *name_shell;
	char **env;
	size_t count;
	int _exit;
} shell;

/* Function prototypes */
/* - In file function.c - */
void free_array(shell *ptr);
void divide_arg(shell *ptr);
void handler(int signal);
void dte_space(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* - In file function_1.c - */
int print(const char *str);
void get_command(shell *ptr);
void fork_execve(shell *ptr);
void init_struct(shell *p, const char *name, char **env);
char *_getenv(char *name, char **env);

/* - In file handle_string.c - */
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);

/* - In file handle_string_1.c - */
int _strcmp(char *s1, char *s2);
int _atoi(char *str);

/* - In file handle_err.c - */
void print_error(shell *ptr, char *err);
void print_number(size_t n);
void putchar_err(char c);

/* - In handle_path.c - */
void check_path(shell *ptr);

/* - In handle_exit_env.c - */
int handle_exit_env(shell *ptr);

#endif /* main.h */
