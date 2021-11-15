/*
** EPITECH PROJECT, 2019
** Created by Alexis Leclercq (alexis1.leclerq@epitech.eu)
** File description:
** lib.h
*/

#ifndef PSU_MINISHELL2_2018_LIB_H
#define PSU_MINISHELL2_2018_LIB_H
//#define malloc(...) NULL
void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);
int my_strlen(char const *str);
int my_printf(char *str, ...);
int number(char const *str);
void my_error(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcpy_wi(char *dest, char const *src, char c);
int my_strlen_wi(char const *str, char c);
char *my_strcpy_st(char *dest, char const *src, int pos);
int my_strlen_st(char const *str, int pos);
int check_word(char const *str, char const *com);
char *clear_spaces(char *str);
void error_message(char *first_name, char *message);
char *my_strdup(char const *src);
int my_getnbr(char const *);
int size_array(char **array);
char *my_strconcat(char *str1, char *str2);

//my_array.c
char **str_to_array(char *str, char delimiter);

//catch_str.c
int catch_str_int(int i, char symbol, char *origin, char symbol2);
char *catch_str(int i, char symbol, const char * const origin, char symbol2);

//compteur_dizaine.c
int compteurdizaine(int nb);

//debug.c
void debug(char *balise);
void debug_loop(void);

//float2char.c
char *float2char(char *op, float value);

//int2char.c
char *int2char(char *str, int nb);

//is_number_letter.c
int isnumber(char c);
int isletter(char c);

//match_str.c
int match_str(char *src, char *match);

//my_f_puiss_float.c
float f_puiss_float(float nb, int puiss);

//my_f_puiss.c
int f_puiss(int nb, int puiss);

//my_putint.c
long my_putint(char *str);

//strtab_tools.c
void free_strtab(char **strtab);
char **define_strtab(int size);
char **re_malloc_strtab(char **strtab);
char **my_strtab_cpy(char **dest, char **src);

//to_strtab_char.c
char **to_strtab_char(char **tab, char *str);
char **to_strtab_int(char **tab, int nb);

//tools_1.c
void print_strtab(char **strtab);
int my_strlen_array(char **str);
char *strconcate(char *origin, char *str);

#endif