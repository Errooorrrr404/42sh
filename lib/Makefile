##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile libmy
##

NAME = libmy.a

SRCNAMES = clean_str.c \
	debug.c \
	my_printf.c \
	my_str_cat.c \
	my_strcpy.c \
	number.c \
	utils.c \
	with_char.c \
	with_start.c \
	check_word.c \
	catch_str.c \
	compteurdizaine.c \
	float2char.c \
	int2char.c \
	is_number_letter.c \
	match_str.c \
	my_f_puiss.c \
	my_f_puiss_float.c \
	my_putint.c \
	strtab_tools.c \
	to_strtab_char.c \
	to_strtab_int.c \
	tools_1.c \
	my_array.c \
	error_message.c \
	my_getnbr.c \
	my_strconcat.c \
	my_strdup.c

SRC = $(addprefix my/, $(SRCNAMES))

CFLAGS = -Wall -Wextra -I ./my

CP = cp

RM = rm -f

CC = gcc

AR = ar rc

REMOTE_INCLUDE = ../../../include/

INCLUDE_FILE = my.h

LIB_OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIB_OBJ)
	$(AR) $(NAME) $(LIB_OBJ)

clean:
	$(RM) $(LIB_OBJ)

fclean:	clean
	$(RM) ../$(NAME)
	$(RM) $(NAME)
	$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)

debug: CFLAGS += -g
debug: re

re:	fclean all