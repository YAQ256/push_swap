/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:31 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/04 15:40:56 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

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
void	sign_error(char *str, int *i, int *sign);
void	num_error(char *str);
void	fake_atoi(char *str);
void	check_duplicates(char **str, int len);
int		is_sorted(t_stack *top);
void	error_check(char **str);
void	print_error(void);
int		num_len(int num);
void	zeros_validation(char **str, int len);
void	put_moves(char	*move, t_stack **a, t_stack **b);
t_stack	*fill_stack(char **str);
void	free_str(char **str);
void	free_lst(t_stack *a, t_stack *b);
void	del(int data);

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *str, int c);

#endif