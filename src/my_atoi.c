/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** function_atoi
*/

int my_atoi(char const *str)
{
    int i = 0;
    int nbr = 0;

    if (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        nbr = str[i] - '0';
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0'){
        nbr = nbr * 10;
        if (nbr < 0)
            nbr = nbr - (str[i] - '0');
        else
            nbr = nbr + (str[i] - '0');
        i++;
    }
    return (nbr);
}
