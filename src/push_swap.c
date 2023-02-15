/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:55:54 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/15 12:43:43 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function will print the instructions in list*/
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
	char		**arguments;

	if (argc < 2)
		return (0);
	arguments = &argv[1];
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	holder = init_holder(arguments);
	if (!holder)
		return (throw_error("Error\n"));
	if (holder->size == 1 || is_sorted(holder->a))
	{
		free_holder(holder);
		return (0);
	}
	if (holder->size >= 50)
		sort(holder);
	else
		sort_short(holder);
	efficient(holder);
	print_instructions(holder->instructions);
	free_holder(holder);
}
