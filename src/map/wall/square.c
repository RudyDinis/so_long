/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:26:32 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 16:27:00 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	no_cross(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.wall_img[10], x, y);
}
