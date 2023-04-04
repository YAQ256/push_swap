/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:04 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/04 13:31:36 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	put_moves(char	*move, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(move, "sa"))
		sa(*a);
	else if (!ft_strcmp(move, "sb"))
		sb(*b);
	else if (!ft_strcmp(move, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(move, "ra"))
		ra(a);
	else if (!ft_strcmp(move, "rb"))
		rb(b);
	else if (!ft_strcmp(move, "rr"))
		rr(*a, *b);
	else if (!ft_strcmp(move, "rra"))
		rra(a);
	else if (!ft_strcmp(move, "rrb"))
		rrb(b);
	else if (!ft_strcmp(move, "rrr"))
		rrr(*a, *b);
	else if (!ft_strcmp(move, "pa"))
		pa(b, a);
	else if (!ft_strcmp(move, "pb"))
		pb(a, b);
}
