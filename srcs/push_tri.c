/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 05:02:35 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/23 15:15:36 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_tmptri(int *tab, t_push *swp)
{
	int	i;
	int t;
	int	*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * (swp->a_nbr + 1))))
		return ;
	i = -1;
	while (++i <= swp->a_nbr)
		tmp[i] = tab[i];
	i = -1;
	while ((++i + 1) <= swp->a_nbr)
	{
		while (i >= 0 && tmp[i] < tmp[i + 1])
		{
			t = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = t;
			i--;
		}
	}
	swp->fina = tmp;
}
