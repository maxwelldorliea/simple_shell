#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * parser - separate command from argumets
 * @buf: command to be separate
 * @cmd: array where commands will be store
 * Return: Nothing
 */

void parser(char *buf, char **cmd)
{
	char *ptr;
	int i = 0;

	ptr = strtok(buf, " \n");

	while (ptr)
	{
		if (strcmp(ptr, "#") == 0)
		{
			cmd[i] = NULL;
			return;
		}
		cmd[i] = ptr;
		ptr = strtok(NULL, " \n");
		i++;
	}

	cmd[i] = NULL;

}

/**
 * add_path - add the rightful path to the command enter by the user
 * @cmd: command enter by user
 * Return: 0 on success and 1 on failure
 */

int add_path(char **cmd)
{
	char *PATH[] = {"/usr/local/bin/ls", "/bin/", "/sbin/", "/usr/bin/", NULL};
	unsigned int i = 0;
	struct stat st;

	while (PATH[i])
	{
		char s[120] = "";

		strcat(s, PATH[i]);
		strcat(s, cmd[0]);

		if (stat(s, &st) == 0)
		{
			cmd[0] = s;
			return (0);
		}

		i++;
	}


	return (-1);
}

/**
 * print_env - prints each evironment variable on newline
 * @env: array of evironment varaible to be printed
 * Return: Nothing
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i])
		printf("%s\n", env[i++]);
}


/**
 * get_arr_len - return the length of string array
 * @s: array whose length is to be calculated
 * Return: Length of a array
 */

int get_arr_len(char **s)
{
	int len = 0, i = 0;

	while (s[i])
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * execute_cmd - create child proccess and execute command
 * @cmd: command to be executed
 * @argv: array of argument values
 * @env: array of environment variables
 * Return: Nothing
 */

void execute_cmd(char **cmd, char **argv, char **env)
{

	add_path(cmd);

	if (fork() == 0)
	{
		execve(cmd[0], cmd, env);
		printf("%s: No such file or directory\n", argv[0]);
		exit(EXIT_SUCCESS);
	}

	wait(NULL);
}
