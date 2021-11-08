/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:41:50 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/02 16:38:58 by rvalton          ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	if (str_len(src) >= n)
	{
		while (i < n)
		{
			*(dest + i) = *(src + i);
			i++;
		}
	}
	else
	{
		while (i < str_len(src))
		{
			*(dest + i) = *(src + i);
			i++;
		}
		while (i < n)
		{
			*(dest + i) = '\0';
			i++;
		}
	}
	return (dest);
}
