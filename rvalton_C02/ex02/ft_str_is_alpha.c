/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:25:55 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/02 20:29:43 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > 'z')
			return (0);
		else if (*(str + i) < 'a' && *(str + i) > 'Z')
			return (0);
		else if (*(str + i) < 'A')
			return (0);
		i++;
	}
	return (1);
}
