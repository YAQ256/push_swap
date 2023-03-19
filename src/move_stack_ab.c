/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:30:41 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/19 19:12:12 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra y rb al mismo tiempo (lleva el de arriba del stack abajo del todo)
void	rr(struct s_push **stack_a, struct s_push **stack_b)
{
	struct s_push	*buffer;
	struct s_push	*start;

	start = (*stack_a)->next;
	buffer = *stack_a;
	*stack_a = start;
	buffer->next = NULL;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = buffer;
	*stack_a = start;
	start = (*stack_b)->next;
	buffer = *stack_b;
	*stack_b = start;
	buffer->next = NULL;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = buffer;
	*stack_b = start;
	pcyan("rr");
}

//rra y rrb al mismo tiempo (lleva el de abajo del stack arriba del todo)
void	rrr(struct s_push **stack_a, struct s_push **stack_b)
{
	struct s_push	*start;
	struct s_push	*buffer;

	start = *stack_a;
	while ((*stack_a)->next->next)
		*stack_a = (*stack_a)->next;
	buffer = (*stack_a)->next;
	(*stack_a)->next = NULL;
	buffer->next = start;
	*stack_a = buffer;
	start = *stack_b;
	while ((*stack_b)->next->next)
		*stack_b = (*stack_b)->next;
	buffer = (*stack_b)->next;
	(*stack_b)->next = NULL;
	buffer->next = start;
	*stack_b = buffer;
	pcyan("rrr");
}
