/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:27:22 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/25 13:40:03 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(char **array)
{
	int	n;
	int	i;

	i = 0;
	n = count_array_elem(array);
	while (i < n + 1)
		free(array[i++]);
	free(array);
	array = NULL;
}

void	ft_exit(const char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	exit(-1);
}
