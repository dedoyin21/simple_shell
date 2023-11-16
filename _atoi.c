#include "shell.h"

/**
 * interactive -function return true if shell is interactive mode
 * @info: structure address
 * Return: 1 if is successful, 0 if is null. 
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->rfd <= 2);
}

/**
 * _delim -function checks if character is a delimeter
 * @c: the char argument to check
 * @delim: the delimeter string
 * Return: 1
 */

int _delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha -funtion checks for alphabetic character
 *@c: The character argument to input
 *Return: 1 
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi -function converts a string to an integer
 *@s: the string argument to be converted
 *Return: 0 
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

