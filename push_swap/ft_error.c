/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:58:06 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 11:55:58 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_inbuf(int val, long *buf, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (val == buf[i])
		{
			ft_print_str("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_is_duplicate(t_elem *list, int size)
{
	t_elem	*tmp;
	long	*buf;
	int		i;

	if (list == NULL)
		return (0);
	buf = malloc(sizeof(long) * size);
	i = -1;
	while (++i < size)
		buf[i] = 2222111000;
	tmp = list;
	i = 0;
	while (tmp)
	{
		if (ft_is_inbuf(tmp->val, buf, size))
			return (1);
		else
		{
			buf[i] = tmp->val;
			i++;
		}
		tmp = tmp->nxt;
	}
	free(buf);
	return (0);
}
