#include "shell.h"
/**
   @brief Builtin command print help.
   @param args List of args.
   @return Always returns 1.
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