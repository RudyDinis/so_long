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

void	select_wall(t_data img, t_vars vars, int x, int y)
{

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
				select_wall(img, vars, x, y);
			x += 31;
			tmp_cell = tmp_cell->next;
		}
		tmp_line = tmp_line->next;
		y += 31;
	}
}
