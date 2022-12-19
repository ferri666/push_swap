/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:30:51 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/13 17:40:50 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->before == NULL)
			return (lst);
		lst = lst->before;
	}
	return (NULL);
}
