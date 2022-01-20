/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:05:00 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/20 17:14:07 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_all *data)
{
	int i = -SIZE;
	int j;
	int k;
	double temp;
	data->fractal.julia = 1;
	data->fractal.mandelbrot = 0;
	data->fractal.burningship = 0;
	int a = 0;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			k = 0;
			data->z.x = (data->plan.x_min+j*(data->plan.x_max - data->plan.x_min) - data->plan.move_x - data->plan.move_mouse_x)/(SIZE * 2);
			data->z.y = (data->plan.y_max-i*(data->plan.y_max - data->plan.y_min) + data->plan.move_y + data->plan.move_mouse_y)/(SIZE * 2);
			//if (a++ == 0)
			//	printf("zx : %f, zy : %f\n", data->z.x, data->z.y);
			while (k <= 50 && data->z.x*data->z.x+data->z.y*data->z.y <= 4)
			{
				temp = data->z.x;
				data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
				data->z.y = 2 * temp * data->z.y + data->z.c_i;
				k++;
			}
			if (k > 50)
				pixel_put(&data->img ,j + SIZE, i + SIZE, 0x00000000);
			else
			{
				pixel_put(&data->img ,j + SIZE, i + SIZE,
				 ((data->colors.base_red - data->colors.red * (k))<<16)
				 +((data->colors.base_green - data->colors.green * (k))<<8)
				 +(data->colors.base_blue - data->colors.blue * (k)));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}

void	mandelbrot(t_all *data)
{
	int i = -SIZE;
	int j;
	int k;
	double temp;
	data->fractal.julia = 0;
	data->fractal.mandelbrot = 1;
	data->fractal.burningship = 0;
	
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			k = 0;
			data->z.c_r = (data->plan.x_min+j*(data->plan.x_max - data->plan.x_min) - data->plan.move_x)/(SIZE * 2);
			data->z.c_i = (data->plan.y_max-i*(data->plan.y_max - data->plan.y_min) + data->plan.move_y)/(SIZE * 2);
			data->z.x = 0;
			data->z.y = 0;
			while (k <= 50 && data->z.x*data->z.x+data->z.y*data->z.y <= 4)
			{
				temp = data->z.x;
				data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
				data->z.y = 2 * temp * data->z.y + data->z.c_i;
				k++;
			}
			if (k > 50)
				pixel_put(&data->img ,j + SIZE, i + SIZE, 0x00000000);
			else
			{
				pixel_put(&data->img ,j + SIZE, i + SIZE,
				 ((data->colors.base_red - data->colors.red * k)<<16)
				 +((data->colors.base_green - data->colors.green * k)<<8)
				 +(data->colors.base_blue - data->colors.blue * k));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}

void	burningship(t_all *data)
{
	int i = -SIZE;
	int j;
	int k;
	double temp;
	data->fractal.julia = 0;
	data->fractal.mandelbrot = 0;
	data->fractal.burningship = 1;
	while (i < SIZE)
	{
		j = -SIZE;
		while (j < SIZE)
		{
			k = 0;
			data->z.c_r = (data->plan.x_min+j*(data->plan.x_max - data->plan.x_min) - data->plan.move_x)/(SIZE * 2);
			data->z.c_i = ((data->plan.y_max-i*(data->plan.y_max - data->plan.y_min) + data->plan.move_y)/(SIZE * 2)) * - 1;
			data->z.x = 0;
			data->z.y = 0;
			while (k <= 50 && data->z.x*data->z.x+data->z.y*data->z.y <= 4)
			{
				temp = data->z.x;
				data->z.x = data->z.x * data->z.x - data->z.y * data->z.y + data->z.c_r;
				data->z.y = 2 * temp * data->z.y + data->z.c_i;
				data->z.x = fabs(data->z.x);
				data->z.y = fabs(data->z.y);
				k++;
			}
			if (k > 50)
				pixel_put(&data->img ,j + SIZE, i + SIZE, 0x00000000);
			else
			{
				pixel_put(&data->img ,j + SIZE, i + SIZE,
				 ((data->colors.base_red - data->colors.red * k)<<16)
				 +((data->colors.base_green - data->colors.green * k)<<8)
				 +(data->colors.base_blue - data->colors.blue * k));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
}