/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_round2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:52:18 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 20:50:44 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_mediane_B(t_push *swp, t_move *lst)
{
	int med;
	int	bas;
	int	nb;

	med = swp->fina[(lst->moves / 2) + swp->a_nbr - 1];
	printf("med : %d\n", med);
	nb = lst->moves;
	bas = 0;
	lst->moves = 0;
	while (nb-- >= 0)
	{
		if (swp->b_tab[swp->b_nbr] > med)
		{
			ft_putstr_fd("pa\n", STDOUT_FILENO);
			ps_pa(swp);
			lst->moves++;
		}
		else
		{
			ft_putstr_fd("rb\n", STDOUT_FILENO);
			ps_rb(swp);
			bas++;
		}
	}
	while (bas-- > 0)
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		ps_rrb(swp);
	}
	sleep(1);
	ps_print(swp);
}

void		ps_round2(t_push *swp, t_move *lst)
{
	t_move	*old;

	while (lst->next)
		lst = lst->next;
	while (lst->nb != 0)
	{
		sleep(1);
		if (lst->moves <= 3)
		{
			ps_order_B(swp, lst);
			if (lst->prev)
			{
				old = lst;
				lst = lst->prev;
				free(old);
				lst->next = NULL;
			}
		}
		else
		{
			puts("++++++++++++++++++++++++++++++");
			printf("lst->moves : %d\n", lst->moves);
			ps_mediane_B(swp, lst);
			printf("!lst->moves : %d\n", lst->moves);
		}
		while (lst->next)
			lst = lst->next;
	}
}
