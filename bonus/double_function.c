/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:00:22 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 13:21:37 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*This function swaps the first and second elements in stacks A and B*/
void	ss(t_holder *holder)
{
	swap(&holder->a);
	swap(&holder->b);
}

/*This function moves the second element in both stacks A and B to first
and first to last*/
void	rr(t_holder *holder)
{
	rotate(&holder->a);
	rotate(&holder->b);
}

/*This function moves the last element in both stacks A and B to first*/
void	rrr(t_holder *holder)
{
	reverse_rotate(&holder->a);
	reverse_rotate(&holder->b);
}
