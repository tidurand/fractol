/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand < tidurand@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:31:09 by tidurand          #+#    #+#             */
/*   Updated: 2022/01/27 10:31:41 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pre_parsing(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (s[i] != '.' && !(s[i] >= '0' && s[i] <= '9'))
		{
			printf("parameters should be between -1 and 1\n");
			exit (1);
		}
		if (s[i] == '.' && i == 0)
		{
			printf("parameters should be between -1 and 1\n");
			exit (1);
		}
		i++;
	}
}

float	atof_decimal(char *s, int i, float value, float decimal)
{
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			value += (s[i] - '0') * decimal;
			decimal *= 0.1;
			i++;
		}
	}
	return (value);
}

float	ft_atof(char *s)
{
	float	value;
	float	decimal;
	int		i;
	char	sign;

	pre_parsing(s);
	sign = 1;
	i = 0;
	value = 0;
	decimal = 0.1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		value = 10.0 * value + (s[i] - '0');
		i++;
	}
	value = atof_decimal(s, i, value, decimal);
	return (sign * value);
}
