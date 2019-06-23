/*
** EPITECH PROJECT, 2019
** signal game
** File description:
** yes
*/

#include "my.h"

void test_attack(navy_t *navy)
{
    int lett = navy->buff[0] - 'A';
    int dig = navy->buff[1] - '0' - 1;

    if (navy->tab1[dig][lett] >= '2' && navy->tab1[dig][lett] <= '5') {
        navy->tab1[dig][lett] = 'x';
        my_printf(":  hit\n");
        usleep(50000);
        kill(navy->oponent, SIGUSR1);
    }
    else if (navy->tab1[dig][lett] == 'x') {
        my_printf(": missed\n");
        navy->tab1[dig][lett] = 'x';
        usleep(5000);
        kill(navy->oponent, SIGUSR2);
    }
    else {
        is_missed(navy, dig, lett);
    }
}

void send_info(navy_t *navy, char *send)
{
    int lett = send[0] - 'A' + 1;
    int dig = send[1] - '0';

    for (int i = 0; i <= lett - 1; i++) {
        kill(navy->oponent, SIGUSR1);
        usleep(500);
    }
    kill(navy->oponent, SIGUSR2);
    usleep(5000);
    for (int i = 0; i <= dig - 1; i++) {
        kill(navy->oponent, SIGUSR1);
        usleep(500);
    }
    kill(navy->oponent, SIGUSR2);
    usleep(5000);
}

void hdl(int sig, siginfo_t *t, void *context)
{
    static int i = 0;

    (void)t;
    (void)context;
    if (sig == SIGUSR1)
        i++;
    if (sig == SIGUSR2) {
        game = i;
        i = 0;
    }
}

void receive_attack(navy_t *navy)
{
    my_printf("\nwaiting for enemy's attack...\n");
    navy->buff[0] = wait_info() + 'A' - 1;
    navy->buff[1] = wait_info() + '0';
    navy->buff[2] = '\0';
    my_printf("%s", navy->buff);
    test_attack(navy);
}

int wait_info(void)
{
    struct sigaction test;

    sigemptyset(&test.sa_mask);
    test.sa_flags = SA_SIGINFO;
    test.sa_sigaction = hdl;
    sigaction(SIGUSR1, &test, NULL);
    sigaction(SIGUSR2, &test, NULL);
    game = 0;
    while (1) {
        if (game != 0)
            return (game);
    }
}