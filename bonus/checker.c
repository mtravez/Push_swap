/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:27:04 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/10 13:03:14 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printlist(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp)
	{
		ft_printf("[%i] -> ", temp->number);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	read_commands(t_holder *holder)
{
	char	*line;

	line = get_next_line(1);
	while (line)
	{
		if (!check(line, holder))
		{
			ft_printf("Error\n");
			free_holder(holder);
			return (0);
		}
		free(line);
		line = get_next_line(1);
	}
	return (1);
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
	if (!read_commands(holder))
		return (0);
	if (is_sorted(holder))
		ft_printf("OK");
	else
		ft_printf("KO");
	free_holder(holder);
	// system("leaks checker");
	return (0);
}
