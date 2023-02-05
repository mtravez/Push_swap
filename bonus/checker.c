/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:27:04 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/05 16:21:36 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_holder	*holder;
	char		*line;

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
	line = get_next_line(1);
	while (line)
	{
		if (!check(line, holder))
		{
			ft_printf("Error\n");
			free_holder(holder);
			return (0);
		}
		line = get_next_line(1);
	}
	if (is_sorted(holder->a))
		ft_printf("OK");
	else
		ft_printf("KO");
	free_holder(holder);
	// system("leaks push_swap");
}
