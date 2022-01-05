/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:32:25 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/05 18:35:07 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

# define NA 0
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define BUFFER_SIZE 100000

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
char	*get_next_line(int fd);

t_stack	*create(char **av, int ac);
t_stack	*new_stack(void);
void	push(t_stack *stack, int data, char *str);
int		pop(t_stack *stack);
void	swap(t_stack *stack, char *str);
void	clear(t_stack *stack);
void	rotate(t_stack *stack, char *str);
void	rrotate(t_stack *stack, char *str);

bool	sorted(t_node *top);
int		select_max(t_node *a);
t_stack	*selection_sort(t_stack *a);
t_stack	*div_sort(t_stack *a, int div);
t_stack	*sort_stack(t_stack *a);

#endif