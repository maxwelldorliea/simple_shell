#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * exit_arg - handle exit with argument
 * @cmd: array of command enter
 * @argv: array of argument
 * @buf: command enter
 * Return: int
 */

int exit_arg(char **cmd, char **argv, char *buf)
{
	int status = _atoi(cmd[1]);

	if (status < 0 || (status == 0 && cmd[1][0] != '0'))
	{
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": 1: exit: Illegal number: ", 27);
		write(2, cmd[1], _strlen(cmd[1]));
		write(2, "\n", 1);
		free(buf);
		exit(2);
	}

	free(buf);
	exit(status);
}

char *_getline()
{
	int i, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	return (buff);
}

/**
 * read_cmd - reads the commands from the terminal till newline char
 * @buf: buffer to read the commands into
 * @buflen: length of the buffer
 * Return: Nothing
 */

char *read_cmd(void)
{
	char *n;

	n = _getline();

	if (n == NULL)
	{
		free(n);
		exit(0);
	}

	return (n);
}

/**
 * REPL - read eval print loop
 * @buf: command to be executed
 * @buflen: length of the command
 * @cmd : array to store command and argument
 * @argv: argument values
 * @env: array of environment variable
 * Return: 0 on success
 */


int REPL(char *buf, char **cmd, char **argv, char **env)
{

	do {
		if (isatty(STDIN_FILENO))
			print_prompt();
		buf = read_cmd();
		if (buf[0] == '\0' || _strcmp(buf, "\n") == 0)
		{
			continue;
		}
		if (_strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			return (0);
		}
		if (_strcmp(buf, "env\n") == 0)
		{
			print_env(env);
			continue;
		}
		parser(buf, cmd);
		if (cmd[0] == NULL)
			continue;
		if (_strcmp(cmd[0], "exit") == 0 && get_arr_len(cmd) == 2)
		{
			exit_arg(cmd, argv, buf);
		}
		execute_cmd(cmd, argv, env);
	} while (1);
	return (0);
}
