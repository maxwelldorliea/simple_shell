#include "shell.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * read_cmd - reads the commands from the terminal till newline char
 * @buf: buffer to read the commands into
 * @buflen: length of the buffer
 * Return: Nothing
 */

void read_cmd(char **buf, size_t *buflen)
{
	int n;

	n = getline(buf, buflen, stdin);

	if (n == -1)
	{
		free(*buf);
		exit(0);
	}
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


int REPL(char *buf, size_t buflen, char **cmd, char **argv, char **env)
{

	do {
		print_prompt();
		read_cmd(&buf, &buflen);

		if (buf[0] == '\0' || _strcmp(buf, "\n") == 0)
		{
			free(buf);
			continue;
		}

		if (_strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			return (0);
		}
		if (_strcmp(buf, "env\n") == 0)
		{
			free(buf);
			print_env(env);
			continue;
		}
		parser(buf, cmd);
		if (cmd[0] == NULL)
			continue;

		if (_strcmp(cmd[0], "exit") == 0 && get_arr_len(cmd) == 2)
		{
			int status = _atoi(cmd[1]);

			free(buf);
			exit(status);
		}
		execute_cmd(cmd, argv, env);
	} while (1);
	return (0);
}
