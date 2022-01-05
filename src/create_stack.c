/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:45:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/05 18:53:43 by omoussao         ###   ########.fr       */
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
	int	i;

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

bool	append(t_stack *stack, char **arr)
{
	int			len;
	long long	nbr;
	t_node		*tmp;

	len = arr_len(arr);
	while (len--)
	{
		nbr = _strtol(arr[len]);
		if (nbr == LONG_MIN)
			return (0);
		push(stack, (int)nbr, NULL);
		tmp = stack->top->next;
		while (tmp)
		{
			if (tmp->data == stack->top->data)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
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
		if (!append(stack, arr))
		{
			clear_arr(arr);
			clear(stack);
			error();
		}
		clear_arr(arr);
	}
	return (stack);
}
