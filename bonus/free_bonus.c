/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:40:25 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/04 15:40:07 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	del(int data)
{
	(void)data;
}

void	free_lst(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	{
		ft_lstclear(&a, del);
		ft_lstclear(&b, del);
		exit(0);
	}
}
