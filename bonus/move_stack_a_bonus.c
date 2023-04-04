/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:28:22 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 18:28:41 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	swap(a);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}
