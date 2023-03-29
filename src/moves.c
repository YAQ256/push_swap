/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:28:59 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/29 12:37:31 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *top)
{
	int	tmp;

	if (top == NULL || top->next == NULL)
		return ;
	tmp = top->data;
	top->data = top->next->data;
	top->next->data = tmp;
	tmp = top->pos;
	top->pos = top->next->pos;
	top->next->pos = tmp;
}

void	push(t_stack **src, t_stack **dest)
{	
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dest, tmp);
}

void	rotate(t_stack **top)
{
	t_stack	*tail;
	t_stack	*tmp;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	tmp = *top;
	*top = (*top)->next;
	tail = ft_lstlast(tmp);
	tail->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack **top)
{
	t_stack	*tail;
	t_stack	*tmp;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	tail = ft_lstlast(*top);
	tmp = ft_lstseclast(*top);
	tmp->next = NULL;
	tail->next = *top;
	*top = tail;
}
