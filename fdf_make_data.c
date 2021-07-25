/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:35:06 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/25 14:41:02 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_min_max(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	data->min_z = data->matrix[0][0];
	data->max_z = data->matrix[0][0];
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->matrix[i][j] < data->min_z)
				data->min_z = data->matrix[i][j];
			else if (data->matrix[i][j] >= data->max_z)
				data->max_z = data->matrix[i][j];
			j++;
		}
		i++;
	}
}

int		*parse_to_int(char **parsed_line, const int length)
{
	int	*ret;
	int	i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * length);
	while (i < length && parsed_line[i] != NULL)
	{
		ret[i] = ft_atoi(parsed_line[i]);
		i++;
	}
	free_array(parsed_line);
	return (ret);
}

void	ft_makedata(t_fdf *data, const char *map_file)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = 0;
	fd = open(map_file, O_RDONLY);
	data->matrix = (int**)malloc(sizeof(int *) * data->height);
	while (get_next_line(fd, &line) || i < data->height)
	{
		if (*line == '\0')
			free(line);
		else
		{
			data->matrix[i] = parse_to_int(ft_strsplit(line, ' '), data->width);
			i++;
			free(line);
		}
	}
	find_min_max(data);
	close(fd);
}
