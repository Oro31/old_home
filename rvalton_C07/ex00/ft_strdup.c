/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:47:53 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/19 17:43:46 by rvalton          ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*cp;

	i = 0;
	if (!(cp = malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (i <= ft_strlen(src))
	{
		*(cp + i) = *(src + i);
		i++;
	}
	return (cp);
}
