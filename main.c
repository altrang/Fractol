/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:48:27 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 12:14:22 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_select(char *fract, t_test *test)
{
	test->fract = ft_atoi(fract);
	ft_start(test);
	return (0);
}

int		main(int ac, char **av)
{
	t_test *test;

	test = (t_test*)malloc(sizeof(t_test));
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, WIDTH, HEIGHT, "fractol");
	if (ac == 1)
		ft_help();
	if (ac == 2)
		ft_select(av[1], test);
	if (ac > 2)
		ft_help();
	if (ft_strlen(av[1]) != 1)
		ft_help();
	mlx_hook(test->win, 2, 0, ft_key_funct, test);
	mlx_hook(test->win, 4, 0, ft_mouse_scroll, test);
	mlx_hook(test->win, 6, 0, ft_mouse_funct, test);
	mlx_string_put(test->mlx, test->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(test->mlx, test->win, 35, 60, 0xFFFFFF, "1-3 = Color");
	mlx_string_put(test->mlx, test->win, 35, 75, 0xFFFFFF, "4-6 = Ch Fract");
	mlx_string_put(test->mlx, test->win, 35, 90, 0xFFFFFF, "r = restart");
	mlx_string_put(test->mlx, test->win, 35, 105, 0xFFFFFF, "Space = Pause");
	mlx_loop(test->mlx);
	return (0);
}
