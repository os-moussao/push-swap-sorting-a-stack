/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:36 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/07 17:17:08 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (div_sort(a, 5));
	return (div_sort(a, 13));
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac <= 1)
		return (1);
	a = create(av + 1, ac - 1);
	sort_stack(a);
	clear(a);
}
