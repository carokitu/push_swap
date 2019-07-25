/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 02:01:30 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/22 17:58:34 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ps_print(t_push *all)
{
	int	i;

	if (all->b_nbr > all->a_nbr)
		i = all->b_nbr + 1;
	else
		i = all->a_nbr + 1;
	printf("%7c --------------------------------\n", ' ');
	printf("%7c |     Pile A    |     Pile B    |\n", ' ');
	printf("%7c --------------------------------\n", ' ');
	while (--i >= 0)
	{
		if (i <= all->a_nbr && i <= all->b_nbr)
			printf("%7d | %13d | %13d |\n", i, all->a_tab[i], all->b_tab[i]);
		else if (i <= all->a_nbr)
			printf("%7d | %13d | %13c |\n", i, all->a_tab[i], ' ');
		else
			printf("%7d | %13c | %13d |\n", i, ' ', all->b_tab[i]);
	}
	printf("%7c --------------------------------\n", ' ');
}

void			ps_printelse(int *tab, t_push *all)
{
	int	i;

	i = all->a_nbr + 1;
	printf("%7c --------------------------------\n", ' ');
	printf("%7c |     Pile A    |     Pile B    |\n", ' ');
	printf("%7c --------------------------------\n", ' ');
	while (--i >= 0)
		printf("%7d | %13d | %13c |\n", i, tab[i], ' ');
	printf("%7c --------------------------------\n", ' ');
}
