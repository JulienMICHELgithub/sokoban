/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_bsq
*/

#include "../include/include.h"

static int count_words(char const *str)
{
    int size = 0;
    int i = 0;

    while (str[i]) {
        while (str[i] == '\n' || str[i] == '\t')
            i++;
        if (!str[i])
            break;
        while (str[i] && str[i] != '\n' && str[i] != '\t')
            i++;
        size++;
    }
    return size;
}

static char *get_word(const char *str, int *n)
{
    int j = 0;
    char *cpy = 0;

    while (str[j] && str[j] != '\n' && str[j] != '\t')
        j++;
    cpy = malloc(sizeof(char) * (j + 1));
    cpy[j] = '\0';
    for (int i = 0; str[i] && i < j; ++i)
        cpy[i] = str[i];
    *n += j;
    return cpy;
}

char **my_str_to_word_array(char const *str)
{
    int size = count_words(str);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int k = 0;

    tab[size] = NULL;
    for (int i = 0; i < size; i++) {
        while (str[k] == '\n' || str[k] == '\t')
            k++;
        tab[i] = get_word(str + k, &k);
    }
    return (tab);
}
