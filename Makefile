##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	$(wildcard src/*.c)

HEADER_NAME	=	f_garbage_collector.h
HEADER_PATH	=	./includes/

OBJ			=	$(SRC:.c=.o)

NAME		=	libf_gc.a

CFLAGS		?=	-I$(HEADER_PATH) -Wall -Wextra -Werror

DEBUG_FLAGS	=	-ggdb

$(NAME):	all

all:		compile

%.o:		%.c
	gcc $(CPPFLAGS) -c $(CFLAGS) $< -o $@

compile:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(HEADER_PATH)$(HEADER_NAME) $(HEADER_NAME)

debug:
	@make compile --no-print-directory CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"

clean:
	rm -f *~
	rm -f \#*\#
	rm -f $(OBJ)
	rm -f $(HEADER_NAME)

fclean:		clean
	rm -f $(NAME)

re:			fclean	compile

re-debug:	fclean debug