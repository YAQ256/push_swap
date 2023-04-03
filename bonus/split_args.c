/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:01:15 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 16:13:13 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**split_args(int argc, char **argv)
{
	int		i;
	char	**str;
	char	*join;
	char	*arr_to_free;

	i = 1;
	join = ft_strdup("");
	while (i < argc)
	{
		arr_to_free = join;
		join = ft_strjoin(join, argv[i]);
		free(arr_to_free);
		arr_to_free = join;
		join = ft_strjoin(join, " ");
		free(arr_to_free);
		i++;
	}
	str = ft_split(join, ' ');
	free(join);
	return (str);
}
