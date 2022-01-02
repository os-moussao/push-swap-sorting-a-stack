/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:36 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 16:13:21 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack	*a;

	a = create(av + 1, ac - 1);

	disp(a->top, "a");
	ft_putstr("\n\n");
	revdisp(a->bottom, "a");

	ft_putstr("\n\ninstructions:\n");
	sort_stack(a);

	ft_putstr("\n\nAfter sort:\n");
	disp(a->top, "a");
	ft_putstr("\n\n");
	revdisp(a->bottom, "a");
	
	clear(a);
}