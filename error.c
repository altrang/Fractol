/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:13:28 by atrang            #+#    #+#             */
/*   Updated: 2016/04/19 11:38:44 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_putstr("Usage: ./fractol 1 or 2 or 3\n");
	ft_putstr("1 = Mandelbrot\n");
	ft_putstr("2 = Julia\n");
	ft_putstr("3 = Burning Ship\n");
	exit(0);
}
