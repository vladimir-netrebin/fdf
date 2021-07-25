/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:27:31 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/28 18:26:30 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include "mlx.h"
# include <math.h>

# define CONNECTION_FAIL    "./fdf: failed to establish graphical connection\n"
# define WINDOW_FAIL        "./fdf: failed to open window\n"
# define USAGE              "usage: ./fdf source_file.fdf\n"
# define EMPTY_FILE         "./fdf: file empty\n"
# define INVALID_EXTENSION  "./fdf: invalid extension\n"
# define INVALID_FILE       "./fdf: file doesn't exist or permission denied\n"
# define INVALID_MAP        "./fdf: map is invalid\n"
# define PARALLEL			0
# define ISOMETRIC			1

typedef struct s_fdf	t_fdf;
typedef struct s_point	t_point;
typedef struct s_shift	t_shift;

struct	s_point
{
	int		x;
	int		y;
	int		color;
	int		z;
};

struct	s_shift
{
	int		x;
	int		y;
};

struct	s_fdf
{
	int		height;
	int		width;
	int		**matrix;
	void	*mlx_ptr;
	void	*mlx_win;
	t_shift	shift;
	int		camera;
	int		zoom;
	int		color_map[3];
	int		menu;
	int		min_z;
	int		max_z;
	double	alpha;
	double	beta;
	double	gamma;
	int		grad;
};

void	print_map(t_fdf *data, int i, int j);
void	draw_line(t_point p0, t_point p1, t_fdf *data);
t_fdf	*ft_fdf_read(const char *map_file, t_fdf **data);
int		get_params(t_fdf **data, const int fd);
int		get_width(char *line);
int		ft_check_line_valid(char **parsed_line);
int		ft_is_char_valid(char *elem);
int		check_spaces(char *line, const int width);
int		check_extension(const char *map_file);
int		count_array_elem(char **line_to_count);
void	free_array(char **array);
void	find_min_max(t_fdf *data);
void	ft_makedata(t_fdf *go, const char *map_file);
int		*parse_to_int(char **parsed_line, const int length);
void	ft_exit(const char *error_msg);
void	free_fdf(t_fdf *data);
int		color(t_point current, t_point start, t_point end, t_point delta);
t_point	project(t_point p, t_fdf *fdf);
void	isometry(t_point *p);
void	increase_decrease(t_fdf *data, int key, int i, int j);
void	change_altitude(int key, t_fdf *data);
void	do_zoom(int key, t_fdf *data);
void	gradient(t_fdf *data);
void	do_shift(int key, t_fdf *data);
void	exit_program(t_fdf *data);
void	change_projection(t_fdf *data);
void	map_coloring(int key, t_fdf *data);
int		events(int key, t_fdf *data);
void	free_fdf(t_fdf *data);
void	get_crds_color(t_point *p, const int i, const int j, t_fdf *data);
void	fill_info(int data[6], t_point p0, t_point p1, t_point *delta);
void	check_projection(t_fdf *data, t_point *p0, t_point *p1);
t_point	project(t_point p, t_fdf *data);
void	rotation(int key, t_fdf *data);
void	menu_create(t_fdf *data);
void	menu_build(t_fdf *data);
#endif
