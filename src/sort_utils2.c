/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:38:42 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/16 17:47:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

/*
FUNCTION: simplify
Given an unsorted array of n size, we return an unsorted array of 'n' size.
But the numbers are simpler, going from 1 + off to n, in the same position 
they are on the array.
*/
int	*simplify(int *array, size_t size, int off)
{
	size_t	i;
	size_t	j;
	int		num;
	int		*simp;

	i = 0;
	simp = (int *)malloc(sizeof(int) * size);
	if (!array || size <= 0 || !simp)
		return (NULL);
	while (i < size)
	{
		j = 0;
		num = 1;
		while (j < size)
		{
			if (array[i] > array[j])
				num++;
			j++;
		}
		simp[i] = num + off;
		i++;
	}
	free(array);
	return (simp);
}

/*
This initializes the s_val on all elements of the stack
The array we give it is the result of the function above
*/
void	simp_stack(t_list *stack, int *array, size_t size)
{
	size_t	i;
	t_list	*first;

	first = ft_lstfirst(stack);
	i = 0;
	while (i < size)
	{
		first->s_val = array[i];
		i++;
		first = first->next;
	}
}

/*
To dump the s_val into an array
*/
int	*s_dump(t_list *stack)
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
		val[i] = stack->s_val;
		i++;
		if (i < size)
			stack = stack->next;
	}
	return (val);
}
