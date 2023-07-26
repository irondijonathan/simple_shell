#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * print_environ - prints the content of a shell environment
 *
 * Return: return void
 */
void print_environ(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
