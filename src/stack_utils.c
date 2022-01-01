/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:51 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/14 02:07:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, char *str)
{
	if (stack->next)
	{
		ft_swap(&(stack->data), &(stack->next->data));
		if (str)
			ft_putstr(str);
	}
}

void	push(t_node **stack, int data, char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = (*stack);
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	(*stack) = new;
	if (str)
		ft_putstr(str);
}

int	pop(t_node **head)
{
	t_node	*to_free;
	int		ret;

	ret = (*head)->data;
	to_free = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(to_free);
	return (ret);
}

void	clear(t_stack *stack)
{
	while (stack->top)
		pop(&(stack->top));
	free(stack);
}