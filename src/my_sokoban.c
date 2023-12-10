/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

int handle_movement(struct_t *word, int ch)
{
    switch (ch) {
        case ' ':
            reset_sokoban(word);
            break;
        case KEY_UP:
            key_up(word);
        break;
        case KEY_DOWN:
            key_down(word);
        break;
        case KEY_LEFT:
            key_left(word);
        break;
        case KEY_RIGHT:
            key_right(word);
        break;
        default:
            break;
    }
    return ch;
}

int moove(struct_t *word)
{
    int ch = 'm';

    while (ch != 27) {
        ch = getch();
        if (word->prim[word->y][word->x] == 'O')
            word->str[word->y][word->x] = ' ';
        mvprintw(word->y, word->x, " ");
        handle_movement(word, ch);
        mvprintw(word->y, word->x, "P");
        refresh();
        if (chec_win(word)) {
            refresh();
            return 0;
        }
        if (im_stuck(word) == 1)
            break;
    }
    return 1;
}

void my_fiind(int y, int x, struct_t *word)
{
    if (word->str[y][x] == 'P') {
        word->x = x;
        word->y = y;
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        word->str[y][x] = ' ';
        for (int i = 0; word->str[i]; i++)
            printw("%s\n", word->str[i]);
        mvprintw(word->y, word->x, "P");
        moove(word);
        endwin();
    }
}

int my_sokoban(struct_t *word)
{
    int y = 0;
    int x = 0;

    for (y = 0; word->str[y] != NULL; y++) {
        for (x = 0; word->str[y][x] != '\0'; x++) {
            my_fiind(y, x, word);
        }
    }
    return 0;
}
