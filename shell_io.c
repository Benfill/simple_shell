#include "shell.h"

/**
 * _eputs - Print a string to stderr.
 * @str: The string to be printed.
 */
void _eputs(char *str)
{
	if (!str)
	return ();

	while (*str)
	{
		_eputchar(*str);
		str++;
	}
}

/**
 * _eputchar - Write a character to stderr.
 * @c: The character to print.
 * Returns:
 *   On success, 1.
 *   On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
		write(2, buffer, buffer_index);
		buffer_index = 0;
	}

	if (c != BUF_FLUSH)
	{
		buffer[buffer_index++] = c;
	}

	return (1);
}

/**
 * _putfd - Write a character to the given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 * Returns:
 *   On success, 1.
 *   On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, buffer_index);
		buffer_index = 0;
	}

	if (c != BUF_FLUSH)
	{
		buffer[buffer_index++] = c;
	}

	return (1);
}

/**
 * _putsfd - Write a string to the given file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 * Returns: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
	int char_count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		char_count += _putfd(*str, fd);
		str++;
	}

	return (char_count);
}
