/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 22:40:36 by bciss             #+#    #+#             */
/*   Updated: 2015/04/30 22:58:02 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_print2(t_env *e, t_va *v)
{
	if (v->drawe < 0)
		v->drawe = LONG;
	v->y = v->drawe;
	while (v->y < LONG)
	{
		mlx_pixel_put_to_image(e->img, v->x, v->y, 0x19318A);
		mlx_pixel_put_to_image(e->img, v->x, LONG - v->y - 1, 0x72408A);
		v->y++;
	}
	v->x++;
}

void	ft_print(t_env *e, t_va *v)
{
	while (v->y < v->drawe)
	{
		if (v->side == 1)
		{
			if (v->step.y > 0)
				mlx_pixel_put_to_image(e->img, v->x, v->y, 0xFF0000);
			else
				mlx_pixel_put_to_image(e->img, v->x, v->y, 0x0000FF);
		}
		else
		{
			if (v->step.x > 0)
				mlx_pixel_put_to_image(e->img, v->x, v->y, 0xE35875);
			else
				mlx_pixel_put_to_image(e->img, v->x, v->y, 0x0FF00F);
		}
		v->y++;
	}
	ft_print2(e, v);
}
