# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 13:13:31 by djoly             #+#    #+#              #
#    Updated: 2016/04/15 13:41:36 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu_hex

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = ../libft/

LIB = ../Libft/libft.a

SRC = main.c debug.c ft_booleen.c init.c init2.c init3.c path_init.c \
	path_find.c check_start_end.c \
	register.c resolve.c tabfonction.c tabfonction2.c \
	coord.c coord2.c before_ncurses.c start_visu.c start_visu2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -lncurses -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
