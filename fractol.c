#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
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
	t_z z;
	t_plan plan;
	plan.x_min = -1.25;
	plan.x_max = 1.25;
	plan.y_min = -1.25;
	plan.y_max = 1.25;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 1200, "Fractol");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	z.x = 0;
	z.y = 0;
	double x = 0.2;
	double y = 0.7;
	int i = -400;
	int j;
	int k;
	while (i < 400)
	{
		j = -400;
		while (j < 400)
		{
			k = 0;
			z.x = (plan.x_min+j*(plan.x_max - plan.x_min))/800;
			z.y = (plan.y_max-i*(plan.y_max - plan.y_min))/800;
			while (k <= 100 && z.x*z.x+z.y*z.y <= 4)
			{
				temp = z.x;
				z.x = z.x * z.x - z.y * z.y + x;
				z.y = 2 * temp * z.y + y;
				k++;
			}
			if (k > 100)
				pixel_put(&img ,j + 400, i + 400, 0x00000000);
			else
				pixel_put(&img ,j + 400, i + 400, ((255 - 10 * k)<<16)+((255 - 3 * k)<<8)+(255 - 8 * k));
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}