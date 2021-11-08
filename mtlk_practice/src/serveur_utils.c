/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:33:46 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/01 11:35:25 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int d, int p)
{
	int	i;
	int	res;

	res = 1;
	i = p;
	while (i > 0)
	{
		res = res * d;
		i--;
	}
	return (res);
}

void	ft_print(int *str, int size)
{
	int		i;
	char	c;

	c = '\0';
	i = -1;
	while (++i < size)
	{
		c = str[i];
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	*ft_realloc(char res, int *str)
{
	int		i;
	int		*tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(int) * (i + 2));
	if (!tmp)
		return (NULL);
	tmp[i + 1] = '\0';
	tmp[i] = res;
	while (--i >= 0)
		tmp[i] = str[i];
	free(str);
	return (tmp);
}

int	*ft_putchar(int *octet, int *str)
{
	int		i;
	int		res;
	char	c;

	c = '\0';
	res = 0;
	i = -1;
	while (++i < 8)
	{
		res = res + (octet[i] * ft_pow(2, i));
	}
	c = res;
	str = ft_realloc(res, str);
	return (str);
}
