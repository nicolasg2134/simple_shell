#include "shell.h"
/**
 *  Main - entry point.
 *  @argc: Argument count.
 *  @argv: Argument vector.
 *  return: status code
 */
int main(int argc, char **argv)
{
  sh_loop();
  return EXIT_SUCCESS;
}