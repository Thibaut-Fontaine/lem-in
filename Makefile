# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 14:26:04 by tfontain          #+#    #+#              #
#    Updated: 2017/04/21 08:27:35 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = clang
HEADER = ./lemin.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ./main.c ./parser.c ./parser2.c ./error.c ./get_next_line.c ./solver.c \
	  ./init.c ./blockfuncs.c ./gnl_print.c

OBJ = $(addsuffix .o,$(basename $(SRC)))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(OPTION) $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L/ libft/libft.a
%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
