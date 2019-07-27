/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_B.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:07:47 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 20:50:42 by cde-moul         ###   ########.fr       */
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


void		ps_order_B(t_push *swp, t_move *lst)
{
	int		nb;

	nb = lst->moves;
	if (nb == 1)
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		ps_pa(swp);
	}
	else if (nb == 2)
	{
		if (swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 1])
		{
			ft_putstr_fd("pa\npa\n", STDOUT_FILENO);
			ps_pa(swp);
			ps_pa(swp);
		}
		else
		{
			ft_putstr_fd("sa\npa\npa\n", STDOUT_FILENO);
			ps_sa(swp);
			ps_pa(swp);
			ps_pa(swp);
		}
	}
	else if (nb == 3)
		ps_orderb(swp);
}