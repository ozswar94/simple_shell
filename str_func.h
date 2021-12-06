#ifndef STR_FUNC_H
#define STR_FUNC_H

char *_strstr(char *haystack, char *needle);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **_strsplit(char *str, int c);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void clean_dptr(char **ptr);

#endif /*STR_FUNC_H*/

