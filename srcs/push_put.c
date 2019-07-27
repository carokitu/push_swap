/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:30:10 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/22 15:15:38 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ps_double(t_push *all)
{
	int	i;
	int	a;

	i = -1;
	while (++i <= all->a_nbr)
	{
		a = -1;
		while (++a <= all->a_nbr)
		{
			if (a != i && all->a_tab[a] == all->a_tab[i])
				return (1);
		}
	}
	return (0);
}

static long	long	ps_atoi(char *str)
{
	int			i;
	long long	res;
	long long	sign;

	i = 0;
	res = 0;
	sign = 1;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res = res * sign;
	return (res);
}

static int			ps_checkarg(char *str)
{
	int		i;

	i = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n')\
			|| (str[i] == '\r') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int			ps_dontput(int **b)
{
	free(*b);
	return (1);
}

int					ps_putintab(t_push *all, char **argv, int size)
{
	int			*b;
	long long	nb;
	int			i;
	int			a;

	a = 0;
	i = 0;
	if (!(b = (int *)ft_memalloc(sizeof(int) * (size + 1))))
		return (1);
	all->a_tabon = 1;
	if (!(all->b_tab = (int *)ft_memalloc(sizeof(int) * (size + 1))))
		return (1);
	all->b_tabon = 1;
	while (argv[i])
		i++;
	all->a_nbr = i - 1;
	while (--i >= 0)
	{
		if (ps_checkarg(argv[i]) == 1
			|| (nb = ps_atoi(argv[i])) < -2147483648 || nb > 2147483647)
			return (ps_dontput(&b));
		b[a++] = (int)nb;
	}
	all->a_tab = b;
	return (ps_double(all));
}
