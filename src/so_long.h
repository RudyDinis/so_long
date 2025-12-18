/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:05:59 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/18 19:47:42 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <sys/time.h>

# include "utils/gnl/get_next_line.h"
# include "utils/libft/libft.h"

typedef struct s_cell
{
	char			value;
	struct s_cell	*next;
}	t_cell;

typedef struct s_arg{
	int	y;
	int	width;
	int	height;
}	t_arg;

typedef struct s_line
{
	int				y;
	int				width;
	t_cell			*cells;
	struct s_line	*next;
}	t_line;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_anim
{
	void			*mlx;
	void			*win;
	void			*img[11];
	int				frame;
	unsigned long	last_ms;
	int				interval_ms;
	int				y;
	int				x;
}	t_anim;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_anim	*sprite;
}				t_vars;

typedef struct s_vars_map {
	int	p;
	int	e;
	int	c;
}	t_vars_map;

int		map(char *arg, t_line **line);
void	ft_push_cell(t_cell **p, int val);
void	ft_push_line(t_line **p, t_cell **cell, int y, int x);
void	ft_view_line(t_line *p);
int		check_map(char **map);
t_anim	*setup_animation(void *mlx, void *win);
void	draw_map(t_vars vars, t_line **line, int height);
void	setup_sprite(t_vars vars, t_line **line);
int		check_condition(t_line *line);
void	left_top(t_data img, t_vars vars, int x, int y);
void	left_bottom(t_data img, t_vars vars, int x, int y);
void	right_bottom(t_data img, t_vars vars, int x, int y);
void	right_top(t_data img, t_vars vars, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	horizontal(t_data img, t_vars vars, int x, int y);
void	verticale(t_data img, t_vars vars, int x, int y);
char	**load_map(char *file, int *height);
int		count_lines(char *file);

#endif