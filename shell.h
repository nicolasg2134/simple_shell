#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdarg.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
/**
 * struct builtins - builtin command and functions
 * @comand: comand name
 * @p: pointer to builtin functions
 *
 * Description: struct for builtin functions
 */
typedef struct typebuiltin
{
	char *comand;
	int (*p)(char **args, char **env);
} built_t;

/* Function Declarations for builtin shell commands */
int shell_env(char **args, char **env);
int shell_exit(char **args, char **env);
int shell_built(char **args, char **env);

void free_array(char **array);
void free_string(int, const unsigned int n, ...);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name, char **env);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strcompare(const char *s1, const char *s2);
char **strtoken(char *str);
void get_word(char **array, char *str);
int count_words(char *str);
void copy_string(int end, char *s, char **word_box);
char *concatenate_strings(char *s1, char *s2);
void check_path(char **string, char **env);
void signal_manipulation(int signal);
void e_exit(char *, int status);
int prompt(char **ptr);
int convert_to_int(char *s);
#endif
