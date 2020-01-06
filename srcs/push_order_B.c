/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:42:48 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/06 12:43:31 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_threepush(t_push *swp)
{
	ft_putstr_fd("pa\npa\npa\n", STDOUT_FILENO);
	ps_pa(swp);
	ps_pa(swp);
	ps_pa(swp);
}

static void	ps_orderter(t_push *swp)
{
	if (swp->b_tab[swp->b_nbr] < swp->b_tab[swp->b_nbr - 1]
		&& swp->b_tab[swp->b_nbr - 1] < swp->b_tab[swp->b_nbr - 2]
		&& swp->b_tab[swp->b_nbr] < swp->b_tab[swp->b_nbr - 2])
	{
		ft_putstr_fd("rb\nsb\npa\npa\nrrb\npa\n", STDOUT_FILENO);
		ps_rb(swp);
		ps_sb(swp);
		ps_pa(swp);
		ps_pa(swp);
		ps_rrb(swp);
		ps_pa(swp);
	}
	else
	{
		ft_putstr_fd("sb\npa\nsb\npa\npa\n", STDOUT_FILENO);
		ps_sb(swp);
		ps_pa(swp);
		ps_sb(swp);
		ps_pa(swp);
		ps_pa(swp);
	}
}

static void	ps_orderbbis(t_push *swp)
{
	if (swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 1]
			&& swp->b_tab[swp->b_nbr] < swp->b_tab[swp->b_nbr - 2]
			&& swp->b_tab[swp->b_nbr - 1] < swp->b_tab[swp->b_nbr - 2])
	{
		ft_putstr_fd("rb\nsb\npa\nrrb\npa\npa\n", STDOUT_FILENO);
		ps_rb(swp);
		ps_sb(swp);
		ps_pa(swp);
		ps_rrb(swp);
		ps_pa(swp);
		ps_pa(swp);
	}
	else if (swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 1]
			&& swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 2]
			&& swp->b_tab[swp->b_nbr - 1] < swp->b_tab[swp->b_nbr - 2])
	{
		ft_putstr_fd("pa\nsb\npa\npa\n", STDOUT_FILENO);
		ps_pa(swp);
		ps_sb(swp);
		ps_pa(swp);
		ps_pa(swp);
	}
	else
		ps_orderter(swp);
}

static void	ps_orderb(t_push *swp)
{
	if (swp->b_tab[swp->b_nbr] < swp->b_tab[swp->b_nbr - 1]
			&& swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 2]
			&& swp->b_tab[swp->b_nbr - 1] > swp->b_tab[swp->b_nbr - 2])
	{
		ft_putstr_fd("sb\n", STDOUT_FILENO);
		ps_sb(swp);
		ps_threepush(swp);
	}
	else if (swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 1]
			&& swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 2]
			&& swp->b_tab[swp->b_nbr - 1] > swp->b_tab[swp->b_nbr - 2])
		ps_threepush(swp);
	else
		ps_orderbbis(swp);
}

void		ps_order_b(t_push *swp, t_move *lst)
{
	int		nb;

	nb = lst->moves;
	if (ps_checkb(swp, nb) == 0)
	{
		while (nb-- > 0)
		{
			ft_putstr_fd("pa\n", STDOUT_FILENO);
			ps_pa(swp);
		}
		return ;
	}
	if (nb == 1)
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		ps_pa(swp);
	}
	else if (nb == 2)
		ps_order_b_deux(swp);
	else if (nb == 3)
		ps_orderb(swp);
}
