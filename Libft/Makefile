# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 18:51:39 by mdriay            #+#    #+#              #
#    Updated: 2016/04/08 10:06:31 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADERS = -I /

SRC=ft_printf.c  fonct_s.c  fonct_ss.c   fonct_p.c fonct_d.c fonct_dd.c\
	fonct_c.c fonct_cc.c fonct_u.c fonct_o.c fonct_oo.c fonct_x.c\
	token.c ft_put.c  ft_putnbr.c ft_putstr.c ft_atoi.c ft_strchr.c\
	ft_nbrlen.c print_percent.c fonct_error.c tools_octal.c tools_d.c\
	tools_dd.c tools_oo.c tools_p.c tools_ss.c tools_cc.c tools_x.c\
	ft_memset.c ft_bzero.c ft_memcpy.c  ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_nbrlen.c ft_words.c \
	ft_isneg.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
	ft_lstiter.c ft_lstmap.c \
	ft_btree_create_node.c ft_btree_apply_prefix.c \
	ft_btree_apply_infix.c ft_btree_apply_suffix.c \
	get_next_line.c\

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

aclean: all clean

re: fclean all
