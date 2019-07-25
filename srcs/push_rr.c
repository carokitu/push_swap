/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 00:09:24 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/19 01:42:25 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_rra(t_push *all)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = all->a_tab[0];
	while (++i < all->a_nbr && i >= 0)
		all->a_tab[i] = all->a_tab[i + 1];
	all->a_tab[all->a_nbr] = tmp;
}

void		ps_rrb(t_push *all)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = all->b_tab[0];
	while (++i < all->b_nbr && i >= 0)
		all->b_tab[i] = all->b_tab[i + 1];
	all->b_tab[all->b_nbr] = tmp;
}

void		ps_rrr(t_push *all)
{
	ps_rra(all);
	ps_rrb(all);
}
