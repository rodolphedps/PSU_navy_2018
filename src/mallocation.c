/*
** EPITECH PROJECT, 2019
** ye
** File description:
** malloc
*/

#include "my.h"

char **malloc_tab(int a, int b)
{
    char **tab = malloc(sizeof(char *) * a + 1);
    int i = 0;

    while (i < a) {
        tab[i] = malloc(sizeof(char) * (b + 1));
        i++;
    }
    return (tab);
}

char **make_board(void)
{
    int i = 1;
    int a = 0;
    int b = 0;
    char str[] = "........";
    char **tab = malloc(sizeof(char *) * 9);

    tab[a] = malloc(sizeof(char) * 9);
    while (a != 8) {
        while (b != 8) {
            tab[a][b] = str[b];
            b++;
        }
        b = 0;
        i++;
        a++;
        tab[a] = malloc(sizeof(char) * 9);
    }
    return (tab);
}