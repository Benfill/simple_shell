#include "shell.h"

/**
 * _myexit - Exits the shell with a given exit status.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Exits with the specified exit status.
 */
int _myexit(info_t *info)
{
	int exit_status = 0;

	if (info->argv[1])
	{
		int exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			exit_status = 1;
		}
		else
		{
			info->err_num = exit_check;
			exit_status = -2;
		}
	}
	else
	{
		info->err_num = -1;
		exit_status = -2;
	}

	return exit_status;
}

/**
 * _mycd - Changes the current directory of the process.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always returns 0.
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		_puts("TODO: >>getcwd failure emsg here<<\n");
	}

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
		{
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		}
		else
		{
			chdir_ret = chdir(dir);
		}
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return 1;
		}

		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
	}

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');

	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return 0;
}

/**
 * _myhelp - Displays help information.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Always returns 0.
 */
int _myhelp(info_t *info)
{
	char **arg_array = info->argv;

	_puts("Help call works. Function not yet implemented.\n");

	if (0)
	{
		_puts(*arg_array); /* Temporary unused workaround */
	}

	return 0;
}
