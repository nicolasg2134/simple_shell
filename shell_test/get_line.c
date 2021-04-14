#include "shell.h"
#define SH_RL_BUFSIZE 1024
/**
 *  void - entry point.
 *  
 *  return: status code
 */

char *sh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0;

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else  {
      perror("readline");
      exit(EXIT_FAILURE);
    }
  }

  return line;
}