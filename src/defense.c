/*
** EPITECH PROJECT, 2019
** defense
** File description:
** yes
*/

#include "my.h"

void rec(int sig, siginfo_t *t, void *context)
{
    (void)t;
    (void)context;
    if (sig == SIGUSR1) {
        my_printf(" hit\n");
        game = 1;
    }
    if (sig == SIGUSR2) {
        my_printf(" missed\n");
        game = 2;
    }
}

void get_defense_answer(navy_t *navy)
{
    int lett = navy->buff[0] - 'A';
    int dig = navy->buff[1] - '0' - 1;
    struct sigaction answ;

    sigemptyset(&answ.sa_mask);
    answ.sa_flags = SA_SIGINFO;
    answ.sa_sigaction = rec;
    sigaction(SIGUSR1, &answ, NULL);
    sigaction(SIGUSR2, &answ, NULL);
    pause();
    if (game == 1)
        navy->tab2[dig][lett] = 'x';
    if (game == 2)
        navy->tab2[dig][lett] = 'o';
}