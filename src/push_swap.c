/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:29 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/22 13:18:40 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	push_swap(struct s_push *stack_a, struct s_push *stack_b, \
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
	stack_a = three_number_sort(stack_a);
	
} */

int	main(int argc, char *argv[])
{
	struct s_push *stack_a;

	if (argc < 3)
		merror("Error: invalid number of arguments");
	stack_a = NULL;
	//nb_args = splited(argc, argv, stack_a);
	//stack_a = args_splited(argc, argv, stack_a);
	stack_a = stack_memory(stack_a, argc, argv);
	assign_index(stack_a);
	if (is_sorted(stack_a))
		merror("Is sorted");
	if (argc == 3)
	{
		pgreen("sa");
		return (0);
	}
	if (argc == 4)
	{
		stack_a = sort_three_numbers(stack_a);
		return (0);
	}
	//push_swap(stack_a, NULL, argc - 1, 0);
}