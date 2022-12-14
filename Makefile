# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agengemb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 17:52:16 by agengemb          #+#    #+#              #
#    Updated: 2022/12/13 04:56:45 by agengemb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIB = ./ft_printf/libftprintf.a
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $^ -o $@
	
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIB):
	make -C ft_printf

clean:	
	make -C ft_printf clean
	rm -f $(LIB)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
