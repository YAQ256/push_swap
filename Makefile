# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 13:56:59 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/23 22:30:19 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
LIB = ./src/push_swap.h
SRC_PATH = ./src/

SRC =	push_swap.c\
		utils.c\
		utils2.c\
		move_stack_a.c\
		move_stack_b.c\
		move_stack_ab.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))

#OBJS = $(SRCS:.c=.o)

all: make_libft $(NAME)

make_libft:
	@make all -C ./libft

#$(NAME): $(OBJS)
#	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -I $(LIB) -o $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(LIBFT) $(SRCS) -I $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re