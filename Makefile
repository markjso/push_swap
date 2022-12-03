# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:48:04 by jmarks            #+#    #+#              #
#    Updated: 2022/12/01 15:02:40 by jmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MLX_DIR = mlx

SRCS = srcs/actions.c \
	srcs/actions1.c \
	srcs/actions2.c \
	srcs/checks.c \
	srcs/push_swap.c \
	srcs/sort_large_utils.c \
	srcs/sort_large.c \
	srcs/sort_utils.c \
	srcs/sort.c \
	srcs/stack_a_utils.c \
	srcs/stack_b_utils.c \
	srcs/stack.c \
	srcs/utils.c
	
OBJS=$(SRCS:.c=.o)

CC=gcc

CFLAGS=-Wall -Wextra -Werror -Iinc/

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
