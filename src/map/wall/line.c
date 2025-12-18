/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:48:03 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/18 14:13:25 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
(y <= size_y - 25 && y >= size_y - 27)
*/

void	horizontal(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;

	size_y = y + 31;
	size_x = x + 31;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x <= size_x)
	{
		y = size_y - 31;
		while (y <= size_y)
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

void	verticale(t_data img, t_vars vars, int x, int y)
{
	int			size_y;
	int			size_x;

	size_y = y + 31;
	size_x = x + 31;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x <= size_x)
	{
		y = size_y - 31;
		while (y <= size_y)
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
