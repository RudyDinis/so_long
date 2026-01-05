/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:10:18 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 15:59:11 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	left_top(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[0], x, y);
}

void	left_bottom(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[1], x, y);
}

void	right_bottom(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[2], x, y);
}

void	right_top(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[3], x, y);
}
