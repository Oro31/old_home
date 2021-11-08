/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:02:27 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/15 21:07:29 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = argc - 1;
		while (i > 0)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
