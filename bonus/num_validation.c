/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:32:42 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:16:52 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	num_len(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

void	zeros_validation(char **str, int len)
{
	int	i;
	int	*num;

	i = 0;
	num = malloc(sizeof(int) * len);
	if (!num)
		return ;
	while (i < len)
	{
		if (num_len(ft_atoi(str[i])) > 16)
			print_error();
		i++;
	}
	free(num);
}
