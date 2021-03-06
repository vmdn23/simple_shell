#include "holberton.h"
/**
 * _realloc - reallocates additional space in memory
 * @ptr: user argument string
 * @original: memory size to increase
 * @resized: enlarged memory size
 *
 * Return: original buffer, NULL, or enlarged buffer containing argument data
 */
char *_realloc(void *ptr, unsigned int original, unsigned int resized)
{
	char *newbuf;
	void *vptr;
	char *tmp;
	unsigned int i;

	if (original == resized)
		return (ptr);
	if (resized == 0 && ptr != NULL)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(resized));
	}
	tmp = ptr;
	newbuf = malloc(resized);
	if (newbuf == NULL)
		return (NULL);

	if (resized > original)
	{
		for (i = 0; i < original; i++)
			newbuf[i] = tmp[i];
	}
	free(ptr);
	free(tmp);
	vptr = newbuf;
	free(newbuf);
	return (vptr);
}
/**
  * tokenize - parses input line into tokens, stores array of tokens stash struct
  * @stash: shell program variable storage struct
  * Return: Array of each command in input string
  */
int tokenize(free_t *stash)
{
	int i;
	const char *deliminator  = " \t\r\n\a";
	int bufsize = 20;
	int newsize;
	char *newbuf;
	char *token;

	// allocate space for stash variable 'commands', an array of arg tokens
	stash->commands = malloc(sizeof(char *) * bufsize);

	// split stored input, save as stash 'token' variable
	token = _strdup(strtok(stash->input, deliminator));
	if (!token)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(stash->commands);
		return (0);
	}
	i = 0;
	while (token != NULL)
	{
		stash->commands[i] = token;
		i++;
		if (i >= bufsize)
		{
			// if input exceeds pre-allocated buffsize, reallocate extra space
			newsize = bufsize + 5;
			newbuf = _realloc(stash->commands,
					  bufsize * sizeof(char *),
					  newsize * sizeof(char *));
			if (!newbuf)
			{
				free2pointer(stash->commands);
				perror("REALLOC FAIL");
				return (0);
			}
		}
		token = _strdup(strtok(NULL, deliminator));
	}
	stash->commands[i] = '\0';
	return (1);
}
