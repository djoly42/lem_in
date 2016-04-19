# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 13:13:31 by djoly             #+#    #+#              #
#    Updated: 2016/04/14 13:04:08 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = libft/

LIB = Libft/libft.a

SRC = main.c debug.c ft_booleen.c init.c init2.c init3.c path_init.c \
	path_find.c check_start_end.c \
	register.c resolve.c tabfonction.c tabfonction2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C Libft/ fclean
	make -C Libft/

$(NAME): $(LIB) $(OBJ)
	make -C visu-hex/ fclean
	make -C visu-hex/
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C Libft/ fclean
	make -C visu-hex/ fclean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
