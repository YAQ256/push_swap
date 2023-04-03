/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:37:04 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 18:45:32 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	put_moves(char	*move, t_stack *a, t_stack *b)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		sa(a);
	if (ft_strncmp(move, "sb", 2) == 0)
		sb(a);
	if (ft_strncmp(move, "ss", 2) == 0)
		ss(a, b);
	if (ft_strncmp(move, "ra", 2) == 0)
		ra(&a);
	if (ft_strncmp(move, "rb", 2) == 0)
		rb(&a);
	if (ft_strncmp(move, "rr", 2) == 0)
		rr(a, b);
	if (ft_strncmp(move, "rra", 3) == 0)
		rra(&a);
	if (ft_strncmp(move, "rrb", 3) == 0)
		rrb(&a);
	if (ft_strncmp(move, "rrr", 3) == 0)
		rrr(a, b);
	if (ft_strncmp(move, "pa", 2) == 0)
		pa(&a, &b);
	if (ft_strncmp(move, "pb", 2) == 0)
		pb(&a, &b);
	else
		ft_putstr_fd("Falla\n", 1);
}
