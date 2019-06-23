/*
** EPITECH PROJECT, 2019
** test
** File description:
** navy
*/

#include "my.h"
#include <criterion/criterion.h>

Test(file_not_ok, is_file_incorect)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;
    navy_t *navy = malloc(sizeof(navy_t));

    av[0] = "./navy";
    av[1] = "pos2";
    cr_assert(prep_map(ac, av, navy) == 84);
}

Test(file_ok, is_file_correct)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;
    navy_t *navy = malloc(sizeof(navy_t));

    av[0] = "./navy";
    av[1] = "pos1";
    cr_assert(prep_map(ac, av, navy) == 0);
}

Test(is_start_ok, check_file)
{
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;
    navy_t *navy = malloc(sizeof(navy_t));

    av[0] = "./navy";
    av[1] = "pos1";
    navy->tab_check = malloc_tab(4, 5);
    cr_assert(start(navy, ac, av) == 0);
}

Test(is_tab_checked, check_if_tab_full_ok)
{
    navy_t *navy = malloc(sizeof(navy_t));
    char **av = malloc(sizeof(char*) * 2);
    int ac = 2;

    av[0] = "./navy";
    av[1] = "pos1";
    navy->tab_check = malloc_tab(4, 5);
    start(navy, ac, av);
    cr_assert(check(navy->tab_check) == 0);
}

Test(is_tab_filled, filled_tab_or_not)
{
    navy_t *navy = malloc(sizeof(navy_t));
    char **av = malloc(sizeof(char *) * 2);
    int ac = 2;

    av[0] = "./navy";
    av[1] = "pos1";
    navy->tab_check = malloc_tab(4, 5);
    start(navy, ac, av);
    check(navy->tab_check);
    navy->tab1 = make_board();
    navy->tab2 = make_board();
    cr_assert(fill_tab(navy) == 0);
}