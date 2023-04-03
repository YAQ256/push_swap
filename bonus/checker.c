/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:17 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:12:38 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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