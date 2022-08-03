#ifndef  SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void print_prompt(void);
void tok_str(char *, char **);
int checkpath(char **cmd);
void environ(char **);

#endif
