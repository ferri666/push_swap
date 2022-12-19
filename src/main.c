/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:55:46 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 12:53:57 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

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
	char	st;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argm = ft_split(argv[1], ' ');
		argn = ft_numstring(argv[1], ' ') + 1;
		st = 'y';
	}
	else
	{
		argm = argv;
		argn = argc;
		st = 'n';
	}
	nums = validate(argm, argn, st);
	if (nums)
		program(nums, argn - 1);
	else
		ft_putstr_fd("Error, Input not valid\n", 1);
	return (0);
}
