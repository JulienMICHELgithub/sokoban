/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c;
*/

#include "../include/include.h"

int cant_win(const char *buff)
{
    int x = 0;
    int o = 0;
    int p = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'X')
            x++;
        if (buff[i] == 'O')
            o++;
        if (buff[i] == 'P')
            p++;
    }
    if (x < o || o < x || p != 1)
        return 84;
    return 0;
}

struct_t create_struct(char *buff)
{
    char **str = NULL;
    char **prim = NULL;
    struct_t word;

    if (cant_win(buff) == 84)
        exit(84);
    str = my_str_to_word_array(buff);
    prim = my_str_to_word_array(buff);
    word.prim = prim;
    word.str = str;
    return word;
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buff = NULL;
    struct stat sb;
    struct_t word;

    error_start(ac, fd, av, &sb);
    buff = malloc(sizeof(char) * (sb.st_size + 1));
    error_malloc(buff, &sb);
    buff[sb.st_size] = '\0';
    read(fd, buff, sb.st_size);
    word = create_struct(buff);
    my_sokoban(&word);
    free(buff);
    close(fd);
    return 0;
}
