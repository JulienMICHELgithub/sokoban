/*
** EPITECH PROJECT, 2023
** my
** File description:
** lib_my
*/

#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdbool.h>

void my_putchar(const char c);
int my_putstr(char *str);
void my_putstr_dir(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
char *my_concat(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
int my_puterror(char *str);
char *my_strdup(char *str);
int my_strncmp(char *s1, char *s2, int n);
