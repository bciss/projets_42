/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:59:03 by bciss             #+#    #+#             */
/*   Updated: 2014/11/15 17:19:16 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s2);
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		k = 0;
		if (s1[i] == s2[k])
		{
			while (s1[i] == s2[k])
			{
				i++;
				k++;
				if (k == j)
					return ((char *)s1 + i - k);
			}
		}
		i++;
	}
	return (NULL);
}
