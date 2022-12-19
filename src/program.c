/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:13 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 12:53:08 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	orderstacks(t_list **stacks)
{
	int		size;

	size = ft_lstsize(ft_lstfirst(stacks[0]));
	if (size < 6)
		mini_sort(stacks, size);
	else
		sort(stacks, size);
}

/*
stacks[0] = STACK_A
stacks[1] = STACK_B
*/

/*
The stacks are finished when:
1-The Stack B is empty
2-The Stack A is sorted
This functions returns 0 if they are not finished and 1 if they are.
*/
int	finished(t_list *stacks[])
{
	int		size;
	int		i;
	int		num1;
	int		num2;

	stacks[0] = ft_lstfirst(stacks[0]);
	size = ft_lstsize(stacks[0]);
	i = 0;
	if (stacks[1])
		return (0);
	while (i < size -1)
	{
		num1 = stacks[0]->val;
		stacks[0] = (stacks[0])->next;
		num2 = (stacks[0])->val;
		if (num1 > num2)
			return (0);
		i++;
	}
	return (1);
}

/*
FUNCTION: print_stack
This functions prints to stdout:
-The Stack we gave it (from top to bottom)
-A Character to diferenciate it
-The Size of the Stack
Perfect for debugging and visualize what's happening
*/
void	print_stack(t_list *stack, char c)
{
	int	i;
	int	num;
	int	size;

	ft_putstr_fd("////////////// ", 1);
	ft_putstr_fd("Stack ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd("\\\\\\\\\\\\\\\\\\\\\\\\\n", 1);
	stack = ft_lstfirst(stack);
	i = 0;
	size = ft_lstsize(stack);
	while (i < size)
	{
		num = stack->val;
		stack = stack->next;
		i++;
		ft_putnbr_fd(num, 1);
		ft_putstr_fd("->", 1);
	}
	ft_putstr_fd("-\n", 1);
	ft_putnbr_fd(size, 1);
	ft_putstr_fd(" elementos\n\n", 1);
}

/*
This is the program that comes after the validation.
First we create the stacks, then we check if they are
already sorted and if not, we do it.
*/
void	program(int *numbers, int num_val)
{
	int			i;
	t_list		*stacks[2];

	i = 0;
	stacks[0] = NULL;
	stacks[1] = NULL;
	while (i < num_val)
	{
		ft_lstadd_back(&stacks[0], ft_lstnew(numbers[i]));
		i++;
	}
	free(numbers);
	if (!finished(stacks))
		orderstacks(stacks);
	else
		ft_lstclear(&stacks[0]);
}
