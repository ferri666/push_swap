/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:30 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/08 17:17:11 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	ss(t_list **stacks)
{
	swap(&stacks[0], 's');
	swap(&stacks[1], 's');
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_list **stacks)
{
	rotate(&stacks[0], 'r');
	rotate(&stacks[1], 'r');
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_list **stacks)
{
	rev_rotate(&stacks[0], 'r');
	rev_rotate(&stacks[1], 'r');
	ft_putstr_fd("rrr\n", 1);
}
