/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:14:03 by bciss             #+#    #+#             */
/*   Updated: 2015/05/01 00:32:36 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	img->data[y * img->sl + x * img->bpp / 8] = color1;
	img->data[y * img->sl + x * img->bpp / 8 + 1] = color2;
	img->data[y * img->sl + x * img->bpp / 8 + 2] = color3;
}
