#include "shell.h"
/**
 * @brief builtins_func
 * @char: pointer arg char
 * @return sizeof builtin_str, char *, struct
 */

int sh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

/**
 *  @brief sh_cd
 * 
 * @param args  
 * @return Always 1 
 */

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
/**
 * @brief sh_help
 * 
 * @param args 
 * @return Always 1
 */

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

/**
 * @brief sh_exit 
 * 
 * @param args 
 * @return always 0 
 */

int sh_exit(char **args)
{
	return 0;
}