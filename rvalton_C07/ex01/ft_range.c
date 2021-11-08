/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:55:50 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 18:05:19 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int length;
	int i;
	int value;

	value = min;
	i = 0;
	length = max - min;
	if (min >= max)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		*(tab + i) = value;
		i++;
		value++;
	}
	return (tab);
}
