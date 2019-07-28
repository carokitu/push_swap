/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mediane_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:08:19 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/28 17:17:08 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_part2(t_push *swp, int bas, t_move *lst)
{
	while (bas-- > 0)
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		ps_rra(swp);
		lst->moves++;
	}
}

void		ps_mediane_a(t_push *swp, t_move *lst, int med)
{
	int		bas;
	int		nb;
	t_move	*prev;

	nb = 0;
	bas = 0;
	printf("MED : %d\n", med);
	printf("lst avant : %p\n", lst);
	printf("lst avant : %d\n", lst->nb);
	printf("lst->prev avant : %p\n", lst->prev);
	printf("lst->next avant : %p\n", lst->next);
	ps_insertlist(lst);
	printf("lst apres : %p\n", lst);
	printf("lst apres : %d\n", lst->prev->nb);
	printf("lst->prev apres : %p\n", lst->prev);
	printf("lst->next apres : %p\n", lst->next);
	
	prev = lst->prev;
	while (lst->moves-- >= 0)
	{
		if (swp->a_tab[swp->a_nbr] < med)
		{
			ft_putstr_fd("pb\n", STDOUT_FILENO);
			ps_pb(swp);
			nb++;
		}
		else
		{
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			ps_ra(swp);
			bas++;
		}
	}
	ps_part2(swp, bas, lst);
	prev->moves = nb;
}
