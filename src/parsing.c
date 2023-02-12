/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:42:27 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 18:05:00 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function checks the stack A for duplicates and returns 
0 if it doesn't*/
static int	has_doubles(t_holder *holder)
{
	t_stack	*temp;
	t_stack	*compare;

	temp = holder->a;
	while (temp->next)
	{
		compare = temp->next;
		while (compare)
		{
			if (temp->number == compare->number)
				return (1);
			compare = compare->next;
		}
		temp = temp->next;
	}
	return (0);
}

/*This function checks if the argument given by the user
is valid. It checks if it is a number and if it contains more than
one '-' character*/
static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i != 0)
			return (0);
		else if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

/*This function fills a stack with the contents of a string array.
It will check for doubles, if each element is a valid number and if
it doesn't exceed the integer limits.*/
int	put_stack(char **numbers, t_holder *holder)
{
	int	i;

	i = 0;
	while (numbers[i])
		if (!is_valid(numbers[i++]))
			return (0);
	holder->size = i;
	i--;
	while (i >= 0)
	{
		push(ft_atoi(numbers[i]), 0, &holder->a);
		if ((holder->a->number < 0 && numbers[i][0] != '-') || \
		(holder->a->number > 0 && numbers[i][0] == '-'))
			return (0);
		i--;
	}
	if (has_doubles(holder))
		return (0);
	return (1);
}
