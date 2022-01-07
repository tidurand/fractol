#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_z {
	double		x;
	double		y;
}				t_z;

typedef struct	s_plan {
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
}				t_plan;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double temp;
	int i = 0;
	t_z z;
	t_plan plan;
	plan.x_min = -1;
	plan.x_max = 1;
	plan.y_min = -1;
	plan.y_max = 1;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 800, "Fractol");
	img.img = mlx_new_image(mlx, 1280, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	z.x = 0;
	z.y = 0;
	double x = -0.0519;
	double y = 0.688;
	while (i < 5000)
	{
		printf("x : %lf, y : %lf\n", z.x, z.y);
		if ((z.x * 400 + 640) < 1270 && (z.y * 400 + 400) < 790)
			my_mlx_pixel_put(&img, z.x * 400 + 640, z.y * 400 + 400, 0x000000FF);
		temp = z.x;
		z.x = z.x * z.x - z.y * z.y + x;
		z.y = 2 * temp * z.y + y;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}