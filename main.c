/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:28:20 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 17:12:56 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	menu_build(t_fdf *data)
{
	int		k;
	void	*ptr;
	void	*win;
	int		col;

	k = 1775;
	col = 0xFFFFFF;
	ptr = data->mlx_ptr;
	win = data->mlx_win;
	if (data->menu == 1)
	{
		mlx_string_put(ptr, win, k, 0, col, "Ctrls: Arrows");
		mlx_string_put(ptr, win, k, 30, col, "Zoom: +/-");
		mlx_string_put(ptr, win, k, 50, col, "Exit: ESC/X");
		mlx_string_put(ptr, win, k, 70, col, "Projection: P");
		mlx_string_put(ptr, win, k, 90, col, "+/- Altitude: I/O");
		mlx_string_put(ptr, win, k, 110, col, "Rotation:");
		mlx_string_put(ptr, win, k + 65, 130, col, "x: 4/1");
		mlx_string_put(ptr, win, k + 65, 150, col, "y: 6/3");
		mlx_string_put(ptr, win, k + 65, 170, col, "z: 5/2");
		mlx_string_put(ptr, win, k, 190, col, "Menu: M");
		mlx_string_put(ptr, win, k, 210, col, "Gradient: G");
		mlx_string_put(ptr, win, k, 230, col, "Colors: 1/2/3");
	}
}

void	fill_standard(t_fdf *data)
{
	data->shift.x = 0;
	data->shift.y = 0;
	data->camera = PARALLEL;
	data->zoom = 10;
	data->color_map[0] = 0x1A08EE;
	data->color_map[1] = 0x08EE1A;
	data->color_map[2] = 0xEE1A08;
	data->menu = 1;
	data->grad = 1;
	data->alpha = 0;
	data->gamma = 0;
	data->beta = 0;
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		ft_exit(USAGE);
	else
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		data = ft_fdf_read(argv[1], &data);
		if (!(data->mlx_ptr = mlx_init()))
			ft_exit(CONNECTION_FAIL);
		if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, 1980, 1080, "FDF")))
			ft_exit(WINDOW_FAIL);
		ft_makedata(data, argv[1]);
		fill_standard(data);
		print_map(data, 0, 0);
		mlx_hook(data->mlx_win, 2, 0, events, data);
		mlx_loop(data->mlx_ptr);
		free_fdf(data);
	}
	return (0);
}
