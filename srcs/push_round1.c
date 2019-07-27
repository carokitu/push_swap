/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_round1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:14:26 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 19:34:35 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_orderabis(t_push *swp)
{
	if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
		&& swp->a_tab[swp->a_nbr] < swp->a_tab[swp->a_nbr - 2]
		&& swp->a_tab[swp->a_nbr - 1] < swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		ps_sa(swp);
	}
	else if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] < swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		ps_ra(swp);
	}
	else
	{
		ft_putstr_fd("sa\nra\n", STDOUT_FILENO);
		ps_sa(swp);
		ps_ra(swp);
	}
}

static void	ps_ordera(t_push *swp)
{
	if (swp->a_nbr == 1)
	{
		ft_putstr_fd("sa\n", STDOUT_FILENO);
		ps_sa(swp);
		return ;
	}
	if (swp->a_tab[swp->a_nbr] < swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] > swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		ps_rra(swp);
	}
	else if (swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 1]
			&& swp->a_tab[swp->a_nbr] > swp->a_tab[swp->a_nbr - 2]
			&& swp->a_tab[swp->a_nbr - 1] > swp->a_tab[swp->a_nbr - 2])
	{
		ft_putstr_fd("rra\nsa\n", STDOUT_FILENO);
		ps_rra(swp);
		ps_sa(swp);
	}
	else
		ps_orderabis(swp);
}

static void	ps_domedia(t_push *swp, int med, t_move *lst)
{
	int	i;

	i = swp->a_nbr;
	while (i >= 0)
	{
		if (swp->a_tab[swp->a_nbr] < med)
		{
			ft_putstr_fd("pb\n", STDOUT_FILENO);
			ps_pb(swp);
			lst->moves++;
		}
		else
		{
			ft_putstr_fd("ra\n", STDOUT_FILENO);
			ps_ra(swp);
		}
		i--;
	}
	ps_print(swp);
}

static void	ps_firstmediane(t_push *swp, t_move *lst)
{
	int med;

	while (ps_quick_check(swp) == 1 && swp->a_nbr >= 3) 
	{
		med = swp->fina[swp->a_nbr / 2];
		while (lst->moves != 0 && lst->next)
			lst = lst->next;
		if (!(lst->moves == 0))
		{
			ps_newlist(lst);
			lst = lst->next;
		}
		ps_domedia(swp, med, lst);
	}
	if (ps_quick_check(swp) == 1)
		ps_ordera(swp);
}

void		ps_round1(t_push *swp)
{
	t_move	*lst;
	t_move	*fre;

	if (!(lst = (t_move *)ft_memalloc(sizeof(t_move))))
		exit (EXIT_FAILURE);
	ps_tmptri(swp->a_tab, swp);
	ps_firstmediane(swp, lst);
	ps_printlist(lst);
	free(swp->fina);
	while (lst->next)
		lst = lst->next;
	while (lst->prev)
	{
		fre = lst;
		lst = lst->prev;
		free(fre);
	}
	free(lst);
}
