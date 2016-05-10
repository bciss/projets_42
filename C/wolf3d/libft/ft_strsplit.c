/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:09:54 by bciss             #+#    #+#             */
/*   Updated: 2014/11/16 21:12:16 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wordlen(char const *s, char c, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		j++;
		i++;
	}
	return (j - 1);
}

unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 1;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	char			**tab;
	unsigned int	len;
	int				j;

	i = -1;
	j = 0;
	if (s)
	{
		if ((tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1)))
				== NULL)
			return (NULL);
		while (s[++i] != '\0')
		{
			(s[i] == '\n') ? i++ : i;
			if (s[i] != c)
			{
				len = ft_wordlen(s, c, i);
				tab[j++] = ft_strsub(s, i, (len + 1));
				i += len;
			}
		}
		return (tab);
	}
	return (0);
}
