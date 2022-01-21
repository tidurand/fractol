/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:18:45 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 09:19:43 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal(t_all *data)
{
	if (data->fractal.julia == 1)
		mandelbrot(data);
	else if (data->fractal.mandelbrot == 1)
		burningship(data);
	else if (data->fractal.burningship == 1)
	{
		init_julia(data);
		julia(data);
	}
}

void	change_parameters(int key, t_all *data)
{
	if (key == 0)
	{
		data->z.c_r -= 0.01;
		julia(data);
	}
	if (key == 2)
	{
		data->z.c_r += 0.01;
		julia(data);
	}
}

void	moves(int key, t_all *data)
{
	if (key == 123)
	{
		data->plan.move_x += 25 * fabs(data->plan.x_max);
		update_fractal(data);
	}
	if (key == 124)
	{
		data->plan.move_x -= 25 * fabs(data->plan.x_max);
		update_fractal(data);
	}
	if (key == 125)
	{
		data->plan.move_y -= 25 * fabs(data->plan.x_max);
		update_fractal(data);
	}
	if (key == 126)
	{
		data->plan.move_y += 25 * fabs(data->plan.x_max);
		update_fractal(data);
	}
}

void	update_fractal(t_all *data)
{
	int	i;
	int	j;

	i = -SIZE;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			pixel_put(&data->img, j + SIZE, i + SIZE, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img.img, 0, 0);
	if (data->fractal.julia == 1)
		julia(data);
	else if (data->fractal.mandelbrot == 1)
		mandelbrot(data);
	else if (data->fractal.burningship == 1)
		burningship(data);
}
