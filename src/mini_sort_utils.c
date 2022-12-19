/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:40:40 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 14:49:46 by ffons-ti         ###   ########.fr       */
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

static void	sort5cases4(t_list **stack, int *val)
{
	if ((val[0] == 4 && val[1] == 1) || (val[0] == 1 && val[1] == 4))
	{
		rev_rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		rotate(&stack[0], 'a');
		rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		frin(stack, val);
	}
}

static void	sort5cases3(t_list **stack, int *val)
{
	if (val[0] == 3 || val[1] == 3)
	{
		push(&stack[1], &stack[0], 'a');
		swap(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		frin(stack, val);
	}
	if ((val[0] == 4 && val[1] == 2) || (val[0] == 2 && val[1] == 4))
	{
		rev_rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		rotate(&stack[0], 'a');
		rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		swap(&stack[0], 'a');
		frin(stack, val);
	}
	if (!finished(stack))
		sort5cases4(stack, val);
}

static void	sort5cases2(t_list **stack, int *val)
{
	if ((val[0] == 4 && val[1] == 3) || (val[0] == 3 && val[1] == 4))
	{
		rev_rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		rev_rotate(&stack[0], 'a');
		rev_rotate(&stack[0], 'a');
		frin(stack, val);
	}
	if (val[0] == 5 || val[1] == 5)
	{
		push(&stack[1], &stack[0], 'a');
		rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		if (val[0] == 2 || val[1] == 2)
			swap(&stack[0], 'a');
		frin(stack, val);
	}
	if (!finished(stack))
		sort5cases3(stack, val);
}

void	sort5cases(t_list **stack, int *val)
{
	print_array(val, 5);
	if ((val[0] == 4 && val[1] == 5) || (val[0] == 5 && val[1] == 4))
	{
		push(&stack[1], &stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		rotate(&stack[0], 'a');
		rotate(&stack[0], 'a');
	}
	else if ((val[0] == 3 && val[1] == 5) || (val[0] == 5 && val[1] == 3))
	{
		rev_rotate(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		swap(&stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
		rev_rotate(&stack[0], 'a');
		rev_rotate(&stack[0], 'a');
	}
	else if ((val[0] == 1 && val[1] == 2) || (val[0] == 2 && val[1] == 1))
	{
		push(&stack[1], &stack[0], 'a');
		push(&stack[1], &stack[0], 'a');
	}
	else
		sort5cases2(stack, val);
}
