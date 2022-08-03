#include "shell.h"
#include <stdlib.h>
#include <string.h>



void tok_str(char *buf, char **cmd)
{
	char *ptr;
	int i = 0;

	ptr = strtok(buf, " \n");

	while (ptr)
	{
		cmd[i] = ptr;
		ptr = strtok(NULL, " \n");
		i++;
	}

	cmd[i] = NULL;

}


int checkpath(char **cmd)
{
	const char *PATH[] = {"/usr/local/bin/", "/bin/", "/sbin/", "/usr/bin/", NULL};
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

void environ(char **env)
{		
	int i = 0;

	while (env[i])
		printf("%s\n", env[i++]);
}
