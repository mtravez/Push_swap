/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:36:25 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 20:23:54 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_cell(t_list **head, t_list *to_remove)
{
	t_list	*temp;

	temp = *head;
	if (to_remove == *head)
	{
		*head = to_remove->next;
		free(to_remove->content);
		free(to_remove);
		return ;
	}
	while (temp && temp->next != to_remove)
		temp = temp->next;
	if (temp)
	{
		temp->next = to_remove->next;
		free(to_remove->content);
		free(to_remove);
	}
}

void	efficient(t_holder *holder)
{
	t_list	*current;
	t_list	*next;

	current = holder->instructions;
	while (current)
	{
		next = current->next;
		if (next && ft_strncmp((char *)current->content, "pb\n", 3) == 0 && \
		ft_strncmp((char *)next->content, "pa\n", 3) == 0)
		{
			remove_cell(&holder->instructions, current);
			remove_cell(&holder->instructions, next);
			current = holder->instructions;
		}
		else if (next && ft_strncmp((char *)current->content, "pa\n", 3) == 0 && \
		ft_strncmp((char *)next->content, "pb\n", 3) == 0)
		{
			remove_cell(&holder->instructions, current);
			remove_cell(&holder->instructions, next);
			current = holder->instructions;
		}
		current = current->next;
	}
}

void	sort(t_holder *holder)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i <= holder->n)
	{
		j = 0;
		while (j < holder->size)
		{
			index = holder->a->index;
			if (((index << (holder->n - i)) >> (holder->n - 1)) & 1)
				ra(holder);
			else
				pb(holder);
			j++;
		}
		while (holder->b)
			pa(holder);
		i++;
	}
	efficient(holder);
}
