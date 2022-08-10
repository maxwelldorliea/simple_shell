#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void print_prompt(void);
void parser(char *, char **);
int add_path(char **cmd);
void print_env(char **);
int REPL(char *buf, size_t buflen, char **cmd, char **argv, char **env);
int get_arr_len(char **s);
void execute_cmd(char **cmd, char **argv, char **env);

#endif
