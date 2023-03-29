# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 12:15:03 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/29 17:54:27 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = push_swap
## COMPILATION ##
CC = gcc
CFLAGS = -Wall -Werror  -Wextra
DEBUG = -g3 -fsanitize=address
## INCLUDE ##
LIBFT = ./libft/libft.a
SRC_PATH = ./src/
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

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = ${SRCS:.c=.o}
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

## CLEANNING ##

clean:
	@$(RM) $(OBJS)
	@cd ./libft && make clean 
	@echo "$(GREEN)$(NAME): $(RED)→ $(BLUE) Cleaning... $(END)"
	@echo "$(GREEN)$(NAME): $(RED)→ $(YELLOW) the files(*.o) were deleted $(END)"

## REMOVING .O FILES AND .A FILES ##

fclean: clean
	$(RM) $(NAME) $(OBJS) $(libft)
	@make fclean -sC ./libft
	@echo "$(GREEN)$(NAME): $(RED) → $(BLUE)was deleted$(END)"

## REMOVING AND RUNNING ##

re: fclean all

.PHONY: all re clean fclean  norm