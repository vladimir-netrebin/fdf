/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:28:03 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/25 13:39:01 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_width(char *line)
{
	char	**parsed_line;
	int		width;
	char	*tmp;

	parsed_line = NULL;
	tmp = NULL;
	tmp = ft_strtrim(line);
	parsed_line = ft_strsplit(tmp, ' ');
	if (tmp != NULL)
		free(tmp);
	if (ft_check_line_valid(parsed_line) == 0)
		ft_exit(INVALID_MAP);
	width = count_array_elem(parsed_line);
	free_array(parsed_line);
	return (width);
}

int		get_params(t_fdf **data, const int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if ((*data)->height == 0)
			(*data)->width = get_width(line);
		else
		{
			if ((*data)->width != get_width(line))
			{
				free(line);
				ft_exit(INVALID_MAP);
			}
		}
		(*data)->height++;
		free(line);
	}
	if (line == NULL)
		return (0);
	line = NULL;
	return (1);
}

t_fdf	*ft_fdf_read(const char *map_file, t_fdf **data)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_exit(INVALID_FILE);
	}
	else if (check_extension(map_file) == 0)
	{
		close(fd);
		ft_exit(INVALID_EXTENSION);
	}
	else if (get_params(data, fd) == 0)
	{
		close(fd);
		ft_exit(EMPTY_FILE);
	}
	close(fd);
	return (*data);
}
