#include "shell.h"

/**
 * main - The starting point of the program
 * @argc: The count of command-line arguments
 * @argv: An array holding the command-line arguments
 * @env: The environment variables
 *
 * Returns: Always returns 0, indicating successful execution
 */
int main(int argc, char **argv, char **env)
{
	char *user_input = NULL;
	size_t input_buffer_size = 0;
	ssize_t chars_read;
	char **input_tokens;
	int token_count;
	char *command_path;
	char *command_name;
	int cycle_count = 1;
	(void)argc;

	command_name = (char *)malloc(sizeof(char) * SIZE_TOKEN);
	command_path = (char *)malloc(SIZE_LINE + 1);

    
	if (command_path == NULL || command_name == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}

  
	printf("$ ");

	while ((chars_read = getline(&user_input, &input_buffer_size, stdin)) != -1) {

		if (chars_read > 0 && user_input[chars_read - 1] == '\n')
		{
			user_input[chars_read - 1] = '\0';
		}

		if (handle_exit_command(user_input))
		{
			exit(0);
		}

		input_tokens = process_input(user_input, &token_count, command_name);

		if (token_count >= 0)
		{
			command_path = find_executable(env, input_tokens[0], command_name);
		}

		if (command_path)
		{
			execute_command(command_path, input_tokens, argv[0]);
		}
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
			argv[0], cycle_count, input_tokens[0]);
		}

		cycle_count++;
		printf("$ ");
	}

	free(command_path);
	free(input_tokens);

	return (0);
}
