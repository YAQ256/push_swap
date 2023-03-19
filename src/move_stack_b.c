/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:52 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/19 19:09:34 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//intercambia el primero por el segundo del stack "b"
struct s_push	*sb(struct s_push *stack_b)
{
	struct s_push	*buffer;

	buffer = stack_b->next;
	stack_b->next = buffer->next;
	buffer->next = stack_b;
	pcyan("sb");
	return (buffer);
}

//lleva el numero de arriba del stack "b" abajo del stack
struct s_push	*rb(struct s_push *stack_b)
{
	struct s_push	*ret;
	struct s_push	*buffer;

	ret = stack_b->next;
	buffer = stack_b;
	stack_b = stack_b->next;
	buffer->next = NULL;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = buffer;
	pcyan("rb");
	return (ret);
}

//lleva el numero de abajo del stack "b" arriba del stack
struct s_push	*rrb(struct s_push *stack_b)
{
	struct s_push	*start;
	struct s_push	*buffer;

	start = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	buffer = stack_b->next;
	stack_b->next = NULL;
	buffer->next = start;
	pcyan("rrb");
	return (buffer);
}

//manda el numbero de arriba del stack "a" al stack "b"
void	pb(struct s_push **stack_a, struct s_push **stack_b)
{
	struct s_push	*buffer;

	if (!*stack_a)
		return ;
	buffer = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = buffer;
	pcyan("pb");
}
