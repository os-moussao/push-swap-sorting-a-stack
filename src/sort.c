/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:46 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 15:41:23y omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_node *top)
{
	int	x;

	if (!top || !top->next)
		return (true);
	x = top->data;
	top = top->next;
	while (top)
	{
		if (top->data < x)
			return (false);
		x = top->data;
		top = top->next;
	}
	return (true);
}

int select_min(t_node *a)
{
	int	min;
	int	min_i;
	int	i;

	i = 0;
	min = INT_MAX;
	while (a)
	{
		if (a->data <= min)
		{
			min = a->data;
			min_i = i;
		}
		i++;
		a = a->next;
	}
	return (min_i);
}

int select_max(t_node *a)
{
	int	max;
	int	max_i;
	int	i;

	i = 0;
	max = INT_MIN;
	while (a)
	{
		if (a->data >= max)
		{
			max = a->data;
			max_i = i;
		}
		i++;
		a = a->next;
	}
	return (max_i);
}

t_stack	*min_up(t_stack *a)
{
	int	min;

	min = select_min(a->top);
	if (min < (a->len + 1) / 2)
	{
		while (min--)
			rotate(a, "ra\n");
	}
	else
	{
		min = a->len - min;
		while (min--)
			rrotate(a, "rra\n");
	}
	return (a);
}

t_stack	*sort_three(t_stack *a)
{
	int	max;

	max = select_max(a->top);
	if (max == 0)
		rotate(a, "ra\n");
	else if (max == 1)
		rrotate(a, "rra\n");
	if (a->top->data > a->top->next->data)
		swap(a, "sa\n");
	return (a);
}

t_stack	*selection_sort(t_stack *a)
{
	t_stack	*b;

	b = new_stack();
	while (a->len > 3)
	{
		min_up(a);
		push(b, pop(a), "pb\n");
	}
	sort_three(a);
	while (b->len)
		push(a, pop(b), "pa\n");
	clear(b);
	return (a);
}

t_stack	*sort_stack(t_stack *a)
{
	if (sorted(a->top))
		return (a);

	if (a->len == 2)
	{
		if (a->top->data > a->top->next->data)
			swap(a, "sa\n");
		return (a);
	}
	else if (a->len <= 30)
		return (selection_sort(a));
	else if (a->len <= 150)
		return (div_sort(a, 6));
	return (div_sort(a, 13));
}