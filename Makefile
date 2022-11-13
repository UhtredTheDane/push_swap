# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agengemb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 17:52:16 by agengemb          #+#    #+#              #
#    Updated: 2022/11/13 19:36:29 by agengemb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIB = ./ft_printf/libftprintf.a
SRC = $(wildcard srcs/*.c)

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $^ -o $@

$(LIB): $(NAME)
	make -C ft_printf

clean:
	rm -r $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
