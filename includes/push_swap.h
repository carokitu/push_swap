/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:02:04 by cde-moul          #+#    #+#             */
/*   Updated: 2019/09/12 20:12:07 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 2654
# include <stdlib.h>
# include <unistd.h>

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
	int				visu;
}					t_push;

typedef struct		s_move
{
	struct s_move	*prev;
	struct s_move	*next;
	int				nb;
	int				moves;
}					t_move;

/*
**		CHECKER AND PUSH
*/

char				**ps_getnewstr(char **argv);
char				**ps_split_whitespaces(char *str);
void				ps_sa(t_push *all);
void				ps_sb(t_push *all);
void				ps_ss(t_push *all);
void				ps_pb(t_push *all);
void				ps_pa(t_push *all);
void				ps_ra(t_push *all);
void				ps_rb(t_push *all);
void				ps_rr(t_push *all);
void				ps_rra(t_push *all);
void				ps_rrb(t_push *all);
void				ps_rrr(t_push *all);
void				ps_freesave(char **save, int to_free);
int					ps_putintab(t_push *all, char **argv, int size);

/*
**		CHECKER
*/

int					ps_read(t_push *all);
int					ps_checkorder(int *tab, int size,int b);

/*
**		PUSH_SWAP
*/

int					ps_quick_check(t_push *swp);
int					ps_checkb(t_push *swp, int i);
void				ps_round1(t_push *swp);
void				ps_newlist(t_move *list);
void				ps_firstlist(t_move *lst);
void				ps_insertlist(t_move *lst);
void				ps_tmptri(int *tab, t_push *swp);
void				ps_round2(t_push *swp, t_move *lst);
void				ps_order_b(t_push *swp, t_move *lst);
void				ps_order_a(t_push *swp, t_move *lst);
void				ps_mediane_a(t_push *swp, t_move *lst, int med);

/*
**		LIB
*/

int					ft_strcmp(const char *s1, const char *s2);
int					get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *str);
void				*ft_memalloc(size_t size);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar(char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);


/*
**		USING PRINTF
*/

void				ps_print(t_push *all);
void				ps_printelse(int *tab, t_push *swp);
void				ps_printlist(t_move *list);
void				ps_printmoves(t_move *lst);

#endif
