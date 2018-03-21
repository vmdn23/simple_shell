#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
typedef struct tokenlist_t
{
	char *token;
	struct tokenlist_t *next;
} tokenlist_t;
void looper(char**);
char *_prompt(void);
char **tokenize(char* str);
void *_realloc(void *ptr, unsigned int, unsigned int);
int launch(char **tokens);
char *checkpath(char *command);
char *appendcmd(tokenlist_t *pathlist, char *arg);
char *_strcmp(char*);
char *findpath();
char **pathsplit(char*);
int _strlen(char *);
tokenlist_t *tokentolist(tokenlist_t **head, char *token);
tokenlist_t *pathsplitlist(char *path);
void freelist(tokenlist_t *head);
int statcommand(char *exec);
#endif