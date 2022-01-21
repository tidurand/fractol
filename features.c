/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:45:26 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 11:59:45 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(t_all *data)
{
	data->plan.move_x = 0;
	data->plan.move_y = 0;
	data->plan.x_min = -2;
	data->plan.x_max = 2;
	data->plan.y_min = -2;
	data->plan.y_max = 2;
	data->plan.move_mouse_x = 0;
	data->plan.move_mouse_y = 0;
	update_fractal(data);
}

void	text(t_all *data)
{
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 250, 0x00FF0000, "C = change colors");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 300, 0x00FF0000, "0 = reset zoom and move");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 350, 0x00FF0000, "Space = change fractal");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 400, 0x00FF0000, "A, D = change parameters (julia only)");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 450, 0x00FF0000, "1 a 9 = change parameters 2 (julia only)");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
		1050, 500, 0x00FF0000, "Esc = exit");
}

void	pre_parameters(int key, t_all *data)
{
	if (key == 83)
	{
		data->z.c_r = -0.122;
		data->z.c_i = 0.744;
		julia(data);
	}
	if (key == 84)
	{
		data->z.c_r = -0.76;
		data->z.c_i = 0.12;
		julia(data);
	}
	if (key == 85)
	{
		data->z.c_r = 0.35;
		data->z.c_i = 0.05;
		julia(data);
	}
	else
		pre_parameters_2(key, data);
}

void	pre_parameters_2(int key, t_all *data)
{
	if (key == 86)
	{
		data->z.c_r = -0.63;
		data->z.c_i = 0.67;
		julia(data);
	}
	if (key == 87)
	{
		data->z.c_r = -0.101;
		data->z.c_i = 0.956;
		julia(data);
	}
	if (key == 88)
	{
		data->z.c_r = -1;
		data->z.c_i = 0;
		julia(data);
	}
	else
		pre_parameters_3(key, data);
}

void	pre_parameters_3(int key, t_all *data)
{
	if (key == 89)
	{
		data->z.c_r = -1.7548;
		data->z.c_i = 0;
		julia(data);
	}
	if (key == 91)
	{
		data->z.c_r = 0.285;
		data->z.c_i = 0.01;
		julia(data);
	}
	if (key == 92)
	{
		data->z.c_r = -0.8;
		data->z.c_i = 0.156;
		julia(data);
	}
}
