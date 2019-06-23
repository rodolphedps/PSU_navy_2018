/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get number
*/

int my_getnbr(char const *str)
{
    int res = 0;
    int i = 0;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res);
}