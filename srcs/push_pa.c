/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:25:12 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/09 11:06:10 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_pa(t_push *all)
{
	int	tmp;

	if (all->b_nbr == -1)
		return ;
	tmp = all->b_tab[all->b_nbr];
	all->b_nbr--;
	all->a_nbr++;
	all->a_tab[all->a_nbr] = tmp;
}

void		ps_pb(t_push *all)
{
	int	tmp;

	if (all->a_nbr == -1)
		return ;
	tmp = all->a_tab[all->a_nbr];
	all->a_nbr--;
	all->b_nbr++;
	all->b_tab[all->b_nbr] = tmp;
}
