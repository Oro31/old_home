/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:09:30 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 20:35:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_error(char *str);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_malloc_tab(int nbr, char *base)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / ft_strlen(base);
		i++;
	}
	i++;
	if (!(tab = malloc(sizeof(int) * i)))
		return (NULL);
	return (tab);
}

char	*ft_rev_tab(char *tab, unsigned int i)
{
	int				tmp;
	unsigned int	j;
	unsigned int	k;

	i--;
	k = 1;
	j = 0;
	if (tab[0] == '-')
	{
		j = 1;
		k = 0;
	}
	while (j <= i / 2)
	{
		tmp = tab[j];
		tab[j] = tab[ft_strlen(tab) - k - j];
		tab[ft_strlen(tab) - k - j] = tmp;
		j++;
	}
	return (tab);
}

char	*ft_itoa_base(int nbr, char *base, char *tab)
{
	unsigned int	i;

	tab = ft_malloc_tab(nbr, base);
	if (tab == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr = nbr * (-1);
		i++;
	}
	while (nbr > 0)
	{
		tab[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
		i++;
	}
	tab[i] = '\0';
	return (ft_rev_tab(tab, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*tab;

	tab = "\0";
	if (ft_error(base_from) < 2 || ft_error(base_to) < 2)
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	if (dec == 0)
	{
		tab = malloc(sizeof(char) * 2);
		tab[0] = base_to[0];
		tab[1] = '\0';
		return (tab);
	}
	return (ft_itoa_base(dec, base_to, tab));
}
