/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roy <ale-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 04:02:10 by ale-roy           #+#    #+#             */
/*   Updated: 2015/01/12 19:10:00 by ale-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION
**	The ft_replace_char() function replaces all find character in the s string
**	for replace character.
**	RETURN VALUES
**	The ft_replace_char() function returns a copy of the string s where find
**	character is replaced with replace.
*/

char	*ft_replace_char(char *s, int find, int replace)
{
	char	*tmp;
	char	*ret;

	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(s));
	ret = tmp;
	while (*s)
	{
		if (*s == find)
			*tmp = replace;
		else
			*tmp = *s;
		s++;
		tmp++;
	}
	return (ret);
}
