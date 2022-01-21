/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:35:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/21 07:11:13 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_plan_zoom(t_all *data, double min, double max)
{
	data->plan.x_min -= min;
	data->plan.x_max -= max;
	data->plan.y_min -= min;
	data->plan.y_max -= max;
}

void	change_plan_dezoom(t_all *data, double min, double max)
{
	data->plan.x_min += min;
	data->plan.x_max += max;
	data->plan.y_min += min;
	data->plan.y_max += max;
}

void	zoom(t_all *data, int *x, int *y)
{
	double	width;

	width = (data->plan.x_min - data->plan.x_max) * -1;
	if (width > 0.2)
	{
		change_plan_zoom(data, -0.1, 0.1);
		data->plan.move_mouse_x = (*x - 500) * -1;
		data->plan.move_mouse_y = (*y - 500) * -1;
	}
	else if (width > 0.02)
		change_plan_zoom(data, -0.01, 0.01);
	else if (width > 0.002)
		change_plan_zoom(data, -0.001, 0.001);
	else
		change_plan_zoom(data, -0.0001, 0.0001);
	update_fractal(data);
}

void	dezoom(t_all *data, int *x, int *y)
{
	double	width;

	width = (data->plan.x_min - data->plan.x_max) * -1;
	if (width > 0.2)
	{
		change_plan_dezoom(data, -0.1, 0.1);
		data->plan.move_mouse_x = (*x - 500) * -1;
		data->plan.move_mouse_y = (*y - 500) * -1;
	}
	else if (width > 0.02)
		change_plan_dezoom(data, -0.01, 0.01);
	else if (width > 0.002)
		change_plan_dezoom(data, -0.001, 0.001);
	else
		change_plan_dezoom(data, -0.0001, 0.0001);
	update_fractal(data);
	update_fractal(data);
}
