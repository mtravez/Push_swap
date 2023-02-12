/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:27:04 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 18:30:07 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*This function reads the commands in the command line for 
instructions until a null terminator is given.*/
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
			free(line);
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
	char		**arguments;

	if (argc < 2)
		return (0);
	arguments = &argv[1];
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	holder = init_holder(arguments);
	if (!holder)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!read_commands(holder))
		return (0);
	if (is_sorted(holder->a) && !holder->b)
		ft_printf("OK");
	else
		ft_printf("KO");
	free_holder(holder);
	return (0);
}
