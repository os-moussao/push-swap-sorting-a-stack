/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:28 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 00:45:31 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nbr)
{
	char		c;
	long long	n;

	n = (long long)nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	disp(t_node *stack, char *name)
{
	while (stack)
	{
		ft_putnbr(stack->data);
		write(1, "\n", 1);
		stack = stack->next;
	}
	write(1, "-\n", 2);
	ft_putstr(name);
	write(1, "\n", 1);
}

void	revdisp(t_node *bottom, char *name)
{
	while (bottom)
	{
		ft_putnbr(bottom->data);
		write(1, "\n", 1);
		bottom = bottom->prev;
	}
	write(1, "-\n", 2);
	ft_putstr(name);
	write(1, "\n", 1);
}