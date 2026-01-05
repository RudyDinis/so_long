/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:36:08 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 17:13:13 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_load(t_vars *vars)
{
	int	i;

	i = 0;
	while (i <= 16)
	{
		if (!vars->wall_img[i])
		{
			write(1, "Error\nimage not found\n", 22);
			close_hook(vars);
		}
		printf("%d %p\n", i, vars->wall_img[i]);
		i++;
	}
}

void	load_img2(t_vars *vars)
{
	int		w;
	int		h;

	vars->wall_img[9] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/end_right.xpm", &w, &h);
	vars->wall_img[10] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/no_cross.xpm", &w, &h);
	vars->wall_img[11] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/t_right.xpm", &w, &h);
	vars->wall_img[12] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/t_left.xpm", &w, &h);
	vars->wall_img[13] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/t_top.xpm", &w, &h);
	vars->wall_img[14] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/t_bottom.xpm", &w, &h);
	vars->wall_img[15] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/t_cross.xpm", &w, &h);
	vars->wall_img[16] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/background.xpm", &w, &h);
}

void	load_img(t_vars *vars)
{
	int		w;
	int		h;

	vars->wall_img[0] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/left_top.xpm", &w, &h);
	vars->wall_img[1] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/left_bottom.xpm", &w, &h);
	vars->wall_img[2] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/right_bottom.xpm", &w, &h);
	vars->wall_img[3] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/right_top.xpm", &w, &h);
	vars->wall_img[4] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/horizontal.xpm", &w, &h);
	vars->wall_img[5] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/vertical.xpm", &w, &h);
	vars->wall_img[6] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/end_bottom.xpm", &w, &h);
	vars->wall_img[7] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/end_top.xpm", &w, &h);
	vars->wall_img[8] = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/wall/end_left.xpm", &w, &h);
	load_img2(vars);
	check_load(vars);
}
