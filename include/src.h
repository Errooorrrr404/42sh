/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** src
*/

#ifndef SRC_H_
#define SRC_H_

#include "struct.h"

void my_pipe(shell_t *, commands_t *commands);
int check_com_pipe_exist(shell_t *);
// main.c
int main(int , __attribute__((unused)) char **, char **);
int loop(int , shell_t *, char **);
int count_caract(char *);

// - - - builtin - - -

// add_alias.c
void print_alias_in_file(shell_t *);
int my_alias(shell_t *);

// alias.c
void launch_alias(shell_t *, char *);
void loop_comp(shell_t *, char *, char **);
void alias_loop(shell_t *, char *);
int exec_alias(shell_t *);
int check_alias(shell_t *);

// assign_alias.c
char *assign_left(char *, char *);
char *assign_right(char *, char *);

// change_pwds.c
void change_dir(shell_t *);

// clean_and_lauch.c
int is_num(char *);
int my_exit(shell_t *);
int check_commands(shell_t *, int, commands_t *);
int clean_and_launch(shell_t *, int, commands_t *);
int check_which_command(shell_t *, commands_t *, int);

// env.c
char **create_env(char **);
void display_env(shell_t *);

// exec_builtin.c
int local_exec(shell_t *);
int sys_exec(shell_t *);
int exec_command(shell_t *);

// history.c
void put_in_history(shell_t *, history_t *);

// my_cd.c
void return_back_folder(shell_t *, char *);
void exist_or_not(int, int, shell_t *, char *);
void cd_option2(shell_t *, char **, int);
void cd_option(shell_t *);
void my_cd(shell_t *);

// my_echo.c
void print_word(shell_t *, int);
void print_echo_multi(shell_t *);
void my_echo(shell_t *);

// setenv.c
int setenv_formatter(char **);
char *add_line_env2(char **, int, int, char *);
char *add_line_env(char **);
void setenv_option_exist(shell_t *);
void setenv_command(shell_t *);

// unsetenv.c
int find_env_var(char *, char **);
void do_unsetenv(shell_t *, int);
void my_unsetenv(shell_t *);

// pipe.c
void launch_pipe(shell_t *, char *input);
void prep_pipe(shell_t *);
int count_pipe(char *str);
char *str_until_pipe(char *input);

// print_alias.c
void print_alias(int fd, char **array);

// - - - init - - -

// init.c
char *my_put_home(char **);
char **init_path(char **);
int init_hist(history_t *);
int init_struct(shell_t *, char **);
commands_t *init_commands(void);

// set_path.c
char *assign_line_path(char *, char *);
int check(char *, char *);
int get_env_2(char *, char **);
char *my_set_exec(char **);

// - - - separator - - -

// and_or.c
void and_or_or(shell_t *, commands_t *);
void clean_for_and_or(shell_t *);

// break_and_or.c
int chose_end(int , char );
int break_and_or(char *, char *, int, int);

// check_separator.c
int have_separator_in_sep(shell_t *, commands_t *);
int have_separator(shell_t *, int, commands_t *);

// right_redir.c
int do_right_redir(shell_t *, commands_t *commands, int is_double);
int get_new_input(shell_t *, char);

// left_redir.c
int do_left_redir(shell_t *, commands_t *commands, int is_double);

// - - - tools - - -

// array_tools.c
char *fill_str(char *, char **, char *);
char *array_to_str(char **, char *);
int _array(char **);
void print_array(char **);
void *free_array(char **);

// check.c
int variable_exist(char **, char *);
int compare_args(char *, char *);
int check_alphanum(char *);

// free_sh.c
void free_sh(shell_t *);
void free_commands(commands_t *);

// link_symbols.c
int link_symbol3(char *, int);
int link_symbol2(char *, int);
int link_symbol(char *);

// my_array.c
int count_nb_delimiter(char *, char);
int count_size(char *, char);
char **my_malloc_array(char **, char *, char, int);
char **fill_new_array(char **, char *, char);
char **str_to_array(char *, char);

// my_clean_str.c
int count_space(int, char *);
int check_end(char *);
char *clean_str(char *);

// my_prompt.c
void print_prompt(shell_t *, char *, char *);
void my_print_dir(shell_t *, char **);

// path_tools_next.c
int check_is_exist(char **, char *);
int path_exist(shell_t *);

// path_tools.c
char *clean_path(char *);
char *recup_new_path(char **);
int assign_new_path(shell_t *);
int assign_path(shell_t *);

// redirs
int check_redir(shell_t *);
char *get_second_input(shell_t *);
int double_left_redir(shell_t *, commands_t *commands);

// check_status_check_nb.c
void check_status_check_nb(int nb, shell_t *);

#endif /* !SRC_H_ */
