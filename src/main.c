/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:09:37 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/16 19:13:21 by omoussao         ###   ########.fr       */
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

	printf("len = %d\n", a->len);
	//ft_putstr("Begin:\n");
	//disp(a, 'a');
	//ft_putstr("\n\n\n");
	//a = sort_stack(a);
	clear(a);
	//ft_putstr("\n\n\nEnd:\n");
	//disp(a, 'a');
}