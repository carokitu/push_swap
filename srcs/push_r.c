/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:24:09 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/19 03:33:31 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_ra(t_push *all)
{
	int	tmp;
	int	i;

	if (all->a_nbr == -1)
		return ;
	i = all->a_nbr + 1;
	tmp = all->a_tab[all->a_nbr];
	while (--i > 0)
		all->a_tab[i] = all->a_tab[i - 1];
	all->a_tab[0] = tmp;
	return ;
}

void		ps_rb(t_push *all)
{
	int	tmp;
	int	i;

	if (all->b_nbr == -1)
		return ;
	i = all->b_nbr + 1;
	tmp = all->b_tab[all->b_nbr];
	while (--i > 0)
		all->b_tab[i] = all->b_tab[i - 1];
	all->b_tab[0] = tmp;
	return ;
}

void		ps_rr(t_push *all)
{
	ps_rb(all);
	ps_ra(all);
}
