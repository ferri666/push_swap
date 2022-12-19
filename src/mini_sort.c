/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:22:45 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 12:52:01 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

/*
With 3 numbers, there are 5 not ordered combinations. That's easy as pie.
We just analize each diferent case and make the apropiate moves.
*/
static void	sort3(t_list **stack, int *val, char c)
{
	if (((val[0] > val[1] && val[1] < val[2] && val[0] < val[2])
			|| (val[0] < val[1] && val[1] > val[2] && val[0] < val[2])
			|| (val[0] > val[1] && val[1] > val[2] && val[0] > val[2]))
		&& c != 'd')
		swap(&stack[0], 'a');
	if (((val[0] > val[1] && val[1] < val[2] && val[0] < val[2])
			|| (val[0] < val[1] && val[1] > val[2] && val[0] < val[2])
			|| (val[0] > val[1] && val[1] > val[2] && val[0] > val[2]))
		&& c == 'd')
		ss(stack);
	if (val[0] < val[1] && val[1] > val[2] && val[0] < val[2])
		rotate(&stack[0], 'a');
	if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2] && c != 'd')
		rev_rotate(&stack[0], 'a');
	if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2] && c == 'd')
		rrr(stack);
	if (val[0] < val[1] && val[1] < val[2] && val[0] < val[2] && c == 'd')
		swap(&stack[0], 'a');
	if (val[0] > val[1] && val[1] > val[2] && val[0] > val[2])
		rev_rotate(&stack[0], 'a');
	if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2] && c != 'd')
		rotate(&stack[0], 'a');
	if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2] && c == 'd')
		rr(stack);
}

/*
With 4 numbers, there are 23 different not-ordered combinations. That's a bunch.
To reduce this, we do the following:

1-Put the lowest number at the top

	-Swap if it's 2nd
	-Double Rev Rotate if it's 3rd
	-Rev Rotate if it's 4th
	-Rotate in a particular case 
	where we just need one movement

2-If it's not sorted, then we Push it to Stack B

3-Order Stack A with the function sort3()

4-Push back the lowest Number

5-Voilá! It's sorted.
*/
static void	sort4(t_list **stack, int *val)
{
	if (val[0] > val[1] && val[0] > val[2] && val[0] > val[3]
		&& val[1] < val[2] && val[1] < val[3] && val[2] < val[3])
		rotate(&stack[0], 'a');
	else if (val[0] > val[1] && val[1] < val[2] && val[1] < val[3])
		swap(&stack[0], 'a');
	if (val[3] < val[0] && val[3] < val[2] && val[3] < val[1])
		rev_rotate(&stack[0], 'a');
	if (val[2] < val[0] && val[2] < val[1] && val[2] < val[3])
	{
		rev_rotate(&stack[0], 'a');
		rev_rotate(&stack[0], 'a');
	}
	if (!finished(&stack[0]))
	{
		val = dump(ft_lstfirst(stack[0]));
		push(&stack[0], &stack[1], 'b');
		sort3(stack, ++val, 'q');
		push(&stack[1], &stack[0], 'a');
	}
}

/*
With 5 numbers, there are 119 not-ordered combinations. That's too much man...
To reduce the number of cases, we double push the first 2 numbers
then we order Stack A with 
*/
static void	sort5(t_list **stack, int *val)
{
	if (val[0] == 2 && val[1] == 1 && val[2] == 3 && val[3] == 4 && val[4] == 5)
	{
		swap(&stack[0], 'a');
		return ;
	}
	if (val[0] == 5 && val[1] == 4 && val[2] == 1 && val[3] == 2 && val[4] == 3)
	{
		swap(&stack[0], 'a');
		rotate(&stack[0], 'a');
		rotate(&stack[0], 'a');
		return ;
	}
	push(&stack[0], &stack[1], 'b');
	push(&stack[0], &stack[1], 'b');
	if (val[0] > val[1])
		sort3(&stack[0], (val + 2), 'd');
	else
		sort3(&stack[0], (val + 2), 'q');
	sort5cases(stack, val);
}

void	mini_sort(t_list **stacks, int size)
{
	int	*val;
	int	*sval;

	val = dump(stacks[0]);
	sval = NULL;
	if (size == 2 && !finished(&stacks[0]))
		swap(&stacks[0], 'a');
	if (size == 3)
	{
		sort3(stacks, val, 'n');
		free(val);
	}
	if (size == 4)
	{
		sort4(stacks, val);
		free(val);
	}
	if (size == 5)
	{
		sval = simplify(val, 5, 0);
		sort5(stacks, sval);
	}
	ft_lstclear(&stacks[0]);
	ft_lstclear(&stacks[1]);
}
