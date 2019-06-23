/*
** EPITECH PROJECT, 2019
** game
** File description:
** navy
*/

#include "my.h"
int game;

int player_one(navy_t *navy)
{
    int is_ok = 0;

    while (1) {
        is_ok = 0;
        if (read(0, navy->buff, 3) < 1)
            return (84);
        navy->buff[2] = '\0';
        if (navy->buff[0] >= 'A' && navy->buff[0] <= 'H')
            is_ok++;
        if (navy->buff[1] >= '1' && navy->buff[1] <= '8')
            is_ok++;
        if (is_ok == 2)
            return (1);
        else {
            my_printf("wrong position\n");
            my_printf("attack: ");
            my_printf("\e[3m");
        }
    }
}

int attack(navy_t *navy)
{
    my_printf("\nattack: ");
    my_printf("\e[3m");
    if (player_one(navy) == 84)
        return (84);
    my_printf("\e[0m%s: ", navy->buff);
    send_info(navy, navy->buff);
    get_defense_answer(navy);
    return (0);
}

int start_game(navy_t *navy, int ac)
{
    if (ac == 2) {
        if (attack(navy) == 84)
            return (84);
        receive_attack(navy);
    }
    if (ac == 3) {
        receive_attack(navy);
        if (attack(navy) == 84)
            return (84);
    }
    return (0);
}

int begin_game(navy_t *navy, int ac)
{
    navy->input = NULL;
    navy->size = 0;

    putmap(navy);
    while (1) {
        if (start_game(navy, ac) == 84)
            return (84);
        putmap(navy);
    }
}