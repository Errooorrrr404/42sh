##
## EPITECH PROJECT, 2019
## PSU_42sh_2018
## File description:
## Makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCNAMES	=  builtin/clean_and_lauch.c \
	  builtin/env.c \
	  builtin/history.c \
	  builtin/exec_builtin.c \
	  builtin/my_cd.c \
	  builtin/change_pwds.c \
	  builtin/unsetenv.c \
	  builtin/setenv.c \
	  builtin/my_echo.c \
	  builtin/alias.c \
	  builtin/assign_alias.c \
	  builtin/add_alias.c \
	  builtin/pipe.c \
	  builtin/check_status_check_nb.c \
	  builtin/print_alias.c \
	  init/init.c \
	  init/set_path.c \
	  main.c \
	  separator/and_or.c \
	  separator/break_and_or.c \
	  separator/check_separator.c \
	  separator/left_redir.c \
	  separator/right_redir.c \
	  separator/dleft_redir.c \
	  tools/check.c \
	  tools/free_sh.c \
	  tools/path_tools.c \
	  tools/path_tools_next.c \
	  tools/array_tools.c \
	  tools/my_array.c \
	  tools/my_clean_str.c \
	  tools/my_prompt.c \
	  tools/link_symbols.c \
	  builtin/utilities_pipe.c \
	  builtin/check.c \

SRCS = $(addprefix src/, $(SRCNAMES))

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/ -I ./lib/my/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) -L lib/ -lmy

clean:
	make clean -C lib/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C lib/
	$(RM) $(NAME)

debug:	CFLAGS += -g
debug:	re

re: fclean all

.PHONY: all clean fclean re debug