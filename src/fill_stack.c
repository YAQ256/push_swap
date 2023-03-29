/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:33:56 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 17:51:02 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **str)
{
	int		i;
	t_stack	*top;
	t_stack	*num;

	i = 0;
	top = ft_lstnew(ft_atoi(str[i]));
	top->pos = i;
	while (str[++i])
	{
		num = ft_lstnew(ft_atoi(str[i]));
		num->pos = i;
		ft_lstadd_back(&top, num);
	}
	return (top);
}
