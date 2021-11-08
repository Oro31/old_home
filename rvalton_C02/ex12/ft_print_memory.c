/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:04 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/06 10:29:53 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int mode, int i, int size)
{
	if (mode == 0)
		write(1, &c, 1);
	else if (mode == 2)
	{
		write(1, &c, 1);
		write(1, &c, 1);
		if (i % 2 != 0)
			write(1, &c, 1);
	}
}

void	print_line(unsigned char *str, int i, int size)
{
	int j;

	while (i < 16)
	{
		ft_putchar(' ', 2, i, size);
		i++;
	}
	j = 0;
	while (j < 16 && j <= size)
	{
		if (*(str + j) < ' ' || *(str + j) > '~')
			ft_putchar('.', 0, i, size);
		else
			ft_putchar(*(str + j), 0, i, size);
		j++;
	}
}

void	pt_l_hx(unsigned char *ft_ch_ad, int i, unsigned char *str, int size)
{
	long r;
	long q;
	char *hexa;

	hexa = "0123456789abcdef";
	while (i > 0)
	{
		i--;
		ft_putchar(ft_ch_ad[i], 0, i, size);
	}
	ft_putchar(':', 0, i, size);
	ft_putchar(' ', 0, i, size);
	i = 0;
	while (i < 16 && i <= size)
	{
		ft_putchar(*(hexa + (*(str + i) / 16)), 0, i, size);
		ft_putchar(*(hexa + (*(str + i) % 16)), 0, i, size);
		if (i % 2 != 0)
			ft_putchar(' ', 0, i, size);
		i++;
	}
	print_line(str, i, size);
}

void	setup_add_fstcharl_hexa(void *addr, int i, int size)
{
	unsigned	char *hexa;
	unsigned	char first_char_addr[15];
	unsigned	char *address;
	unsigned	long n;

	address = (unsigned char *)addr;
	n = (long)address;
	i = 0;
	hexa = (unsigned char *)"0123456789abcdef";
	while (n != 0)
	{
		n = n / 16;
		first_char_addr[i] = *(hexa + (n % 16));
		i++;
	}
	while (i < 15)
	{
		first_char_addr[i] = '0';
		i++;
	}
	pt_l_hx(first_char_addr, i, address, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int a;

	if (size > 0)
	{
		a = 0;
		while (a < size)
		{
			setup_add_fstcharl_hexa(addr + a, 0, size - a);
			ft_putchar('\n', 0, 0, size);
			a += 16;
		}
	}
	return (addr);
}
