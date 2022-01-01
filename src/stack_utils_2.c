/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:54 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 00:45:56 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *str)
{
	t_node	*tmp;

	tmp = stack->top->next;
	stack->top->next->prev = NULL;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = tmp;
	if (str)
		ft_putstr(str);
	// while (stack->next)
	// {
	// 	ft_swap(&(stack->data), &(stack->next->data));
	// 	stack = stack->next;
	// }
}

void	rrotate(t_stack *stack, char *str)
{
	t_node	*tmp;

	tmp = stack->bottom->prev;
	stack->bottom->prev->next = NULL;
	stack->bottom->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	if (str)
		ft_putstr(str);
	// if (!(stack->next))
	// 	return ;
	// rrotate(stack->next);
	// ft_swap(&(stack->data), &(stack->next->data));
}