/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:39:26 by cde-moul          #+#    #+#             */
/*   Updated: 2019/09/02 12:33:52 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_and_check(int size, char **arg)
{
	t_push	*swp;

	if (!(swp = (t_push *)ft_memalloc(sizeof(t_push))))
		return ;
	swp->b_nbr = -1;
	if (ps_putintab(swp, arg, size) == 1)
	{
		ft_putstr("Error\n");
		if (swp->a_tabon)
			free(swp->a_tab);
		if (swp->b_tabon)
			free(swp->b_tab);
		free(swp);
		return ;
	}
	ps_round1(swp);
	if (swp->a_tabon)
		free(swp->a_tab);
	if (swp->b_tabon)
		free(swp->b_tab);
	free(swp);
}

int			main(int argv, char **argc)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (argv < 2)
		return (0);
	if (argc[1] && ft_strcmp(argc[1], "-v") == 0)
		new = ps_getnewstr(argc + 2);
	else
		new = ps_getnewstr(argc + 1);
	while (new[i])
		i++;
	init_and_check(i, new);
	ps_freesave(new, 1);
	return (1);
}
