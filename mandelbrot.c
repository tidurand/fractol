/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:34:41 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 08:35:06 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_fonction(t_all *data, int i, int j)
{
	double	temp;
	int		k;

	k = 0;
	data->z.c_r = (data->plan.x_min + j
			* (data->plan.x_max - data->plan.x_min) - data->plan.move_x
			- data->plan.move_mouse_x) / (SIZE * 2);
	data->z.c_i = (data->plan.y_max - i
			* (data->plan.y_max - data->plan.y_min) + data->plan.move_y
			+ data->plan.move_mouse_y) / (SIZE * 2);
	data->z.x = 0;
	data->z.y = 0;
	while (k++ <= 50 && data->z.x * data->z.x + data->z.y * data->z.y <= 4)
	{
		temp = data->z.x;
		data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
		data->z.y = 2 * temp * data->z.y + data->z.c_i;
	}
	print_colors(data, i, j, k);
}

void	mandelbrot(t_all *data)
{
	int		i;
	int		j;

	i = -SIZE;
	data->fractal.julia = 0;
	data->fractal.mandelbrot = 1;
	data->fractal.burningship = 0;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			mandelbrot_fonction(data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img.img, 0, 0);
}

void	burningship_fonction(t_all *data, int i, int j)
{
	double	temp;
	int		k;

	k = 0;
	data->z.c_r = (data->plan.x_min + j
			* (data->plan.x_max - data->plan.x_min) - data->plan.move_x
			- data->plan.move_mouse_x) / (SIZE * 2);
	data->z.c_i = ((data->plan.y_max - i
				* (data->plan.y_max - data->plan.y_min) + data->plan.move_y
				+ data->plan.move_mouse_y) / (SIZE * 2)) * -1;
	data->z.x = 0;
	data->z.y = 0;
	while (k++ <= 50 && data->z.x * data->z.x + data->z.y * data->z.y <= 4)
	{
		temp = data->z.x;
		data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
		data->z.y = 2 * temp * data->z.y + data->z.c_i;
		data->z.x = fabs(data->z.x);
		data->z.y = fabs(data->z.y);
	}
	print_colors(data, i, j, k);
}

void	burningship(t_all *data)
{
	int		i;
	int		j;

	i = -SIZE;
	data->fractal.julia = 0;
	data->fractal.mandelbrot = 0;
	data->fractal.burningship = 1;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			burningship_fonction(data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img.img, 0, 0);
}
