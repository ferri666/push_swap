/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:58:12 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/17 19:24:23 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

/*
FUNCTION: find_n
Given an array of integers, it returns the index of node with value 'n'
*/
int	find_n(int *val, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (val[i] == n)
			return (i);
		i++;
	}
	return (0);
}

/*
FUNCTION: find_max
Given an array of integers, it returns the index of the highest value
*/
int	find_max(int *val, int size)
{
	int	i;
	int	max_val;
	int	max_idx;

	i = 0;
	max_val = val[i];
	while (i < size)
	{
		if (val[i] > max_val)
		{
			max_idx = i;
			max_val = val[i];
		}
		i++;
	}
	return (max_idx);
}

/*
FUNCTION: find_min
Given an array of integers, it returns the index of the lowest value
*/
int	find_min(int *val, int size)
{
	int	i;
	int	min_val;
	int	min_idx;

	i = 0;
	min_idx = 0;
	min_val = val[i];
	while (i < size)
	{
		if (val[i] < min_val)
		{
			min_idx = i;
			min_val = val[i];
		}
		i++;
	}
	return (min_idx);
}

/*
FUNCTION: dump
This return an array with all the values of the list we gave it.
If there is a problem with the alocation it returns NULL
*/
int	*dump(t_list *stack)
{
	int		*val;
	int		i;
	int		size;

	i = 0;
	stack = ft_lstfirst(stack);
	size = ft_lstsize(stack);
	val = (int *)malloc(sizeof(int) * size);
	if (!val)
		return (NULL);
	while (i < size)
	{
		val[i] = stack->val;
		i++;
		if (i < size)
			stack = stack->next;
	}
	return (val);
}

/*
FUNCTION: print_array
This prints all elements of an array of 'n' size to sdout, 
followed by a line break. A debugging tool for working with arrays
*/
void	print_array(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
