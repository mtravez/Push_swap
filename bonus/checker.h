/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:55:47 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/09 19:51:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	ss(t_holder *holder);
void	rr(t_holder *holder);
void	rrr(t_holder *holder);

int		check(char *inst, t_holder *holder);
void	printlist(t_stack *list);

#endif