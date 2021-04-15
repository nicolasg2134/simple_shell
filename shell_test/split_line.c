#include "shell.h"
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
