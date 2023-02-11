/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:42:27 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/10 15:02:28 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_doubles(t_holder *holder)
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

int	is_valid(char *str)
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

int	put_stack(char **numbers, t_holder *holder)
{
	int	i;

	i = 1;
	while (numbers[i])
		if (!is_valid(numbers[i++]))
			return (0);
	holder->size = i - 1;
	i--;
	while (i >= 1)
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
