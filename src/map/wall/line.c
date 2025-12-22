/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:48:03 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/22 19:51:41 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_vertical_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;

	if (x <= 0 || x >= ft_strlen(vars.map[y]) - 1)
		return (1);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	if (is_endtop(vars, x, y) == 1)
		return (0);
	if (is_endbottom(vars, x, y) == 1)
		return (0);
	if (left != '1' && right != '1')
		return (1);
	return (0);
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
