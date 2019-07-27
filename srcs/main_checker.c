/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:41:07 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 17:20:44 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			ps_main(int size, char **argv)
{
	t_push		*all;

	if (!(all = (t_push *)ft_memalloc(sizeof(t_push))))
		return (1);
	all->b_tabon = 0;
	all->a_tabon = 0;
	all->b_nbr = -1;
	if (ps_putintab(all, argv, size) == 1)
	{
		ft_putstr("Error\n");
		if (all->a_tabon)
			free(all->a_tab);
		if (all->b_tabon)
			free(all->b_tab);
		free(all);
		return (1);
	}
	ps_print(all);
	ps_read(all);
	if (all->b_tabon == 1)
		free(all->b_tab);
	if (all->a_tabon == 1)
		free(all->a_tab);
	free(all);
	return (0);
}

int					main(int argc, char **argv)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (argc < 2)
		return (0);
	if (argv[1] && ft_strcmp(argv[1], "-v") == 0)
		new = ps_getnewstr(argv + 2);
	else
		new = ps_getnewstr(argv + 1);
	while (new[i])
		i++;
	ps_main(i, new);
	ps_freesave(new, 1);
	return (0);
}
