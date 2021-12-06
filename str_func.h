#ifndef STR_FUNC_H
#define STR_FUNC_H

char *_strstr(char *haystack, char *needle);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **_strsplit(char *str, int c);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /*STR_FUNC_H*/

