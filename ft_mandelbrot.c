/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 10:50:46 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 13:23:03 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_test		*init_mand(t_test *info)
{
	info->x1 = -2.1;
	info->x2 = 0.6;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->image_x = WIDTH;
	info->image_y = HEIGHT;
	info->zoom_x = info->image_x / (info->x2 - info->x1);
	info->zoom_y = info->image_y / (info->y2 - info->y1);
	info->i_max = 30;
	info->c_r = 0;
	info->c_i = 0;
	info->z_r = 0;
	info->z_i = 0;
	info->tmp_r = 0;
	info->tmp_i = 0;
	info->color = 1;
	return (info);
}

void		fractol_draw_mand(t_test *t)
{
	double x;
	double y;
	double tmp;

	x = -1;
	while (++x < t->image_x)
	{
		y = -1;
		while (++y < t->image_y)
		{
			t->c_r = x / t->zoom_x + t->x1;
			t->c_i = y / t->zoom_y + t->y1;
			t->z_r = t->tmp_r;
			t->z_i = t->tmp_i;
			t->i = 0;
			while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && t->i < t->i_max)
			{
				tmp = t->z_r;
				t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
				t->z_i = 2 * t->z_i * tmp + t->c_i;
				t->i = t->i + 1;
			}
			put_pixel(t, x, y);
		}
	}
}
