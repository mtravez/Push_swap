/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:00:22 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/05 15:25:44 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_holder *holder)
{
	swap(&holder->a);
	swap(&holder->b);
}

void	rr(t_holder *holder)
{
	rotate(&holder->a);
	rotate(&holder->b);
}

void	rrr(t_holder *holder)
{
	reverse_rotate(&holder->a);
	reverse_rotate(&holder->b);
}
