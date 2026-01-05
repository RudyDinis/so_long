/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:04:22 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 16:06:49 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	end_bottom(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[6], x, y);
}

void	end_top(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[7], x, y);
}

void	end_left(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[8], x, y);
}

void	end_right(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[9], x, y);
}
