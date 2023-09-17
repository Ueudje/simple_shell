#include "holberton.h"

/**
* userimmediate - extract $ to tell user what program is....
* All rights reserved or owned by noiseworking
* Stamps the prompt if the shell is in interactive mode
* ON initializing to take their input
* Return: no return
*/
void userimmediate(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
