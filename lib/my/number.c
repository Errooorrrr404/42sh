/*
** EPITECH PROJECT, 2018
** Created by Alexis Leclercq (alexis1.leclerq@epitech.eu)
** File description:
** number.c
*/

int number(char const *str)
{
    int	i = 0;
    int	n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            return n /= 10;
        n = n + str[i] - 48;
        n = n * 10;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}