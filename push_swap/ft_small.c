/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:46:27 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 12:35:02 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small(t_elem **a, t_elem **b, t_estr **res)
{
	int		*tab;
	int		i;

	i = ft_size_list(*a);
	tab = ft_list_to_tab(*a);
	if (i == 2)
	{
		if (tab[0] > tab[1])
			*a = ft_swap(*a, 'a', res);
	}
	else if (i == 3)
		ft_three(a, res);
	else if (i == 4)
		ft_four(a, b, res);
	else if (i == 5)
		ft_five(a, b, res);
	free(tab);
}
