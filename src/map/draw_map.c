/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:13:55 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/18 14:48:52 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	setup_sprite(t_vars vars)
{
	int		y;
	int		x;
	t_data	img;

	img.img = mlx_new_image(vars.mlx, ft_strlen(vars.map[0]) * 31,
			vars.height * 31);
	y = 0;
	while (y < vars.height && vars.map[y])
	{
		x = 0;
		while (vars.map[y][x])
		{
			if (vars.map[y][x] == 'P')
			{
				vars.sprite->x = x * 31;
				vars.sprite->y = y * 31;
			}
			x++;
		}
		y++;
	}
}

int	is_vertical_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;

	if (x <= 0 || x >= ft_strlen(vars.map[y]) - 1)
		return (1);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	if (left == '0' && right == '0')
		return (1);
	return (0);
}

void	select_wall(t_data img, t_vars vars, int x, int y)
{
	if (is_lefttop_wall(vars, x, y))
		left_top(img, vars, x * 31, y * 31);
	else if (is_leftbottom_wall(vars, x, y))
		left_bottom(img, vars, x * 31, y * 31);
	else if (is_righttop_wall(vars, x, y))
		right_top(img, vars, x * 31, y * 31);
	else if (is_rightbottom_wall(vars, x, y))
		right_bottom(img, vars, x * 31, y * 31);
	else if (is_vertical_wall(vars, x, y))
		vertical(img, vars, x * 31, y * 31);
	else
		horizontal(img, vars, x * 31, y * 31);
}

t_data	draw_map(t_vars vars)
{
	int		y;
	int		x;
	t_data	img;

	img.img = mlx_new_image(vars.mlx, ft_strlen(vars.map[0]) * 31,
			vars.height * 31);
	y = 0;
	while (y < vars.height && vars.map[y])
	{
		x = 0;
		while (vars.map[y][x])
		{
			if (vars.map[y][x] == '1')
				select_wall(img, vars, x, y);
			x++;
		}
		y++;
	}
	return (img);
}
