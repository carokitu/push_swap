/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:34:09 by cde-moul          #+#    #+#             */
/*   Updated: 2020/01/09 11:13:18 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_newlist(t_move *lst)
{
	t_move	*new;

	if (!(new = (t_move *)ft_memalloc(sizeof(t_move))))
		exit(EXIT_FAILURE);
	while (lst->next)
		lst = lst->next;
	new->nb = lst->nb + 1;
	new->moves = 0;
	new->prev = lst;
	new->next = NULL;
	lst->next = new;
	lst = lst->next;
}

/*
** insert nouveau maillon avant le dernier
**		utile pour les pushs de A vers B round2
*/

void		ps_insertlist(t_move *lst)
{
	t_move	*las;
	t_move	*new;
	t_move	*bef;

	las = lst;
	while (las->next)
		las = las->next;
	bef = las->prev;
	las->nb++;
	if (!(new = (t_move *)ft_memalloc(sizeof(t_move))))
		exit(EXIT_FAILURE);
	new->prev = bef;
	new->next = las;
	new->nb = (bef->nb) + 1;
	bef->next = new;
	las->prev = new;
	las->next = NULL;
}
