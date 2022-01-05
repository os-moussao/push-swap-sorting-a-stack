/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:28:23 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/05 18:47:19 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_error(t_stack *a, t_stack *b)
{
	clear(a);
	clear(b);
	error();
}

int	command_id(char *com)
{
	if (!ft_strncmp(com, "sa\n", 3))
		return (SA);
	else if (!ft_strncmp(com, "sb\n", 3))
		return (SB);
	else if (!ft_strncmp(com, "ss\n", 3))
		return (SS);
	else if (!ft_strncmp(com, "pa\n", 3))
		return (PA);
	else if (!ft_strncmp(com, "pb\n", 3))
		return (PB);
	else if (!ft_strncmp(com, "ra\n", 3))
		return (RA);
	else if (!ft_strncmp(com, "rb\n", 3))
		return (RB);
	else if (!ft_strncmp(com, "rr\n", 3))
		return (RR);
	else if (!ft_strncmp(com, "rra\n", 4))
		return (RRA);
	else if (!ft_strncmp(com, "rrb\n", 4))
		return (RRB);
	else if (!ft_strncmp(com, "rrr\n", 4))
		return (RRR);
	return (NA);
}

int	exec(t_stack *a, t_stack *b, int cid)
{
	if (cid == SA && a->len >= 2)
		return (swap(a, NULL), 1);
	else if (cid == SB && b->len >= 2)
		return (swap(b, NULL), 1);
	else if (cid == SS && a->len >= 2 && b->len >= 2)
		return (ss(a, b), 1);
	else if (cid == PA && b->len)
		return (push(a, pop(b), NULL), 1);
	else if (cid == PB && a->len)
		return (push(b, pop(a), NULL), 1);
	else if (cid == RA && a->len >= 2)
		return (rotate(a, NULL), 1);
	else if (cid == RB && b->len >= 2)
		return (rotate(b, NULL), 1);
	else if (cid == RR && a->len >= 2 && b->len >= 2)
		return (rr(a, b), 1);
	else if (cid == RRA && a->len >= 2)
		return (rrotate(a, NULL), 1);
	else if (cid == RRB && b->len >= 2)
		return (rrotate(b, NULL), 1);
	else if (cid == RRR && a->len >= 2 && b->len >= 2)
		return (rrr(a, b), 1);
	return (0);
}

bool	sort(t_stack *a, t_stack *b)
{
	char	*com;
	int		cid;

	com = get_next_line(0);
	while (com)
	{
		cid = command_id(com);
		if (!cid)
			checker_error(a, b);
		if (!exec(a, b, cid))
		{
			free(com);
			return (0);
		}
		free(com);
		com = get_next_line(0);
	}
	return (!b->len && sorted(a->top));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (1);
	a = create(av + 1, ac - 1);
	b = new_stack();
	if (sort(a, b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	clear(a);
	clear(b);
}
