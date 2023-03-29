/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:44:10 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 17:55:52 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void *(*f)(int))
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp -> next;
	}
}
