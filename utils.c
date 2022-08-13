#include "shell.h"
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

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

	ptr = _strtok(buf, " \a\r\t\n");

	while (ptr)
	{
		if (ptr[0] == '#')
		{
			cmd[i] = NULL;
			return;
		}
		cmd[i] = ptr;
		ptr = _strtok(NULL, " \n");
		i++;
	}

	cmd[i] = NULL;

}

/**
 * add_path - add the rightful path to the command enter by the user
 * @cmd: command enter by user
 * @env: array of env
 * Return: 0 on success and 1 on failure
 */

int add_path(char **cmd, char **env)
{
	char *patharr, *s, *path = _getenv("PATH", env);
	struct stat st;

	patharr = _strtok(path, ":");

	while (patharr)
	{
		s = build_path(*cmd, patharr);
		if (stat(s, &st) == 0)
		{
			*cmd = _strdup(s);
			free(s);
			free(path);
			return (0);
		}
		patharr = _strtok(NULL, ":");
		free(s);
	}


	free(path);
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
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
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
	int status, n = 1;

	if (cmd[0][0] != '/' && cmd[0][0] != '.')
	{
		n = add_path(&(cmd[0]), env);
		if (n == -1)
		{

			_printf(argv[0]);
			_printf(": No such file or directory\n");
			return;
		}
	}

	if (fork() == 0)
	{
		execve(cmd[0], cmd, env);
		_printf(argv[0]);
		_printf(": No such file or directory\n");
		free(cmd[0]);
		exit(0);

	}

	else
	{
		wait(&status);
		if (n == 1 || n == -1)
			return;
		free(cmd[0]);
	}

}
