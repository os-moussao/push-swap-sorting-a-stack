/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:25 by omoussao          #+#    #+#             */
/*   Updated: 2021/12/29 20:08:20 by omoussao         ###   ########.fr       */
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
void	push(t_node **stack, int data, char *str);
int		pop(t_node **stack);
void	swap(t_node *stack, char *str);
void	clear(t_stack *stack);
void	rotate(t_stack *stack, char *str);
void	rrotate(t_stack *stack, char *str);
int		stack_len(t_node *stack);
int		bottom(t_node *stack);

t_node	*sort_stack(t_node *a);

#endif
