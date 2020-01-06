# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 13:45:49 by cde-moul          #+#    #+#              #
#    Updated: 2020/01/06 12:38:26 by cde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			=	checker

NAME2			=	push_swap

SRCSDIR			=	./srcs

OBJSDIR			=	./objs

SRCSLIB			=	./lib

INCLUDES		=	./includes/push_swap.h

SRCS1			=	main_checker.c \
					push_split_whitespaces.c \
					push_put.c \
					push_r.c \
					push_pa.c \
					push_ss.c \
					push_rr.c \
					push_read.c \
					push_order.c \
					push_print.c

SRCS2			=	main_push.c \
					push_put.c \
					push_print.c \
					push_order.c \
					push_round1.c \
					push_round2.c \
					push_order_a.c \
					push_order_b.c \
					push_order_b_bis.c \
					push_list.c \
					push_tri.c \
					push_r.c \
					push_mediane_a.c \
					push_pa.c \
					push_ss.c \
					push_rr.c \
					push_check.c \
					push_split_whitespaces.c \

LIB				=	ft_memalloc.c \
					ft_putnbr.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_putchar.c \
					ft_strlen.c \
					ft_strsub.c \
					ft_strdel.c \
					ft_strjoin.c \
					ft_char_in_str.c \
					get_next_line.c

OBJS1			=	$(addprefix $(OBJSDIR)/, $(SRCS1:.c=.o))

OBJS2			=	$(addprefix $(OBJSDIR)/, $(SRCS2:.c=.o))

OBJLIB			=	$(addprefix $(SRCSLIB)/, $(LIB:.c=.o))

CC				=	gcc -g

CFLAGS			=	-Wall -Wextra -Werror

INCL			=	-I includes/ -I libft/ -I libft/libft

RM				=	rm -f

all				:	$(NAME1) $(NAME2)

$(NAME1)		:	$(OBJS1) $(OBJLIB) $(INCLUDES)
					$(CC) $(CFLAGS) $(INCL) $(OBJLIB) $(OBJS1) -o $(NAME1)

$(NAME2)		:	$(OBJS2) $(OBJLIB) $(INCLUDES)
					$(CC) $(CFLAGS) $(OBJS2) $(OBJLIB) -o $(NAME2)

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c $(INCLUDES)
					mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAGS) $(INCL) -c $< -o $@


clean			:
					rm -rf $(OBJSDIR)
					rm -rf $(OBJLIB)

fclean			:	clean
					$(RM) $(NAME1) $(NAME2)

re				:
					make fclean
					make all

.PHONY			:	clean fclean re libft
