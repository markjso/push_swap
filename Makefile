# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:48:04 by jmarks            #+#    #+#              #
#    Updated: 2022/12/09 17:18:08 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MLX_DIR = mlx

SRCS = srcs/rotate.c \
	srcs/push.c \
	srcs/swap.c \
	srcs/rev_rotate.c \
	srcs/checks.c \
	srcs/cost.c \
	srcs/push_swap.c \
	srcs/sort_large_utils.c \
	srcs/sort_large.c \
	srcs/position.c \
	srcs/sort_utils.c \
	srcs/sort.c \
	srcs/stack.c \
	srcs/utils.c
	
OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror -Iinc/ -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS) 
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
