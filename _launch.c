#include "shell.h"
/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments
  @return Always returns 1.
 */
int sh_launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {

    if (execvp(args[0], args) == -1) {
      perror("sh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    
    perror("sh");
  } else {
    
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return (1);
}