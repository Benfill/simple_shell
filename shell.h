#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SHELL_SIZE_TOKEN 90
#define SHELL_SIZE_LINE 1024
#define SHELL_SIZE_PATH 1024

char **SHELL_process_input(char *line, int *token_count, char *exe_name);
void SHELL_execute_command(char *exe_path, char **tokens, char *shell_name);
int SHELL_handle_exit_command(char *line);
char *SHELL_get_PATH(char **env);
char *SHELL_find_executable(char **env, char *file_path, char *exe_name);

#endif
