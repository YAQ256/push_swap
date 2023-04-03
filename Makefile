# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 12:15:03 by cyacoub-          #+#    #+#              #
#    Updated: 2023/04/03 17:54:17 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = push_swap
NAME2 = bonus
## COMPILATION ##
CC = gcc
CFLAGS = -Wall -Werror  -Wextra
DEBUG = -g3 -fsanitize=address
## INCLUDE ##
LIBFT = ./libft/libft.a
SRC_PATH = ./src/
SRC_PATH_BONUS = ./bonus/
#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
## VARIABLES ##
AR = @ar rcs
RM = @rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory -C
LINK = -L $(LIBS_PATH)
## SOURCE FILE ##
SRC =	move_stack_a.c move_stack_b.c move_stack_ab.c moves.c push_swap.c \
		args_parser.c errors.c fill_stack.c free.c index.c num_validation.c \
		pos.c small_sort.c split_args.c stack_divider.c

SRC_BONUS =	move_stack_a.c move_stack_b.c move_stack_ab.c moves.c checker.c \
			args_parser.c errors.c get_next_line.c get_next_line_utils.c \
			num_validation.c put_moves.c split_args.c fill_stack.c free.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = ${SRCS:.c=.o}

SRCS_BONUS = $(addprefix $(SRC_PATH_BONUS), $(SRC_BONUS))
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
## COLORS ##
END     = \033[0m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
WHITE   = \033[1;37m
## RULES ##
all: make_libft $(NAME)

make_libft:
	@echo "$(BLUE)Generating...$(RESET)"
	@make -sC ./libft
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

%.o :%.c 
	@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(WHITE)$< $(END)" 
	@$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME) : make_libft $(OBJS)
	@make -sC ./libft
	clear
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)You Created $(NAME)$(END)"

$(NAME2) : make_libft $(OBJS_BONUS)
	@make -sC ./libft
	clear
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o checker
	@echo "$(GREEN)You Created Checker$(END)"

## CLEANNING ##

clean:
	@$(RM) $(OBJS)
	@cd ./libft && make clean 
	@echo "$(GREEN)$(NAME): $(RED)→ $(BLUE) Cleaning... $(END)"
	@echo "$(GREEN)$(NAME): $(RED)→ $(YELLOW) the files(*.o) were deleted $(END)"

## REMOVING .O FILES AND .A FILES ##

fclean: clean
	$(RM) $(NAME) checker $(OBJS) $(OBJS_BONUS) $(libft)
	@make fclean -sC ./libft
	clear
	@echo "$(GREEN)$(NAME): $(RED) → $(BLUE)was deleted$(END)"

## REMOVING AND RUNNING ##

re: fclean all

.PHONY: all re clean fclean  norm