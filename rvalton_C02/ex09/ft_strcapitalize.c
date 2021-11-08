/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:46:27 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/06 10:49:07 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char str)
{
	if (str > 'z')
		return (0);
	else if (str < 'a' && str > 'Z')
		return (0);
	else if (str < 'A')
		return (0);
	return (1);
}

int		is_num(char str)
{
	if (str < '0')
		return (0);
	else if (str > '9')
		return (0);
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	*str = *ft_strlowcase(str);
	while (*(str + i) != '\0')
	{
		if (i == 0)
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else
		{
			if (is_num(*(str + i - 1)) == 0 && is_alpha(*(str + i - 1)) == 0)
			{
				if (*(str + i) >= 'a' && *(str + i) <= 'z')
					*(str + i) -= 32;
			}
		}
		i++;
	}
	return (str);
}
