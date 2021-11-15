/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_clean_str
*/

#include "my.h"
#include "src.h"

int count_space(int i, char *str)
{
    int check = 0;

    if (i == 0)
        check = 1;
    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i++;
    if (check == 0)
        i--;
    return (i);
}

int check_end(char *str)
{
    int size = my_strlen(str);

    for (; str[size] == ' ' || str[size] == '\n' || str[size] == '\0'; size--);
    return (size);
}

char *clean_str(char *str)
{
    int j = 0;
    int end = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t' || str[i] == 34 || str[i] == 39 || str[i] == '\\'
        || str[i] == '`')
            str[i] = ' ';
    }
    end = check_end(str);
    for (int i = 0; i <= end; i++) {
        if (str[i] == ' ')
            i = count_space(i, str);
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';
    return (str);
}