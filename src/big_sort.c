/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:56:58 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/17 19:47:28 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

static void	frin(t_list **stack, int *val)
{
	ft_lstclear(&stack[0]);
	ft_lstclear(&stack[1]);
	free(val);
}

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

static void	big_sort(t_list **stacks, int size, int	*val)
{
	int	i;
	int	data[3];

	i = 1;
	simp_stack(stacks[0], val, size);
	while (i < 6)
	{
		data[0] = (size / 5) + (size % 5) * (1 / i);
		data[1] = (size / 5) * (6 - i) + (size % 5) * (1 / i);
		data[2] = (size / 5) * (5 - i) + 1;
		chunck(stacks, size, data);
		i++;
	}
	frin(stacks, val);
}

static void	med_sort(t_list **stacks, int size, int	*val)
{
	int	i;
	int	min;
	int	*durp;

	i = 0;
	while (i < size - 2)
	{
		min = find_min(val, size - i);
		sm_rotate(stacks, min, size - i, 'a');
		push (&stacks[0], &stacks[1], 'b');
		i++;
		durp = dump(stacks[0]);
		free(val);
		val = simplify(durp, size - i, i);
	}
	durp = dump(stacks[0]);
	if (durp[0] > durp[1])
		swap(&stacks[0], 'a');
	free(durp);
	while (i > 0)
	{
		push (&stacks[1], &stacks[0], 'a');
		i--;
	}
	frin(stacks, val);
}

void	sort(t_list **stacks, int size)
{
	int	*val;
	int	*s_val;

	val = (dump(stacks[0]));
	s_val = simplify(val, size, 0);
	if (size < 100)
		med_sort(stacks, size, s_val);
	else if (size > 99 && size < 500)
		big_sort(stacks, size, s_val);
	else
		giant_sort(stacks, size, s_val);
}
