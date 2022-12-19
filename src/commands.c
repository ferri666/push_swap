/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:30 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/17 11:46:05 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	push(t_list **stack1, t_list **stack2, char c)
{
	t_list	*first;
	t_list	*first2;
	t_list	*second;

	if (!*stack1)
		return ;
	first = ft_lstfirst(*stack1);
	second = NULL;
	first2 = ft_lstfirst(*stack2);
	if (ft_lstsize(first) > 1)
	{
		second = first->next;
		second->before = NULL;
	}
	*stack1 = second;
	first->next = first2;
	if (*stack2)
		first2->before = first;
	*stack2 = first;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	swap(t_list **stack, char c)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		size;

	size = ft_lstsize(ft_lstfirst(*stack));
	if (!*stack || size == 1)
		return ;
	tmp1 = ft_lstfirst(*stack);
	tmp2 = tmp1->next;
	if (size > 2)
	{
		(tmp2->next)->before = tmp1;
		tmp1->next = tmp2->next;
	}
	else
		tmp1->next = NULL;
	tmp1->before = tmp2;
	tmp2->before = NULL;
	tmp2->next = tmp1;
	*stack = tmp2;
	if (c == 's')
		return ;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rev_rotate(t_list **stack, char c)
{
	t_list	*last;
	t_list	*first;
	t_list	*sec_bot;

	if (!*stack || ft_lstsize(ft_lstfirst(*stack)) == 1)
		return ;
	last = ft_lstlast(*stack);
	first = ft_lstfirst(*stack);
	if (ft_lstsize(ft_lstfirst(*stack)) > 2)
	{
		sec_bot = last->before;
		sec_bot->next = NULL;
	}
	else
		first->next = NULL;
	last->next = first;
	last->before = NULL;
	first->before = last;
	*stack = last;
	if (c == 'r')
		return ;
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate(t_list **stack, char c)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*stack || ft_lstsize(ft_lstfirst(*stack)) == 1)
		return ;
	last = ft_lstlast(*stack);
	first = ft_lstfirst(*stack);
	if (ft_lstsize(ft_lstfirst(*stack)) > 2)
		second = first->next;
	else
		second = last;
	last->next = first;
	second->before = NULL;
	first->next = NULL;
	first->before = last;
	*stack = second;
	if (c == 'r')
		return ;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
