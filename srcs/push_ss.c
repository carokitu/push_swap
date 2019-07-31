/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:33:43 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/29 14:07:47 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_sa(t_push *all)
{
	int	tmp;

	if (all->a_nbr < 1)
		return ;
	tmp = all->a_tab[all->a_nbr];
	all->a_tab[all->a_nbr] = all->a_tab[all->a_nbr - 1];
	all->a_tab[all->a_nbr - 1] = tmp;
}

void		ps_sb(t_push *all)
{
	int	tmp;

	if (all->b_nbr < 1)
		return ;
	tmp = all->b_tab[all->b_nbr];
	all->b_tab[all->b_nbr] = all->b_tab[all->b_nbr - 1];
	all->b_tab[all->b_nbr - 1] = tmp;
}

void		ps_ss(t_push *all)
{
	ps_sb(all);
	ps_sa(all);
}
