/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:26:32 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/27 19:06:04 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	no_cross_draw(int x, int y, int size_y, int size_x)
{
	if ((x <= size_x - 25 && x >= size_x - 27
			&& (y <= size_y - 4 && y >= size_y - 27))
		|| (x <= size_x - 4 && x >= size_x - 6
			&& (y <= size_y - 4 && y >= size_y - 27))
		|| ((y <= size_y - 25 && y >= size_y - 27)
			&& x <= size_x - 4 && x >= size_x - 27)
		|| ((y <= size_y - 4 && y >= size_y - 6)
			&& x <= size_x - 4 && x >= size_x - 27))
		return (1);
	return (0);
}

void	no_cross(t_data img, t_vars vars, int x, int y)
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
			if (no_cross_draw(x, y, size_y, size_x))
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00353094);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}
