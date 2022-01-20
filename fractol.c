#include "fractol.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*void	ft_zoom(t_all data)
{
	mouse_position(data);
}*/
void	init_julia(t_all *data)
{
	data->z.c_r = -0.122;
	data->z.c_i = 0.744;
}

void	update_fractal(t_all *data)
{
	if (data->fractal.julia == 1)
		julia(data);
	else if (data->fractal.mandelbrot == 1)
		mandelbrot(data);
	else if (data->fractal.burningship == 1)
		burningship(data);
}

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

void	change_colors(t_all *data)
{
	if (data->colors.step == 1)
	{
		data->colors.step = 2;
		data->colors.base_red = 255;
		data->colors.base_green = 255;
		data->colors.base_blue = 255;
		data->colors.red = 10;
		data->colors.green = 10;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else if (data->colors.step == 2)
	{
		data->colors.step = 3;
		data->colors.base_red = 177;
		data->colors.base_green = 211;
		data->colors.base_blue = 15;
		data->colors.red = 3;
		data->colors.green = 2;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else if (data->colors.step == 3)
	{
		data->colors.step = 4;
		data->colors.base_red = 255;
		data->colors.base_green = 255;
		data->colors.base_blue = 255;
		data->colors.red = 10;
		data->colors.green = 10;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else if (data->colors.step == 4)
	{
		data->colors.step = 5;
		data->colors.base_red = 255;
		data->colors.base_green = 255;
		data->colors.base_blue = 255;
		data->colors.red = 10;
		data->colors.green = 10;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else if (data->colors.step == 5)
	{
		data->colors.step = 1;
		data->colors.base_red = 255;
		data->colors.base_green = 255;
		data->colors.base_blue = 255;
		data->colors.red = 10;
		data->colors.green = 3;
		data->colors.blue = 8;
		update_fractal(data);
	}
}

int	keys(int key, t_all *data)
{
	//printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_image(data->mlx.mlx, data->img.img);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		exit(1);
	}
	if (key == 8)
	{
		change_colors(data);
		//mouse_position(data);
	}
	if (key == 49)
		change_fractal(data);
	if (key == 123)
	{
		data->plan.move_x -= 10;
		update_fractal(data);
	}
	if (key == 124)
	{
		data->plan.move_x += 10;
		update_fractal(data);
	}
	if (key == 125)
	{
		data->plan.move_y += 10;
		update_fractal(data);
	}
	if (key == 126)
	{
		data->plan.move_y -= 10;
		update_fractal(data);
	}
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
	return (0);
}

int	mouse(int key, t_all *data)
{
	if (key == 5)
	{
		printf("ZOOM\n");
		//mouse_position(data);
		/*data->plan.x_min -= -0.1;
		data->plan.x_max -= 0.1;
		data->plan.y_min -= -0.1;
		data->plan.y_max -= 0.1;
		update_fractal(data);*/
	}
	if (key == 4)
	{
		printf("DEZOOM\n");
		//mouse_position(data);
		/*data->plan.x_min += -0.1;
		data->plan.x_max += 0.1;
		data->plan.y_min += -0.1;
		data->plan.y_max += 0.1;
		update_fractal(data);*/
	}
	return (0);
}

int	mouse_position(t_all *data)
{
	int x, y;
	mlx_mouse_get_pos(data->mlx.mlx_win, &x, &y);
	printf("x : %d, y : %d\n", x, y);
	return (0);
}

void	text(t_all *data)
{
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 250, 0x00FF0000, "C = change colors");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 300, 0x00FF0000, "0 = reset zoom and move");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 350, 0x00FF0000, "Space = change fractal");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 400, 0x00FF0000, "A, D = change parameters (julia only)");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 450, 0x00FF0000, "1 a 9 = change parameters 2 (julia only)");
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 1050, 500, 0x00FF0000, "Esc = exit");
}

void	init_mlx(t_all *data)
{
	data->plan.x_min = -2;
	data->plan.x_max = 2;
	data->plan.y_min = -2;
	data->plan.y_max = 2;
	data->plan.move_x = 0;
	data->plan.move_y = 0;
	data->z.c_r = -0.122;
	data->z.c_i = 0.744;
	data->colors.step = 1;
	data->colors.base_red = 255;
	data->colors.base_green = 255;
	data->colors.base_blue = 255;
	data->colors.red = 10;
	data->colors.green = 3;
	data->colors.blue = 8;
	data->mlx.mlx = mlx_init();
	mlx_do_key_autorepeaton(data->mlx.mlx);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	data->img.img = mlx_new_image(data->mlx.mlx, SIZE*2, SIZE*2);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	text(data);
}

int	main(int ac, char **av)
{
	t_all	data;

	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if ((atof(av[2]) >= -1 && atof(av[2]) <= 1) && (atof(av[3]) >= -1 && atof(av[3]) <= 1))
		{
			init_mlx(&data);
			data.z.c_r = atof(av[2]);
			data.z.c_i = atof(av[3]);
			julia(&data);
		}
		else
		{
			printf("parameters should be between -1 and 1\n");
			exit (1);
		}
	}
	else if (ac != 2)
	{
		printf("./fractol [fractal_name] [parameter 1 (julia)] [parameter 2 (julia)]\n");
		exit(1);
	}

	else if (ft_strcmp(av[1], "julia") == 0)
	{
		init_mlx(&data);
		julia(&data);
	}
	else if	(ft_strcmp(av[1], "mandelbrot") == 0)
	{
		init_mlx(&data);
		mandelbrot(&data);
	}
	else if (ft_strcmp(av[1], "burningship") == 0)
	{
		init_mlx(&data);
		burningship(&data);
	}
	else
	{
		printf("./fractol [fractal_name] [parameter 1 (julia)] [parameter 2 (julia)]\n");
		exit(1);
	}
	//mlx_hook(mlx.mlx_win, 2, (1L<<2), close, &mlx);
	mlx_key_hook(data.mlx.mlx_win, keys, &data);
	mlx_mouse_hook(data.mlx.mlx_win, mouse, &data);
	mlx_loop(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.img.img);
	mlx_destroy_window(data.mlx.mlx, data.mlx.mlx_win);
}
