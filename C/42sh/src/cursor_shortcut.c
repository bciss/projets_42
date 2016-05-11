/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_shortcut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:38:17 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/10 17:38:56 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					size_until_next_word(char *sentence, int cursor)
{
	int		i;

	i = cursor;
	while (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n' &&
			sentence[i] != '\0')
		i++;
	while (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t')
		i++;
	if (sentence[i] == '\0')
		i--;
	return (i - cursor + 1);
}

int					size_until_prev_word(char *sentence, int cursor)
{
	int		i;
	int		j;

	i = cursor;
	j = 0;
	while (i > 0 && sentence[i] != ' ' && sentence[i] != '\t'
			&& sentence[i] != '\n' && i > 0)
		i--;
	while (i > 0 && (sentence[i] == ' ' || sentence[i] == '\n'
				|| sentence[i] == '\t') && i > 0)
		i--;
	while (i > 0 && sentence[i] != ' ' && sentence[i] != '\t'
			&& sentence[i] != '\n')
	{
		j = 1;
		i--;
	}
	if (i == 0 && (sentence[i] != ' ' || sentence[i] != '\t'
				|| sentence[i] != '\n'))
		i--;
	return (cursor - i - j);
}
