/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:18:08 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/09 19:13:52 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char			*insert_char(char *to_edit, char c, int *cursor)
{
	char		edited[2048];
	int			i;
	int			k;

	if (to_edit[0] == '\0')
	{
		to_edit[0] = c;
		return (to_edit);
	}
	i = -1;
	while (to_edit[++i] && i < *cursor)
		edited[i] = to_edit[i];
	k = i;
	edited[k++] = c;
	while (to_edit[i])
		edited[k++] = to_edit[i++];
	edited[k] = '\0';
	return (ft_strcpy(to_edit, edited));
}
