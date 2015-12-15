# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/02 05:00:20 by amerle            #+#    #+#              #
#    Updated: 2015/12/15 11:45:39 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft/include -g3

# LDFLAGS = 
LDFLAGS = -Llibft -lft

SRCS = $(shell find src -name "*.c")

OBJS = $(patsubst src/%,obj/%,$(SRCS:.c=.o))

NAME = push_swap

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.c include/push_swap.h
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make -C libft clean
	rm -rf obj

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib