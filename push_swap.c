/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:55:54 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/10 13:33:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printlist(t_stack *list)
// {
// 	t_stack	*temp;

// 	temp = list;
// 	while (temp)
// 	{
// 		ft_printf("[%i] -> ", temp->number);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }

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
		system("leaks push_swap");
		return (0);
	}
	if (holder->size == 1 || is_sorted(holder))
	{
		free_holder(holder);
		return (0);
	}
	if (holder->size > 5)
		sort(holder);
	else
		sort_short(holder);
	print_instructions(holder->instructions);
	printlist(holder->a);
	free_holder(holder);
}
