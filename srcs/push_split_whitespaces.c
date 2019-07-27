/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 21:09:59 by cde-moul          #+#    #+#             */
/*   Updated: 2019/07/18 17:44:51 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_nbrmot(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*str)
		return (0);
	while (str[j] != '\0')
	{
		if ((str[j] >= 33 && str[j] <= 127) && (str[j] != '\0'))
		{
			if ((str[j + 1] == ' ' || str[j + 1] == '\t' || str[j + 1] == '\n'
						|| str[j + 1] == '\0'))
				i++;
		}
		j++;
	}
	return (i);
}

static char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_nbrlettre(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && str[j] != '\n'
				&& str[j] != '\t' && str[j] != 32)
		{
			i++;
			j++;
		}
		if ((str[j] == '\0' || str[j] == '\n' ||
					str[j] == '\t' || str[j] == ' '))
		{
			return (i);
		}
		j++;
	}
	return (i);
}

char			**ps_split_whitespaces(char *str)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_nbrmot(str) + 1));
	while (str[k] != '\0')
	{
		while ((str[k] != '\0') && (str[k] == '\t' || str[k] == '\n'
					|| str[k] == ' '))
			k++;
		if (str[k] != '\t' && str[k] != ' ' && str[k] != '\n' && str[k] != '\0')
		{
			tab[i] = (char *)malloc(sizeof(char) * (ft_nbrlettre(str + k) + 1));
			tab[i] = ft_strcpy(tab[i], str + k);
			i++;
			k++;
		}
		while (str[k] != '\0' && str[k] != '\t' &&
				str[k] != ' ' && str[k] != '\n')
			k++;
	}
	tab[i] = NULL;
	return (tab);
}
