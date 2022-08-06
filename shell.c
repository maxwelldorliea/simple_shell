#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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
			print_env(env);
			free(buf);
			buf = NULL;
			continue;
		}

		parser(buf, cmd);
		
		if (cmd[0] == NULL)
		{
			free(buf);
			buf = NULL;
			continue;
		}

		if (strcmp(cmd[0], "exit") == 0 && get_arr_len(cmd) == 2)
		{
			int status = atoi(cmd[1]);
			free(buf);
			buf = NULL;
			exit(status);
		}

		add_path(cmd);

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
