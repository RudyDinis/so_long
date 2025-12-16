/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:13:55 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 17:22:10 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	square(t_data img, t_vars vars, int x, int y)
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
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
}

void	setup_sprite(t_vars vars, t_line **line)
{
	t_line	*tmp_line;
	t_cell	*tmp_cell;
	int		y;
	int		x;

	tmp_line = *line;
	y = 0;
	while (tmp_line)
	{
		tmp_cell = tmp_line->cells;
		x = 0;
		while (tmp_cell)
		{
			if (tmp_cell->value == 'P')
			{
				vars.sprite->x = x + 1;
				vars.sprite->y = y + 1;
			}
			x += 31;
			tmp_cell = tmp_cell->next;
		}
		tmp_line = tmp_line->next;
		y += 31;
	}
}

void	draw_map(t_vars vars, t_line **line, int height)
{
	t_line	*tmp_line;
	t_cell	*tmp_cell;
	int		y;
	int		x;
	t_data	img;

	img.img = mlx_new_image(vars.mlx, (*line)->width * 31, height * 31);
	tmp_line = *line;
	y = 0;
	while (tmp_line)
	{
		tmp_cell = tmp_line->cells;
		x = 0;
		while (tmp_cell)
		{
			if (tmp_cell->value == '1')
				square(img, vars, x, y);
			x += 31;
			tmp_cell = tmp_cell->next;
		}
		tmp_line = tmp_line->next;
		y += 31;
	}
}
