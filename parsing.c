/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:42:27 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 18:26:42 by mtravez          ###   ########.fr       */
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
			{
				ft_printf("%i, %i", temp->number, compare->number);
				return (1);
			}
				
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
	// char **zahl;

	// zahl = ft_split(numbers, ' ');
	i = 1;
	while (numbers[i])
	{
		if (!is_valid(numbers[i++]))
		{
			// free_array(numbers);
			return (0);
		}
	}
	holder->size = i - 1;
	i--;
	while (i >= 1)
		push(ft_atoi(numbers[i--]), 0, &holder->a);
	if (has_doubles(holder))
	{
		free_holder(holder);
		return (0);
	}
	// free_array(numbers);
	return (1);
}

// int main(void)
// {
// 	t_holder *hi;
	
// 	hi = malloc(sizeof(t_holder *) + sizeof(t_stack *) * 2);
// 	hi->a = NULL;
// 	hi->b = NULL;
// 	hi->size = 0;
// 	if (put_stack("1 2 5 3 6 9 7 -5 -1 5", hi))
// 		ft_printf("%i\n", has_doubles(hi));
// 	printlist(hi->a);
// 	return (0);
// }