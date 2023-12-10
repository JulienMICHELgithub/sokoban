/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

void realy_stuck(int y, int x, struct_t *w)
{
    if (w->str[y][x] == 'X') {
        w->count_x++;
        w->next_to = 0;
        if ((w->str[y - 1][x] == '#' || w->str[y - 1][x] == 'X'))
            w->next_to++;
        if (w->str[y + 1] != NULL && (w->str[y + 1][x] == '#'
                || w->str[y + 1][x] == 'X'))
            w->next_to++;
        if (x > 0 && (w->str[y][x - 1] == '#' || w->str[y][x - 1] == 'X'))
            w->next_to++;
        if (w->str[y][x + 1] != '\0' && (w->str[y][x + 1] == '#'
                || w->str[y][x + 1] == 'X'))
            w->next_to++;
        if (w->next_to >= 2)
            w->stuck++;
    }
}

int im_stuck(struct_t *word)
{
    int x = 0;
    int y = 0;
    int next_to = 0;
    int stuck = 0;
    int count_x = 0;

    word->next_to = next_to;
    word->stuck = stuck;
    word->count_x = count_x;
    for (y = 0; word->str[y] != NULL; y++) {
        for (x = 0; word->str[y][x] != '\0'; x++) {
            realy_stuck(y, x, word);
        }
    }
    if (word->count_x > 0 && word->count_x == word->stuck) {
        return 1;
    } else {
        return 0;
    }
}

bool chec_win(struct_t *word)
{
    int x = 0;
    int y = 0;

    for (y = 0; word->str[y] != NULL; y++) {
        x = 0;
        while (word->str[y][x] != '\0' &&
            !(word->str[y][x] == 'X' && word->prim[y][x] != 'O')) {
            x++;
        }
        if (word->str[y][x] != '\0')
            return FALSE;
    }
    return TRUE;
}
