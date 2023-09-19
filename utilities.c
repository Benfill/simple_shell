#include "shell.h"

/**
 * str_to_int - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted integer if successful, -1 on error.
 */
int str_to_int(char *s)
{
	int i = 0;
	long int result = 0;
	int is_negative = 0;

	if (*s == '+')
		s++;  /* Skip leading '+' if present */

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
			return (-1);  /* Overflow */
		}
		else
		{
			return (-1);  /* Invalid character */
		}
	}

	return ((int)result);
}

/**
 * print_error_message - Prints an error message.
 * @info: The parameter & return info struct.
 * @error_msg: String containing the specified error message.
 */
void print_error_message(info_t *info, char *error_msg)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(error_msg);
}

/**
 * print_integer - Prints an integer to the specified file descriptor.
 * @input: The integer to print.
 * @fd: The file descriptor to write to.
 * Return: Number of characters printed.
 */
int print_integer(int input, int fd)
{
	int (*output_char)(char) = _putchar;
	int i, count = 0;
	unsigned int absolute_value, current;

	if (fd == STDERR_FILENO)
	output_char = _eputchar;

	if (input < 0)
	{
		absolute_value = -input;
		output_char('-');
		count++;
	}
	else
	{
		absolute_value = input;
	}

	current = absolute_value;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absolute_value / i)
		{
			output_char('0' + current / i);
			count++;
		}
		current %= i;
	}

	output_char('0' + current);
	count++;

	return (count);
}

/**
 * convert_to_string - Converts a number to a string.
 * @num: The number to convert.
 * @base: The base for conversion.
 * @flags: Argument flags.
 *
 * Return: The resulting string.
 */
char *convert_to_string(long int num, int base, int flags)
{
	static char *digits;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = digits[n % base];
		n /= base;

	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0' in a string.
 * @buf: Address of the string to modify.
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
