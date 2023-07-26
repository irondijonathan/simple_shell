#include <stdlib.h>
#include "shell.h"
#include <stdio.h>
/**
 * free_shell_data - this frees the data of the shell from the heap
 * @shell_data: this is the pointer to the shell data
 *
 * Return: return void
 */
void free_shell_data(shell_t *shell_data)
{
	int i = 0;

	if (shell_data->inp_line != NULL)
	{
		printf("Free line: %s\n", shell_data->inp_line);
		free(shell_data->inp_line);
	}
	if (shell_data->args != NULL)
	{
		while (shell_data->args[i] != NULL)
		{
			printf("free: %s\n", shell_data->args[i]);
			if (shell_data->args[i] != NULL)
				free(shell_data->args[i++]);
		}
		printf("free: %s\n", shell_data->args[i]);
		free(shell_data->args[i]);
		free(shell_data->args);
	}
}
