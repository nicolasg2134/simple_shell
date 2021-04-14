#include "shell.h"
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