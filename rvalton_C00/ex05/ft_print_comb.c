/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:09:39 by rvalton           #+#    #+#             */
/*   Updated: 2019/08/30 11:48:19 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar3(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
}

void	ft_print_comb(void)
{
	char first_numb;
	char second_numb;
	char third_numb;

	first_numb = 48;
	while (first_numb <= 55)
	{
		second_numb = first_numb + 1;
		while (second_numb <= 56)
		{
			third_numb = second_numb + 1;
			while (third_numb <= 57)
			{
				ft_putchar3(first_numb, second_numb, third_numb);
				if (first_numb != 55 || second_numb != 56 || third_numb != 57)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				third_numb += 1;
			}
			second_numb += 1;
		}
		first_numb += 1;
	}
}
