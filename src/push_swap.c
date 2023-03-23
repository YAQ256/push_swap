/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:29 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/23 21:35:03 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(struct s_push *stack_a, struct s_push *stack_b, \
		int argc, int i)
{
	while (i < (argc / 2) && stack_a->next->next->next)
	{
		if ((stack_a->index / 2) < (argc / 2))
		{
			pb(&stack_a, &stack_b);
			++i;
		}
		else
			stack_a = ra(stack_a);
	}
	while (stack_a->next->next->next)
		pb(&stack_a, &stack_b);
	stack_a = sort_three_numbers(stack_a);
	while (stack_b)
	{
		assign_pos(stack_a, stack_b);
		assign_target_pos(stack_a, stack_b, 1, stack_a);
		calculate_cost(stack_a, stack_b);
		sort_single(&stack_a, &stack_b);
	}
	assign_pos(stack_a, stack_b);
	stack_a = orient_a(stack_a, stack_a, stack_size(stack_a));
	stack_b = stack_a;
	free_stack(stack_a);
}

int	main(int argc, char *argv[])
{
	struct s_push *stack_a;
	int				n_args;

	if (argc == 1)
		merror("Error: invalid number of arguments");
	stack_a = NULL;
	stack_a = splited(argc, argv, stack_a);
	n_args = ft_lastnode(stack_a)->pos + 1;
	assign_index(stack_a);
	if (is_sorted(stack_a, NULL))
		merror("Is sorted");
	if (n_args == 3)
	{
		stack_a = sort_three_numbers(stack_a);
		return (0);
	}
	if (n_args == 2)
	{
		pgreen("sa");
		return (0);
	}
	push_swap(stack_a, NULL, argc - 1, 0);
	return (0);
}