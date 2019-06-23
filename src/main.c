/*
** EPITECH PROJECT, 2019
** main navy
** File description:
** navy
*/

#include "my.h"
int game;

static void handle(int sig, siginfo_t *si, void *context)
{
    (void)sig;
    (void)context;
    game = si->si_pid;
    my_printf("\nenemy connected\n");
}

int get_help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("     ./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("     first_player_pid:  only for the second player.");
        my_printf("  pid of the ");
        my_printf("first player.\n");
        my_printf("     navy_positions:  file representing the positions");
        my_printf(" of the ships.\n");
        return (1);
    }
    return (0);
}

void *send_signal(navy_t *navy, int en_pid)
{
    navy->oponent = en_pid;
    navy->player = getpid();
    my_printf("my_pid: %d\n", navy->player);
    if (kill(en_pid, SIGUSR2) == -1)
        return (NULL);
    my_printf("successfully connected\n");
    return (navy);
}

void rec_signal(navy_t *navy)
{
    struct sigaction sign;

    sigemptyset(&sign.sa_mask);
    sign.sa_flags = SA_SIGINFO;
    sign.sa_sigaction = &handle;
    sigaction(SIGUSR1, &sign, NULL);
    sigaction(SIGUSR2, &sign, NULL);
    navy->player = getpid();
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", navy->player);
    pause();
    navy->oponent = game;
}

int main(int ac, char **av)
{
    navy_t *navy;
    if (ac > 3 || ac == 0)
        return (84);
    navy = malloc(sizeof(navy_t));
    if (ac == 2) {
        if (get_help(av) == 1)
            return (0);
        if (prep_map(ac, av, navy) == 84)
            return (84);
        rec_signal(navy);
        if (begin_game(navy, ac) == 84)
            return (84);
    }
    if (ac == 3) {
        send_signal(navy, my_atoi(av[1]));
        prep_map(ac, av, navy);
        if (begin_game(navy, ac) == 84)
            return (84);
    }
}