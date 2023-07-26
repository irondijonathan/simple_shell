#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * get_args - Function that gets the arguments of the shell
 * @inp_line: Pointer to string variable to hold string line
 * @args: Pointer to an array of strings
 *
 * Return: Positive integer or -1 when it fails to read a line
 */

int get_args(char **inp_line, char ***args)
{
	int read_line = 0;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		write(1, '($) ', 4);
	read_line = getline(inp_line, &len, stdin);
	if (read_line != -1)
		*args = tokenize_string(*line, " ");
	free(*inp_line);
	*inp_line = NULL;
	return (read_line);
}

/**
 * _print_error - Function that prints the error message
 * @shell: Shell
 * @cmd: command
 *
 * Return: void
 */

void _print_error(char *shell, char *cmd)
{
	write(1, shell, _strlen(shell));
	write(1, ": 1:", 5);
	write(1, cmd, _strlen(cmd));
	write(1, ": Not Found\n", 12);
}

/**
 * _exec_command - Function that executes commands
 * @args: show the arguments
 *
 * Return: Integer(success)
 */

int _exec_command(char *args[])
{
	int result = 0;

	result = execve(args[0], args, environ);
	return (result);
}

/**
 * free_string_array - Function that frees an array of strings
 * from a heap
 * @args: An array of strings
 *
 * Return: void
 */

void free_string_array(char *args[])
{
	int i = 0;

	while (args != NULL && args[i] != NULL)
	{
		free(args[i++]);
		args[i - 1] = NULL;
	}
	if (args != NULL)
	{
		free(args[i]);
		args[i] = NULL;
	}
	if (args != NULL)
	{
		free(args);
		args = NULL;
	}
}

/**
 * main - Entry point
 * @argc: Number of cmd line arguments
 * @argv: cmd line arguments
 *
 * Return: 0(success), 1(error)
 */

int main(int argc, char *argv[])
{
	pid_t child_pid;
	int cmd_status = 0, read = 0;
	char *inp_line = NULL, **args = NULL;

	(void) argv;
	(void) argc;
	while (1)
	{
		read = get_args(&inp_line, &args);
		if (read == -1 || _strcmp(args[0], "exit"))
		{
			break;
		}
		else if (_strcmp(args[0], "env"))
		{
			print_environ();
		}
		else
		{
			if (access(args[0], F_OK) == -1)
			{

			}
			else
			{
				child_pid = fork();
				if (child_pid == -1)
					return (1);
				if (child_pid == 0)
					_exec_command(args);
				else
					wait(&cmd_status);
			}
		}
		free_string_array(args);
	}
	if (read != -1)
		free_string_array(args);
	return (0);
}
