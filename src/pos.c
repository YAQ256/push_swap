/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:39:13 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 14:39:21 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_pos(t_stack *a)
{
	int	max;
	int	index;

	max = a->data;
	index = a->pos;
	while (a)
	{
		if (a->data > max)
		{
			max = a->data;
			index = a->pos;
		}
		a = a->next;
	}
	return (index);
}

int	largest_element(t_stack *head)
{
	int	max;

	max = INT_MIN;
	while (head != NULL)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	min_pos(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->data;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}