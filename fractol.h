/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 10:54:23 by atrang            #+#    #+#             */
/*   Updated: 2016/04/20 12:14:13 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# define WIDTH 1080
# define HEIGHT 1080

typedef struct	s_test
{
	void	*mlx;
	void	*win;
	int		bpp;
	int		bpp_div;
	int		sizeline;
	char	*data;
	int		endian;
	void	*img;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	double	image_x;
	double	image_y;
	int		i_max;
	int		i;
	double	c_r;
	double	c_i;
	double	z_i;
	double	z_r;
	double	tmp_r;
	double	tmp_i;
	int		pause;
	int		color;
	int		fract;
	int		width;
	int		height;
}				t_test;

int				init_fractal(t_test *test);
void			put_pixel(t_test *info, int x, int y);
t_test			*init_mand(t_test *info);
int				ft_hook(int keycode, t_test *test);
int				ft_start(t_test *test);
int				ft_mouse_funct(int x, int y, t_test *test);
int				ft_key_funct(int keycode, void *param);
int				ft_mouse_scroll(int scroll, int x, int y, void *param);
void			ft_zoom(int scroll, t_test *test);
int				ft_colors_bm(t_test *info, int x, int y);
int				ft_colors_next(t_test *info, int x, int y);
int				ft_colors_next_2(t_test *info, int x, int y);
void			fractol_draw_mand(t_test *t);
void			fractol_draw_julia(t_test *t);
t_test			*init_julia(t_test *info);
double			ft_abs(double x);
void			fractol_draw_burn(t_test *b);
t_test			*init_burn(t_test *test);
void			ft_help(void);
int				ft_key_funct2(int keycode, void *param);

#endif
