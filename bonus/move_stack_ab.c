/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:41 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:11:04 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(&a);
	rb(&b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(&a);
	rrb(&b);
	write(1, "rrr\n", 4);
}
