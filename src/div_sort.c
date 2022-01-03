/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:35:41 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/03 18:56:58 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_tab(int *tab, int length)
{
    int i;
	int j;
	int swapped;

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

int *get_tab(t_stack *a)
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

void	move_chunk(t_stack *a, t_stack *b, int val)
{
	t_node	*top;
	t_node	*bott;
	int		i;
	
	top = a->top;
	bott = a->bottom;
	i = 0;
	while (top != bott)
	{
		if (top->data <= val)
		{
			while (i--)
				rotate(a, "ra\n");
			push(b, pop(a), "pb\n");
			i = 0;
			top = a->top;
			bott = a->bottom;
		}
		else if (bott->data <= val)
		{
			while (i-- > -1)
				rrotate(a, "rra\n");
			push(b, pop(a), "pb\n");
			i = 0;
			top = a->top;
			bott = a->bottom;
		}
		else
		{
			i++;
			top = top->next;
			if (top == bott)
				break ;
			bott = bott->prev;
		}
	}
}

t_stack	*div_sort(t_stack *a)
{
	t_stack	*b;
    int 	*tab;
	int		max_i;
	int		index;
	int		len;

	b = new_stack();
    tab = get_tab(a);
	len = a->len;
	index = len / 5;
	while (index < len)
	{
		move_chunk(a, b, tab[index - 1]);
		index += len / 5;
	}
	if (a->len > 3)
		selection_sort(a);
	else
		sort_stack(a);
	while (b->len)
	{
		max_i = select_max(b->top);
		if (max_i >= b->len / 2)
		{
			while (max_i--)
				rotate(b, "rb\n");
			push(a, pop(b), "pa\n");
		}
		else
		{
			int c = b->len - max_i;
			while (c--)
				rrotate(b, "rrb\n");
			push(a, pop(b), "pa\n");
		}
	}
	//disp(a->top, "a");
	//disp(b->top, "b");
    return (a);
}