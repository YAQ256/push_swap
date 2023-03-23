/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:31 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/23 21:51:46 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define	TRUE (void *)0
# define	FALSE (void *)1

typedef struct s_push
{
	int				index;
	int				value;
	int				pos;
	int				target_pos;
	int				moves_a;
	int				moves_b;
	struct s_push	*next;
}	t_push;

void			merror(char *str);
struct s_push	*stack_memory(struct s_push *stack, char **argv, int *n);
int				get_index(struct s_push *stack, struct s_push *cur);
void			assign_index(struct s_push *stack);
int				is_sorted(struct s_push *stack_a, struct s_push *stack_b);
void			pgreen(char *str);
struct s_push 	*sa(struct s_push *stack_a);
struct s_push 	*ra(struct s_push *stack_a);
struct s_push	*rra(struct s_push *stack_a);
void			pa(struct s_push **stack_a, struct s_push **stack_b);
struct s_push	*sb(struct s_push *stack_b);
struct s_push	*rb(struct s_push *stack_b);
struct s_push	*rrb(struct s_push *stack_b);
void			pb(struct s_push **stack_a, struct s_push **stack_b);
void			rr(struct s_push **stack_a, struct s_push **stack_b);
void			rrr(struct s_push **stack_a, struct s_push **stack_b);
struct s_push	*sort_three_numbers(struct s_push *stack);
struct s_push	*splited(int argc, char **argv, struct s_push *stack);
struct s_push	*ft_lastnode(struct s_push *lst);
int	stack_size(struct s_push *stack);
void	calculate_cost(struct s_push *stack_a, struct s_push *stack_b);
int	ft_abs(int i);
int	find_lowest_cost(struct s_push *stack_b);
int	rotate_a(struct s_push **stack_a, int rotations);
int	rotate_b(struct s_push **stack_b, int rotations);
void	move_single(struct s_push **stack_a, struct s_push **stack_b, \
	struct s_push *start);
void	sort_single(struct s_push **stack_a, struct s_push **stack_b);
struct s_push	*orient_a(struct s_push *stack_a, \
		struct s_push *start, int a_size);
void	free_stack(struct s_push *stack);
void	assign_pos(struct s_push *stack_a, struct s_push *stack_b);
void	assign_target_pos(struct s_push *stack_a, struct s_push *stack_b, \
		int target_pos, struct s_push *start);
void	rotate_single(struct s_push **stack_a, struct s_push **stack_b, \
	int a_rotations, int b_rotations);



//===SETTINGS 	COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif