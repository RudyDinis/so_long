/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:05:59 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/22 19:38:52 by rdinis           ###   ########.fr       */
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
# include <time.h>

# include "utils/gnl/get_next_line.h"
# include "utils/libft/libft.h"

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
	int				moving;
	int				dir;
	int				step;
	int				start_x;
	int				start_y;
}	t_anim;

typedef struct s_ghost
{
	int				x;
	int				y;
	void			*img;
	int				moving;
	int				dir;
	int				step;
	int				start_x;
	int				start_y;
	struct s_ghost	*next;
}	t_ghost;

typedef struct s_animated_var
{
	unsigned long	now;
	int				speed;
	int				dx[4];
	int				dy[4];
}	t_animated_var;

typedef struct s_vars_map
{
	int	p;
	int	e;
	int	c;
}	t_vars_map;


typedef struct s_vars
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				height;
	long			moove;
	long			score;
	t_data			img;
	t_anim			*sprite;
	t_ghost 		*ghost;
	t_animated_var	*animated_var;
}	t_vars;


int		check_map(char **map);
t_anim	*setup_animation(void *mlx, void *win);
t_data	draw_map(t_vars vars);
void	setup_sprite(t_vars *vars);
void	left_top(t_data img, t_vars vars, int x, int y);
void	left_bottom(t_data img, t_vars vars, int x, int y);
void	right_bottom(t_data img, t_vars vars, int x, int y);
void	right_top(t_data img, t_vars vars, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	horizontal(t_data img, t_vars vars, int x, int y);
void	vertical(t_data img, t_vars vars, int x, int y);
void	end_bottom(t_data img, t_vars vars, int x, int y);
void	end_top(t_data img, t_vars vars, int x, int y);
void	end_right(t_data img, t_vars vars, int x, int y);
void	end_left(t_data img, t_vars vars, int x, int y);
char	**load_map(char *file, int *height);
int		count_lines(char *file);
int		is_vertical_wall(t_vars vars, int x, int y);
int		is_lefttop_wall(t_vars vars, int x, int y);
int		is_leftbottom_wall(t_vars vars, int x, int y);
int		is_righttop_wall(t_vars vars, int x, int y);
int		is_rightbottom_wall(t_vars vars, int x, int y);
int		is_endbottom(t_vars vars, int x, int y);
int		is_endtop(t_vars vars, int x, int y);
int		is_endleft(t_vars vars, int x, int y);
int		is_endright(t_vars vars, int x, int y);
void	background(t_data img, t_vars vars, int x, int y);
void	clear_sprite(t_anim	*a);
void	free_map(char **map);
int		animate_hook_var(void *param);
void	draw_text(t_vars *vars);
int		close_hook(void *param);
int		setup_ghost(t_vars *vars, int x, int y);
void	ft_clear(t_vars *vars);
void    random_moove(t_vars *vars);
void	draw_ghosts(t_vars *vars);

#endif