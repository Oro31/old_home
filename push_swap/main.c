/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:48:39 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/25 11:55:45 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_vars(t_vars *vars, t_elem *a, t_elem *b)
{
	vars->a = ft_copy_list(a);
	vars->b = ft_copy_list(b);
	vars->res = NULL;
}

t_estr	*ft_get_best_chunk(t_vars *vars, t_elem *a, t_elem *b)
{
	t_estr	*ops;
	int		n;
	int		i;

	if (ft_size_list(a) <= 5)
		return (NULL);
	ops = NULL;
	n = 20000;
	i = 0;
	while (++i < 15)
	{
		ft_get_vars(vars, a, b);
		ft_push_swap(&vars->a, &vars->b, &vars->res, i);
		vars->nchunk[i - 1] = ft_size_listr(vars->res);
		if (vars->nchunk[i - 1] < n)
		{
			n = vars->nchunk[i - 1];
			ft_free_listr(ops);
			ops = ft_copy_listr(vars->res);
		}
		ft_free_list(vars->a);
		ft_free_list(vars->b);
		ft_free_listr(vars->res);
	}
	return (ops);
}

static int	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_is_num(argv[i]))
		{
			ft_print_str("Error\n");
			return (0);
		}
		else if (!ft_is_int(argv[i]))
		{
			ft_print_str("Error\n");
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_estr	*res;
	t_elem	*a;
	t_elem	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (!ft_check_argv(argc, argv))
		return (0);
	i = 0;
	while (++i < argc)
		a = ft_eadd_tolist(a, ft_atoi(argv[i]));
	if (ft_is_duplicate(a, argc - 1) || ft_is_list_sort(a))
	{
		ft_free_list(a);
		return (0);
	}
	res = ft_get_best_chunk(&vars, a, b);
	ft_small(&a, &b, &res);
	ft_print_list(res);
	ft_free_list(a);
	ft_free_list(b);
	ft_free_listr(res);
	return (0);
}
