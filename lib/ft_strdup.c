/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:44:35 by cde-moul          #+#    #+#             */
/*   Updated: 2019/09/12 20:07:43 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		t;

	t = 0;
	while (s1[t])
		t++;
	if (!(str = ((char *)malloc(sizeof(char) * (t + 1)))))
		return (NULL);
	t = 0;
	while (s1[t])
	{
		str[t] = s1[t];
		t++;
	}
	str[t] = '\0';
	return (str);
}
