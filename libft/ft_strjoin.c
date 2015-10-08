/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:31:22 by bciss             #+#    #+#             */
/*   Updated: 2014/12/13 19:45:08 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_memalloc(i)))
		return (NULL);
	i = -1;
	k = 0;
	while (s1[++i] != '\0')
		str[k++] = s1[i];
	i = -1;
	k = (k == 0) ? 0 : k - 1;
	while (s2[++i] != '\0')
		str[k++] = s2[i];
	return (str);
}
