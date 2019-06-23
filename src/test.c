/*
** EPITECH PROJECT, 2019
** args
** File description:
** in tab
*/

#include "my.h"

int start(navy_t *navy, int ac, char **av)
{
    int fd = 0;
    int size = 8;
    char buff[size];
    int rd;
    int count_line = 0;

    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    if (ac == 3)
        fd = open(av[2], O_RDONLY);
    for (int i = 0; (rd = read(fd, buff, size)) > 0; i++, count_line++) {
        if (rd != 8 || count_line >= 4)
            return (84);
        buff[size] = '\0';
        my_strcpy(navy->tab_check[i], buff);
    }
    return (0);
}

int prep_map(int ac, char **av, navy_t *navy)
{
    navy->tab_check = malloc_tab(4, 5);

    if (start(navy, ac, av) == 84)
        return (84);
    if (check(navy->tab_check) == 84)
        return (84);
    navy->tab1 = make_board();
    navy->tab2 = make_board();
    if (fill_tab(navy) == 84)
        return (84);
    return (0);
}
