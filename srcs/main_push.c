/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:41:07 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/24 17:04:30 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ps_mainerror(t_push *swp)
{
	ft_putstr("Error\n");
	if (swp->a_tabon)
		free(swp->a_tab);
	if (swp->b_tabon)
		free(swp->b_tab);
	free(swp);
	return ;
}

static void	ps_main(int size, char **argv)
{
	t_push	*swp;

	if (!(swp = (t_push *)ft_memalloc(sizeof(t_push))))
		return ;
	swp->b_nbr = -1;
	swp->a_tabon = 0;
	swp->b_tabon = 0;
	swp->fina = NULL;
	swp->a_tab = NULL;
	swp->b_tab = NULL;
	if (ps_putintab(swp, argv, size) == 1)
		return (ps_mainerror(swp));
	ps_tmptri(swp->a_tab, swp);
	ps_printelse(swp->fina, swp);
	ps_start(swp);
	if (swp->b_tabon == 1)
		free(swp->b_tab);
	if (swp->a_tabon == 1)
		free(swp->a_tab);
	free(swp->fina);
	free(swp->moves);
	free(swp);
}

int			main(int argc, char **argv)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (argc < 2)
		return (1);
	new = ps_getnewstr(argv + 1);
	while (new[i])
		i++;
	ps_main(i, new);
	ps_freesave(new, 1);
	return (0);
}
