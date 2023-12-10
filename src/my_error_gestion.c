/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

void my_description(int ac)
{
    write(1, "USAGE\n", 6);
    write(1, "     ./my_sokoban map\n", 22);
    write(1, "DESCRIPTION\n", 12);
    write(1, "     map file representing the warehouse map", 44);
    write(1, ", containing ‘#’ for walls,\n", 32);
    write(1, "         ‘P’ for the player, ‘X’ for boxes and ‘O", 59);
    write(1, "’ for storage locations.\n", 27);
}

int error_start(int ac, int fd, char **av, struct stat *sb)
{
    if (ac != 2)
        return 84;
    if (my_strncmp(av[1], "-h", 2) == 0) {
        my_description(ac);
        exit(0);
    }
    if (fd == -1)
        return 84;
    if (stat(av[1], sb) == -1) {
        close(fd);
        return 84;
    }
    return 0;
}

int error_malloc(char *buff, struct stat *sb)
{
    if (!buff)
        return 84;
    return 0;
}
