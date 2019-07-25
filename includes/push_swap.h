/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:02:04 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/25 03:11:05 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libftprintf.h"

typedef struct		s_push
{
	int				*b_tab;
	int				*a_tab;
	int				*fina;
	int				*moves;
	int				a_nbr;
	int				b_nbr;
	int				b_tabon;
	int				a_tabon;
}					t_push;

int					ps_read(t_push *all);
int					ps_checkorder(int *tab, int size,int b);
int					ps_quick_check(t_push *swp);
int					ps_checkb(t_push *swp, int move);
int					ps_checktill(t_push *swp);
int					ps_putintab(t_push *all, char **argv, int size);
void				ps_sa(t_push *all);
void				ps_sb(t_push *all);
void				ps_ss(t_push *all);
void				ps_pb(t_push *all);
void				ps_pa(t_push *all);
void				ps_rra(t_push *all);
void				ps_rrb(t_push *all);
void				ps_rrr(t_push *all);
void				ps_ra(t_push *all);
void				ps_rb(t_push *all);
void				ps_rr(t_push *all);
void				ps_print(t_push *all);
void				ps_start(t_push *all);
void				ps_mediane(t_push *swp);
void				ps_medianeb(t_push *swp,int moves);
void				ps_step2(t_push *swp);
void				ps_loop(t_push *swp, int *mv);
void				ps_loop2(t_push *swp, int *tab, int a);
void				ps_printelse(int *tab, t_push *all);
void				ps_tmptri(int *tab, t_push *swp);
void				ps_freesave(char **save, int to_free);
char				**ps_split_whitespaces(char *str);
char				**ps_getnewstr(char **argv);
#endif
