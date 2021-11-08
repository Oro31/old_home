/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:48:59 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 11:07:38 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_four(t_elem **a, t_elem **b, t_estr **res)
{
	int	*atab;

	*b = ft_push_x_to_y(a, *b, 'b', res);
	ft_three(a, res);
	atab = ft_list_to_tab(*a);
	if ((*b)->val < atab[0])
		*a = ft_push_x_to_y(b, *a, 'a', res);
	else if ((*b)->val < atab[1])
	{
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_swap(*a, 'a', res);
	}
	else if ((*b)->val < atab[2])
	{
		*a = ft_reverse_rotate(*a, 'a', res);
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_rotate(*a, 'a', res);
		*a = ft_rotate(*a, 'a', res);
	}
	else
	{
		*a = ft_push_x_to_y(b, *a, 'a', res);
		*a = ft_rotate(*a, 'a', res);
	}
	free(atab);
}
