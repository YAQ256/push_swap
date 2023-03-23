/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:36:01 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/20 14:32:30 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//escribe los movimientos color cyan
void	pgreen(char *str)
{
	ft_putstr_fd(LGREEN, 1);
	ft_putendl_fd(str, 1);
	ft_putstr_fd(RESET, 1);
}

struct s_push	*sort_three_numbers(struct s_push *stack)
{
	if (is_sorted(stack))
		return (stack);
	if (stack->index > stack->next->index && \
			stack->index > stack->next->next->index)
	{
		if (stack->next->index > stack->next->next->index)
		{
			stack = ra(stack);
			stack = sa(stack);
			return (stack);
		}
		else
			return (ra(stack));
	}
	if (stack->index > stack->next->index || \
			stack->index > stack->next->next->index)
	{
		if (stack->index > stack->next->index)
			return (sa(stack));
		else
			return (rra(stack));
	}
	stack = sa(stack);
	return (ra(stack));
}

void	assign_pos(struct s_push *stack_a, struct s_push *stack_b)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		++i;
	}
	i = 0;
	while (stack_b)
	{
		stack_b->pos = i;
		stack_b = stack_b->next;
		++i;
	}
}

void	assign_target_pos(struct s_push *stack_a, struct s_push *stack_b, \
		int target_pos, struct s_push *start)
{
	while (stack_b)
	{
		stack_b->target_pos = 0;
		while (stack_a->next)
		{
			if ((stack_a->index < stack_b->index && \
				stack_a->next->index > stack_b->index) || \
				(((stack_a->index > stack_b->index && \
				stack_a->next->index > stack_b->index) || \
				(stack_a->index < stack_b->index && \
				stack_a->next->index < stack_b->index)) && \
				stack_a->next->index < stack_a->index))
			{
				stack_b->target_pos = target_pos;
				break ;
			}
			++target_pos;
			stack_a = stack_a->next;
		}
		stack_a = start;
		if (!stack_b->target_pos)
			stack_b->target_pos = 0;
		stack_b = stack_b->next;
		target_pos = 1;
	}
}