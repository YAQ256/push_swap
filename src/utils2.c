/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:36:01 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/19 18:38:21 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//escribe los movimientos color cyan
void	pcyan(char *str)
{
	ft_putstr_fd(CYAN, 1);
	ft_putendl_fd(str, 1);
	ft_putstr_fd(RESET, 1);
}