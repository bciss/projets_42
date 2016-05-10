/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:45:33 by bciss             #+#    #+#             */
/*   Updated: 2015/10/05 23:01:15 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <mlx.h>

# define BUF_SIZE 50
# define LARG 1280
# define LONG 900
# define T 0.1
# define W 13
# define A 0
# define D 2
# define S 1
# define SHIFT 257
# define Q 12
# define E 14
# define RIGHT 124
# define LEFT 123
# define TOP 126
# define BOT 125
# define PLUS 69
# define MOINS 78
# define NUM_1 18
# define NUM_2 19
# define NUM_3 20
# define NUM_4 21
# define NUM_5 23

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_move
{
	int				f;
	int				b;
	int				l;
	int				r;
	float			g;
	float			turn;
	float			vitt;
	int				first;
}					t_move;

typedef	struct		s_img
{
	void			*img;
	int				bpp;
	int				sl;
	int				endian;
	char			*data;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				nbr;
	t_img			*img;
	t_move			*m;
}					t_env;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	struct s_point	*next;
}					t_point;

typedef struct		s_var
{
	int				fd;
	int				ret;
	char			*tmp;
	char			*lol;
	int				x;
	int				y;
	int				j;
	int				i;
}					t_var;

typedef struct		s_va
{
	float			x;
	float			y;
	int				hit;
	int				side;
	int				height;
	int				draws;
	int				drawe;
	float			perpwalldist;
	t_pos			cam;
	t_pos			raypos;
	t_pos			raydir;
	t_pos			map;
	t_pos			sidedist;
	t_pos			deltadist;
	t_pos			step;
}					t_va;

extern t_pos		g_pos;
extern t_pos		g_dir;
extern t_pos		g_plane;
extern int			g_carte[24][24];

t_point				*ft_scan(char *str, int *nbr);
t_point				*ft_create_elem(int x, int y, int z);
t_point				*ft_scan2(t_var *var, int *nbr, t_point **p);
int					ft_scan3(t_var *var, t_point **p);
t_point				*ft_p_push_back(t_point **begin_list, int x, int y, int z);
void				mlx_pixel_put_to_image(t_img *img, int x, int y, int color);
void				ft_print(t_env *e, t_va *v);
void				ft_ini(t_va *v);
void				ft_perspe(t_va *v);
void				ft_back_forward(t_env *e, float vit);
void				ft_crabby_move(t_env *e, float vit);
void				ft_hit(t_va *v);
void				ft_calc(t_va *v);
t_move				*init(void);
double				get_posx(void);
double				get_posy(void);
void				set_posx(double x);
void				set_posy(double y);
double				get_dirx(void);
double				get_diry(void);
void				set_dirx(double x);
void				set_diry(double y);
double				get_plax(void);
double				get_play(void);
void				set_plax(double x);
void				set_play(double y);
int					get_map(int x, int y);

#endif
