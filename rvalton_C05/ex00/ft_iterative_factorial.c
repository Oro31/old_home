/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:35:23 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/13 21:50:43 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	res = nb;
	if (res == 0)
		return (1);
	else if (res < 0)
		return (0);
	while (--nb > 0)
		res = res * nb;
	return (res);
}
