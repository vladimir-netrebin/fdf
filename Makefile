# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbespin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 14:28:34 by hbespin           #+#    #+#              #
#    Updated: 2020/02/27 18:32:28 by hbespin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SOURCES = utils.c control.c control2.c control3.c projection.c exit.c fdf_check_utils.c fdf_make_data.c fdf_read.c main.c draw_line.c draw_utils.c print_map.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

STL = libft/

MLX = minilibx_macos/

all: $(NAME)

$(NAME): $(OBJECTS)
	    make -C $(STL)
		make -C $(MLX)
		$(CC) $(OBJECTS) -I fdf.h -L. $(STL)libft.a -L. $(MLX)libmlx.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	    $(CC) $(CFLAGS) -g -I fdf.h -c $< -o $@

clean:
	    make -C $(STL) clean
		/bin/rm -f $(OBJECTS)
fclean: clean
	    /bin/rm -f $(NAME) $(STL)libft.a
		make -C $(MLX) clean

re: fclean all
