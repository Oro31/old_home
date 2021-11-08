/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:09:02 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/13 10:51:19 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (str_len(to_find) == 0)
		return (str);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == *(to_find))
		{
			j = 1;
			while (*(str + i + j) == *(to_find + j) && j < str_len(to_find))
			{
				j++;
			}
			if (j == (str_len(to_find)))
				return (str + i);
		}
		i++;
	}
	return (0);
}
