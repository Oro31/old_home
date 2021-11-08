/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:28:36 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/12 22:01:58 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*start(char *str, int *minus)
{
	int i;
	int m;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	m = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = m * (-1);
		i++;
	}
	*minus = m;
	return (str + i);
}

int		sl(char *str, char *base)
{
	int i;
	int size;
	int valide;
	int k;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		valide = 0;
		k = 0;
		while (*(base + k) != '\0')
		{
			if (*(str + i) == *(base + k))
				valide = 1;
			k++;
		}
		if (valide == 0)
			return (size);
		size++;
		i++;
	}
	return (size);
}

int		ft_error(char *str)
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

int		pw(int len_base, int power)
{
	int i;

	i = 1;
	while (power > 0)
	{
		i = i * len_base;
		power--;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int m;
	int i;
	int j;
	int res;
	int size;

	if (ft_error(base) < 2)
		return (0);
	res = 0;
	i = 0;
	str = start(str, &m);
	size = sl(str, base);
	while (i < size)
	{
		j = sl(base, base);
		while (str[i] != base[j])
			j--;
		res = res + j * pw(sl(base, base), size - 1 - i);
		i++;
	}
	return (res * m);
}
