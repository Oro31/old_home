/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:53:10 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/13 17:19:24 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen_error(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tab[95];

	i = -1;
	while (++i < 95)
		tab[i] = '\0';
	k = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '+' || *(str + i) == '-')
			return (0);
		j = -1;
		while (++j < 95)
			if (*(str + i) == *(tab + j))
				return (0);
		*(tab + k) = *(str + i);
		k++;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		r;
	long	res;

	res = (long)nbr;
	r = 0;
	if (ft_strlen_error(base) > 1)
	{
		if (res < 0)
		{
			write(1, "-", 1);
			res = res * (-1);
		}
		if (res >= ft_strlen_error(base))
			ft_putnbr_base(res / ft_strlen_error(base), base);
		r = res % ft_strlen_error(base);
		write(1, base + r, 1);
	}
}
