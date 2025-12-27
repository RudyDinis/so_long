/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:31:43 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/27 14:46:47 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_dead(t_vars	*vars)
{
	t_ghost	*g;
	int		sx;
	int		sy;
	int		gx;
	int		gy;

	g = vars->ghost;
	while (g)
	{
		sx = vars->sprite->x / 31;
		sy = vars->sprite->y / 31;
		gx = g->x / 31;
		gy = g->y / 31;
		if (sx == gx && sy == gy)
			close_hook(vars);
		g = g->next;
	}
}

void	is_eat_all(t_vars	*vars)
{
	if (vars->score == vars->collectible)
	{
		if (vars->sprite->x / 31 == vars->exit->x
			&& vars->sprite->y / 31 == vars->exit->y)
			close_hook(vars);
		game_exit(vars->img, *vars, vars->exit->x * 31, vars->exit->y * 31);
	}
}
