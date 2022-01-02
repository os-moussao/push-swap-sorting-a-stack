/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:25 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/02 13:44:02 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"


typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		len;
}				t_stack;

void	ft_swap(int *a, int *b);
void	error(void);
void	disp(t_node *stack, char *name);
void	revdisp(t_node *bottom, char *name);
void	ft_putnbr(int n);
void	ft_putstr(char *str);

t_stack	*create(char **av, int ac);
t_stack	*new_stack(void);
void	push(t_stack *stack, int data, char *str);
int		pop(t_stack *stack);
void	swap(t_stack *stack, char *str);
void	clear(t_stack *stack);
void	rotate(t_stack *stack, char *str);
void	rrotate(t_stack *stack, char *str);

t_node	*sort_stack(t_stack *a);

#endif
