/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:28:25 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 16:44:03 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_decrease(t_fdf *data, int key, int i, int j)
{
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (data->matrix[j][i] != 0 && key == 34)
			{
				data->matrix[j][i] += 5;
				if (data->matrix[j][i] == 0)
					data->matrix[j][i] += 5;
			}
			else if (data->matrix[j][i] != 0 && key == 31)
			{
				data->matrix[j][i] -= 5;
				if (data->matrix[j][i] == 0)
					data->matrix[j][i] -= 5;
			}
			i++;
		}
		j++;
	}
	find_min_max(data);
}

void	change_altitude(int key, t_fdf *data)
{
	if (key == 34 || key == 31)
		increase_decrease(data, key, 0, 0);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	menu_build(data);
	print_map(data, 0, 0);
}

void	do_zoom(int key, t_fdf *data)
{
	if (key == 24)
	{
		if (data->zoom == 0)
			data->zoom += 5;
		else
			data->zoom *= 2;
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data, 0, 0);
	}
	if (key == 27)
	{
		data->zoom /= 2;
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data, 0, 0);
	}
}

void	do_shift(int key, t_fdf *data)
{
	if (key == 126)
		data->shift.y -= 10;
	if (key == 125)
		data->shift.y += 10;
	if (key == 123)
		data->shift.x -= 10;
	if (key == 124)
		data->shift.x += 10;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	print_map(data, 0, 0);
}

void	exit_program(t_fdf *data)
{
	free_fdf(data);
	exit(0);
}
