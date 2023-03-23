# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 13:56:59 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/23 21:36:36 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#NAME_BONUS = pipex_bonus

HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address -g3
LIBFT = ./libft/libft.a
LIB = ./src/push_swap.h
#LIB_BONUS = ./src_bonus/pipex_bonus.h
SRC_PATH = ./src/
#SRC_BONUS_PATH = ./src_bonus/

SRC =	push_swap.c\
		utils.c\
		utils2.c\
		move_stack_a.c\
		move_stack_b.c\
		move_stack_ab.c\

#SRC_BONUS =	

SRCS = $(addprefix $(SRC_PATH), $(SRC))
#SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft $(NAME)

make_libft:
	@make all -C ./libft

bonus: make_libft $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -I $(LIB) -o $(NAME)
	@echo "all compiled"

#$(NAME_BONUS): $(OBJS_BONUS)
#	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONUS) -I $(LIB_BONUS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "All Clean"

re: fclean all

#reb: fclean all

.PHONY: all clean fclean re bonus reb