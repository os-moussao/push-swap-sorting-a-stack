/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 13:44:36 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static void	clear_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

long long	_strtol(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1 - (str[0] == '-') * 2;
	i = (str[0] == '+' || str[0] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	res *= (long long)sign;
	if (str[i] || res > INT_MAX || res < INT_MIN)
		return (LONG_MIN);
	return (res);
}

void	append(t_stack *stack, char **arr)
{
	int			len;
	long long	nbr;
	t_node		*tmp;

	len = arr_len(arr);
	while (len--)
	{
		nbr = _strtol(arr[len]);
		if (nbr == LONG_MIN)
		{
			clear_arr(arr);
			clear(stack);
			error();
		}
		push(stack, (int)nbr, NULL);
		tmp = stack->top->next;
		while (tmp)
		{
			if (tmp->data == stack->top->data)
			{
				clear_arr(arr);
				clear(stack);
				error();
			}
			tmp = tmp->next;
		}
	}
}

t_stack	*create(char **av, int ac)
{
	t_stack	*stack;
	char	**arr;

	stack = new_stack();
	if (!stack)
		error();
	while (ac--)
	{
		arr = ft_split(av[ac], ' ');
		if (!arr)
		{
			clear(stack);
			error();
		}
		append(stack, arr);
		clear_arr(arr);
	}
	return (stack);
}