/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:40:56 by rvalton           #+#    #+#             */
/*   Updated: 2019/08/30 10:59:41 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char negatif;
	char positif;

	negatif = 'N';
	positif = 'P';
	if (n < 0)
	{
		write(1, &negatif, 1);
	}
	else
	{
		write(1, &positif, 1);
	}
}
