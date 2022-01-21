/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:25:32 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 09:46:29 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1350
# define WIN_HEIGHT 1000
# define SIZE 500
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_z {
	double		x;
	double		y;
	double		c_r;
	double		c_i;
}				t_z;

typedef struct s_plan {
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			move_x;
	int			move_y;
	int			move_mouse_x;
	int			move_mouse_y;
}				t_plan;

typedef struct s_mouse {
	int		x;
	int		y;
}				t_mouse;

typedef struct s_colors {
	int		base_red;
	int		base_green;
	int		base_blue;
	int		red;
	int		green;
	int		blue;
	int		step;
}				t_colors;

typedef struct s_fractal {
	int		julia;
	int		mandelbrot;
	int		burningship;
}				t_fractal;

typedef struct s_all {
	t_mlx		mlx;
	t_img		img;
	t_z			z;
	t_plan		plan;
	t_mouse		mouse;
	t_fractal	fractal;
	t_colors	colors;
}				t_all;

void	init_mlx(t_all *data);
//parsing
void	parsing_error(void);
int		parsing_parameters(t_all *data, int ac, char **av);
void	parsing_solo(t_all *data, int ac, char **av);
//zoom
int		mouse_position(t_all *data);
void	change_plan_zoom(t_all *data, double min, double max);
void	change_plan_dezoom(t_all *data, double min, double max);
void	zoom(t_all *data, int *x, int *y);
void	dezoom(t_all *data, int *x, int *y);
//fractales
void	julia(t_all *data);
void	julia_fonction(t_all *data, int i, int j);
void	mandelbrot(t_all *data);
void	mandelbrot_fonction(t_all *data, int i, int j);
void	burningship(t_all *data);
void	burningship_fonction(t_all *data, int i, int j);
//features
void	update_fractal(t_all *data);
void	reset(t_all *data);
void	change_fractal(t_all *data);
void	text(t_all *data);
void	moves(int key, t_all *data);
//colors
void	print_colors(t_all *data, int i, int j, int k);
void	change_colors(t_all *data);
void	change_colors_2(t_all *data);
void	change_colors_3(t_all *data);
//julia parameters
void	init_julia(t_all *data);
void	change_parameters(int key, t_all *data);
void	pre_parameters(int key, t_all *data);
void	pre_parameters_2(int key, t_all *data);
void	pre_parameters_3(int key, t_all *data);
//tools
float	ft_atof(char *s);
float	atof_decimal(char *s, int i, float value, float decimal);
int		ft_strcmp(char *s1, char *s2);
void	pixel_put(t_img *data, int x, int y, int color);

#endif