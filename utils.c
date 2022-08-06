#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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


int add_path(char **cmd)
{
	const char *PATH[] = {"/usr/local/bin/ls", "/bin/", "/sbin/", "/usr/bin/", NULL};
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

void print_env(char **env)
{		
	int i = 0;

	while (env[i])
		printf("%s\n", env[i++]);
}
