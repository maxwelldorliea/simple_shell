#include "shell.h"

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
	char *cmd[20];

	(void)argc;
	REPL(buf, cmd, argv, env);
	return (0);
}
