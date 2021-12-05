#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include "str_func.h"
#include "printf.h"

typedef struct built_in_s
{
    char command[100];
    void (*built_in)(void);
} built_in_t;

extern char **environ;

int simple_shell(void);
void print_env(void);
char *_getenv(char *name);
int check_built_in(char *command);
char *search_path(char *command);

#endif /*SHELL_*/
