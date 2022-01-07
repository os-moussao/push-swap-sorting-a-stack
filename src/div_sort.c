/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:35:41 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/07 17:03:38 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int length)
{
	int	i;
	int	j;
	int	swapped;

	i = -1;
	while (++i < length)
	{
		j = 0;
		swapped = 0;
		while (j + 1 < length - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(tab + j, tab + j + 1);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			return ;
	}
}

int	*get_tab(t_stack *a)
{
	int		*tab;
	t_node	*tmp;
	int		i;

	tab = malloc(a->len * sizeof(int));
	if (!tab)
	{
		clear(a);
		error();
	}
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	sort_tab(tab, a->len);
	return (tab);
}

void	move_elem(t_stack *a, t_stack *b, int i, int mode)
{
	if (mode & PUSH_B)
	{
		if (mode & MV_UP)
			while (i--)
				rotate(a, "ra\n");
		else if (mode & MV_DOWN)
			while (i--)
				rrotate(a, "rra\n");
		push(b, pop(a), "pb\n");
	}
	else if (mode & PUSH_A)
	{
		if (mode & MV_UP)
			while (i--)
				rotate(b, "rb\n");
		else if (mode & MV_DOWN)
			while (i--)
				rrotate(b, "rrb\n");
		push(a, pop(b), "pa\n");
	}
}

void	move_chunk(t_stack *a, t_stack *b, int val)
{
	t_node	*top;
	t_node	*bott;
	int		i;

	i = 0;
	top = a->top;
	bott = a->bottom;
	while (top != bott)
	{
		if (top->data <= val || bott->data <= val)
		{
			move_elem(a, b, i + (top->data > val), PUSH_B
				| ((top->data <= val) * MV_UP + (top->data > val) * MV_DOWN));
			i = 0;
			top = a->top;
			bott = a->bottom;
			continue ;
		}
		i++;
		top = top->next;
		if (top == bott)
			break ;
		bott = bott->prev;
	}
}

t_stack	*div_sort(t_stack *a, int div)
{
	t_stack	*b;
	int		*tab;
	int		max_i;
	int		index;

	b = new_stack();
	tab = get_tab(a);
	index = (a->len + b->len) / div;
	while (index < (a->len + b->len))
	{
		move_chunk(a, b, tab[index - 1]);
		index += (a->len + b->len) / div;
	}
	selection_sort(a);
	while (b->len)
	{
		max_i = select_max(b->top);
		if (max_i <= (b->len / 2))
			move_elem(a, b, max_i, PUSH_A | MV_UP);
		else
			move_elem(a, b, b->len - max_i, PUSH_A | MV_DOWN);
	}
	free(tab);
	clear(b);
	return (a);
}
