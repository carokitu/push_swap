/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:16:43 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/29 14:18:50 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ps_quick_check(t_push *swp)
{
	int	i;

	i = -1;
	while (++i <= swp->a_nbr)
	{
		if (swp->a_tab[i] != swp->fina[i])
			return (1);
	}
	return (0);
}

int				ps_quicktill(t_push *swp)
{
	int	i;

	i = -1;
	while (++i <= swp->a_nbr)
	{
		if (swp->a_tab[i] != swp->fina[i])
			return (i);
	}
	return (i);
}

int				ps_checkb(t_push *swp, int move)
{
	int	i;
	int	a;
	int	u;

	u = 0;
	i = swp->a_nbr + 1;
	a = swp->b_nbr;
	while (u++ < move)
	{
		if (swp->b_tab[a--] != swp->fina[i++])
			return (1);
	}
	return (0);
}
