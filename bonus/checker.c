/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:17 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/04/03 19:43:56 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	valid_move(char *moves)
{
	int	res;

	res = 1;
	if (ft_strlen(moves) < 2 || ft_strlen(moves) > 3 || ((ft_strlen(moves) == 2
				&& ft_strncmp(moves, "pa", 2) && ft_strncmp(moves, "pb", 2)
				&& ft_strncmp(moves, "sa", 2) && ft_strncmp(moves, "sb", 2)
				&& ft_strncmp(moves, "ss", 2) && ft_strncmp(moves, "ra", 2)
				&& ft_strncmp(moves, "rb", 2) && ft_strncmp(moves, "rr", 2))
			|| (ft_strlen(moves) == 3 && ft_strncmp(moves, "rra", 3)
				&& ft_strncmp(moves, "rrb", 3) && ft_strncmp(moves, "rrr", 3))))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (res);
}

char	*read_move(int fd)
{
	char	*read;
	char	*res;

	read = get_next_line(fd);
	if (!read)
		return (0);
	res = ft_substr(read, 0, ft_strlen(read) - 1);
	free(read);
	valid_move(res);
	return (res);
}

static void	stack_validation(char **args, int argc, char **argv, t_stack *a,
		t_stack *b)
{
	args = split_args(argc, argv);
	if (!args || !args[0])
		exit(0);
	error_check(args);
	a = fill_stack(args);
	free_str(args);
	if (is_sorted(a))
	{
		ft_lstclear(&a, del);
		ft_lstclear(&b, del);
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	**args = NULL;
	char	*moves;
	int		fd;

	fd = 0;
	if (argc > 1)
	{
		stack_validation(args, argc, argv, a, b);
		while (1)
		{
			moves = read_move(fd);
			if (!moves)
				break ;
			put_moves(moves, a, b);
			free(moves);
		}
		free(moves);
		if (is_sorted(a) && ft_lstsize(b) == 0){
			ft_putstr_fd("OK\n", 1);
			printf("entra\n");}
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
