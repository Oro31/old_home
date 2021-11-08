/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:16:04 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/02 17:13:20 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int if_modif;
	int tmp;

	if_modif = 1;
	while (if_modif == 1)
	{
		i = 0;
		if_modif = 0;
		while (i < (size - 1))
		{
			if (*(tab + i) > *(tab + i + 1))
			{
				if_modif = 1;
				tmp = *(tab + i);
				*(tab + i) = *(tab + i + 1);
				*(tab + i + 1) = tmp;
			}
			i++;
		}
	}
}
