# 0x16. C - Simple Shell

### This repo is a reproducing shell functions, it contains:

- shell.h - headerfile for the shell functions
- str_func.h - headerfile for the string functions
- printf.h - headerfile for a printf function
- format.h - headerfile for the formats of the printf function

- comp_shell - file to execute

- man_simple_shell - manual file for simple shell

- main.c - main programe
- printf.c - main function of printf
- function.c - the functions, which print char, stirng, int, adress of pointer.(for printf)
- puts.c - prints string(for printf)
- putchar.c - the functions, which print char and string, are made up of function in this file.(for printf)
- print_number.c - the functions, which print numbers and pointer address, are made up of functions in this file.
(for printf)
- print_convert.c - prints binary, hexadeximal, ocatal number, and unsigned intnumber(for ptintf)
- convert_number - convert numbers to binary, octal, hexadecimal.(for printf)
- custom_conversion.c - print string in reverse, crypt a string in rot13, print value of not printable char
- shell.c - read the command typed to standard, and check if its built-in command or not
- prompt.c - read lines(for shell)
- strsplit.c - split the line(for shell)
- strcat.c - concataine 2 strings(for shell)
- strstr.c - search a particulary string in the specified string(for shell)
- strdup.c - duplicate string(for shell)
- strcpy.c - copy string(for shell)
- strncmp - compare two strinhgs(for shell)
- strchr - search the characters in string(for shell)
- strncpy - copy the characters of the specified number(for shell)
- env_functions.c - print environ, get the value in environ(for shell)
- strcpy.c - copy string(for shell)
- exit_sh.c - exit this shell(for shell)
- atoi.c - convert the string to the number(for shell)
- isalpha.c - check if its alphabet or not(for shell)
- isdigit - isalpha.c - check if its number or not(for shell)
- realloc.c - add allocated memory(for shell)
- built_in.c - check if it is built-in command or not(for shell)
- search_PATH.c - search in PATH environment variable(for shell)


### This project is a group project for Holberton School

Resources

    Unix shell
    Thompson shell
    man page of sh

### List of allowed functions and system calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation

#### Your shell will be compiled this way:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Testing
#### This shell should work like this in interactive mode:

(example)

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

#### But also in non-interactive mode:

(example)

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $

## Project made by:

- Anna78990 - https://github.com/Anna78990
- NeoV0id   - https://github.com/NeoV0id
- ozswar94 - https://github.com/ozswar94
