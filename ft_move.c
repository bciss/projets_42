/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 19:01:06 by bciss             #+#    #+#             */
/*   Updated: 2015/10/08 17:25:20 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#define MAP get_map

void	ft_back_forward(t_env *e, float vit)
{
	float	oldd;
	float	oldp;

	if (e->m->f)
		if (MAP((int)(get_posx() + (get_dirx() * vit)), (int)get_posy()) == 0)
			set_posx(get_posx() + (get_dirx() * vit));
	if (e->m->f)
		if (MAP((int)get_posx(), (int)(get_posy() + (get_diry() * vit))) == 0)
			set_posy(get_posy() + (get_diry() * vit));
	if (e->m->b)
	{
		if (MAP((int)(get_posx() - (get_dirx() * vit)), (int)get_posy()) == 0)
			set_posx(get_posx() - (get_dirx() * vit));
		if (MAP((int)get_posx(), (int)(get_posy() - (get_diry() * vit))) == 0)
			set_posy(get_posy() - (get_diry() * vit));
	}
	if (e->m->turn)
	{
		oldd = get_dirx();
		set_dirx(get_dirx() * cos(-e->m->vitt) - get_diry() * sin(-e->m->vitt));
		set_diry(oldd * sin(-e->m->vitt) + get_diry() * cos(-e->m->vitt));
		oldp = get_plax();
		set_plax(get_plax() * cos(-e->m->vitt) - get_play() * sin(-e->m->vitt));
		set_play(oldp * sin(-e->m->vitt) + get_play() * cos(-e->m->vitt));
	}
}

void	ft_crabby_move(t_env *e, float vit)
{
	if (e->m->r)
	{
		if (MAP((int)(get_posx() + (get_plax() * vit)), (int)get_posy()) == 0)
			set_posx(get_posx() + (get_plax() * vit));
		if (MAP((int)get_posx(), (int)(get_posy() + (get_play() * vit))) == 0)
			set_posy(get_posy() + (get_play() * vit));
	}
	if (e->m->l)
	{
		if (MAP((int)(get_posx() - (get_plax() * vit)), (int)get_posy()) == 0)
			set_posx(get_posx() - (get_plax() * vit));
		if (MAP((int)get_posx(), (int)(get_posy() - (get_play() * vit))) == 0)
			set_posy(get_posy() - (get_play() * vit));
	}
}
