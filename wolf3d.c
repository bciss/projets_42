/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:31:17 by bciss             #+#    #+#             */
/*   Updated: 2015/10/04 17:45:21 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#define ABS(x) (x < 0) ? -x : x
#define K {system("killall afplay"); exit(0);}

int		key_down_hook(int keycode, t_env *e)
{
	t_move	*m;

	m = e->m;
	if (keycode == W)
		m->f = 1;
	if (keycode == S)
		m->b = 1;
	if (keycode == A)
		m->l = 1;
	if (keycode == D)
		m->r = 1;
	if (keycode == SHIFT)
		m->g = 1;
	if (keycode == LEFT)
		m->turn = 1;
	if (keycode == LEFT)
		m->vitt = -T;
	if (keycode == RIGHT)
		m->turn = 1;
	if (keycode == RIGHT)
		m->vitt = T;
	if (keycode == 53)
		K;
	return (0);
}

int		key_up_hook(int keycode, t_env *e)
{
	t_move	*m;

	m = e->m;
	if (keycode == W)
		m->f = 0;
	if (keycode == S)
		m->b = 0;
	if (keycode == A)
		m->l = 0;
	if (keycode == D)
		m->r = 0;
	if (keycode == SHIFT)
		m->g = 0;
	if (keycode == LEFT)
	{
		m->turn = 0;
		m->vitt = 0;
	}
	if (keycode == RIGHT)
	{
		m->turn = 0;
		m->vitt = 0;
	}
	return (0);
}

void	move(t_env *e)
{
	float	vit;

	if (e->m->g)
		vit = 0.6;
	else
		vit = 0.2;
	ft_back_forward(e, vit);
	ft_crabby_move(e, vit);
}

int		expose_hook(t_env *e)
{
	t_va	*v;

	v = NULL;
	if (!(v = malloc(sizeof(t_va))))
		return (0);
	if (e->m->f || e->m->b || e->m->l || e->m->r || e->m->turn || e->m->first)
	{
		move(e);
		e->m->first = 0;
		v->x = 0;
		while (v->x < LARG)
		{
			ft_ini(v);
			ft_perspe(v);
			ft_hit(v);
			ft_calc(v);
			ft_print(e, v);
		}
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	}
	free((void *)v);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_img	img;

	if (ac == 1)
	{
		system("afplay esg.mp3&");
		e.mlx = mlx_init();
		if (e.mlx == NULL)
			return (-1);
		img.img = mlx_new_image(e.mlx, LARG, LONG);
		img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endian);
		e.img = &img;
		e.win = mlx_new_window(e.mlx, LARG, LONG, "Wolf3d");
		e.m = init();
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 2, 1, key_down_hook, &e);
		mlx_hook(e.win, 3, 2, key_up_hook, &e);
		mlx_loop_hook(e.mlx, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	(void)av;
	return (0);
}
