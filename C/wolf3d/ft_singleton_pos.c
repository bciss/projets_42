/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 02:01:15 by bciss             #+#    #+#             */
/*   Updated: 2015/05/01 02:09:14 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos		*get_pos(void)
{
	static t_pos	pos = {22, 11.5};

	return (&pos);
}

void		set_posx(double x)
{
	get_pos()->x = x;
}

void		set_posy(double y)
{
	get_pos()->y = y;
}

double		get_posx(void)
{
	return (get_pos()->x);
}

double		get_posy(void)
{
	return (get_pos()->y);
}
