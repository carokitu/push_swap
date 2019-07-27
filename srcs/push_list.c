/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:34:09 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 19:36:13 by cde-moul         ###   ########.fr       */
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

void		ps_printlist(t_move *lst)
{
	t_move	*wlk;

	wlk = lst;
	while (wlk->prev)
		wlk = wlk->prev;
	while (wlk->next)
	{
		printf("%d) %d\n", wlk->nb, wlk->moves);
		wlk = wlk->next;
	}
	printf("%d) %d\n", wlk->nb, wlk->moves);
}
