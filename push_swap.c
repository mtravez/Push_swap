/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:55:54 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 20:43:32 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_holder	*init_holder(char **numbers)
{
	t_holder	*newh;
	int			bits;
	int			max;

	newh = malloc(sizeof(t_holder *) + sizeof(t_stack) \
	* 2 + sizeof(t_list *) * 2);
	newh->a = NULL;
	newh->b = NULL;
	if (!put_stack(numbers, newh))
		return (NULL);
	max = newh->size;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	newh->n = bits;
	newh->instructions = NULL;
	put_index(newh);
	return (newh);
}

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
	if (holder->size == 1)
		return (0);
	sort(holder);
	print_instructions(holder->instructions);
	free_holder(holder);
	// system("leaks push_swap");
}
