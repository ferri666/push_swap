/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:14:03 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/17 18:41:28 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	f_chunck(int *val, int min, int max, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (val[i])
	{
		if (val[i] > max || val[i] < min)
			i++;
		else
			break ;
	}
	while (val[j])
	{
		if (val[j] > max || val[j] < min)
			j--;
		else
			break ;
	}
	free(val);
	if (i > (size - j))
		return (j);
	else
		return (i);
}

void	sm_rotate(t_list **stacks, int n, int size, char c)
{
	if (n < size / 2)
		up_to_top(stacks, n, c);
	else
		down_to_top(stacks, n, size, c);
}

/*
Takes the element of the stack 'c' in the 'n' position 
and puts it the first of the list using rotate
*/
void	up_to_top(t_list **stacks, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (c == 'a')
			rotate(&stacks[0], c);
		else
			rotate(&stacks[1], c);
		i++;
	}
}

/*
Takes the element of the stack 'c' in the 'n' position 
and puts it the first  of the list using reverse rotate
*/
void	down_to_top(t_list **stacks, int n, int size, char c)
{
	int	i;

	i = 0;
	while (i < size - n)
	{
		if (c == 'a')
			rev_rotate(&stacks[0], c);
		else
			rev_rotate(&stacks[1], c);
		i++;
	}
}
