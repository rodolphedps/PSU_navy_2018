/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** navy
*/

#ifndef NAVY_H
#define NAVY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

extern int game;

typedef struct navy_s {
    char *input;
    size_t size;
    char buff[3];
    pid_t player;
    pid_t oponent;
    char **tab_check;
    char **tab1;
    char **tab2;
}              navy_t;

//includes for tab
char **malloc_tab(int a, int b);
int check(char **tab);
char **make_board();
int fill_tab(navy_t *navy);
void putmap(navy_t *navy);
void my_print_map(char **map, char *which);
int prep_map(int ac, char **av, navy_t *navy);
int start(navy_t *navy, int ac, char **av);

//includes for beginning of the game
int begin_game(navy_t *navy, int ac);
int pars_input(navy_t *navy);

//includes for signal during the game
void send_info(navy_t *navy, char *send);
int wait_info(void);
void hdl(int sig, siginfo_t *t, void *context);
void receive_attack(navy_t *navy);
void test_attack(navy_t *navy);
void get_defense_answer(navy_t *navy);
void rec(int sig, siginfo_t *t, void *context);
void is_missed(navy_t *navy, int dig, int lett);

//includes for win lose
int losing(navy_t *navy);
int check_x(navy_t *navy, int x);
int x_there(navy_t *navy, int i, int j, int x);

//lib includes
int my_strlen(char *str);
int my_printf(char *s, ...);
int my_atoi(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif