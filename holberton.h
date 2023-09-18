#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <sys/types.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* Function prototypes */
void freesupplies(char **buf);

/* Structure for built-in commands */
struct builtin
{
	char *env;   /* Stores the environment command */
	char *exit;  /* Stores the exit command */
};

/* Structure to store information about program execution */
struct info
{
	int final_exit; /* Stores the final exit status */
	int ln_count;   /* Stores the line count */
};

/* Structure for program behavior flags */
struct flags
{
	bool interactive; /* Indicates if the program is in interactive mode */
};

/* Function prototypes for string manipulation */
int stringcompares(char *s1, char *s2);
int stringlength(char *s);
int stringncmp(char *s1, char *s2, int n);
char *stringdupicates(char *s);
char *stringcharacter(char *s, char c);

/* Function prototypes for main program functions */
void application(char *cp, char **cmd);
char *findlocatepath(void);

/* Function prototypes for built-in plugins */
int mytchecker(char **cmd, char *buf);
void userimmediate(void);
void signalhandler(int m);
char **distinct_symbol(char *line);
char *pathtesting(char **path, char *command);
char *pathend(char *path, char *command);
int builtihandler(char **command, char *line);
void leavecommand(char **command, char *line);
void environmentprint(void);

/* External environment variable and signal handler declaration */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#endif /* HOLBERTON_H */
