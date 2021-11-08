/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:54:36 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/01 12:48:35 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_SOURCE
# define MS 100
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

int		ft_pow(int d, int p);
void	ft_print(int *str, int size);
int		*ft_realloc(char res, int *str);
int		*ft_putchar(int *octet, int *str);

int		ft_atoi(char *str);
void	ft_putnbr(int d);
void	ft_printf(const char *format, ...);

#endif
