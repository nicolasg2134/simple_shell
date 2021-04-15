#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* prompt.c */
void prompt(int sig);

/* strtoken.c */
unsigned int find_command_length(char *s);
char **array_from_strtok(char *str);

/* help.c */
char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlen_const(const char *name);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);

/* _env.c */
unsigned int find_semis(char *path);
char **store_env_variables(char *fir_com, char **environ);
char *_getenv(const char *name, char **environ);
char *_strncpycmd(char *dest, char *src, char *command, int n, int c);
void print_env(char **environ);

/*free_dptr.c */
void free_all_double_ptr(char **d_ptr);

/*error.c*/
void build_error_message(char **av, char *fir_com, int count);
int _puterror(char c);
void end_of_file(char *buffer);
void fork_fail(void);

/*child_pro.c */
void command_is_null(char *buffer);
void exit_out(char *buffer, char **commands);
void env_out(char *buffer, char **commands, char **env);
void parent_free_buff_commands(char *buffer, char **commands);
void c_path(char **commands, char *buffer, char **env, char **argv, int count);
#endif /* HOLBERTON_H */