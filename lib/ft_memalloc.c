/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:18:09 by cde-moul          #+#    #+#             */
/*   Updated: 2019/09/12 20:05:31 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
		str[size] = 0;
	return ((void *)str);
}
