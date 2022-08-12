#include "shell.h"
#include <string.h>


/**
 * _strncmp - compare the n bit of string A with B, return 1 if s1 > s2,
 * 0 when s1 =s2, -1 s1 < s2
 *
 * @s1: char pointer
 * @s2: char pointer
 * @n: number of char to check
 * Return: int
 */


int _strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 && (*s1 == *s2) && n)
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * _getenv - return a env and its values
 * @target: env to be return
 * @environ: array of env
 * Return: env and values on Success, NULL on Failure
 */

char *_getenv(char *target, char **environ)
{
	char *path;
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(environ[i], target, _strlen(target)) == 0)
		{
			path = _strdup(environ[i]);
			return (path);
		}
		i++;
	}

	return (NULL);
}
