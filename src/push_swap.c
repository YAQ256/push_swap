/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:39:39 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 15:57:03 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 5)
	{
		small_sort(size, a, b);
		ft_lstclear(a, del);
		ft_lstclear(b, del);
	}
	else
	{
		indexing(*a);
		stack_divider(a, b);
		ft_lstclear(a, del);
		ft_lstclear(b, del);
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		args = split_args(argc, argv);
		if (!args || !args[0])
			return (0);
		error_check(args);
		a = fill_stack(args);
		free_str(args);
		if (is_sorted(a))
		{
			ft_lstclear(&a, del);
			ft_lstclear(&b, del);
			return (0);
		}
		sort(&a, &b);
	}
	return (0);
}
