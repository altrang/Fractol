/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 09:37:33 by atrang            #+#    #+#             */
/*   Updated: 2016/04/20 18:11:28 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_test	*init_burn(t_test *test)
{
	test->x1 = -1.5;
	test->x2 = 1.5;
	test->y1 = -1;
	test->y2 = 1;
	test->image_x = WIDTH;
	test->image_y = HEIGHT;
	test->zoom_x = test->image_x / (test->x2 - test->x1);
	test->zoom_y = test->image_y / (test->y2 - test->y1);
	test->i_max = 42;
	test->c_r = 0;
	test->c_i = 0;
	test->z_r = 0;
	test->z_i = 0;
	test->tmp_r = 0;
	test->tmp_i = 0;
	test->i = 10;
	test->color = 1;
	return (test);
}

void	fractol_draw_burn(t_test *b)
{
	double	x;
	double	y;
	double	tmp;

	x = -1;
	while (++x < b->image_x)
	{
		y = -1;
		while (++y < b->image_y)
		{
			b->c_r = x / b->zoom_x + b->x1;
			b->c_i = y / b->zoom_y + b->y1;
			b->z_r = b->tmp_r;
			b->z_i = b->tmp_i;
			b->i = -1;
			while (b->z_r * b->z_r + b->z_i * b->z_i < 4 && ++b->i < b->i_max)
			{
				tmp = b->z_r;
				b->z_r = b->z_r * b->z_r - b->z_i * b->z_i - b->c_r;
				b->z_i = 2 * ft_abs(b->z_i) * ft_abs(tmp) + b->c_i;
			}
			put_pixel(b, WIDTH - x, y);
		}
	}
}
