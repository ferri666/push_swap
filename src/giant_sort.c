/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giant_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:06:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/17 19:30:20 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

static void	chunck(t_list **stack, int size, int data[])
{
	int	i;
	int	*sdump;

	i = 0;
	while (i < data[0])
	{
		sdump = s_dump(stack[0]);
		sm_rotate(stack, f_chunck(sdump, data[2], data[1], size), size, 'a');
		push(&stack[0], &stack[1], 'b');
		i++;
		size--;
	}
	sdump = s_dump(stack[0]);
	sm_rotate(stack, find_n(sdump, (data[1] + 1), size), size, 'a');
	free(sdump);
	while (i > 0)
	{
		sdump = s_dump(stack[1]);
		data[2] = find_max(sdump, i);
		free(sdump);
		sm_rotate(stack, data[2], i, 'b');
		push(&stack[1], &stack[0], 'a');
		i--;
	}
}
/*
data[0] = num valores
data[1] = max
data[2] = min
*/

void	giant_sort(t_list **stacks, int size, int	*val)
{
	int	i;
	int	data[3];

	i = 1;
	simp_stack(stacks[0], val, size);
	while (i < 11)
	{
		data[0] = (size / 10) + (size % 10) * (1 / i);
		data[1] = (size / 10) * (11 - i) + (size % 10) * (1 / i);
		data[2] = (size / 10) * (10 - i) + 1;
		chunck(stacks, size, data);
		i++;
	}
	free(val);
	ft_lstclear(&stacks[0]);
	ft_lstclear(&stacks[1]);
}
