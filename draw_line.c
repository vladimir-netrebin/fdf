/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:07:45 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/27 17:33:12 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_info(int data[6], t_point p0, t_point p1, t_point *delta)
{
	int delta_x;
	int delta_y;
	int sign_x;
	int sign_y;
	int error;

	delta_x = abs(p1.x - p0.x);
	delta_y = abs(p1.y - p0.y);
	sign_x = p0.x < p1.x ? 1 : -1;
	sign_y = p0.y < p1.y ? 1 : -1;
	error = delta_x - delta_y;
	data[0] = delta_x;
	data[1] = delta_y;
	data[2] = sign_x;
	data[3] = sign_y;
	data[4] = error;
	data[5] = 0;
	delta->x = delta_x;
	delta->y = delta_y;
}

void	check_projection(t_fdf *data, t_point *p0, t_point *p1)
{
	if (data->camera == ISOMETRIC)
	{
		isometry(p0);
		isometry(p1);
	}
}

void	draw_line(t_point p0, t_point p1, t_fdf *data)
{
	int		info[6];
	t_point	d;
	t_point c;

	check_projection(data, &p0, &p1);
	fill_info(info, p0, p1, &d);
	c = p0;
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, p1.x + data->shift.x, p1.y +
	data->shift.y, (data->grad == 1) ? color(p1, p0, p1, d) : p1.color);
	while (c.x != p1.x || c.y != p1.y)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, c.x + data->shift.x, c.y +
		data->shift.y, (data->grad == 1) ? color(c, p0, p1, d) : p0.color);
		info[5] = info[4] * 2;
		if (info[5] > -info[1])
		{
			info[4] -= info[1];
			c.x += info[2];
		}
		if (info[5] < info[0])
		{
			info[4] += info[0];
			c.y += info[3];
		}
	}
}
