/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_round2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:52:18 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/31 12:30:05 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ps_mediane_b(t_push *swp, t_move *lst)
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
//	printf("prev nb :%d\n", prev->nb);
//	printf("lst nb :%d\n", lst->nb);
	prev->moves = 0;
	while (nb-- > 0)
	{
		if (swp->b_tab[swp->b_nbr] > med)
			ps_is_sup(swp, lst);
		else
			ps_is_inf(swp, &bas, prev);
	}
	while (bas-- > 0)
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		ps_rrb(swp);
	}
//	printf("prev value :%d\n", prev->moves);
//	printf("lst value :%d\n", lst->moves);
}

static void	ps_manymoves(t_push *swp, t_move *lst)
{
	t_move	*old;

//	printf("mediane B : %d\n", lst->moves);
	ps_mediane_b(swp, lst);
//	puts("APRES MEDIANE B :");
//	ps_print(swp);
//	ps_printmoves(lst);
	while (lst->nb > 0)
	{
		while (lst->next)
			lst = lst->next;
		if (lst->moves <= 3)
		{
			if (ps_quick_check(swp) != 0)
				ps_order_a(swp, lst);
//			puts("APRES ORDER A");
//			ps_print(swp);
			if (lst->prev)
			{
				old = lst;
				lst = lst->prev;
				free(old);
				lst->next = NULL;
			}
//			ps_printmoves(lst);
			return ;
		}
		while (lst->prev)
			lst = lst->prev;
		while (lst->next)
			lst = lst->next;
		ps_mediane_a(swp, lst, swp->fina[(lst->moves / 2) + (swp->a_nbr - lst->moves) + 1]);
		while (lst->next)
			lst = lst->next;
//		puts("APRES MEDIANE SUR A");
//		ps_print(swp);
//		ps_printmoves(lst);
	}
}

void		ps_round2(t_push *swp, t_move *lst)
{
	t_move	*old;

	while (lst->next)
		lst = lst->next;
	while (lst->nb != 0)
		// && (!(ps_quick_check(swp) == 0 && swp->b_nbr == 0)))
	{
		while (lst->next)
			lst = lst->next;
		if (lst->moves <= 3)
		{
			ps_order_b(swp, lst);
			puts("APRES PTIT TRI DE B VERS A");
			ps_print(swp);
			if (lst->prev)
			{
				old = lst;
				lst = lst->prev;
				free(old);
				lst->next = NULL;
			}
			ps_printmoves(lst);
		}
		else
			ps_manymoves(swp, lst);
		if (lst->nb == 0 && lst->moves == 0)
			return ;
	}
}
