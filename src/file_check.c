/*
** EPITECH PROJECT, 2019
** every check for file
** File description:
** navy project
*/

#include "my.h"

int check_boat_count(char letter)
{
    int z = 0;

    if (letter == '2')
        z += 1;
    if (letter == '3')
        z += 10;
    if (letter == '4')
        z += 100;
    if (letter == '5')
        z += 1000;
    return (z);
}

int check_boat(char **str)
{
    int i = 0;
    int z = 0;

    while (i < 4) {
        z += check_boat_count(str[i][0]);
        i++;
    }
    if (z == 1111)
        return (0);
    else
        return (84);
}

int check_alpha(char a, char b, char c)
{
    int x = a - '0';
    int y = b - '0' - 17;
    int z = c - '0' - 17;

    if (x - 1 == y - z || x - 1 == z - y)
        return (1);
    else
        return (84);
}

int check_lenght(char *str, char a, char b, char c)
{
    int x = a - '0';
    int y = b - '0';
    int z = c - '0';

    if ((x - 1 == y - z || x - 1 == z - y) && str[2] == str[5])
        return (1);
    else if (y == z && check_alpha(str[0], str[2], str[5]) == 1)
        return (1);
    else
        return (84);
}

int check(char **tab)
{
    int i = 0;
    int tmp = 0;

    if (check_boat(tab) == 84)
        return (84);
    while (tmp < 4) {
        if (check_lenght(tab[i], tab[i][0], tab[i][3], tab[i][6]) == 84) {
            return (84);
        }
        tmp++;
        i++;
    }
    return (0);
}