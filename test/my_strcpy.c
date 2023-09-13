#include "shell.h"

/**
 * my_strcpy - Copy a string from source to destination.
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 * Return: Pointer to the destination buffer.
 */
char *my_strcpy(char *destination, const char *source)
{	int source_length = 0;
	int i;

	while (source[source_length] != '\0')
	{
		source_length++;
	}

	for ( i = 0; i <= source_length; i++)
	{
		destination[i] = source[i];
	}

	return (destination);
}
