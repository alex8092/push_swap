# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 07:07:27 by amerle            #+#    #+#              #
#    Updated: 2015/12/15 11:52:41 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LD = ar

CFLAGS = -Wall -Wextra -Werror -Iinclude -g3

LDFLAGS = rc

LDFLAGS_TEST = -L. -lft

SRCS = $(shell find src -name "*.c")

OBJS = $(patsubst src/%,obj/%,$(SRCS:.c=.o))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^
	ranlib $@

test: $(NAME)
	$(CC) -o $@ tests/main.c $(LDFLAGS_TEST) $(CFLAGS)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
