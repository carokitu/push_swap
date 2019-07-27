/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:37:00 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/27 17:40:42 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ps_checkorder(int *tab, int size, int b)
{
	if (b != -1)
		return (1);
	while (--size >= 0)
	{
		if (tab[size] < tab[size + 1])
			return (1);
	}
	return (0);
}

static char		**ps_newnew(char **old, char **small)
{
	int		i;
	int		size;
	char	**new;

	i = 0;
	while (old[i])
		i++;
	size = i;
	i = -1;
	while (small[++i])
		size++;
	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		exit (EXIT_FAILURE);
	i = -1;
	size = 0;
	while (old[++i])
		if (!(new[size++] = ft_strdup(old[i])))
			exit (EXIT_FAILURE);
	i = -1;
	while (small[++i])
		if (!(new[size++] = ft_strdup(small[i])))
			exit (EXIT_FAILURE);
	new[size] = NULL;
	ps_freesave(old, 1);
	ps_freesave(small, 1);
	return (new);
}

char			**ps_getnewstr(char **argv)
{
	int		i;
	char	**new;
	char	**small;

	i = 0;
	new = ps_split_whitespaces(argv[i]);
	while (argv[++i])
	{
		small = ps_split_whitespaces(argv[i]);
		new = ps_newnew(new, small);
	}
	return (new);
}

void			ps_freesave(char **save, int to_free)
{
	int	i;

	i = 0;
	if (to_free == 0)
		return ;
	if (!(save[0]))
	{
		free(save);
		return ;
	}
	while (save[i])
	{
		free(save[i]);
		save[i] = NULL;
		i++;
	}
	free(save);
}
