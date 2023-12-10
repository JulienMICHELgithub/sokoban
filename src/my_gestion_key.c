/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

static void reset(struct_t *word, int y, int x)
{
    word->str[y][x] = word->prim[y][x];
    if (word->str[y][x] == 'P') {
        word->y = y;
        word->x = x;
    }
}

void reset_sokoban(struct_t *word)
{
    int y = 0;
    int x = 0;

    clear();
    for (y = 0; word->str[y] != NULL; y++) {
        for (x = 0; word->str[y][x] != '\0'; x++) {
            reset(word, y, x);
        }
    }
    for (int i = 0; word->str[i]; i++)
        printw("%s\n", word->str[i]);
}

void key_up(struct_t *word)
{
    if (word->y - 2 >= 0 &&
        word->str[word->y - 1][word->x] != '#') {
        my_condition_key_up(word);
    }
}

void key_down(struct_t *word)
{
    if (word->str[word->y + 2] != NULL &&
        word->str[word->y + 1][word->x] != '#') {
        my_condition_key_down(word);
    }
}

void key_left(struct_t *word)
{
    if (word->x - 1 >= 0 && word->str[word->y][word->x - 1] != '#') {
        my_condition_key_left(word);
    }
}

void key_right(struct_t *word)
{
    if (word->str[word->y][word->x + 2] != '\0' &&
        word->str[word->y][word->x + 1] != '#') {
        my_condition_key_right(word);
    }
}
