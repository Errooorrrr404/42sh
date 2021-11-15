/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_word.c
*/

int check_word(char const *str, char const *com)
{
    for (int i = 0; str[i] != '\0' || com[i] != '\0'; i++)
        if (str[i] != com[i])
            return 0;
    return 1;
}