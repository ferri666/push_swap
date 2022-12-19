/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:37:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 15:38:47 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

static char	**ft_free_matrix(char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

static void	err_invalid(char *message, int *num)
{
	free(num);
	ft_putstr_fd(message, 2);
	exit(142);
}

/*
FUNCTION: same_number

This function checks if there is any repeated numbers 
on the array and returns true if it does.
*/
static bool	same_number(int *number, int num_val)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (num_val == 1)
		return (false);
	while (i < num_val)
	{
		while (j < num_val)
		{
			if (number[i] == number[j])
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

/*
FUNCTION: is_int

This function checks if the string represents an integer 
and it doesn't exceed the MIN and MAX Values
Returns true is it's valid and false when not.
*/
static bool	is_int(char *value)
{
	int			i;
	long int	num;

	i = 0;
	if (value[i] == 0)
		return (false);
	if (value[i] == '-' || value[i] == '+')
		i++;
	while (value[i] != '\0')
	{
		if (!ft_isdigit(value[i]))
			return (false);
		i++;
	}
	num = ft_atoi2(value);
	if (num > 2147483647 || num < -2147483648)
		return (false);
	return (true);
}

/*  Value of INT_MAX is +2147483647.
Value of INT_MIN is -2147483648. */

/* 
It returns an array with all the numbers

For the parameters to be valid they have to be:
1-Integer Numbers
2-Not Repeated
3-Not Exceed the Min or Max of Integers
*/
int	*validate(char **values, int num_val)
{
	int		i;
	int		*numbers;

	i = 1;
	numbers = (int *)malloc(sizeof(int) * num_val);
	if (!numbers)
		return (0);
	while (i < num_val)
	{
		if (is_int(values[i - 1]))
			numbers[i - 1] = ft_atoi(values[i - 1]);
		else
			err_invalid("Error: ¡Number or Format not valid!\n", numbers);
		i++;
	}
	ft_free_matrix(values, num_val);
	if (same_number(numbers, num_val - 1))
		err_invalid("Error:¡You put the same number twice!\n", numbers);
	return (numbers);
}
