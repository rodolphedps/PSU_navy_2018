/*
** EPITECH PROJECT, 2019
** misse
** File description:
** yes
*/

#include "my.h"

void is_missed(navy_t *navy, int dig, int lett)
{
    my_printf(":  missed\n");
    navy->tab1[dig][lett] = 'o';
    usleep(50000);
    kill(navy->oponent, SIGUSR2);
}