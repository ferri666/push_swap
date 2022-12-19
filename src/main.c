/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:55:46 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 15:55:55 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

static	char	**mat_app(char **m1, char **m2, int len1, int len2)
{
	char	**ret;
	int		i;
	int		sl;

	if (!m1)
		return (m2);
	i = 0;
	ret = (char **) malloc(sizeof (char *) * (len1 + len2) + 1);
	while (i < len1)
	{
		sl = ft_strlen(*m1[i]);
		ret[i] = (char *)malloc(sizeof(char) * sl + 1);
		ft_strlcpy(ret[i], *m1[i], sl + 1);
		i++;
	}
	while (i < (len2 + len1))
	{
		sl = ft_strlen(*m2[i]);
		ret[i] = (char *)malloc(sizeof(char) * sl + 1);
		ft_strlcpy(ret[i], *m2[i], sl + 1);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static size_t	ft_numstring(const char *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	char	**argm;
	int		argn;
	int		*nums;
	int		i;

	if (argc < 2)
		return (0);
	else
	{
		i = 1;
		argm = NULL;
		argn = 0;
		while (i < argc)
		{
			argn += ft_numstring(argv[i], ' ') + 1;
			argm = ft_split(argv[i], ' ');
			i++;
		}
	}
	nums = validate(argm, argn);
	if (nums)
		program(nums, argn - 1);
	else
		ft_putstr_fd("Error: Input not valid\n", 1);
	return (0);
}
