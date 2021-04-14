#include "shell.h"

/**
 * builtin_str - entry point.
 * @cd: character type
 * @help: pointer to line
 * return: sizeof builtin_str
 */
 
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

/**
 * builtin_func - entry point.
 * 
 * @char: character type 
 */

int (*builtin_func[]) (char **) = {
  &sh_cd,
  &sh_help,
  &sh_exit
};

int sh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/**
 * sh_cd - entry point.
 * @char: character type
 * @args: pointer to line
 * return: Always 1
 */

int sh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "sh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

/**
 * sh_help - entry point.
 * @char: character type
 * @args: pointer to line
 * return: Always 1
 */

int sh_help(char **args)
{
  int i;
  printf("Holberton School SH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < sh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

/**
 * sh_exit - entry point.
 * @char: character type
 * @args: pointer to line
 * return: Always 0 Succes
 */

int sh_exit(char **args)
{
  return 0;
}