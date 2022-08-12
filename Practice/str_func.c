#include "str.h"

/**
 * _atoi - convert char to integer
 *
 * @s: char pointer
 *
 * Return: int
 */

int _atoi(char *s)
{
	int i;
	int res = 0;
	int sig = -1;
	int brk = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sig = sig * -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10;
			res -= (s[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
			break;
	}
	res = sig * res;
	return (res);
}


/**
 * _strcpy - copy src to dest
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: char pointer
 */


char *_strcpy(char *dest, char *src)
{
	char *ptr = src;
	int i = 0;

	while (*ptr != '\0')
	{
		dest[i] = *ptr;
		i++;
		ptr++;
	}

	dest[i] = *ptr;

	return (dest);
}


/**
 * _strcmp - compare two string, return 1 if s1 > s2, 0 when s1 =s2, -1 s1 < s2
 *
 * @s1: char pointer
 * @s2: char pointer
 *
 * Return: int
 */


int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * _strcat - Appends str to dest
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: char pointer
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);


	while (*src != '\0')
	{
		dest[len] = *src;

		len++;
		src++;
	}

	dest[len] = '\0';

	return (dest);
}

/**
 * _strlen - returns the length if a string
 *
 * @s: char
 *
 * Return: int
 */

int _strlen(char *s)
{
	int _len = 0;

	while (*s != '\0')
	{
		_len++;
		s++;
	}

	return (_len);
}
