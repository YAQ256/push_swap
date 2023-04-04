/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:37 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:40:02 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack *b)
{
	swap(b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}
