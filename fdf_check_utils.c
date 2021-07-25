/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:27:43 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/25 13:41:02 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_extension(const char *map_file)
{
	int n;

	n = ft_strlen(map_file);
	if (map_file[n - 1] != 'f')
		return (0);
	if (map_file[n - 2] != 'd')
		return (0);
	if (map_file[n - 3] != 'f')
		return (0);
	if (map_file[n - 4] != '.')
		return (0);
	return (1);
}

int		ft_is_char_valid(char *elem)
{
	int n;
	int i;

	i = 1;
	n = ft_strlen(elem);
	if (ft_isdigit(elem[0]) == 0 && elem[0] != '-')
		return (0);
	while (i < n)
	{
		if (ft_isdigit(elem[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_line_valid(char **parsed_line)
{
	int n;
	int i;

	i = 0;
	n = count_array_elem(parsed_line);
	while (i < n)
	{
		if (ft_is_char_valid(parsed_line[i]) == 0)
		{
			free_array(parsed_line);
			return (0);
		}
		i++;
	}
	return (1);
}

int		count_array_elem(char **line_to_count)
{
	int i;

	i = 0;
	while (line_to_count[i] != NULL)
		i++;
	return (i);
}
