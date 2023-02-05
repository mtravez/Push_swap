/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:32:18 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/05 16:26:43 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check(char *inst, t_holder *holder)
{
	if (ft_strncmp(inst, "sa", 2) == 0)
		swap(&holder->a);
	else if (ft_strncmp(inst, "sb", 2) == 0)
		swap(&holder->b);
	else if (ft_strncmp(inst, "ss", 2) == 0)
		ss(holder);
	else if (ft_strncmp(inst, "pa", 2) == 0)
		push_stack(&holder->b, &holder->a);
	else if (ft_strncmp(inst, "pb", 2) == 0)
		push_stack(&holder->a, &holder->b);
	else if (ft_strncmp(inst, "ra", 2) == 0)
		rotate(&holder->a);
	else if (ft_strncmp(inst, "rb", 2) == 0)
		rotate(&holder->b);
	else if (ft_strncmp(inst, "rr", 2) == 0)
		rr(holder);
	else if (ft_strncmp(inst, "rra", 3) == 0)
		reverse_rotate(&holder->a);
	else if (ft_strncmp(inst, "rrb", 3) == 0)
		reverse_rotate(&holder->b);
	else if (ft_strncmp(inst, "rrr", 3) == 0)
		rrr(holder);
	else
		return (0);
	return (1);
}

