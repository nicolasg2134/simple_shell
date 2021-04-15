#ifndef BUILT_H
#define BUILT_H 

int (*builtin_func[]) (char **) = {
	&sh_cd,
	&sh_help,
    &sh_exit
};
#endif