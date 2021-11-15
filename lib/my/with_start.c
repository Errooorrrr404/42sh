/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** with_start.c
*/

int my_strlen_st(char const *str, int pos)
{
    int i = pos;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strcpy_st(char *dest, char const *src, int pos)
{
    int i = 0;
    int col = pos;

    for (; src[col] != '\0'; col++) {
        dest[i] = src[col];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}