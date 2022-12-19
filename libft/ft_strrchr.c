/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:59:25 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/06 16:59:27 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(char *str, char to_find)
{
	int	n;

	n = ft_strlen(str);
	while (n >= 0)
	{
		if (str[n] == to_find)
		{
			return (&str[n]);
		}
		n--;
	}
	return (NULL);
}
