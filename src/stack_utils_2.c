/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:54 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/05 18:42:12 by omoussao         ###   ########.fr       */
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
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a, NULL);
    swap(b, NULL);
}

void    rr(t_stack *a, t_stack *b)
{
    rotate(a, NULL);
    rotate(b, NULL);
}

void    rrr(t_stack *a, t_stack *b)
{
    rrotate(a, NULL);
    rrotate(b, NULL);
}