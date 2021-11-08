/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:05:24 by rvalton           #+#    #+#             */
/*   Updated: 2019/09/15 20:07:27 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	else if (index == 1)
	   return (1);
	else
		return(ft_fibonacci(index - 1) + ft_fibonacci(index - 2));	
}
