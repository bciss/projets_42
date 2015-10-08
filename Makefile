# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/21 18:46:26 by bciss             #+#    #+#              #
#    Updated: 2015/10/08 17:36:47 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = lecture.c wolf3d.c display.c ft_print.c ft_verif.c\
	  ft_move.c ft_singleton_pos.c ft_singleton_dir.c ft_singleton_plane.c\
	  ft_singleton_map.c

NAME = wolf3d

FLAGS = -lmlx -framework OpenGL -framework AppKit -Llibft -lft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -I libft/ -c $(SRC)
	gcc -o $(NAME) -I $(INCDIR) $(SRC:.c=.o) $(FLAGS)


clean:
	@echo "cleaning ..."
	@rm -rf $(SRC:.c=.o)
	@echo "done !"


fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: clean all


f: re
	./$(NAME)

norm:
	norminette $(SRC) wolf3d.h

.PHONY: re clean fclean all
