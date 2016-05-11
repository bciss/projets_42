/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 01:25:52 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/03 16:04:41 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlencign(const char *str, char c)
{
	size_t	i;
	char	q;

	i = 0;
	while (str[i] && str[i] != c)
	{
		while (str[i] && str[i] == '\\')
			i = i + 2;
		if (str[i] == '\'' || str[i] == '\"')
		{
			q = str[i];
//			while (str[i] == q)
				i++;
			while (str[i] != q)
			{
				while (str[i] == '\\')
					i = i + 2;
				i++;
			}
//			while (str[i] && str[i] == q && (*str + 1 == q || * str + 1 == c))
//			if (str[i])
			//	i++;
		}
		if (str[i] && str[i] == '\\')
			i = i + 2;
		else if (str[i] && str[i] != c)
			i++;
	}
	return (i);
}
