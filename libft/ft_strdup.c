/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:23:45 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/06 16:59:27 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len_str;
	size_t	i;

	i = 0;
	len_str = ft_strlen(s1) + 1;
	ret = (char *) malloc (len_str);
	if (!ret)
		return (NULL);
	while (len_str > 0)
	{
		*(ret + i) = *(s1 + i);
		i++;
		len_str--;
	}
	return (ret);
}
