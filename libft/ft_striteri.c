/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:19:01 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/06 16:59:27 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static unsigned int	str_len(char	*s)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return ;
	len = str_len(s);
	i = 0;
	while (i < len)
	{
		f(i, (s + i));
		i++;
	}
}
