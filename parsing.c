/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:28:50 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 09:09:23 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parsing_error(void)
{
	printf("./fractol [fractal_name]");
	printf(" [parameter 1 (julia)] [parameter 2 (julia)]\n");
	exit(1);
}

int	parsing_parameters(t_all *data, int ac, char **av)
{
	if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if ((ft_atof(av[2]) >= -1 && ft_atof(av[2]) <= 1)
			&& (ft_atof(av[3]) >= -1 && ft_atof(av[3]) <= 1))
		{
			init_mlx(data);
			data->z.c_r = ft_atof(av[2]);
			data->z.c_i = ft_atof(av[3]);
			julia(data);
			return (0);
		}
		else
		{
			printf("parameters should be between -1 and 1\n");
			exit (1);
		}
	}
	return (1);
}

void	parsing_solo(t_all *data, int ac, char **av)
{
	if (ac != 2)
		parsing_error();
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		init_mlx(data);
		julia(data);
	}
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		init_mlx(data);
		mandelbrot(data);
	}
	else if (ft_strcmp(av[1], "burningship") == 0)
	{
		init_mlx(data);
		burningship(data);
	}
	else
		parsing_error();
}
