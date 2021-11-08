/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:16:42 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/01 22:03:05 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putchar_numb2(int i, int j)
{
	ft_putchar(i + '0');
	ft_putchar(j + '0');
}

void	coma_and_space_ex06(int i, int j)
{
	if (i != 98 || j != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int q;
	int r;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b < 100)
		{
			q = a / 10;
			r = a % 10;
			putchar_numb2(q, r);
			ft_putchar(' ');
			q = b / 10;
			r = b % 10;
			putchar_numb2(q, r);
			coma_and_space_ex06(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
