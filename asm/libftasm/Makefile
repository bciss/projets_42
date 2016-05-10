#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 05:20:11 by esaminad          #+#    #+#              #
#    Updated: 2015/06/11 01:01:56 by bciss            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libfts.a

SRC	=   ft_isalnum.s\
	    ft_isdigit.s\
	    ft_isalpha.s\
	    ft_isascii.s\
	    ft_isprint.s\
	    ft_toupper.s\
	    ft_tolower.s\
	    ft_bzero.s\
	    ft_strcat.s\
	    ft_memcpy.s\
	    ft_memset.s\
	    ft_puts.s\
	    ft_strdup.s\
	    ft_strlen.s\
	    ft_cat.s\
		ft_islower.s\
		ft_isupper.s\
		ft_isspace.s\
		ft_strncat.s\
		ft_memalloc.s

HDR	= libfta.h

OBJ	= $(SRC:.s=.o)

CC	= clang
CFLAGS	= -Wall -Werror -Wextra

CC_ASM	= ~/.brew/Cellar/nasm/2.11.08/bin/nasm -f macho64

.PHONY: all clean fclean re intro

all: $(NAME)

%.o: %.s
	@printf "\033[1;36m compiling... \e[33m%-41s\e[0m" "$<"
	@$(CC_ASM) -o $@ $<
	@printf "\033[1;32m[✔]\033[0m\n"

$(NAME): intro $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

intro:

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

test: re
	@$(CC) main.c -o test -L ./ -lfts
	./test

re: fclean all
