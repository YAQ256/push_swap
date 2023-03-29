/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:42:25 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 08:05:43 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (*lst && new)
	{
		aux = lst[0];
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else if (new)
		*lst = new;
}
