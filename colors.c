/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:21:06 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 12:06:21 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		data->colors.base_red = 113;
		data->colors.base_green = 70;
		data->colors.base_blue = 255;
		data->colors.red = 3;
		data->colors.green = 15;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else
		change_colors_2(data);
}

void	change_colors_2(t_all *data)
{
	if (data->colors.step == 3)
	{
		data->colors.step = 4;
		data->colors.base_red = 184;
		data->colors.base_green = 255;
		data->colors.base_blue = 243;
		data->colors.red = 5;
		data->colors.green = 9;
		data->colors.blue = 10;
		update_fractal(data);
	}
	else if (data->colors.step == 4)
	{
		data->colors.step = 5;
		data->colors.base_red = 255;
		data->colors.base_green = 245;
		data->colors.base_blue = 184;
		data->colors.red = 1;
		data->colors.green = 10;
		data->colors.blue = 15;
		update_fractal(data);
	}
	else
		change_colors_3(data);
}

void	change_colors_3(t_all *data)
{
	if (data->colors.step == 5)
	{
		data->colors.step = 1;
		data->colors.base_red = 255;
		data->colors.base_green = 105;
		data->colors.base_blue = 40;
		data->colors.red = 3;
		data->colors.green = 10;
		data->colors.blue = 0;
		update_fractal(data);
	}
}
