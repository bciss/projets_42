/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 23:01:06 by bciss             #+#    #+#             */
/*   Updated: 2015/05/05 17:38:44 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#define ABS(x) (x < 0) ? -x : x
#define X deltadist.x
#define Y deltadist.y
#define P v->perpwalldist

t_move	*init(void)
{
	t_move	*m;

	if (!(m = (t_move *)malloc(sizeof(t_move))))
		return (0);
	m->f = 0;
	m->b = 0;
	m->l = 0;
	m->r = 0;
	m->turn = 0;
	m->vitt = 0;
	m->first = 1;
	m->g = 0;
	return (m);
}

void	ft_ini(t_va *v)
{
	v->y = 0;
	v->cam.x = (2 * v->x / LONG) - 1;
	v->raypos.x = get_posx();
	v->raypos.y = get_posy();
	v->raydir.x = get_dirx() + get_plax() * v->cam.x;
	v->raydir.y = get_diry() + get_play() * v->cam.x;
	v->map.x = (int)v->raypos.x;
	v->map.y = (int)v->raypos.y;
	v->X = sqrt(1 + (v->raydir.y * v->raydir.y) / (v->raydir.x * v->raydir.x));
	v->Y = sqrt(1 + (v->raydir.x * v->raydir.x) / (v->raydir.y * v->raydir.y));
	v->hit = 0;
}

void	ft_perspe(t_va *v)
{
	if (v->raydir.x < 0)
	{
		v->step.x = -1;
		v->sidedist.x = (v->raypos.x - v->map.x) * v->deltadist.x;
	}
	else
	{
		v->step.x = 1;
		v->sidedist.x = (v->map.x + 1.0 - v->raypos.x) * v->deltadist.x;
	}
	if (v->raydir.y < 0)
	{
		v->step.y = -1;
		v->sidedist.y = (v->raypos.y - v->map.y) * v->deltadist.y;
	}
	else
	{
		v->step.y = 1;
		v->sidedist.y = (v->map.y + 1.0 - v->raypos.y) * v->deltadist.y;
	}
}

void	ft_hit(t_va *v)
{
	while (v->hit == 0)
	{
		if (v->sidedist.x < v->sidedist.y)
		{
			v->sidedist.x += v->deltadist.x;
			v->map.x += v->step.x;
			v->side = 0;
		}
		else
		{
			v->sidedist.y += v->deltadist.y;
			v->map.y += v->step.y;
			v->side = 1;
		}
		if (get_map((int)v->map.x, (int)v->map.y) > 0)
			v->hit = 1;
	}
}

void	ft_calc(t_va *v)
{
	if (v->side == 0)
		P = ABS((v->map.x - v->raypos.x + (1 - v->step.x) / 2) / v->raydir.x);
	else
		P = ABS((v->map.y - v->raypos.y + (1 - v->step.y) / 2) / v->raydir.y);
	v->height = ABS((int)(LONG / v->perpwalldist));
	v->draws = (int)(-v->height / 2 + LONG / 2);
	v->drawe = (int)(v->height / 2 + LONG / 2);
	if (v->draws < 0)
		v->draws = 0;
	if (v->drawe >= LONG)
		v->drawe = LONG - 1;
	v->y = v->draws;
}
