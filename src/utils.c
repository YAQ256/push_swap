/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:42 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/19 19:13:22 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pone un mensaje de error y sale del programa
void	merror(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(0);
}

//aloca memoria para el stack_a
struct s_push *stack_memory(struct s_push *stack, int argc, char **argv)
{
	int				i;
	struct s_push	*res;

	i = 0;
	while (++i < argc)
	{
		if (stack)
		{
			stack->next = malloc(sizeof(t_push));
			if (!stack->next)
				merror("Malloc fail");
			stack = stack->next;
		}
		else
		{
			stack = malloc(sizeof(t_push));
			if (!stack)
				merror("malloc fail");
			res = stack;
		}
		stack->value = ft_atoi(argv[i]);
		stack->pos = (i - 1);
	}
	stack->next = NULL;
	return (res);
}

//calcula el número basandose si es mayor o menor que el resto
int	get_index(struct s_push *stack, struct s_push *cur)
{
	int i;

	i = 0;
	while (stack)
	{
		if (cur->pos != stack->pos)
		{
			if (cur->value == stack->value)
				merror("4");
			if (cur->value > stack->value)
				++i;
		}
		stack = stack->next;
	}
	return (i);
}

//asigna el número basandose si es mayor o menor que el resto
void	assign_index(struct s_push *stack)
{
	struct s_push *cur;
	
	cur = stack;
	while (cur)
	{
		cur->index = get_index(cur, stack);
		cur = cur->next;
	}
	return ;
}

//comprueba si el stack está ordenado
int	is_sorted(struct s_push *stack_a, struct s_push *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a)
	{
		stack_b = stack_a->next;
		while (stack_b)
		{
			if (stack_b->value < stack_a->value)
				return (0);
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}