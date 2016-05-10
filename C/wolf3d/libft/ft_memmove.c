/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:34:20 by bciss             #+#    #+#             */
/*   Updated: 2014/11/16 20:39:35 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;

	str = ft_memalloc(sizeof(char *) * len);
	str = ft_memcpy(str, src, len);
	dst = ft_memcpy(dst, src, len);
	free((void *)str);
	return (dst);
}
