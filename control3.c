/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:24:42 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 16:49:30 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(int key, t_fdf *data)
{
	if (key == 86)
		data->alpha += 0.01;
	else if (key == 87)
		data->gamma += 0.01;
	else if (key == 88)
		data->beta += 0.01;
	else if (key == 83)
		data->alpha -= 0.01;
	else if (key == 84)
		data->gamma -= 0.01;
	else if (key == 85)
		data->beta -= 0.01;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	print_map(data, 0, 0);
}

void	menu_create(t_fdf *data)
{
	if (data->menu == 1)
		data->menu = 0;
	else if (data->menu == 0)
		data->menu = 1;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	print_map(data, 0, 0);
}
