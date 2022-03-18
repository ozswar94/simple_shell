#ifndef ERROR_H
#define ERROR_H

int error_exit(char *name, char **command, int counter);
int error_not_found(char *name, char **command, int counter);
int error_help(char *name, char **command, int counter);

#endif
