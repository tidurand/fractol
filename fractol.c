/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:17:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 12:13:40 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_all *data)
{
	data->z.c_r = -0.8;
	data->z.c_i = 0.156;
}

int	keys(int key, t_all *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx.mlx, data->img.img);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		exit(1);
	}
	if (key == 8)
		change_colors(data);
	if (key == 49)
		change_fractal(data);
	moves(key, data);
	if (data->fractal.julia == 1)
		change_parameters(key, data);
	if (data->fractal.julia == 1)
		pre_parameters(key, data);
	if (key == 82)
		reset(data);
	return (0);
}

int	mouse(int key, int x, int y, t_all *data)
{
	if (key == 5)
		zoom(data, &x, &y);
	if (key == 4)
		dezoom(data, &x, &y);
	return (0);
}

void	init_mlx(t_all *data)
{
	data->plan.x_min = -2;
	data->plan.x_max = 2;
	data->plan.y_min = -2;
	data->plan.y_max = 2;
	data->plan.move_x = 0;
	data->plan.move_y = 0;
	data->plan.move_mouse_x = 0;
	data->plan.move_mouse_y = 0;
	data->z.c_r = -0.8;
	data->z.c_i = 0.156;
	data->colors.step = 1;
	data->colors.base_red = 255;
	data->colors.base_green = 105;
	data->colors.base_blue = 40;
	data->colors.red = 3;
	data->colors.green = 10;
	data->colors.blue = 0;
	data->mlx.mlx = mlx_init();
	mlx_do_key_autorepeaton(data->mlx.mlx);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx,
			WIN_WIDTH, WIN_HEIGHT, "Fractol");
	data->img.img = mlx_new_image(data->mlx.mlx, SIZE * 2, SIZE * 2);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	text(data);
}

int	main(int ac, char **av)
{
	t_all	data;

	if (parsing_parameters(&data, ac, av) == 1)
		parsing_solo(&data, ac, av);
	mlx_key_hook(data.mlx.mlx_win, keys, &data);
	mlx_mouse_hook(data.mlx.mlx_win, mouse, &data);
	mlx_loop(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.img.img);
	mlx_destroy_window(data.mlx.mlx, data.mlx.mlx_win);
}
