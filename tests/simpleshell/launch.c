#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **argv, char **tokens)
{
	pid_t child_pid;
	char *executable;
	static int comcount;

	executable = NULL;
	comcount = 0;

	child_pid = fork();
	comcount++;
	if (child_pid == -1)
	{
		printf("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			executable = checkpath(tokens[0]); /*return NULL on fail*/
			if (execve(executable, tokens, NULL) == -1)
			{
				printerror(argv, comcount, tokens);
				exit(0);
			}

		}
	}
	else
	{
			child_pid = wait(NULL);
	}
	printf("%i", comcount);
	return (1);
}
