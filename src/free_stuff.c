/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:00:45 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/15 16:19:35 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function frees a two dimentional array*/
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*This function frees a stack*/
void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		stack = temp->next;
		free(temp);
		temp = stack;
	}
}

/*This function frees a list*/
void	free_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		free(temp->content);
		head = temp->next;
		free(temp);
		temp = head;
	}
}

/*This function frees a holder*/
void	free_holder(t_holder *holder)
{
	free_stack(holder->a);
	free_stack(holder->b);
	free_list(holder->instructions);
	free(holder);
}

int	throw_error(void)
{
	ft_printf("Error\n");
	return (0);
}
