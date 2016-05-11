/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roy <ale-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:27:11 by ale-roy           #+#    #+#             */
/*   Updated: 2016/04/22 03:05:39 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if ((tmp = ft_strjoin(s1, s2)) != NULL)
	{
		free(s1);
		return (tmp);
	}
	return (NULL);
}
