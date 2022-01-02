/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:35:41 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 20:55:53 by omoussao         ###   ########.fr       */
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


#include <stdio.h>
t_stack	*div_sort(t_stack *a)
{
    //int *tab;

    //tab = get_tab(a);
    //for (int i = 0; i < a->len; i++)
    //    printf("tab[%d] = %d\n", i, tab[i]);
    return (a);
}