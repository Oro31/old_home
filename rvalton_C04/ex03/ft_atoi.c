/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:28:00 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/11 14:50:24 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skip_isspace(char *str)
{
	int i;

	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == ' '))
		i++;
	return (i);
}

int		ft_count_minus(char *str, int *i)
{
	int m;
	int j;

	j = *i;
	m = 1;
	while ((*(str + j) == '-') || (*(str + j) == '+'))
	{
		if (*(str + j) == '-')
			m = m * (-1);
		j++;
	}
	*i = j;
	return (m);
}

int		ft_nbr(char *str, int *i, int nbr)
{
	int n;
	int j;
	int k;

	k = *i;
	j = 0;
	n = 1;
	nbr = 0;
	while (*(str + k + j) >= '0' && *(str + k + j) <= '9')
	{
		n = n * 10;
		j++;
	}
	while (j > 0)
	{
		j--;
		n = n / 10;
		nbr = nbr + ((*(str + k) - '0') * n);
		k++;
	}
	*i = k;
	return (nbr);
}

int		ft_atoi(char *str)
{
	int i;
	int m;
	int nbr;

	i = ft_skip_isspace(str);
	m = ft_count_minus(str, &i);
	nbr = 0;
	nbr = ft_nbr(str, &i, nbr);
	nbr = nbr * m;
	return (nbr);
}
