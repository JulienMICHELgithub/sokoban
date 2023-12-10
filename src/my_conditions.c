/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

void my_condition_key_up(struct_t *w)
{
    char current_char = w->str[w->y - 1][w->x];
    char next_char = w->str[w->y - 2][w->x];

    if (w->str[w->y - 1][w->x] == ' ' || w->str[w->y - 1][w->y] == 'O') {
        (w->y)--;
    } else if (current_char == 'X' && (next_char == ' ' || next_char == 'O')) {
        w->str[w->y - 2][w->x] = 'X';
        w->str[w->y - 1][w->x] = ' ';
        mvprintw(w->y - 2, w->x, "X");
        (w->y)--;
    }
    if (w->prim[w->y + 1][w->x] == 'O' && w->str[w->y + 1][w->x] == ' ') {
        w->str[w->y + 1][w->x] = 'O';
        mvprintw(w->y + 1, w->x, "O");
    }
}

void my_condition_key_down(struct_t *w)
{
    char current_char = w->str[w->y + 1][w->x];
    char next_char = w->str[w->y + 2][w->x];

    if (w->str[w->y + 1][w->x] == ' ' || w->str[w->y + 1][w->x] == 'O') {
        (w->y)++;
    } else if (current_char == 'X' && (next_char == ' ' || next_char == 'O')) {
        w->str[w->y + 2][w->x] = 'X';
        w->str[w->y + 1][w->x] = ' ';
        mvprintw(w->y + 2, w->x, "X");
        (w->y)++;
    }
    if (w->prim[w->y - 1][w->x] == 'O' && w->str[w->y - 1][w->x] == ' ') {
        w->str[w->y - 1][w->x] = 'O';
        mvprintw(w->y - 1, w->x, "O");
    }
}

void my_condition_key_left(struct_t *w)
{
    char current_char = w->str[w->y][w->x - 1];
    char next_char = w->str[w->y][w->x - 2];

    if (w->str[w->y][w->x - 1] == ' ' || w->str[w->y][w->x - 1] == 'O') {
        (w->x)--;
    } else if (current_char == 'X' && (next_char == ' ' || next_char == 'O')) {
        w->str[w->y][w->x - 2] = 'X';
        w->str[w->y][w->x - 1] = ' ';
        mvprintw(w->y, w->x - 2, "X");
        (w->x)--;
    }
    if (w->prim[w->y][w->x + 1] == 'O' && w->str[w->y][w->x + 1] == ' ') {
        w->str[w->y][w->x + 1] = 'O';
        mvprintw(w->y, w->x + 1, "O");
    }
}

void my_condition_key_right(struct_t *w)
{
    char current_char = w->str[w->y][w->x + 1];
    char next_char = w->str[w->y][w->x + 2];

    if (w->str[w->y][w->x + 1] == ' ' || w->str[w->y][w->x + 1] == 'O') {
        (w->x)++;
    }else if (current_char == 'X' && (next_char == ' ' || next_char == 'O')) {
        w->str[w->y][w->x + 2] = 'X';
        w->str[w->y][w->x + 1] = ' ';
        mvprintw(w->y, w->x + 2, "X");
        (w->x)++;
    }
    if (w->prim[w->y][w->x - 1] == 'O' && w->str[w->y][w->x - 1] == ' ') {
        w->str[w->y][w->x - 1] = 'O';
        mvprintw(w->y, w->x - 1, "O");
    }
}
