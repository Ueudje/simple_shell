#include "main.h"

/**
 * main - Entry point for a UNIX command line interpreter.
 *
 * Description: This function creates a simple shell that reads and executes
 * user commands. It provides a command prompt, parses user input, handles
 * built-in commands like exit, and executes external commands.
 *
 * @argc: The number of command-line arguments (unused).
 * @argv: An array of command-line arguments (unused).
 * @env: An array of environment variables.
 *
 * Return: 0 on success, otherwise returns an exit status code.
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	shell sh;

	init_struct(&sh, argv[0], env);
	signal(SIGINT, handler);
	while (++sh.count)
	{
		if (isatty(STDIN_FILENO))
			print("#cisfun$ ");
		get_command(&sh);

		if (_strlen(sh.stored))
		{
			divide_arg(&sh);

			if (!handle_exit_env(&sh))
			{
				check_path(&sh);

				if (!((sh.array[0][0] == '.' || sh.array[0][0] == '/') &&
							access(sh.array[0], F_OK) == 0))
				{
					print_error(&sh, "not found\n");
					sh._exit = 127;
				}
				else if (access(sh.array[0], X_OK) != 0)
				{
					print_error(&sh, "permission denied\n");
					sh._exit = 126;
				}
				else
					fork_execve(&sh);
			}

			free_array(&sh);
		}

		free(sh.stored);
	}

	return (sh._exit);
}
