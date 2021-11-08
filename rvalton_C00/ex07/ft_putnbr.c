/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:06:07 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/09 16:45:43 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int r;
	int q;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb += 2000000000;
		}
		nb = nb * -1;
	}
	r = nb % 10;
	q = nb / 10;
	if (q != 0)
	{
		ft_putnbr(q);
		ft_putchar(r + '0');
	}
	else
	{
		ft_putchar(r + '0');
	}
}
