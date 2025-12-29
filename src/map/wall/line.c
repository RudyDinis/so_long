/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:48:03 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/29 13:46:07 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_vertical_wall(t_data img, t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return ;
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return (vertical(img, vars, x * 31, y * 31));
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right != '1' && bottom == '1' && top == '1')
		return (vertical(img, vars, x * 31, y * 31));
}

void	is_horizontal_wall(t_data img, t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return (horizontal(img, vars, x * 31, y * 31));
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	right = vars.map[y][x + 1];
	left = vars.map[y][x - 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left == '1' && right == '1' && bottom != '1' && top != '1')
		horizontal(img, vars, x * 31, y * 31);
}

void	horizontal(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;

	size_y = y + 31;
	size_x = x + 31;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < size_x)
	{
		y = size_y - 31;
		while (y < size_y)
		{
			if ((y <= size_y - 25 && y >= size_y - 27)
				|| (y <= size_y - 4 && y >= size_y - 6))
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	vertical(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;

	size_y = y + 31;
	size_x = x + 31;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < size_x)
	{
		y = size_y - 31;
		while (y < size_y)
		{
			if ((x <= size_x - 25 && x >= size_x - 27)
				|| (x <= size_x - 4 && x >= size_x - 6))
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	background(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;

	size_y = y + 31;
	size_x = x + 31;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < size_x)
	{
		y = size_y - 31;
		while (y < size_y)
		{
			my_mlx_pixel_put(&img, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}
