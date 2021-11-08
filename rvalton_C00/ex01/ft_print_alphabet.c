/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphanet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:13:30 by rvalton           #+#    #+#             */
/*   Updated: 2019/08/30 11:26:58 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char actual_letter;

	actual_letter = 'a';
	while (actual_letter < 123)
	{
		write(1, &actual_letter, 1);
		actual_letter = actual_letter + 1;
	}
}
