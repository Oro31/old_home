/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 11:35:54 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_is_three(t_elem **a, t_elem **b, t_estr **res, int *atab)
{
	int		i;

	i = 1;
	while (atab[i] < (*b)->val && i < 3)
		i++;
	if (i == 3)
	{
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_rotate(*a, 'a', res);
		*a = ft_rotate(*a, 'a', res);
	}
	else if (i == 2)
	{
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_reverse_rotate(*a, 'a', res);
	}
	else if (i == 1)
	{
		*a = ft_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
	}
}

static void	ft_set_is_two(t_elem **a, t_elem **b, t_estr **res, int *atab)
{
	int		i;

	i = 3;
	while (atab[i] > (*b)->val && i > 1)
		i--;
	if (i == 3)
	{
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_reverse_rotate(*a, 'a', res);
	}
	else if (i == 2 && atab[i] > (*b)->val)
	{
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
	}
	else if (i == 2 && atab[i] < (*b)->val)
	{
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_reverse_rotate(*a, 'a', res);
	}
}

static void	ft_five_second_ret(t_elem **a, t_elem **b, t_estr **res, int set)
{
	int		*atab;

	atab = ft_list_to_tab(*a);
	if (set == 0)
		*a = ft_push_x_to_y(b, *a, 'a', res);
	else if (set == 1)
	{
		if (atab[3] < (*b)->val)
		{
			*a = ft_push_x_to_y(b, *a, 'a', res);
			*a = ft_reverse_rotate(*a, 'a', res);
		}
		else
		{
			*a = ft_reverse_rotate(*a, 'a', res);
			*a = ft_push_x_to_y(b, *a, 'a', res);
		}
	}
	else if (set == 2)
		ft_set_is_two(a, b, res, atab);
	else
		ft_set_is_three(a, b, res, atab);
	free(atab);
}

static int	ft_five_first_ret(t_elem **a, t_elem **b, t_estr **res)
{
	int		*atab;
	int		i;

	atab = ft_list_to_tab(*a);
	i = 0;
	while (atab[i] < (*b)->val && i < 3)
		i++;
	if (i == 3)
		*a = ft_push_x_to_y(b, *a, 'a', res);
	else if (i == 2)
	{
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
	}
	else if (i == 0)
		*a = ft_push_x_to_y(b, *a, 'a', res);
	else
	{
		*a = ft_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
	}
	free(atab);
	return (i);
}

void	ft_five(t_elem **a, t_elem **b, t_estr **res)
{
	int		set;

	*b = ft_push_x_to_y(a, *b, 'b', res);
	*b = ft_push_x_to_y(a, *b, 'b', res);
	if ((*b)->val < (*b)->nxt->val)
		*b = ft_swap(*b, 'b', res);
	ft_three(a, res);
	set = ft_five_first_ret(a, b, res);
	ft_five_second_ret(a, b, res, set);
}
