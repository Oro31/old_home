/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:23:44 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/05 15:39:51 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	hexa_tab(unsigned long n)
{
	char hexa_char[16];

	hexa_char[0] = '0';
	hexa_char[1] = '1';
	hexa_char[2] = '2';
	hexa_char[3] = '3';
	hexa_char[4] = '4';
	hexa_char[5] = '5';
	hexa_char[6] = '6';
	hexa_char[7] = '7';
	hexa_char[8] = '8';
	hexa_char[9] = '9';
	hexa_char[10] = 'a';
	hexa_char[11] = 'b';
	hexa_char[12] = 'c';
	hexa_char[13] = 'd';
	hexa_char[14] = 'e';
	hexa_char[15] = 'f';
	return (hexa_char[n]);
}

void	conv_dec_to_hex(unsigned long n)
{
	long r;
	long i;
	char hex[2];

	r = 0;
	i = 0;
	hex[0] = '0';
	hex[1] = '0';
	r = n % 16;
	n = n / 16;
	hex[0] = hexa_tab(r);
	hex[1] = hexa_tab(n);
	ft_putchar(hex[1]);
	ft_putchar(hex[0]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char *ustr;
	unsigned long i;

	ustr = (unsigned char *)str;
	i = 0;
	while (*(ustr + i) != '\0')
	{
		if (*(ustr + i) < 32 || *(ustr + i) > 127)
		{
			ft_putchar('\\');
			conv_dec_to_hex(*(ustr + i));
		}
		else
			ft_putchar(*(ustr + i));
		i++;
	}
}
