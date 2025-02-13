#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#define _USE_MATH_DEFINES
#include <math.h>

extern int size;
extern int *a;
extern double *result;

//void _exec(char **args);
void free_buf(char **buf);
ssize_t read_line(void);
void my_prompt(void);
char **split_line(char *line);
//int _strlen(char *s);
//char *_strcpy(char *dest, const char *src);
//char *_strcat(char *dest, char *src);
//char *_strdup(char *s);
//int _strcmp(char *s1, char *s2);
//char *_pathfinder(char *command);
//char *path_finder(char *command);
int *angles(char **args);
double *analyze(char **args);
void save_to_csv(char **args);
void plot_with_gnuplot(char **args);
int valid_double(char *str);


#endif /* SHELL_H */