/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/29 18:50:44 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_hook2(t_vars *vars)
{
	if (vars->sprite)
		clear_sprite(vars->sprite);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->ghost)
		ft_clear(vars);
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	if (vars->map)
		free_map(vars->map);
	if (vars->exit)
		free(vars->exit);
}

int	close_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (!vars)
		return (0);
	close_hook2(vars);
	if (vars->mlx)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->animated_var)
		free(vars->animated_var);
	free(vars);
	exit(0);
}
