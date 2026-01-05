/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:31:57 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 16:36:51 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	t_left(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[11], x, y);
}

void	t_right(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[12], x, y);
}

void	t_top(t_vars vars, int x, int y)
{

	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[13], x, y);
}

void	t_bottom(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[14], x, y);
}

void	t_cross(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[15], x, y);
}
