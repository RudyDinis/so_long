/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:48:03 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 17:20:16 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_vertical_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return ;
	if (x == 0 || x == (int)ft_strlen(vars.map[0]))
		return (vertical(vars, x * 31, y * 31));
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right != '1' && bottom == '1' && top == '1')
		return (vertical(vars, x * 31, y * 31));
}

void	is_horizontal_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return (horizontal(vars, x * 31, y * 31));
	if (x == 0 || x == (int)ft_strlen(vars.map[0]))
		return ;
	right = vars.map[y][x + 1];
	left = vars.map[y][x - 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left == '1' && right == '1' && bottom != '1' && top != '1')
		horizontal(vars, x * 31, y * 31);
}

void	horizontal(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[4], x, y);
}

void	vertical(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[5], x, y);
}

void	background(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[16], x, y);
}
