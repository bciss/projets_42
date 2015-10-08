/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 02:01:15 by bciss             #+#    #+#             */
/*   Updated: 2015/05/05 17:06:39 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos		*get_dir(void)
{
	static t_pos	dir = {-1, 0};

	return (&dir);
}

void		set_dirx(double x)
{
	get_dir()->x = x;
}

void		set_diry(double y)
{
	get_dir()->y = y;
}

double		get_dirx(void)
{
	return (get_dir()->x);
}

double		get_diry(void)
{
	return (get_dir()->y);
}
