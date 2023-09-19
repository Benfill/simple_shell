#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int isInteractiveMode(info_t *info);
int is_delimiter(char c, const char *delim);
int isAlphabetic(int c);
int stringToInteger(const char *s);

int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int str_to_int(char *s);
void print_error_message(info_t *info, char *error_msg);
int print_integer(int input, int fd);
char *convert_to_string(long int num, int base, int flags);
void remove_comments(char *buf);

char *_strncpy(char *dest, const char *src, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
char *_strchr(const char *s, int c);

#endif
