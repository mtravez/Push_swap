/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:34:37 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/04 16:52:56 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int	*copy_a_array(t_holder *holder)
{
	int	*copy;
	t_stack *temp;
	int i = 0;
	
	copy = malloc(sizeof(int) * holder->size);
	temp = holder->a;
	while (temp)
	{
		copy[i] = temp->number;
		temp = temp->next;
		i++;
	}
	return (copy);
}

void	put_index_array(int *sar, t_holder *holder)
{
	int		i;
	t_stack	*temp;

	temp = holder->a;
	while (temp)
	{
		i = 0;
		while (i < holder->size)
		{
			if (temp->number == sar[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	swap_array(int *cell1, int *cell2)
{
	int	temp;

	temp = *cell1;
	*cell1 = *cell2;
	*cell2 = temp;
}

int	*sorted_array(int *copy, int size)
{
	int	i;
	int	j;
	int	h;

	h = size / 2;
	while (h >= 1)
	{
		j = h;
		while (j < size)
		{
			i = j - h;
			while (i >= 0)
			{
				if (copy[i] > copy[i + h])
					swap_array(&copy[i], &copy[i + h]);
				else
					break ;
				i -= h;
			}
			j++;
		}
		h = h / 2;
	}
	return (copy);
}

void	put_index(t_holder *holder)
{
	int	*array;
	
	array = copy_a_array(holder);
	sorted_array(array, holder->size);
	// draw_array(array, holder->size);
	put_index_array(array, holder);
	free(array);
}


// int main()
// {
// 	int hi[] = {5, 8, 6, 3, 9, 7, 2, 1, 4, 0, -2, -8, -5, -1, -3, -9, -7, -6, -4};
// 	draw_array(hi, 19);
// 	sorted_array(hi, 19);
// 	ft_printf("\n");
// 	draw_array(hi, 19);
// }