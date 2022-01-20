/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:25:32 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/20 05:35:51 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define SIZE 400
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct	s_z {
	double		x;
	double		y;
	double		c_r;
	double		c_i;
}				t_z;

typedef struct	s_plan {
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			move_x;
	int			move_y;
}				t_plan;

typedef struct	s_mouse {
	int		x;
	int		y;
}				t_mouse;

typedef struct	s_colors {
	int		base_red;
	int		base_green;
	int		base_blue;
	int		red;
	int		green;
	int		blue;
	int		step;
}				t_colors;

typedef struct	s_fractal {
	int		julia;
	int		mandelbrot;
}				t_fractal;

typedef struct	s_all {
	t_mlx	mlx;
	t_img	img;
	t_z		z;
	t_plan	plan;
	t_mouse	mouse;
	t_fractal	fractal;
	t_colors	colors;
}				t_all;

int	mouse_position(t_all *data);
void	julia(t_all *data);
void	mandelbrot(t_all *data);
int	ft_strcmp(char *s1, char *s2);
void	update_fractal(t_all *data);
void	pixel_put(t_img *data, int x, int y, int color);

#endif