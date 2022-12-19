/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:21:28 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/13 12:01:06 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstgoto(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == n)
			return (lst);
		lst = (lst)->next;
		i++;
	}
	return (lst);
}
