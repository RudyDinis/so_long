/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/22 14:11:30 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	mlx_loop_end(vars->mlx);
	if (vars->sprite)
		clear_sprite(vars->sprite);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	ft_clear(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->animated_var);
	free_map(vars->map);
	free(vars);
	exit(0);
}