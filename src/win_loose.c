/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Win or loose fction
*/

#include "my.h"

int x_there(navy_t *navy, int i, int j, int x)
{
    if (navy->tab1[i][j] == 'x')
        x++;
    return (x);
}

int check_x(navy_t *navy, int x)
{
    int i = 0;
    int j = 0;

    while (i < 8) {
        j = 0;
        while (j < 8) {
            x = x_there(navy, i, j, x);
            j++;
        }
        i++;
    }
    return (x);
}

int losing(navy_t *navy)
{
    int x = 0;

    x = check_x(navy, x);
    if (x == 14) {
        my_printf("enemy won\n");
        usleep(10000);
        kill(navy->oponent, SIGUSR2);
        return (1);
    }
    else
        return (0);
}