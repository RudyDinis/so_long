/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:13:55 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/27 18:52:07 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	setup_sprite(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	while (y < vars->height && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->sprite->x = x * 31;
				vars->sprite->y = y * 31;
			}
			x++;
		}
		y++;
	}
}

void	select_wall(t_data img, t_vars vars, int x, int y)
{
	is_horizontal_wall(img, vars, x, y);
	is_vertical_wall(img, vars, x, y);
	is_t_left(img, vars, x, y);
	is_t_right(img, vars, x, y);
	is_t_top(img, vars, x, y);
	is_t_bottom(img, vars, x, y);
	is_t_cross(img, vars, x, y);
	is_no_cross(img, vars, x, y);
	is_lefttop_wall(img, vars, x, y);
	is_leftbottom_wall(img, vars, x, y);
	is_righttop_wall(img, vars, x, y);
	is_rightbottom_wall(img, vars, x, y);
	if (is_endbottom(vars, x, y))
		end_bottom(img, vars, x * 31, y * 31);
	else if (is_endtop(vars, x, y))
		end_top(img, vars, x * 31, y * 31);
	else if (is_endright(vars, x, y))
		end_right(img, vars, x * 31, y * 31);
	else if (is_endleft(vars, x, y))
		end_left(img, vars, x * 31, y * 31);
}

void	collectible(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;
	int			cx;
	int			cy;

	size_y = y + 31;
	size_x = x + 31;
	cx = x + 15;
	cy = y + 15;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < size_x)
	{
		y = size_y - 31;
		while (y < size_y)
		{
			if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= 5 * 5)
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

int	find_exit(t_vars *vars, int x, int y)
{
	t_exit	*exit;

	exit = malloc(sizeof(*exit));
	if (!exit)
		return (write(2, "Error\nMalloc Error\n", 20), close_hook(vars));
	exit->y = y;
	exit->x = x;
	vars->exit = exit;
	return (1);
}

t_data	draw_map(t_vars *vars)
{
	int		y;
	int		x;
	t_data	img;

	img.img = mlx_new_image(vars->mlx, ft_strlen(vars->map[0]) * 31,
			vars->height * 31);
	y = 0;
	while (y < vars->height && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				select_wall(img, *vars, x, y);
			if (vars->map[y][x] == 'C')
				collectible(img, *vars, x * 31, y * 31);
			if (vars->map[y][x] == 'E')
				find_exit(vars, x, y);
			x++;
		}
		y++;
	}
	return (img);
}
