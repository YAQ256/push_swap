/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:31 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 15:52:36 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	swap(t_stack *top);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);
void	sa(t_stack *a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack *b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	**split_args(int argc, char **argv);
void	error_check(char **str);
void	print_error(void);
void	sign_error(char *str, int *i, int *sign);
void	num_error(char *str);
void	fake_atoi(char *str);
void	check_duplicates(char **str, int len);
int		is_sorted(t_stack *top);
int		num_len(int num);
void	zeros_validation(char **str, int len);
void	free_str(char **str);
void	del(int data);
t_stack	*fill_stack(char **str);
int		max_pos(t_stack *a);
int		largest_element(t_stack *head);
int		min_pos(t_stack *a);
int		*str_to_arr(t_stack *a);
int		*bubble_sort(t_stack *a);
void	indexing(t_stack *a);
int		place_in_stack(t_stack **a, int data);
void	b_to_a(t_stack **a, t_stack **b);
int		generate_n(int size);
void	a_to_b(t_stack **a, t_stack **b, int n);
void	stack_divider(t_stack **a, t_stack **b);
void	sort2(t_stack **a);
void	sort3(t_stack **a);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
void	small_sort(int size, t_stack **a, t_stack **b);

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