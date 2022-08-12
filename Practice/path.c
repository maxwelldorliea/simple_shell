#include <stdlib.h>
#include <string.h>
#include <stdio.h>


extern char **environ;


/**
 * _getenv - return a env and its values
 * @target: env to be return
 * Return: env and values on Success, NULL on Failure
 */

char *_getenv(char *target)
{
	int i = 0;

	while (environ[i]) 
	{
		if (strncmp(environ[i], target, strlen(target)) == 0)
			return (environ[i]);
		i++;
	}

	return (NULL);
}

/**
 * path_to_arr - return array of tokenize values of a env
 * @path: env to be tokenize
 * @arr: array to store tokenize values of the env
 * Return: array of tokenize value
 */

char **path_to_arr(char *path, char **arr)
{
	char *ptr = strtok(path, ": PATH=");
	int i = 0;

	while (ptr)
	{
		arr[i++] = ptr;
		ptr = strtok(NULL, ":");
	}

	arr[i] = NULL;

	return (arr);
}

int main(void)
{
	char *path = _getenv("PATH");
	int len = strlen(path);
	char **arr;
	int i = 0;

	arr = malloc(sizeof(**arr) * (len + 1));

	if (arr == NULL)
	{
		printf("Could not allocate memory");
		return (1);
	}

	arr = path_to_arr(path, arr);

	while (arr[i])

		printf("%s\n", arr[i++]);

	free(arr);

	return (0);
}
