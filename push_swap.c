/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:55:54 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/05 18:09:38 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		ft_printf("%s", ((char *)(temp->content)));
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_holder	*holder;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	holder = init_holder(argv);
	if (!holder)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (holder->size == 1 || is_sorted(holder->a))
	{
		free_holder(holder);
		return (0);
	}
	sort(holder);
	print_instructions(holder->instructions);
	free_holder(holder);
	// system("leaks push_swap");
}
