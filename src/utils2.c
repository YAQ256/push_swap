/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:36:01 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/23 21:26:33 by cyacoub-         ###   ########.fr       */
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
	if (is_sorted(stack, NULL))
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

int	stack_size(struct s_push *stack)
{
	int	ret;

	ret = 0;
	while (stack)
	{
		stack = stack->next;
		++ret;
	}
	return (ret);
}

void	calculate_cost(struct s_push *stack_a, struct s_push *stack_b)
{
	int				a_size;
	int				b_size;
	struct s_push	*start;

	a_size = stack_size(stack_a);
	b_size = stack_size(stack_b);
	start = stack_b;
	while (stack_b)
	{
		if (stack_b->target_pos <= (a_size / 2))
			stack_b->moves_a = stack_b->target_pos;
		else
			stack_b->moves_a = ((a_size - stack_b->target_pos) * -1);
		stack_b = stack_b->next;
	}
	while (start)
	{
		if (start->pos <= (b_size / 2))
			start->moves_b = start->pos;
		else
			start->moves_b = ((b_size - start->pos) * -1);
		start = start->next;
	}
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int	find_lowest_cost(struct s_push *stack_b)
{
	int	ret;

	ret = (ft_abs(stack_b->moves_a) + ft_abs(stack_b->moves_b));
	while (stack_b)
	{
		if ((ft_abs(stack_b->moves_a) + ft_abs(stack_b->moves_b)) < ret)
			ret = (ft_abs(stack_b->moves_a) + ft_abs(stack_b->moves_b));
		stack_b = stack_b->next;
	}
	return (ret);
}

int	rotate_a(struct s_push **stack_a, int rotations)
{
	if (rotations > 0)
	{
		*stack_a = ra(*stack_a);
		return (-1);
	}
	else if (rotations < 0)
	{
		*stack_a = rra(*stack_a);
		return (1);
	}
	return (0);
}

int	rotate_b(struct s_push **stack_b, int rotations)
{
	if (rotations > 0)
	{
		*stack_b = rb(*stack_b);
		return (-1);
	}
	else if (rotations < 0)
	{
		*stack_b = rrb(*stack_b);
		return (1);
	}
	return (0);
}

void	rotate_single(struct s_push **stack_a, struct s_push **stack_b, \
	int a_rotations, int b_rotations)
{
	while (a_rotations > 0 && b_rotations > 0)
	{
		--a_rotations;
		--b_rotations;
		rr(stack_a, stack_b);
	}
	while (a_rotations < 0 && b_rotations < 0)
	{
		++a_rotations;
		++b_rotations;
		rrr(stack_a, stack_b);
	}
	while (a_rotations)
	{
		a_rotations += rotate_a(stack_a, a_rotations);
	}
	while (b_rotations)
	{
		b_rotations += rotate_b(stack_b, b_rotations);
	}
}

void	move_single(struct s_push **stack_a, struct s_push **stack_b, \
	struct s_push *start)
{
	int	a_rotations;
	int	b_rotations;

	a_rotations = (*stack_b)->moves_a;
	b_rotations = (*stack_b)->moves_b;
	*stack_b = start;
	rotate_single(stack_a, stack_b, a_rotations, b_rotations);
	pa(stack_a, stack_b);
}

void	sort_single(struct s_push **stack_a, struct s_push **stack_b)
{
	int				cheapest;
	struct s_push	*start;

	cheapest = find_lowest_cost(*stack_b);
	start = *stack_b;
	while (*stack_b)
	{
		if ((ft_abs((*stack_b)->moves_a) + ft_abs((*stack_b)->moves_b)) == \
				cheapest)
		{
			move_single(stack_a, stack_b, start);
			return ;
		}
		*stack_b = (*stack_b)->next;
	}
}

struct s_push	*orient_a(struct s_push *stack_a, \
		struct s_push *start, int a_size)
{
	int	rotations;

	while (stack_a)
	{
		if (stack_a->index == 0)
		{
			if (stack_a->pos <= (a_size / 2))
			{
				rotations = stack_a->pos;
				while (rotations--)
					start = ra(start);
				return (start);
			}
			else
			{
				rotations = (a_size - stack_a->pos);
				while (rotations--)
					start = rra(start);
				return (start);
			}
		}
		stack_a = stack_a->next;
	}
	return (start);
}

void	free_stack(struct s_push *stack)
{
	struct s_push	*buffer;

	while (stack)
	{
		buffer = stack->next;
		free(stack);
		stack = buffer;
	}
}