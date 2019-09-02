/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:23:49 by cde-moul          #+#    #+#             */
/*   Updated: 2019/09/02 12:35:30 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ps_givefct(int i, t_push *all)
{
	void	(*fonction[11])(t_push *all);

	fonction[0] = ps_pb;
	fonction[1] = ps_pa;
	fonction[2] = ps_sa;
	fonction[3] = ps_sb;
	fonction[4] = ps_ss;
	fonction[5] = ps_ra;
	fonction[6] = ps_rb;
	fonction[7] = ps_rr;
	fonction[8] = ps_rra;
	fonction[9] = ps_rrb;
	fonction[10] = ps_rrr;
	return (fonction[i](all));
}

static int		ps_check2(int a, t_push *all)
{
	if (a == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ps_givefct(a, all);
	return (0);
}

static int		ps_checkline(char *line, t_push *all)
{
	char	*tab[11];
	int		i;
	int		a;

	i = -1;
	a = -1;
	tab[0] = "pb";
	tab[1] = "pa";
	tab[2] = "sa";
	tab[3] = "sb";
	tab[4] = "ss";
	tab[5] = "ra";
	tab[6] = "rb";
	tab[7] = "rr";
	tab[8] = "rra";
	tab[9] = "rrb";
	tab[10] = "rrr";
	while (++i <= 10)
	{
		if (ft_strcmp(line, tab[i]) == 0)
			a = i;
	}
	return (ps_check2(a, all));
}

int				ps_read(t_push *all)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if (!line || ps_checkline(line, all) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	if (ps_checkorder(all->a_tab, all->a_nbr, all->b_nbr) == 1)
	{
		ft_putstr("KO\n");
		return (1);
	}
	ft_putstr("OK\n");
	return (0);
}
