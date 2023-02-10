/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:56:41 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/10 15:12:58 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_holder
{
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;
	int		n;
	int		size;
}	t_holder;

t_stack		*new_cell(int number, int index);
void		push(int number, int index, t_stack **stack);
void		pop(t_stack **stack);
int			stack_size(t_stack *stack);
void		put_last(t_stack *to_last, t_stack **stack);
void		swap(t_stack **stack);
void		push_stack(t_stack **from, t_stack **to);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
int			checker(char **instructions, t_stack **a, t_stack **b);
int			is_sorted(t_holder *holder);

void		swap(t_stack **stack);
void		push_stack(t_stack **from, t_stack **to);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);

int			put_stack(char **numbers, t_holder *holder);
void		put_index(t_holder *holder);

void		free_stack(t_stack *stack);
void		free_holder(t_holder *holder);
void		free_array(char **array);
void		free_list(t_list *head);

void		sort(t_holder *holder);
void		sort_short(t_holder *holder);
void		pa(t_holder *holder);
void		pb(t_holder *holder);
void		ra(t_holder *holder);
void		rb(t_holder *holder);
void		sa(t_holder *holder);
void		sb(t_holder *holder);
void		rra(t_holder *holder);
void		rrb(t_holder *holder);
t_holder	*init_holder(char **numbers);

void	printlist(t_stack *list);


#endif