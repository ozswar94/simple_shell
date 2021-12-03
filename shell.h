#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>

int simple_shell(void);
int prompt(char *line, size_t size);
void print_env(void);
char *_getenv(char *name);

#endif /*SHELL_*/
