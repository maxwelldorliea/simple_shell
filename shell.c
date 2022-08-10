#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - run shell
 * @argc : argument length
 * @argv: array of argument value
 * @env: array of environment variable
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *buf = NULL;
	size_t buflen = 0;
	char *cmd[20];

	(void)argc;
	REPL(buf, buflen, cmd, argv, env);
	exit(EXIT_SUCCESS);
}
