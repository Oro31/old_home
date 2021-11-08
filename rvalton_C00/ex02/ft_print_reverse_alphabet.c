/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:29:41 by rvalton           #+#    #+#             */
/*   Updated: 2019/08/30 11:24:52 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char actual_letter;

	actual_letter = 'z';
	while (actual_letter > 96)
	{
		write(1, &actual_letter, 1);
		actual_letter = actual_letter - 1;
	}
}
