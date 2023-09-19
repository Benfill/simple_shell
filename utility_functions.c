#include "shell.h"

/**
 * Check if the shell is running in interactive mode.
 * @param info - A pointer to the info_t structure.
 * @return 1 if in interactive mode, 0 otherwise.
 */
int isInteractiveMode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Check if a character is a delimiter.
 * @param c - The character to check.
 * @param delim - The delimiter string.
 * @return 1 if it's a delimiter, 0 otherwise.
 */
int is_delimiter(char c, const char *delim)
{
	while (*delim)
	{
		if (*delim == c)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

/**
 * Check if a character is alphabetic.
 * @param c - The character to check.
 * @return 1 if it's alphabetic, 0 otherwise.
 */
int isAlphabetic(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * Convert a string to an integer.
 * @param s - The string to be converted.
 * @return 0 if no numbers in the string, the converted number otherwise.
 */
int stringToInteger(const char *s)
{
	int i = 0, sign = 1, flag = 0, output = 0;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
		i++;
	}

	if (sign == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}

	return (output);
}
