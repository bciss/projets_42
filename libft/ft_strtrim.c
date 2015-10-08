/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:42:24 by bciss             #+#    #+#             */
/*   Updated: 2015/03/24 18:47:21 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtrimback(const char *s)
{
	int	i;

	i = 0;
	while (s[i + 1] != '\0')
		i++;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (i))
		i--;
	return (i);
}

char	*ft_strtrim(const char *s)
{
	unsigned int	v;
	unsigned int	k;
	unsigned int	i;
	char			*str;

	if (s)
	{
		i = ft_strlen(s);
		v = ft_strtrimback(s);
		str = ft_memalloc(i);
		i = 0;
		k = 0;
		while (s[i] != '\0' && (s[i] == ' ' || (s[i] == '\n' || s[i] == '\t')))
			i++;
		while (i <= v)
		{
			str[k++] = s[i++];
		}
		str[k] = '\0';
		return (str);
	}
	return (0);
}
