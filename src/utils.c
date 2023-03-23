/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:42 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/23 17:10:44 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//el exit libera memoria?  = NO

//pone un mensaje de error y sale del programa
void	merror(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(0);
}

struct s_push	*ft_lastnode(struct s_push *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (0);
}

/* struct s_push	*ft_newnode(int number)
{
	struct s_push	*node;

	node = (struct s_push *)malloc(sizeof(struct s_push));
	if (!node)
		return (0);
	node->nb = number;
	node->next = NULL;
	return (node);
} */

struct s_push	*splited(int argc, char **argv, struct s_push *stack)
{
	int		i;
	int		n;
	char	**tmp;

	i = 1;
	n = 0;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		stack = stack_memory(stack, tmp, &n);
		i++;
	}
	return (stack);
}

/* t_push	*args_splited(int argc, char *argv[], t_push *stack)
{
	char	**args;
	int		i;
	
	i = 0;
	while(i < argc)
	{
		args = ft_split(argv[i], ' ');
		stack = stack_memory(stack, argc, args);
	}
	return (stack);
} */

//aloca memoria para el stack_a
struct s_push	*stack_memory(struct s_push *stack, char **argv, int *n)
{
	int				i;
	struct s_push	*aux;

	i = 0;
	aux = stack;
	stack = ft_lastnode(stack);
	while (argv[i])
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
			aux = stack;
		}
		stack->value = ft_atoi(argv[i]);
		i++;
		stack->pos = *n;
		*n += 1;
	}
	stack->next = NULL;
	return (aux);
}

//calcula el número basandose si es mayor o menor que el resto
int	get_index(struct s_push *cur, struct s_push *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		if (cur->pos != stack->pos)
		{
			if (cur->value == stack->value)
				merror("Error");
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

//comprueba si el stack está ordenado
/* int	is_sorted(struct s_push *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
} */
