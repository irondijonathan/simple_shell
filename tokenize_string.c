#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * _strlen - gets the exact length of a string or character
 * @s: the string
 *
 * Return: the exact length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s != NULL && s[len] != '\0')
		len++;
	return (len);
}

/**
 * remove_newline - deletes the new line from a string
 * @s: the string itself
 *
 * Return: return void
 */
void remove_newline(char *s)
{
	int len = _strlen(s);

	if (s != NULL && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

/**
 * _strcmp - compares two different strings against eachother
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 *
 * Return: 1 of equal 0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int i = 0;

	remove_newline(s1);
	remove_newline(s2);
	if (len1 != len2)
		return (0);
	for (i = 0; i < len1; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
/**
 * tokenize_string -this converts a string to an array based on token
 * @s: the string to be converted
 * @t: the token that will be used
 *
 * Return: return pointer to the array of strings that was converted
 */
char **tokenize_string(char *s, const char *t)
{
	int i = 0, j = 0, len = 0, tokens = 1;
	char **arr;
	char *token = NULL;

	remove_newline(s);
	while (s[i] != '\0')
	{
		if (s[i] == t[0] && s[i + 1] != t[0] && s[i + 1] != '\0')
			tokens++;
		i++;
	}
	arr = malloc(sizeof(char *) * (tokens + 1));
	if (arr == NULL)
		return (NULL);
	token = strtok(s, t);
	i = 0;
	while (token != NULL)
	{
		len = _strlen(token);
		arr[i] = malloc(sizeof(char) * (len + 1));
		for (j = 0; j <= len; j++)
			arr[i][j] = token[j];
		token = strtok(NULL, t);
		i++;
	}
	arr[tokens] = NULL;
	return (arr);
}
