/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:11:50 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/22 09:40:03 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	ret;
	int			negative;

	ret = 0;
	negative = 1;
	if (*str == '-')
	{
		if (*str == '-')
			negative = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (*str - 48);
		++str;
	}
	if (ret < INT_MIN || ret > INT_MAX || \
			(*str < '0' && *str != '\0') || (*str > '9' && *str != '\0'))
	{
		ft_putstr_fd(RED"Error\n"RESET, 2);
		exit(0);
	}
	return (ret * negative);
}
