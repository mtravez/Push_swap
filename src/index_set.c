/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:34:37 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/12 12:44:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function copies the contents of stack A to an
int array so it can be sorted*/
static int	*copy_a_array(t_holder *holder)
{
	int		*copy;
	t_stack	*temp;
	int		i;

	i = 0;
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

/*This function puts the index f the ordered array for each
element on the stack A in holder, thus giving every element
a positive value and where in the stack it should be placed.
@param sar the sorted array
@param holder the holder containing the stacks and size*/
static void	put_index_array(int *sar, t_holder *holder)
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

/*This function swaps the contents of two cells in an array*/
static void	swap_array(int *cell1, int *cell2)
{
	int	temp;

	temp = *cell1;
	*cell1 = *cell2;
	*cell2 = temp;
}

/*This function is a shell sort algorithm that sorts an integer
array. It is used here to asssign the elements in the stack an index
of where in an array they would be if it was sorted.*/
static int	*sorted_array(int *copy, int size)
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

/*This function gives every element in stack A its index in a
sorted array.*/
void	put_index(t_holder *holder)
{
	int	*array;

	array = copy_a_array(holder);
	sorted_array(array, holder->size);
	put_index_array(array, holder);
	free(array);
}
