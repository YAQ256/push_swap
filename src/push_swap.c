/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:29 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/19 18:43:59 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	struct s_push *stack_a;

	if (argc < 3)
		merror("Error: invalid number of arguments");
	stack_a = NULL;
	stack_a = stack_memory(stack_a, argc, argv);
	assign_index(stack_a);
	if (is_sorted(stack_a, NULL))
		merror("Is sorted");
}