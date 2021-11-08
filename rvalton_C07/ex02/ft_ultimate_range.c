/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:06:28 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 20:29:57 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int length;
	int i;
	int value;

	if (min >= max)
		return (NULL);
	length = max - min;
	if (!(tab = malloc(sizeof(int) * length)))
		return (NULL);
	i = 0;
	value = min;
	while (i < length)
	{
		*(tab + i) = value;
		i++;
		value++;
	}
	return (tab);
}

int		ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	else
		return (max - min);
}
