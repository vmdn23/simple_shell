#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  * Return: buffer containing command line arguments
  */
int _prompt(char **line, free_t *stash)
{
	size_t bufsize = 0;
	if (getline(line, &bufsize, stdin) == -1)
	{
		return (0);
	}
	stash->input = *line;
	return (1);
}
