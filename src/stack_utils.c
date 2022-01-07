/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:46:03 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/07 17:05:52 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->len = 0;
	return (stack);
}

void	swap(t_stack *stack, char *str)
{
	if (stack->top->next)
	{
		ft_swap(&(stack->top->data), &(stack->top->next->data));
		if (str)
			ft_putstr(str);
	}
}

void	push(t_stack *stack, int data, char *str)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = stack->top;
	new->prev = NULL;
	if (stack->top)
		stack->top->prev = new;
	else
		stack->bottom = new;
	stack->top = new;
	(stack->len)++;
	if (str)
		ft_putstr(str);
}

int	pop(t_stack *stack)
{
	t_node	*to_free;
	int		ret;

	ret = stack->top->data;
	to_free = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	(stack->len)--;
	free(to_free);
	return (ret);
}

void	clear(t_stack *stack)
{
	while (stack->len)
		pop(stack);
	free(stack);
}
