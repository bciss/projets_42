/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 02:01:15 by bciss             #+#    #+#             */
/*   Updated: 2015/05/05 17:08:41 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos		*get_pla(void)
{
	static t_pos	pla = {0, 0.6};

	return (&pla);
}

void		set_plax(double x)
{
	get_pla()->x = x;
}

void		set_play(double y)
{
	get_pla()->y = y;
}

double		get_plax(void)
{
	return (get_pla()->x);
}

double		get_play(void)
{
	return (get_pla()->y);
}
