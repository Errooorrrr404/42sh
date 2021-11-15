/*
** EPITECH PROJECT, 2019
** Reverse Rotate String
** File description:
** utils.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb <= 9 && nb >= 0)
        my_putchar(nb + '0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
        if (nb <= 9 && nb >= 0)
            my_put_nbr(nb);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + '0');
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

void my_putstr(char *str)
{
    write(1, str, (size_t) my_strlen(str));
}

void my_error(char *str)
{
    write(2, str, (size_t) my_strlen(str));
}