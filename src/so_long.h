/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:05:59 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/06 19:35:39 by rdinis           ###   ########.fr       */
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

typedef struct s_line
{
	int				y;
	t_cell			*cells;
	struct s_line	*next;
}	t_line;

typedef struct s_map
{
	t_line	*lines;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_square
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
}	t_square;

typedef struct s_anim
{
	void			*mlx;
	void			*win;
	void			*imgs[11];
	int				frame;
	unsigned long	last_ms;
	int				interval_ms;
	int				y;
	int				x;
}	t_anim;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	t_anim	*sprite;
}				t_vars;

void	map(char *arg, t_line **line);
void	ft_push_cell(t_cell **p, int val);
void	ft_push_line(t_line **p, t_cell **cell, int y);
void	ft_view_line(t_line *p);
int		check_line(t_cell *cell);
int		check_map(t_line *line);
t_anim	*setup_animation(void *mlx, void *win);

#endif