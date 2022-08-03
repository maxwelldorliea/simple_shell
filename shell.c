#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char **argv, char **env)
{
	char *buf = NULL;
	size_t buflen = 0;
	char *cmd[20];

	do
	{
		print_prompt();

		if (getline(&buf, &buflen, stdin) == -1)
		{
			if (feof(stdin))
			{
				free(buf);
				buf = NULL;
				exit(EXIT_SUCCESS);
			}

			perror("Error occurred");
			free(buf);
			buf = NULL;
			exit(EXIT_FAILURE);
		}

		if (buf[0] == '\0' || strcmp(buf, "\n") == 0)
		{
			free(buf);
			buf = NULL;
			continue;
		}

		if (strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			buf = NULL;
			exit(EXIT_SUCCESS);
		}

		if (strcmp(buf, "env\n") == 0)
		{
			environ(env);
			free(buf);
			buf = NULL;
			continue;
		}

		tok_str(buf, cmd);
		checkpath(cmd);

		if (fork() == 0)
		{

			execve(cmd[0], cmd, env);
			printf("%s: No such file or directory\n", argv[0]);
			exit(EXIT_SUCCESS);
		}

		else
		{
			wait(NULL);
			free(buf);
			buf = NULL;
		}

	} while (1);

	exit(EXIT_SUCCESS);
}
