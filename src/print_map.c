/*
** EPITECH PROJECT, 2019
** print_map
** File description:
** for navy
*/

#include "my.h"

void space(int j)
{
    if (j != 7)
        my_printf(" ");
}

void putmap(navy_t *navy)
{
    my_print_map(navy->tab1, "my positions:");
    my_print_map(navy->tab2, "enemy's positions:");
}

void print_one(char dig)
{
    if (dig >= '2' && dig <= '5')
        my_printf("\033[33;01m%c\033[00m", dig);
    else if (dig == 'x')
        my_printf("\033[32m%c\033[00m", dig);
    else
        my_printf("\033[34;01m%c\033[00m", dig);
}

void my_print_map(char **map, char *which)
{
    int i = 0;
    int z = 1;
    int j = 0;

    my_printf("\n%s\n", which);
    my_printf("\033[31m |A B C D E F G H\033[00m\n");
    my_printf("\033[33;01m-+---------------\033[00m\n");
    while (i < 8) {
        j = 0;
        my_printf("\033[31m%d|\033[00m", z);
        while (j < 8) {
            print_one(map[i][j]);
            space(j);
            j++;
        }
        my_printf("\n");
        i++;
        z++;
    }
}