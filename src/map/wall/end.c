/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:04:22 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 19:00:24 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	end_bottom(t_data img, t_vars vars, int x, int y)
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
			if ((x <= size_x - 25 && x >= size_x - 27 && y <= size_y - 6)
				|| (x <= size_x - 4 && x >= size_x - 6 && y <= size_y - 6)
				|| (y <= size_y - 4 && y >= size_y - 6)
				&& x <= size_x - 4 && x >= size_x - 27)
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	end_top(t_data img, t_vars vars, int x, int y)
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
			if ((x <= size_x - 25 && x >= size_x - 27 && y >= size_y - 25)
				|| (x <= size_x - 4 && x >= size_x - 6 && y >= size_y - 25)
				|| (y <= size_y - 25 && y >= size_y - 27)
				&& x <= size_x - 4 && x >= size_x - 27)
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	end_left(t_data img, t_vars vars, int x, int y)
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
			if ((y <= size_y - 25 && y >= size_y - 27 && x >= size_x - 25)
				|| (y <= size_y - 4 && y >= size_y - 6 && x >= size_x - 25)
				|| (x <= size_x - 25 && x >= size_x - 27
					&& (y <= size_y - 4 && y >= size_y - 27)))
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	end_right(t_data img, t_vars vars, int x, int y)
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
			if ((y <= size_y - 25 && y >= size_y - 27 && x <= size_x - 4)
				|| (y <= size_y - 4 && y >= size_y - 6 && x <= size_x - 4)
				|| (x <= size_x - 4 && x >= size_x - 6
					&& (y <= size_y - 4 && y >= size_y - 27)))
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}
