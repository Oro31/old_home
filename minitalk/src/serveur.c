/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:36:14 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/01 12:09:51 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		**g_str;

static int	**ft_init(void)
{
	int		**s;

	s = malloc(sizeof(int *) * 3);
	s[0] = malloc(sizeof(int));
	s[0][0] = '\0';
	s[1] = malloc(sizeof(int) * 8);
	s[2] = malloc(sizeof(int) * 3);
	s[2][0] = 0;
	s[2][1] = 11;
	s[2][2] = 0;
	return (s);
}

static int	*ft_reset_str(int *gs)
{
	int		*str;

	str = malloc(sizeof(int));
	str[0] = '\0';
	free(gs);
	return (str);
}

static void	hndlr_bis(int signum)
{
	if (signum == SIGUSR1 && g_str[2][0] == 1)
	{
		g_str[2][2]++;
	}
	else if (signum == SIGUSR2 && g_str[2][0] == 1)
	{
		g_str[2][1] = g_str[2][2];
		g_str[2][0] = 2;
	}
	else if (signum == SIGUSR1 && g_str[2][0] > 1 && g_str[2][0] < 10 &&
			g_str[2][0] > 0)
	{
		g_str[1][g_str[2][0] - 2] = 1;
		g_str[2][0]++;
	}
	else if (signum == SIGUSR2 && g_str[2][0] > 1 && g_str[2][0] < 10 &&
			g_str[2][2] > 0)
	{
		g_str[1][g_str[2][0] - 2] = 0;
		g_str[2][0]++;
	}
}

static void	handler(int signum)
{
	int		i;

	i = -1;
	if (signum == SIGUSR1 && g_str[2][0] == 0)
	{
		g_str[0] = ft_reset_str(g_str[0]);
		g_str[2][0] = 1;
	}
	else if (signum == SIGUSR1 && g_str[2][0] == 10)
	{
		g_str[0] = ft_putchar(g_str[1], g_str[0]);
		while (++i < 8)
			g_str[1][i] = 0;
		g_str[2][2]--;
		g_str[2][0] = 2;
	}
	else if (signum == SIGUSR2 && g_str[2][2] == 0 && g_str[2][0] == 2)
	{
		ft_print(g_str[0], g_str[2][1]);
		g_str[2][0] = 0;
	}
	else
		hndlr_bis(signum);
}

int	main(void)
{
	struct sigaction	action;

	g_str = ft_init();
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}
	ft_printf("Pret a recevoir des signaux. Mon PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
