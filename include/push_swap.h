/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:43:51 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/12/19 15:17:32 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*CONTROL*/
int			*validate(char **values, int num_val);
void		program(int *numbers, int num_val);
void		mini_sort(t_list **stacks, int size);
void		sort(t_list **stacks, int size);
int			finished(t_list **stacks);

/* COMMANDS */
void		push(t_list **stack_1, t_list **stack_2, char c);
void		swap(t_list **stack, char c);
void		rotate(t_list **stack, char c);
void		rev_rotate(t_list **stack, char c);
void		ss(t_list **stacks);
void		rr(t_list **stacks);
void		rrr(t_list **stacks);

/* MINI SORT UTILS */
void		sort5cases(t_list **stack, int *val);

/* SORT UTILS */
int			*dump(t_list *stack);
void		print_stack(t_list *stack, char c);
int			*simplify(int *array, size_t size, int off);
void		print_array(int *array, size_t size);
int			find_min(int *val, int size);
int			find_max(int *val, int size);
int			find_n(int *val, int search, int size);
void		simp_stack(t_list *stack, int *array, size_t size);
int			*s_dump(t_list *stack);

/* BIG SORT UTILS */
void		up_to_top(t_list **stacks, int n, char c);
void		down_to_top(t_list **stacks, int n, int size, char c);
int			f_chunck(int *val, int min, int max, int size);
void		sm_rotate(t_list **stacks, int n, int size, char c);
void		giant_sort(t_list **stacks, int size, int	*val);

#endif