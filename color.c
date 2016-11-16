/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:04:01 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 11:54:32 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_test *info, int x, int y)
{
	t_test *test;

	test = info;
	if (test->color == 2)
		ft_colors_bm(test, x, y);
	else if (test->color == 1)
		ft_colors_next(test, x, y);
	else if (test->color == 3)
		ft_colors_next_2(test, x, y);
}

int			ft_colors_bm(t_test *info, int x, int y)
{
	int		index;

	index = x * info->bpp_div + (y * info->sizeline);
	if (info->i == info->i_max)
	{
		info->data[index] = 168;
		info->data[index + 1] = 185;
		info->data[index + 2] = 2;
	}
	else
	{
		info->data[index] = 255;
		info->data[index + 1] = 127;
		info->data[index + 2] = info->i * 255 / info->i_max;
	}
	return (0);
}

int			ft_colors_next(t_test *info, int x, int y)
{
	int		index;
	t_test	*test;

	test = info;
	index = x * info->bpp_div + (y * test->sizeline);
	if (test->i == test->i_max)
	{
		test->data[index] = 0;
		test->data[index + 1] = 102;
		test->data[index + 2] = 230;
	}
	else
	{
		test->data[index] = 0;
		test->data[index + 1] = 200;
		test->data[index + 2] = test->i * 255 / test->i_max;
	}
	return (0);
}

int			ft_colors_next_2(t_test *info, int x, int y)
{
	int		index;
	t_test	*test;

	test = info;
	index = x * info->bpp_div + (y * test->sizeline);
	if (test->i == test->i_max)
	{
		test->data[index] = 60;
		test->data[index + 1] = 65;
		test->data[index + 2] = 50;
	}
	else
	{
		test->data[index] = 52;
		test->data[index + 1] = 50;
		test->data[index + 2] = test->i * 255 / test->i_max;
	}
	return (0);
}
