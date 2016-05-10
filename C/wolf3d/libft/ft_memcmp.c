/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:46:56 by bciss             #+#    #+#             */
/*   Updated: 2014/11/16 20:40:48 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if ((str1 == NULL) || (str2 == NULL) || (int)n == 0)
		return (0);
	while (i < n - 1)
	{
		if ((str1[i]) == (str2[i]))
			i++;
		else
			return (str1[i]) - (str2[i]);
	}
	return (0);
}
