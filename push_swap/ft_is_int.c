/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:03:15 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 11:53:11 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_strcomp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (str1[i] != str2[i])
		return (str1[i] - str2[i]);
	else
		return (0);
}

static int	ft_is_int_max(char *str)
{
	char	*int_max;

	int_max = "2147483647";
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strcomp(str, int_max) > 0)
		return (0);
	return (1);
}

static int	ft_is_int_min(char *str)
{
	char	*int_min;

	int_min = "-2147483648";
	if (ft_strlen(str) < 11)
		return (1);
	if (ft_strcomp(str, int_min) <= 0)
		return (1);
	return (0);
}

int	ft_is_int(char *str)
{
	if (ft_strlen(str) < 10)
		return (1);
	else if (ft_strlen(str) > 11)
		return (0);
	else if (str[0] == '-')
		return (ft_is_int_min(str));
	else
		return (ft_is_int_max(str));
}
