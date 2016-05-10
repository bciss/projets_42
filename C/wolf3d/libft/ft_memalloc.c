/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:00:21 by bciss             #+#    #+#             */
/*   Updated: 2015/03/24 18:46:02 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*memory;
	char			*explorer;
	unsigned int	i;

	i = 0;
	memory = (void *)malloc(size + 1);
	explorer = (char *)memory;
	if (memory != NULL)
	{
		while (i++ < size)
			*explorer++ = 0;
	}
	return (memory);
}
