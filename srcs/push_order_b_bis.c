/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order_b_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:33:18 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/09 11:05:39 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_order_b_deux(t_push *swp)
{
	if (swp->b_tab[swp->b_nbr] > swp->b_tab[swp->b_nbr - 1])
	{
		ft_putstr_fd("pa\npa\n", STDOUT_FILENO);
		ps_pa(swp);
		ps_pa(swp);
	}
	else
	{
		ft_putstr_fd("sb\npa\npa\n", STDOUT_FILENO);
		ps_sb(swp);
		ps_pa(swp);
		ps_pa(swp);
	}
}
