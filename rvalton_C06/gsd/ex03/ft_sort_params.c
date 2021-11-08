/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:08:14 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/16 11:43:29 by rvalton          ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s2 + i) != '\0' || *(s1 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_params(int arc, char **arg)
{
	int		i;
	int		modif;
	char	*tmp;

	modif = 1;
	while (modif == 1)
	{
		modif = 0;
		i = 1;
		while (i < arc - 1)
		{
			if (ft_strcmp(arg[i], arg[i + 1]) > 0)
			{
				tmp = arg[i];
				arg[i] = arg[i + 1];
				arg[i + 1] = tmp;
				modif = 1;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
