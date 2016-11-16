/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 10:52:52 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 13:28:07 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_funct(int keycode, void *param)
{
	t_test *test;

	test = param;
	if (keycode == 49)
		test->pause = test->pause ^ 1;
	if (keycode == 53)
		exit(0);
	if (keycode == 83)
	{
		test->color = 1;
		init_fractal(test);
	}
	if (keycode == 84)
	{
		test->color = 2;
		init_fractal(test);
	}
	if (keycode == 85)
	{
		test->color = 3;
		init_fractal(test);
	}
	else
		ft_key_funct2(keycode, test);
	return (0);
}

int		ft_key_funct2(int keycode, void *param)
{
	t_test *test;

	test = param;
	if (keycode == 15)
		ft_start(test);
	if (keycode == 86)
	{
		test->fract = 1;
		ft_start(test);
	}
	if (keycode == 87)
	{
		test->fract = 2;
		ft_start(test);
	}
	if (keycode == 88)
	{
		test->fract = 3;
		ft_start(test);
	}
	return (0);
}

void	ft_zoom(int scroll, t_test *test)
{
	if (scroll == 4)
	{
		test->zoom_x = test->zoom_x * 2;
		test->zoom_y = test->zoom_y * 2;
		test->i_max += 10;
	}
	if (scroll == 5)
	{
		test->zoom_x = test->zoom_x / 2;
		test->zoom_y = test->zoom_y / 2;
		test->i_max = test->i_max - 10 <= 0 ? 1 : test->i_max - 10;
	}
}

int		ft_mouse_scroll(int scroll, int x, int y, void *param)
{
	t_test	*test;
	double	z_x;
	double	z_y;

	test = param;
	if (test->pause != 1)
		return (1);
	z_x = test->zoom_x;
	z_y = test->zoom_y;
	ft_zoom(scroll, test);
	test->x1 += x / z_x - (x / test->zoom_x);
	test->y1 += y / z_y - (y / test->zoom_y);
	init_fractal(test);
	return (0);
}

int		ft_mouse_funct(int x, int y, t_test *test)
{
	if (test->pause != 1)
	{
		test->tmp_r = (double)(x - 500) / 500;
		test->tmp_i = (double)(y - 500) / 500;
		init_fractal(test);
	}
	return (0);
}
