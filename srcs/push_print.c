/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 02:01:30 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/09 11:07:48 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ps_largeur(int i, int a)
{
	int size;

	size = 1;
	if (i < 0)
	{
		size++;
		i = -i;
	}
	while (i / 10 >= 1)
	{
		i = i / 10;
		size++;
	}
	return (a - size);
}

static void	ps_print_both(t_push *all, int i)
{
	int a;

	a = ps_largeur(all->a_tab[i], 13);
	while (a--)
		ft_putstr(" ");
	ft_putnbr(all->a_tab[i]);
	ft_putstr(" | ");
	a = ps_largeur(all->b_tab[i], 13);
	while (a--)
		ft_putstr(" ");
	ft_putnbr(all->b_tab[i]);
	ft_putstr(" |\n");
}

static void	ps_print_a(t_push *all, int i)
{
	int a;

	a = ps_largeur(all->a_tab[i], 13);
	while (a--)
		ft_putstr(" ");
	ft_putnbr(all->a_tab[i]);
	ft_putstr(" |               |\n");
}

static void	ps_print_b(t_push *all, int i)
{
	int a;

	ft_putstr("              | ");
	a = ps_largeur(all->b_tab[i], 13);
	while (a--)
		ft_putstr(" ");
	ft_putnbr(all->b_tab[i]);
	ft_putstr(" |\n");
}

void		ps_print(t_push *all)
{
	int	i;
	int a;

	if (all->b_nbr > all->a_nbr)
		i = all->b_nbr + 1;
	else
		i = all->a_nbr + 1;
	ft_putstr("       --------------------------------\n");
	ft_putstr("       |     Pile A    |     Pile B    |\n");
	ft_putstr("       --------------------------------\n");
	while (--i >= 0)
	{
		a = ps_largeur(i, 6);
		while (a--)
			ft_putstr(" ");
		ft_putnbr(i);
		ft_putstr(" | ");
		if (i <= all->a_nbr && i <= all->b_nbr)
			ps_print_both(all, i);
		else if (i <= all->a_nbr)
			ps_print_a(all, i);
		else
			ps_print_b(all, i);
	}
	ft_putstr("       --------------------------------\n\n");
}
