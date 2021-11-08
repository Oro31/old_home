/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:48:04 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 20:41:16 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
}

char	*ft_malloc0(void)
{
	char	*join;

	if (!(join = malloc(sizeof(char))))
		return (NULL);
	*join = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*join;

	if (size == 0)
	{
		join = ft_malloc0();
		return (join);
	}
	len = 0;
	i = -1;
	while (++i < size)
		len = len + ft_strlen(strs[i]);
	len = len + ((size - 1) * ft_strlen(sep));
	if (!(join = malloc(sizeof(char) * len)))
		return (NULL);
	join[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < size - 1)
			ft_strcat(join, sep);
	}
	return (join);
}
