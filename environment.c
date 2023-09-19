#include "shell.h"

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	print_environment(info->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(info_t *info, const char *name)
{
	return (find_environment_variable(info->env, name));
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (set_environment_variable(info->env, info->argv[1], info->argv[2]) == 0)
		return (0);

	return (1);
}

/**
 * _myunsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure.
 */
int _myunsetenv(info_t *info)
{
	if (info->argc < 2)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (int i = 1; i < info->argc; i++)
	{
		if (unset_environment_variable(info->env, info->argv[i]) != 0)
		{
			_eputs("Failed to unset environment variable.\n");
			return (1);
		}
	}

	return (0);
}
