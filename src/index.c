/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:42:52 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 14:42:59 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*str_to_arr(t_stack *a)
{
	int	i;
	int	*nums;
	int	len;

	i = 0;
	len = ft_lstsize(a);
	nums = malloc(sizeof(int) * len);
	while (a)
	{
		nums[i] = a->data;
		i++;
		a = a->next;
	}
	return (nums);
}

int	*bubble_sort(t_stack *a)
{
	int	*nums;
	int	i;
	int	j;
	int	len;

	nums = str_to_arr(a);
	len = ft_lstsize(a);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] > nums[j])
				ft_swap(&nums[i], &nums[j]);
			j++;
		}
		i++;
	}
	return (nums);
}

void	indexing(t_stack *a)
{
	int	*nums;
	int	i;
	int	len;

	nums = bubble_sort(a);
	len = ft_lstsize(a);
	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->data == nums[i])
				a->pos = i;
			i++;
		}
		a = a->next;
	}
	free(nums);
}

int	place_in_stack(t_stack **a, int data)
{
	int		i;
	int		index;
	t_stack	*tmp;

	tmp = *a;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->data == data)
			index = i;
		i++;
		tmp = tmp->next;
	}
	return (index);
}