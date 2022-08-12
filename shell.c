#include "shell.h"
#include "str.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Simple Shell
 * @argc: length of array of argument values
 * @argv: array of argument values
 * @env: environment variable
 * Return: 0 on success
 */


int main(int argc, char **argv, char **env)
{
	char *buf = NULL;
	size_t buflen = 0;
	int n;

	(void)argc;

	do {
		print_prompt();
		n = getline(&buf, &buflen, stdin);

		if (n == -1)
		{
			free(buf);
			exit(1);
		}


		if (fork() == 0)
		{
			char *cmd[2], *str;

			str = strtok(buf, "\n");
			cmd[0] = str;
			cmd[1] = NULL;
			execve(cmd[0], cmd, env);
			_printf(argv[0]);
			_printf(": No such file or directory\n");
			free(buf);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	} while (1);

	return (0);
}
