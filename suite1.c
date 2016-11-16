/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:39:10 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 11:38:01 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_fractal(t_test *test)
{
	mlx_destroy_image(test->mlx, test->img);
	test->img = mlx_new_image(test->mlx, WIDTH, HEIGHT);
	test->data = mlx_get_data_addr(test->img, &test->bpp,
		&test->sizeline, &test->endian);
	test->bpp_div = test->bpp >> 3;
	if (test->fract == 2)
		fractol_draw_julia(test);
	if (test->fract == 1)
		fractol_draw_mand(test);
	if (test->fract == 3)
		fractol_draw_burn(test);
	mlx_put_image_to_window(test->mlx, test->win, test->img, 0, 0);
	mlx_string_put(test->mlx, test->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(test->mlx, test->win, 35, 60, 0xFFFFFF, "1-3 = Color");
	mlx_string_put(test->mlx, test->win, 35, 75, 0xFFFFFF,
		"4-6 = Ch Fract");
	mlx_string_put(test->mlx, test->win, 35, 90, 0xFFFFFF, "r = restart");
	mlx_string_put(test->mlx, test->win, 35, 105, 0xFFFFFF, "Space = Pause");
	return (0);
}

int		ft_start(t_test *test)
{
	if (test->fract == 2)
		test = init_julia(test);
	if (test->fract == 1)
		test = init_mand(test);
	if (test->fract == 3)
		test = init_burn(test);
	if (test->fract > 3)
		ft_help();
	test->img = mlx_new_image(test->mlx, WIDTH, HEIGHT);
	test->data = mlx_get_data_addr(test->img, &test->bpp,
		&test->sizeline, &test->endian);
	test->bpp_div = test->bpp >> 3;
	if (test->fract == 2)
		fractol_draw_julia(test);
	if (test->fract == 1)
		fractol_draw_mand(test);
	if (test->fract == 3)
		fractol_draw_burn(test);
	mlx_put_image_to_window(test->mlx, test->win, test->img, 0, 0);
	mlx_string_put(test->mlx, test->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(test->mlx, test->win, 35, 60, 0xFFFFFF, "1-3 = Color");
	mlx_string_put(test->mlx, test->win, 35, 75, 0xFFFFFF, "4-6 = Ch Fract");
	mlx_string_put(test->mlx, test->win, 35, 90, 0xFFFFFF, "r = restart");
	mlx_string_put(test->mlx, test->win, 35, 105, 0xFFFFFF, "Space = Pause");
	return (0);
}
