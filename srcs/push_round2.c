/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_round2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:52:18 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/08 18:02:00 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_manymoves_2(t_push *swp, t_move *lst, t_move *old)
{
	while (lst->next)
		lst = lst->next;
	if (lst->moves <= 3)
	{
		if (ps_quick_check(swp) != 0)
			ps_order_a(swp, lst);
		if (lst->prev)
		{
			old = lst;
			lst = lst->prev;
			free(old);
			lst->next = NULL;
		}
		else
			lst->moves = 0;
		return (1);
	}
	return (0);
}

static void	ps_manymoves(t_push *swp, t_move *lst)
{
	t_move	*old;

	ps_mediane_b(swp, lst);
	old = NULL;
	while (lst->nb >= 0)
	{
		if (ps_manymoves_2(swp, lst, old) == 1)
			return ;
		while (lst->prev)
			lst = lst->prev;
		while (lst->next)
			lst = lst->next;
		ps_mediane_a(swp, lst, swp->fina[(lst->moves / 2) +
			(swp->a_nbr - lst->moves) + 1]);
		while (lst->next)
			lst = lst->next;
	}
}

static void	ps_round2_bis(t_push *swp, t_move *lst, t_move *old)
{
	while (lst->nb >= 0 && !(swp->b_nbr == 0 && ps_quick_check(swp) == 0))
	{
		while (lst->next)
			lst = lst->next;
		if (lst->moves <= 3)
		{
			ps_order_b(swp, lst);
			if (lst->prev)
			{
				old = lst;
				lst = lst->prev;
				free(old);
				lst->next = NULL;
			}
			else
				lst->moves = 0;
		}
		else
			ps_manymoves(swp, lst);
		if (lst->nb == 0 && lst->moves == 0)
			return ;
	}
}

void		ps_round2(t_push *swp, t_move *lst)
{
	t_move	*old;

	old = NULL;
	while (lst->next)
		lst = lst->next;
	ps_round2_bis(swp, lst, old);
}
