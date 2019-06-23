/*
** EPITECH PROJECT, 2019
** remplissage map
** File description:
** navy
*/

#include "my.h"

int left_right(navy_t *navy, char *file, int e, int f)
{
    int j = 1;
    int b = file[3] - '0' - 1;

    if (e > f)
        j = -1;
    while (e != f) {
        if (navy->tab1[b][e] != '.') {
            return (84);
        }
        navy->tab1[b][e] = file[0];
        e += j;
    }
    navy->tab1[b][e] = file[0];
    return (0);
}

int top_bottom(navy_t *navy, char *file, int e)
{
    int b = file[3] - '0' - 1;
    int c = file[6] - '0';
    int j = 1;

    if (b > c)
        j = -1;
    while (b != c) {
        if (navy->tab1[b][e] != '.') {
            return (84);
        }
        navy->tab1[b][e] = file[0];
        b += j;
    }
    return (0);
}

int fill_tab(navy_t *navy)
{
    int i = 0;
    int e;
    int f;

    for (int a = 0; a < 4; a++) {
        e = navy->tab_check[a][2] - '0' - 17;
        f = navy->tab_check[a][5] - '0' - 17;
        if (e == f)
            i = top_bottom(navy, navy->tab_check[a], e);
        else
            i = left_right(navy, navy->tab_check[a], e, f);
        if (i == 84)
            return (84);
    }
    return (0);
}