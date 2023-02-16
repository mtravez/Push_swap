/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:36:25 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/15 15:17:32 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function returns the last cell in a stack*/
t_stack	*get_last_stack(t_stack *head)
{
	if (!head)
		return (head);
	while (head->next)
		head = head->next;
	return (head);
}

/*This function removes a specific cell from the given list
and frees the space
@param head pointer to the head of thee list
@param to_remove the list cell to be removed*/
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

/*This function removes instructions that negate each other*/
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
		else
			current = current->next;
	}
}

/*This is the main algorithm that sorts a list. It is based on radix sort
and utilizes binary numbers to be able to sort using only two buckets.
For each bit, it will push every 0 to stack B, and leave each 1 in stack
A by rotating it. When the reading of the current bit of every cell in
the stack is done, all cells in stack B will be returned to stack A.*/
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
			if ((index >> i) & 1)
				ra(holder);
			else
				pb(holder);
			if (is_sorted(holder->a) && !holder->b)
				return ;
			j++;
		}
		while (holder->b)
			pa(holder);
		i++;
	}
}
