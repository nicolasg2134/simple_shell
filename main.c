#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  Function Declarations for builtin shell commands:
 */
<<<<<<< HEAD
int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);

/*
  List of builtin commands and functions.
=======
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
<<<<<<< HEAD
  &sh_cd,
  &sh_help,
  &sh_exit
};

int sh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

=======
  &lsh_cd,
  &lsh_help,
  &lsh_exit
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/

>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
/**
   @brief Bultin command: change directory.
   @param args List of args.  args[0] is "cd".  args[1] is the directory.
   @return Always returns 1, to continue executing.
 */
<<<<<<< HEAD
int sh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "sh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("sh");
=======
int lsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    }
  }
  return 1;
}

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
<<<<<<< HEAD
int sh_help(char **args)
{
  int i;
  printf("Holberton Project Chort 14 Montevideo SH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < sh_num_builtins(); i++) {
=======
int lsh_help(char **args)
{
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
<<<<<<< HEAD
int sh_exit(char **args)
=======
int lsh_exit(char **args)
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
{
  return 0;
}

/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */
<<<<<<< HEAD
int sh_launch(char **args)
=======
int lsh_launch(char **args)
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
<<<<<<< HEAD
    if (execvp(args[0], args) == -1) {
      perror("sh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("sh");
  } else {
=======
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */
<<<<<<< HEAD
int sh_execute(char **args)
=======
int lsh_execute(char **args)
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
{
  int i;

  if (args[0] == NULL) {
<<<<<<< HEAD
    return 1;
  }

  for (i = 0; i < sh_num_builtins(); i++) {
=======
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

<<<<<<< HEAD
  return sh_launch(args);
=======
  return lsh_launch(args);
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
}

/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
<<<<<<< HEAD
char *sh_read_line(void)
{
#ifdef SH_USE_STD_GETLINE
  char *line = NULL;
  ssize_t bufsize = 0;
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else  {
      perror("sh: getline\n");
=======
char *lsh_read_line(void)
{
#ifdef LSH_USE_STD_GETLINE
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We received an EOF
    } else  {
      perror("lsh: getline\n");
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
      exit(EXIT_FAILURE);
    }
  }
  return line;
#else
<<<<<<< HEAD
#define SH_RL_BUFSIZE 1024
  int bufsize = SH_RL_BUFSIZE;
=======
#define LSH_RL_BUFSIZE 1024
  int bufsize = LSH_RL_BUFSIZE;
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
<<<<<<< HEAD
    fprintf(stderr, "sh: allocation error\n");
=======
    fprintf(stderr, "lsh: allocation error\n");
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    exit(EXIT_FAILURE);
  }

  while (1) {
<<<<<<< HEAD
=======
    // Read a character
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
    c = getchar();

    if (c == EOF) {
      exit(EXIT_SUCCESS);
    } else if (c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
<<<<<<< HEAD
    if (position >= bufsize) {
      bufsize += SH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "sh: allocation error\n");
=======

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
        exit(EXIT_FAILURE);
      }
    }
  }
#endif
}

<<<<<<< HEAD
#define SH_TOK_BUFSIZE 64
#define SH_TOK_DELIM " \t\r\n\a"
=======
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */
<<<<<<< HEAD
char **sh_split_line(char *line)
{
  int bufsize = SH_TOK_BUFSIZE, position = 0;
=======
char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens) {
<<<<<<< HEAD
    fprintf(stderr, "sh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, SH_TOK_DELIM);
=======
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
<<<<<<< HEAD
      bufsize += SH_TOK_BUFSIZE;
=======
      bufsize += LSH_TOK_BUFSIZE;
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
<<<<<<< HEAD
        fprintf(stderr, "sh: allocation error\n");
=======
        fprintf(stderr, "lsh: allocation error\n");
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
        exit(EXIT_FAILURE);
      }
    }

<<<<<<< HEAD
    token = strtok(NULL, SH_TOK_DELIM);
=======
    token = strtok(NULL, LSH_TOK_DELIM);
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
  }
  tokens[position] = NULL;
  return tokens;
}

/**
   @brief Loop getting input and executing it.
 */
<<<<<<< HEAD
void sh_loop(void)
=======
void lsh_loop(void)
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
{
  char *line;
  char **args;
  int status;

  do {
<<<<<<< HEAD
    printf("#cisfun$ ");
    line = sh_read_line();
    args = sh_split_line(line);
    status = sh_execute(args);
=======
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);
>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a

    free(line);
    free(args);
  } while (status);
}

/**
   @brief Main entry point.
   @param argc Argument count.
   @param argv Argument vector.
   @return status code
 */
int main(int argc, char **argv)
{
<<<<<<< HEAD
 
  sh_loop();
=======
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

>>>>>>> f39005fdbe0062f45e5307ca17de210df290c09a
  return EXIT_SUCCESS;
}