/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#pragma once

#include "../lib/my/libmy.h"

#define SUCCESS 0
#define FAILURE 1
#define ERROR 84
#define TRUE 1
#define FALSE 0

typedef struct struct_s {
    char **prim;
    char **str;
    int x;
    int y;
    int next_to;
    int stuck;
    int count_x;
}struct_t;

char **my_str_to_word_array(char const *str);
int my_sokoban(struct_t *word);
int moove(struct_t *word);
int handle_movement(struct_t *word, int ch);
void my_fiind(int y, int x, struct_t *word);
void key_up(struct_t *word);
void key_down(struct_t *word);
void key_left(struct_t *word);
void key_right(struct_t *word);
void my_condition_key_up(struct_t *w);
void my_condition_key_down(struct_t *w);
void my_condition_key_left(struct_t *w);
void my_condition_key_right(struct_t *w);
int error_start(int ac, int fd, char **av, struct stat *sb);
int error_malloc(char *buff, struct stat *sb);
bool chec_win(struct_t *word);
void reset_sokoban(struct_t *word);
int im_stuck(struct_t *word);
