/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:36 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 00:51:03 by omoussao         ###   ########.fr       */
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

	//printf("len = %d\n", a->len);
	//ft_putstr("Begin:\n");
	//disp(a, 'a');
	//ft_putstr("\n\n\n");
	//a = sort_stack(a);
	clear(a);
	//ft_putstr("\n\n\nEnd:\n");
	//disp(a, 'a');
}