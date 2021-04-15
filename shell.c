#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
  	"exit"
};

int (*builtin_func[]) (char **) = {
	&sh_cd,
	&sh_help,
  	&sh_exit
};

int sh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

int sh_cd(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "sh: expected argument to \"cd\"\n");
	} else {
		if (chdir(args[1]) != 0) {
			perror("sh");
		}
	}
	return 1;
}


int sh_help(char **args)
{
	int i;
	printf("Holberton School SH project Cohort 14, Montevideo - NG & JP\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < sh_num_builtins(); i++) {
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return 1;
}


int sh_exit(char **args)
{
	return 0;
}

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

	return 1;
}

/**
 * sh_execute - entry point.
 * @char: character type
 * @args: charged arguments
 * return: always 1, sh_lunch
 */
int sh_execute(char **args)
{
	int i;

	if (args[0] == NULL) {
    
		return 1;
	}

	for (i = 0; i < sh_num_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}

	return sh_launch(args);
}

/**
 *  sh_read_line - entry point.
 *  
 *  return: line
 */

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
			exit(EXIT_FAILURE);
		}
	}
	return line;
#else
#define SH_RL_BUFSIZE 1024
	int bufsize = SH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {

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


		if (position >= bufsize) {
			bufsize += SH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "sh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}

#define SH_TOK_BUFSIZE 64
#define SH_TOK_DELIM " \t\r\n\a"

/**
 * sh_split_line - entry point.
 * @char: character type
 * @line: pointer to line
 * return: tokens line
 */

char **sh_split_line(char *line)
{
	int bufsize = SH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens) {
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, SH_TOK_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += SH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				free(tokens_backup);
				fprintf(stderr, "sh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, SH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

/**
 *  sh_loop - entry point.
 *  
 *  return: status code
 */
void sh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = sh_read_line();
		args = sh_split_line(line);
		status = sh_execute(args);

		free(line);
		free(args);
	} while (status);
}

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
