/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_round2_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:51:50 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/06 16:45:32 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_bas(int bas, t_push *swp)
{
	while (bas-- > 0)
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		ps_rrb(swp);
	}
}

static void	ps_is_sup(t_push *swp, t_move *lst)
{
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	ps_pa(swp);
	lst->moves++;
}

static void	ps_is_inf(t_push *swp, int *bas, t_move *prev)
{
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	ps_rb(swp);
	(*bas)++;
	prev->moves++;
}

void		ps_mediane_b(t_push *swp, t_move *lst)
{
	int		med;
	int		bas;
	int		nb;
	t_move	*prev;

	med = swp->fina[(lst->moves / 2) + swp->a_nbr + 1];
	nb = lst->moves;
	bas = 0;
	while (lst->next)
		lst = lst->next;
	ps_newlist(lst);
	lst = lst->next;
	lst->next = NULL;
	prev = lst->prev;
	prev->moves = 0;
	while (nb-- > 0)
	{
		if (swp->b_tab[swp->b_nbr] > med)
			ps_is_sup(swp, lst);
		else
			ps_is_inf(swp, &bas, prev);
	}
	ps_bas(bas, swp);
}
