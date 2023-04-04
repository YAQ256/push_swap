/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:41 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:39:56 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(&a);
	rb(&b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(&a);
	rrb(&b);
}
