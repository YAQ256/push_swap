/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:30:41 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/20 12:27:02 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//intercambia el primero por el segundo del stack "a"
struct s_push *sa(struct s_push *stack_a)
{
	struct s_push	*buffer;

	buffer = stack_a->next;
	stack_a->next = buffer->next;
	buffer->next = stack_a;
	pgreen("sa");
	return (buffer);
}

//lleva el numero de arriba del stack "a" abajo del stack
struct s_push *ra(struct s_push *stack_a)
{
	struct s_push	*res;
	struct s_push	*buffer;

	res = stack_a->next;
	buffer = stack_a;
	stack_a = stack_a->next;
	buffer->next = NULL;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = buffer;
	pgreen("ra");
	return (res);
}

//lleva el numero de abajo del stack "a" arriba del stack
struct s_push	*rra(struct s_push *stack_a)
{
	struct s_push	*start;
	struct s_push	*buffer;

	start = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	buffer = stack_a->next;
	stack_a->next = NULL;
	buffer->next = start;
	pgreen("rra");
	return (buffer);
}

//manda el numbero de arriba del stack "b" al stack "a"
void	pa(struct s_push **stack_a, struct s_push **stack_b)
{
	struct s_push	*buffer;

	if (!*stack_b)
		return ;
	buffer = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = buffer;
	pgreen("pa");
}