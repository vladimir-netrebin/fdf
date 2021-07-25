/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:29:26 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 16:44:40 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_projection(t_fdf *data)
{
	if (data->camera == PARALLEL)
	{
		data->camera = ISOMETRIC;
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data, 0, 0);
	}
	else
	{
		data->camera = PARALLEL;
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data, 0, 0);
	}
}

void	map_coloring(int key, t_fdf *data)
{
	if (key == 18)
	{
		data->color_map[0] = 0x08EEAE;
		data->color_map[1] = 0xEEAE08;
		data->color_map[2] = 0xAE08EE;
	}
	else if (key == 19)
	{
		data->color_map[0] = 0x1A08EE;
		data->color_map[1] = 0x08EE1A;
		data->color_map[2] = 0xEE1A08;
	}
	else if (key == 20)
	{
		data->color_map[0] = 0xCEEE08;
		data->color_map[1] = 0xEE08CE;
		data->color_map[2] = 0x08CEEE;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	print_map(data, 0, 0);
}

void	gradient(t_fdf *data)
{
	if (data->grad == 1)
		data->grad = 0;
	else if (data->grad == 0)
		data->grad = 1;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	print_map(data, 0, 0);
}

int		events(int key, t_fdf *data)
{
	if (key == 24 || key == 27)
		do_zoom(key, data);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		do_shift(key, data);
	if (key == 35)
		change_projection(data);
	if (key == 7 || key == 53)
		exit_program(data);
	if (key == 34 || key == 31)
		change_altitude(key, data);
	if (key == 18 || key == 19 || key == 20)
		map_coloring(key, data);
	if (key == 5)
		gradient(data);
	if (key >= 83 && key <= 88)
		rotation(key, data);
	if (key == 46)
		menu_create(data);
	menu_build(data);
	return (0);
}
