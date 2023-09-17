#include "holberton.h"

/**
* stringcharacter - specifies the location of a character in a string
* All rights reserved or owned by noiseworkin
* @c: identify the character location
* @s: string being checked
* Return: re-signal to the first occurrence of the character
* Or a NULL operation if the character is not detected
*/
char *stringcharacter(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

/**
* stringlength - retrieve length of string
* All rights reserved or owned by noiseworking
* @s: string traversal
* Return: length of string return of string traversal
*/
int stringlength(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* stringcompares - it does a comparison between two strings
* All rights reserved or owned by noiseworking
* @s1: paired with s2;
* @s2: paired with s1;
* Return: Retrieve the difference between the strings
*/
int stringcompares(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	output = (*(s1 + i) - *(s2 + i));

	return (output);
}

/**
* stringdupicates - repeated string
* All rights reserved or owned by noiseworking
* @s: redundant
* Return: string recursive guide
*/
char *stringdupicates(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = stringlength(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* stringncmp - performs an operation comparing two strings of up to n bytes
* All rights reserved or owned by noiseworking
* @s1: paired with s2
* @s2: paired with s1
* @n: number of bytes
* Return: Retrieve the difference between s1 and also s2
*/
int stringncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
