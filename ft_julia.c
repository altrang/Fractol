/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:03:34 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 13:24:18 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_test		*init_julia(t_test *info)
{
	info->x1 = -1.5;
	info->x2 = 1.5;
	info->y1 = -1.2;
	info->y2 = 1.2;
	info->image_x = WIDTH;
	info->image_y = HEIGHT;
	info->zoom_x = info->image_x / (info->x2 - info->x1);
	info->zoom_y = info->image_y / (info->y2 - info->y1);
	info->i_max = 50;
	info->c_r = 0;
	info->c_i = 0;
	info->z_r = 0;
	info->z_i = 0;
	info->tmp_r = 0.285;
	info->tmp_i = 0.01;
	info->i = 0;
	info->color = 1;
	return (info);
}

void		fractol_draw_julia(t_test *t)
{
	double	x;
	double	y;
	double	tmp;

	x = -1;
	while (++x < t->image_x)
	{
		y = -1;
		while (++y < t->image_y)
		{
			t->z_r = x / t->zoom_x + t->x1;
			t->z_i = y / t->zoom_y + t->y1;
			t->c_r = t->tmp_r;
			t->c_i = t->tmp_i;
			t->i = -1;
			while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && ++t->i < t->i_max)
			{
				tmp = t->z_r;
				t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
				t->z_i = 2 * t->z_i * tmp + t->c_i;
			}
			put_pixel(t, x, y);
		}
	}
}
