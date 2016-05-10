#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfournie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 12:38:41 by gfournie          #+#    #+#              #
#    Updated: 2016/05/11 01:51:38 by bciss            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm

FLAG = -Wall -Werror -Wextra #-framework OpenGL -framework AppKit#

SRC = src/main.cpp src/Processor.class.cpp src/Host.class.cpp src/render.cpp src/graphic.cpp #src/mandel.cpp #src/IMonitorDisplay.cpp #src/t_env.cpp

OBJ = src/main.o src/Processor.class.o src/Host.class.o src/render.o# -lncurses -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):
	g++ -o $(NAME) $(FLAG) $(SRC) -lncurses -lmlx -framework OpenGL -framework AppKit

clean:
#	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
