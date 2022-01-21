/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:05:00 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 09:43:30 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_colors(t_all *data, int i, int j, int k)
{
	if (k > 50)
		pixel_put(&data->img, j + SIZE, i + SIZE, 0x00000000);
	else
	{
		pixel_put(&data->img, j + SIZE, i + SIZE,
			((data->colors.base_red - data->colors.red * (k / 2)) << 16)
			+((data->colors.base_green - data->colors.green * (k / 2)) << 8)
			+(data->colors.base_blue - data->colors.blue * (k / 2)));
	}
}

void	julia_fonction(t_all *data, int i, int j)
{
	double	temp;
	int		k;

	k = 0;
	data->z.x = (data->plan.x_min + j
			* (data->plan.x_max - data->plan.x_min) - data->plan.move_x
			- data->plan.move_mouse_x) / (SIZE * 2);
	data->z.y = (data->plan.y_max - i
			* (data->plan.y_max - data->plan.y_min) + data->plan.move_y
			+ data->plan.move_mouse_y) / (SIZE * 2);
	while (k++ <= 50 && data->z.x * data->z.x + data->z.y * data->z.y <= 4)
	{
		temp = data->z.x;
		data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
		data->z.y = 2 * temp * data->z.y + data->z.c_i;
	}
	print_colors(data, i, j, k);
}

void	julia(t_all *data)
{
	int		i;
	int		j;

	i = -SIZE;
	data->fractal.julia = 1;
	data->fractal.mandelbrot = 0;
	data->fractal.burningship = 0;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			julia_fonction(data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img.img, 0, 0);
}
