/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:07:47 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/09 11:04:46 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_orderbbis(t_push *swp)
{
	if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] < swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] < swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		ps_sa(swp);
	}
	else if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] < swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("sa\nra\nsa\nrra\n", STDOUT_FILENO);
		ps_sa(swp);
		ps_ra(swp);
		ps_sa(swp);
		ps_rra(swp);
	}
	else
	{
		ft_putstr_fd("ra\nsa\nrra\n", STDOUT_FILENO);
		ps_ra(swp);
		ps_sa(swp);
		ps_rra(swp);
	}
}

static void	ps_orderb(t_push *swp)
{
	if (ps_quick_check(swp) == 0)
		return ;
	if (swp->a_tab[swp->a_nbr] < swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] > swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("ra\nsa\nrra\nsa\n", STDOUT_FILENO);
		ps_ra(swp);
		ps_sa(swp);
		ps_rra(swp);
		ps_sa(swp);
	}
	else if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] > swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("sa\nra\nsa\nrra\nsa\n", STDOUT_FILENO);
		ps_sa(swp);
		ps_ra(swp);
		ps_sa(swp);
		ps_rra(swp);
		ps_sa(swp);
	}
	else
		ps_orderbbis(swp);
}

void		ps_order_a(t_push *swp, t_move *lst)
{
	int		nb;

	nb = lst->moves;
	if (nb == 2)
	{
		if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1])
		{
			ft_putstr_fd("sa\n", STDOUT_FILENO);
			ps_sa(swp);
		}
	}
	else if (nb == 3 && ps_quick_check(swp) != 0)
		ps_orderb(swp);
}
