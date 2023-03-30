/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:36:52 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/30 15:12:28 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void	sort3(t_stack **a)
{
	int	max_i;

	max_i = max_pos(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)->pos == max_i)
		ra(a);
	else if ((*a)->next->pos == max_i)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void	sort4(t_stack **a, t_stack **b)
{
	int	min_i;

	min_i = min_pos(*a);
	if (min_i == 1)
		sa(*a);
	else if (min_i == 2)
	{
		rra(a);
		rra(a);
	}
	else if (min_i == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort3(a);
	pa(b, a);
}

void	sort5(t_stack **a, t_stack **b)
{
	int	min_i;

	min_i = min_pos(*a);
	if (min_i == 1)
		sa(*a);
	else if (min_i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_i == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_i == 4)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort4(a, b);
	pa(b, a);
}

void	small_sort(int size, t_stack **a, t_stack **b)
{
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
}
