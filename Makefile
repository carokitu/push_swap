# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 13:45:49 by cde-moul          #+#    #+#              #
#    Updated: 2019/07/27 20:50:46 by cde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1			=	checker

NAME2			=	push_swap

SRCSDIR			=	./srcs

OBJSDIR			=	./objs

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
					push_order_B.c \
					push_list.c \
					push_tri.c \
					push_r.c \
					push_pa.c \
					push_ss.c \
					push_rr.c \
					push_check.c \
					push_split_whitespaces.c \

OBJS1			=	$(addprefix $(OBJSDIR)/, $(SRCS1:.c=.o))

OBJS2			=	$(addprefix $(OBJSDIR)/, $(SRCS2:.c=.o))

CC				=	gcc -g

CFLAGS			=	-Wall -Wextra -Werror

INCL			=	-I includes/ -I libft/ -I libft/libft

RM				=	rm -f

LIB				=	libft/libft.a

all				:	libft $(NAME1) $(NAME2)

$(NAME1)		:	$(OBJS1) $(LIB) $(INCLUDES)
					$(CC) $(CFLAGS) $(INCL) $(OBJS1) $(LIB) -o $(NAME1)

$(NAME2)		:	$(OBJS2) $(LIB) $(INCLUDES)
					$(CC) $(CFLAGS) $(OBJS2) $(LIB) -o $(NAME2)

$(LIB)			:
					make -C libft/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c $(INCLUDES)
					mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAGS) $(INCL) -c $< -o $@

libft			:
					make -C libft/

clean			:
					rm -rf $(OBJSDIR)
					make -C libft/ clean

fclean			:	clean
					$(RM) $(NAME1) $(NAME2)
					make -C libft/ clean

re				:
					make fclean
					make all

.PHONY			:	clean fclean re
