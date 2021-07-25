/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:49:37 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 16:51:06 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometry(t_point *p)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -(p->z) + (previous_x + previous_y) * sin(0.523599);
}

void	get_crds_color(t_point *p, const int i, const int j, t_fdf *data)
{
	p->x = i * data->zoom;
	p->y = j * data->zoom;
	p->z = data->matrix[j][i];
	if (p->z == data->min_z)
		p->color = data->color_map[1];
	else if (p->z == data->max_z)
		p->color = data->color_map[0];
	else
		p->color = data->color_map[2];
	*p = project(*p, data);
}

void	print_map(t_fdf *data, int i, int j)
{
	t_point cur;
	t_point next;

	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			get_crds_color(&cur, i, j, data);
			if (i < data->width - 1 && cur.x <= 1980 * 2 && cur.x >= -1980 * 2)
			{
				get_crds_color(&next, i + 1, j, data);
				draw_line(cur, next, data);
			}
			if (j < data->height - 1 && cur.y <= 1080 * 2 && cur.y >= -1080 * 2)
			{
				get_crds_color(&next, i, j + 1, data);
				draw_line(cur, next, data);
			}
			i++;
		}
		j++;
	}
}
